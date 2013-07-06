
#include "pch.h"

#include <stdio.h>
#include <stack>
#include <algorithm>
#include <iterator>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/variant.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/optional.hpp>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/range/adaptors.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/spirit/include/lex_lexertl.hpp>
#include <boost/spirit/include/classic_position_iterator.hpp>

#include "glscene/Parse.h"
#include "glscene/SceneGraph.h"
#include <glutil/array_ref.h>
#include <glload/gl_all.hpp>
#include <glimg/glimg.h>
#include "ResourceData.h"
#include "ParserUtils.h"
#include "ParserExceptions.h"
#include "ParserEnums.h"

namespace lex = boost::spirit::lex;
namespace qi = boost::spirit::qi;

using boost::string_ref;
using refs::array_ref;

namespace
{
	using namespace glscene::_detail;

	//////////////////////////////////////////////////////////////////////////
	// Uniform definitions
	struct UniformFromSingleValue : public boost::static_visitor<glscene::UniformData>
	{
		UniformFromSingleValue(int _typeIx) : typeIx(_typeIx) {}

		template<typename T>
		glscene::UniformData operator()(const T &t) const
		{
			return ConstructFromSingleValue(t, typeIx);
		}

	private:
		int typeIx;
	};

	template<typename Dest>
	struct ParseConvertVisit : public boost::static_visitor<Dest>
	{
		template<typename T>
		Dest operator()(T t) {return Dest(t);}
	};

	template<typename Dest>
	std::vector<Dest> ConvertParsedVector(const std::vector<ParsedValue> &parsed)
	{
		ParseConvertVisit<Dest> func;
		BOOST_AUTO(newData, parsed | boost::adaptors::transformed(boost::apply_visitor(func)));
		return std::vector<Dest>(newData.begin(), newData.end());
	}

	template<typename T>
	glscene::UniformData MakeUniformData(const std::vector<T> &arr, int typeIx)
	{
		BOOST_ASSERT(arr.size() == GetUniformTypeLength(typeIx));
		switch(typeIx)
		{
		case 0: return glscene::UIntVectorTypes((unsigned int)(arr[0]));
		case 1: return glscene::UIntVectorTypes(glm::uvec2(arr[0], arr[1]));
		case 2: return glscene::UIntVectorTypes(glm::uvec3(arr[0], arr[1], arr[2]));
		case 3: return glscene::UIntVectorTypes(glm::uvec4(arr[0], arr[1], arr[2], arr[3]));

		case 4: return glscene::IntVectorTypes(int(arr[0]));
		case 5: return glscene::IntVectorTypes(glm::ivec2(arr[0], arr[1]));
		case 6: return glscene::IntVectorTypes(glm::ivec3(arr[0], arr[1], arr[2]));
		case 7: return glscene::IntVectorTypes(glm::ivec4(arr[0], arr[1], arr[2], arr[3]));

		case 8: return glscene::VectorTypes(float(arr[0]));
		case 9: return glscene::VectorTypes(glm::vec2(arr[0], arr[1]));
		case 10: return glscene::VectorTypes(glm::vec3(arr[0], arr[1], arr[2]));
		case 11: return glscene::VectorTypes(glm::vec4(arr[0], arr[1], arr[2], arr[3]));

		case 12: return glscene::MatrixTypes(glm::mat2(
					 arr[0], arr[1],
					 arr[2], arr[3]));
		case 13: return glscene::MatrixTypes(glm::mat3(
					 arr[0], arr[1], arr[2],
					 arr[0], arr[1], arr[2],
					 arr[0], arr[1], arr[2]));
		case 14: return glscene::MatrixTypes(glm::mat4(
					 arr[0], arr[1], arr[2], arr[3],
					 arr[4], arr[5], arr[6], arr[7],
					 arr[8], arr[9], arr[10], arr[11],
					 arr[12], arr[13], arr[14], arr[15]));
		}

		return glscene::UniformData();
	}

	glscene::UniformData BuildUniformData(const std::vector<ParsedValue> &parsed, int typeIx)
	{
		if(IsUnifTypeUnsigned(typeIx))
			return MakeUniformData(ConvertParsedVector<unsigned int>(parsed), typeIx);
		else if(IsUnifTypeInteger(typeIx))
			return MakeUniformData(ConvertParsedVector<int>(parsed), typeIx);
		else
			return MakeUniformData(ConvertParsedVector<float>(parsed), typeIx);
	}



	//////////////////////////////////////////////////////////////////////////
	// Tokens
	enum AllTokens
	{
#define MAC(name, pattern, debug_name, display_name) TOK_##name,
		BEGIN_KEYWORDS = KEYWORD_ID_PREFIX - 1,
#include "keywords.incl"
		BEGIN_WHITESPACE = WHITESPACE_ID_PREFIX - 1,
#include "whitespace.incl"
		BEGIN_STRINGS = STRING_ID_PREFIX - 1,
#include "strings.incl"
		BEGIN_NUMBERS = NUMBER_ID_PREFIX - 1,
#include "numbers.incl"
		BEGIN_SYMBOLS = SYMBOL_ID_PREFIX - 1,
#include "symbols.incl"
#undef MAC
	};

	//////////////////////////////////////////////////////////////////////////
	// Token string names.
	static const char *g_keywordStrings[][3] =
	{
#define MAC(name, pattern, debug_name, display_name) {pattern, pattern, pattern},
#include "keywords.incl"
#undef MAC
	};

	static const char *g_whitespaceStrings[][3] =
	{
#define MAC(name, pattern, debug_name, display_name) {pattern, debug_name, display_name},
#include "whitespace.incl"
#undef MAC
	};

	static const char *g_stringsStrings[][3] =
	{
#define MAC(name, pattern, debug_name, display_name) {pattern, debug_name, display_name},
#include "strings.incl"
#undef MAC
	};

	static const char *g_numbersStrings[][3] =
	{
#define MAC(name, pattern, debug_name, display_name) {pattern, debug_name, display_name},
#include "numbers.incl"
#undef MAC
	};

	static const char *g_symbolStrings[][3] =
	{
#define MAC(name, pattern, debug_name, display_name) {pattern, debug_name, display_name},
#include "symbols.incl"
#undef MAC
	};

	//////////////////////////////////////////////////////////////////////////
	//Token groups
	const size_t g_integerTokenIds[] =
	{TOK_UNSIGNED_INTEGER, TOK_SIGNED_INTEGER};

	const size_t g_validSamplerTokens[] =
	{
		TOK_MAG,
		TOK_MIN,
		TOK_COMPARE,
		TOK_WRAP_S,
		TOK_WRAP_T,
		TOK_WRAP_R,
		TOK_ANISO,
	};

	//////////////////////////////////////////////////////////////////////////
	// The lexer.
	template <typename Lexer>
	struct simple_lexer : lex::lexer<Lexer>
	{
		simple_lexer()
		{
			for(size_t loop = 0; loop < boost::size(g_keywordStrings); ++loop)
			{
				this->self.add(g_keywordStrings[loop][0], loop | KEYWORD_ID_PREFIX);
			}

			for(size_t loop = 0; loop < boost::size(g_whitespaceStrings); ++loop)
			{
				this->self.add(g_whitespaceStrings[loop][0], loop | WHITESPACE_ID_PREFIX);
			}

			for(size_t loop = 0; loop < boost::size(g_stringsStrings); ++loop)
			{
				this->self.add(g_stringsStrings[loop][0], loop | STRING_ID_PREFIX);
			}

			for(size_t loop = 0; loop < boost::size(g_numbersStrings); ++loop)
			{
				this->self.add(g_numbersStrings[loop][0], loop | NUMBER_ID_PREFIX);
			}

			for(size_t loop = 0; loop < boost::size(g_symbolStrings); ++loop)
			{
				this->self.add(g_symbolStrings[loop][0], loop | SYMBOL_ID_PREFIX);
			}

			//Catch two keywords rammed together. Not a matched token, so it's bad.
			this->self.add("[a-zA-Z]+", 0x0);

		}
	};
}

namespace glscene { namespace _detail {
	//////////////////////////////////////////////////////////////////////////
	// Token Identification
	size_t GetPrefixFromId(size_t id)
	{
		return id & PREFIX_MASK;
	}

	std::string GetTokenCatName(size_t id)
	{
		size_t prefix = GetPrefixFromId(id);
		switch(prefix)
		{
		case KEYWORD_ID_PREFIX:				return "Keyword";
		case WHITESPACE_ID_PREFIX:			return "Whitespace";
		case STRING_ID_PREFIX:				return "String";
		case NUMBER_ID_PREFIX:				return "Number";
		case SYMBOL_ID_PREFIX:				return "Symbol";
		default:
			return "UNKNOWN_CATEGORY!";
		}
	}

	std::string GetTokenName(size_t id)
	{
		size_t prefix = GetPrefixFromId(id);
		switch(prefix)
		{
		case KEYWORD_ID_PREFIX:
			return g_keywordStrings[id & ~KEYWORD_ID_PREFIX][1];
		case WHITESPACE_ID_PREFIX:
			return g_whitespaceStrings[id & ~WHITESPACE_ID_PREFIX][1];
		case STRING_ID_PREFIX:
			return g_stringsStrings[id & ~STRING_ID_PREFIX][1];
		case NUMBER_ID_PREFIX:
			return g_numbersStrings[id & ~NUMBER_ID_PREFIX][1];
		case SYMBOL_ID_PREFIX:
			return g_symbolStrings[id & ~SYMBOL_ID_PREFIX][1];
		default:
			return "UNKNOWN_TOKEN!";
		}
	}

	std::string GetTokenErrorName(size_t id)
	{
		size_t prefix = GetPrefixFromId(id);
		switch(prefix)
		{
		case KEYWORD_ID_PREFIX:
			return g_keywordStrings[id & ~KEYWORD_ID_PREFIX][2];
		case WHITESPACE_ID_PREFIX:
			return g_whitespaceStrings[id & ~WHITESPACE_ID_PREFIX][2];
		case STRING_ID_PREFIX:
			return g_stringsStrings[id & ~STRING_ID_PREFIX][2];
		case NUMBER_ID_PREFIX:
			return g_numbersStrings[id & ~NUMBER_ID_PREFIX][2];
		case SYMBOL_ID_PREFIX:
			return g_symbolStrings[id & ~SYMBOL_ID_PREFIX][2];
		default:
			return "UNKNOWN_TOKEN!";
		}
	}

	expect_category_t exp_cat;
	expect_message_t exp_message;
	uniform_unsigned_mismatch_t unf_type_unsigned;
	uniform_scalar_mismatch_t unif_type_scalar;
	uniform_float_mismatch_t unf_type_float;
	uniform_size_mismatch_t unf_type_size;

	struct ThrowOnInvalid
	{
		template<typename Token>
		bool operator()(const Token &tok) const
		{
			if(!token_is_valid(tok))
				throw BadTokenError(tok);
			return true;
		}
	};

	struct SkipWhitespace
	{
		template<typename Token>
		bool operator()(const Token &tok) const
		{
			return GetPrefixFromId(tok.id()) != WHITESPACE_ID_PREFIX;
		}
	};

}}


namespace glscene
{
	namespace classic = boost::spirit::classic;
	typedef classic::position_iterator2<boost::string_ref::const_iterator> pos_iterator;
	typedef pos_iterator base_iterator_type;
	typedef lex::lexertl::token<base_iterator_type> token_type;
	typedef lex::lexertl::lexer<token_type> lexer_type;

	typedef simple_lexer<lexer_type>::iterator_type token_iterator;
	typedef boost::iterator_range<token_iterator> token_range;

	struct FilePosition
	{
		std::string fileName;
		int lineNumber;
		int columnNumber;
		std::string theLine;
	};

	struct ParsedUniformDef
	{
		FilePosition pos;
		UniformData data;
	};

	struct ParsedSamplerDef
	{
		FilePosition pos;
		SamplerInfo sampler;
	};

	typedef boost::container::flat_map<IdString, ParsedUniformDef> ParsedUniformMap;
	typedef boost::container::flat_map<IdString, ParsedSamplerDef> ParsedSamplerMap;

	struct ParsedResources
	{
		ParsedUniformMap uniforms;
		ParsedSamplerMap samplers;
	};

	template<typename Range>
	class SceneGraphParser
	{
	public:
		typedef typename Range::value_type Token;

		SceneGraphParser(pos_iterator &posIt, const Range &rng)
			: m_currIt(posIt)
			, m_rng(rng)
		{}

		void ParseSceneGraph()
		{
			ParseResources();
		}

		void ParseResources()
		{
			PosStackPusher push(*this);

			ExpectToken(TOK_RESOURCES);
			EatOneToken();

			while(!m_rng.empty() && m_rng.front().id() != TOK_END)
			{
				PosStackPusher push(*this);

				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				typename Range::value_type tok = m_rng.front();
				switch(tok.id())
				{
				case TOK_UNIFORM_RES:
					{
						EatOneToken();
						ParseIdentifier();
						int uniformType = ParseEnumerator(g_uniformTypeEnumeration);
						UniformData data = ParseUniformData(uniformType);
					}
					break;
				case TOK_SAMPLER_RES:
					ParseSamplerData();
					break;
				default:
					throw UnexpectedDataError(m_rng.front(), "a valid resource.", exp_message);
				}
			}

			ExpectToken(TOK_END);
			EatOneToken();
		}

	private:
		void EatOneToken() {m_rng.advance_begin(1);}

		void ParseIdentifier()
		{
			ExpectToken(TOK_IDENTIFIER);

			EatOneToken();
		}

		void ParseSamplerData()
		{
			ExpectAndEatToken(TOK_SAMPLER_RES);
			ParseIdentifier();

			TokenChecker hasBeenFound;

			while(!m_rng.empty() && m_rng.front().id() != TOK_END)
			{
				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				if(!HasTokenOneOfNoEmpty(g_validSamplerTokens))
					throw UnexpectedDataError(m_rng.front(), "a valid sampler parameter.", exp_message);

				typename Range::value_type tok = m_rng.front();
				CheckMultipleKeyword(hasBeenFound, tok, TOK_SAMPLER_RES);
				EatOneToken();

				switch(tok.id())
				{
				case TOK_MAG:
					ParseEnumerator(g_magFilterEnumeration);
					break;
				case TOK_MIN:
					ParseEnumerator(g_minFilterEnumeration);
					break;
				case TOK_COMPARE:
					ParseEnumerator(g_compareModeEnumeration);
					break;
				case TOK_WRAP_S:
				case TOK_WRAP_T:
				case TOK_WRAP_R:
					ParseEnumerator(g_wrapModeEnumeration);
					break;
				case TOK_ANISO:
					{
						ExpectCategory(NUMBER_ID_PREFIX);
						boost::lexical_cast<float>(GetTokenString());
						EatOneToken();
					}
					break;
				}
			}
		}

		UniformData ParseUniformData(int typeIx)
		{
			boost::optional<bool> has_cat = HasCategory(NUMBER_ID_PREFIX);

			//Only returns this if there is no next token. It's an error, but it's someone else's error.
			if(!has_cat)
				return CreateDefaultUniform(typeIx);

			if(has_cat.get())
			{
				//No parenthesis, so the type must be a scalar.
				if(GetUniformTypeLength(typeIx) != 1)
					throw UniformTypeMismatchError(m_rng.front(), g_uniformTypeList[typeIx], unif_type_scalar);

				if(HasTokenOneOfNoEmpty(g_integerTokenIds))
				{
					//Starts with minus and the type should be unsigned.
					if(IsUnifTypeUnsigned(typeIx) && HasTokenNoEmpty(TOK_SIGNED_INTEGER))
						throw UniformTypeMismatchError(m_rng.front(), g_uniformTypeList[typeIx], unf_type_unsigned);

					std::string theInt(GetTokenString());
					EatOneToken();

					if(theInt[0] == '-')
					{
						int val = boost::lexical_cast<int>(theInt);
						return ConstructFromSingleValue(val, typeIx);
					}
					else
					{
						unsigned int val = boost::lexical_cast<unsigned int>(theInt);
						return ConstructFromSingleValue(val, typeIx);
					}
				}
				else
				{
					BOOST_ASSERT(HasTokenNoEmpty(TOK_FLOAT));
					if(IsUnifTypeInteger(typeIx))
						throw UniformTypeMismatchError(m_rng.front(),
						g_uniformTypeList[typeIx], unf_type_float);

					std::string theFloat(GetTokenString());

					EatOneToken();
					float val = boost::lexical_cast<float>(theFloat);
					return ConstructFromSingleValue(val, typeIx);
				}
			}
			else if(HasTokenNoEmpty(TOK_OPEN_PAREN))
			{
				std::vector<ParsedValue> vals = ParseNumberList(typeIx);
				if(vals.size() == 1)
					return boost::apply_visitor(UniformFromSingleValue(typeIx), vals[0]);

				return BuildUniformData(vals, typeIx);
			}
			else
				//Not a number, so let the next statement handle it.
				return CreateDefaultUniform(typeIx);
		}

		std::vector<ParsedValue> ParseNumberList(int typeIx)
		{
			ExpectAndEatToken(TOK_OPEN_PAREN);

			const int expectedSize = GetUniformTypeLength(typeIx);

			std::vector<ParsedValue> ret;
			ret.reserve(16);

			int count = 0;

			for(;
				!m_rng.empty() && !HasTokenNoEmpty(TOK_CLOSE_PAREN);
				EatOneToken(), ++count)
			{
				ExpectCategory(NUMBER_ID_PREFIX);
				if(expectedSize == count)
					throw UniformTypeMismatchError(m_rng.front(), g_uniformTypeList[typeIx], expectedSize, true);

				if(HasTokenOneOfNoEmpty(g_integerTokenIds))
				{
					//Starts with minus and the type should be unsigned.
					if(IsUnifTypeUnsigned(typeIx) && HasTokenNoEmpty(TOK_SIGNED_INTEGER))
						throw UniformTypeMismatchError(m_rng.front(),
						g_uniformTypeList[typeIx], unf_type_unsigned);

					std::string theInt(GetTokenString());

					if(theInt[0] == '-')
						ret.push_back(boost::lexical_cast<int>(theInt));
					else
						ret.push_back(boost::lexical_cast<unsigned int>(theInt));
				}
				else
				{
					BOOST_ASSERT(HasTokenNoEmpty(TOK_FLOAT));
					if(IsUnifTypeInteger(typeIx))
						throw UniformTypeMismatchError(m_rng.front(),
						g_uniformTypeList[typeIx], unf_type_float);

					std::string theFloat(GetTokenString());

					ret.push_back(boost::lexical_cast<float>(theFloat));
				}
			}

			//Throws if we hit the EOF first.
			ExpectToken(TOK_CLOSE_PAREN);

			//Throw if not enough parameters were provided. A count of 1 is always allowed.
			if(expectedSize != count && count != 1)
				throw UniformTypeMismatchError(m_rng.front(), g_uniformTypeList[typeIx], expectedSize, false);

			ExpectAndEatToken(TOK_CLOSE_PAREN);
			return ret;
		}

		template<typename Mapped>
		int ParseEnumerator(const EnumData<Mapped> &data)
		{
			ExpectToken(TOK_ENUMERATOR);

			std::string testEnum = GetEnumFromToken(m_rng.front());

			const boost::string_ref *foundEnum = boost::find(data.enumerators, boost::string_ref(testEnum));
			size_t enumIx = foundEnum - data.enumerators.data();
			if(enumIx >= data.enumerators.size())
				throw IncorrectEnumError(m_rng.front(), data);

			EatOneToken();

			return enumIx;
		}

		std::string GetEnumFromToken(const Token &tok)
		{
			std::string enumerator(tok.value().begin(), tok.value().end());
			return std::string(enumerator.begin() + 1, enumerator.end() - 1);
		}

		void ExpectAndEatToken(size_t idExpected)
		{
			if(m_rng.empty())
				throw UnexpectedDataError(idExpected);
			else
			{
				ExpectToken(m_rng.front(), idExpected);
				EatOneToken();
			}
		}

		void ExpectToken(size_t idExpected) const
		{
			if(m_rng.empty())
				throw UnexpectedDataError(idExpected);
			else
				ExpectToken(m_rng.front(), idExpected);
		}

		void ExpectToken(const Token &tok, size_t idExpected) const
		{
			if(tok.id() != idExpected)
				throw UnexpectedDataError(idExpected, tok);
		}

		void ExpectCategory(const Token &tok, size_t prefix) const
		{
			if((tok.id() & PREFIX_MASK) != prefix)
				throw UnexpectedDataError(prefix, tok, exp_cat);
		}

		void ExpectCategory(size_t prefix) const
		{
			if(m_rng.empty())
				throw UnexpectedDataError(prefix, exp_cat);
			else
				ExpectCategory(m_rng.front(), prefix);
		}

		bool HasToken(const Token &tok, size_t idExpected) const
		{
			return tok.id() == idExpected;
		}

		boost::optional<bool> HasToken(size_t idExpected) const
		{
			if(m_rng.empty())
				return boost::none;
			else
				return HasToken(m_rng.front(), idExpected);
		}

		bool HasTokenNoEmpty(size_t idExpected) const
		{
			BOOST_ASSERT(!m_rng.empty());
			return HasToken(m_rng.front(), idExpected);
		}

		bool HasTokenOneOfNoEmpty(array_ref<size_t> expecteds) const
		{
			BOOST_ASSERT(!m_rng.empty());
			BOOST_FOREACH(size_t idExpected, expecteds)
			{
				if(HasToken(m_rng.front(), idExpected))
					return true;
			}

			return false;
		}

		bool HasCategory(const token_type &tok, size_t prefix) const
		{
			size_t t = tok.id() & PREFIX_MASK;
			return (t) == prefix;
		}

		boost::optional<bool> HasCategory(size_t prefix) const
		{
			if(m_rng.empty())
				return boost::none;
			else
				return HasCategory(m_rng.front(), prefix);
		}

		bool HasCategoryNoEmpty(size_t prefix) const
		{
			BOOST_ASSERT(!m_rng.empty());
			return HasCategory(m_rng.front(), prefix);
		}


		FilePosition GetPositionForCurrToken() const
		{
			FilePosition pos;
			const classic::file_position_base<std::string> &itPos = m_currIt.get_position();

			pos.fileName = itPos.file;
			pos.lineNumber = itPos.line;
			pos.columnNumber = itPos.column;
			pos.theLine = boost::algorithm::replace_all_copy(m_currIt.get_currentline(), "\t", "    ");

			if(token_is_valid(m_rng.front()))
			{
				//The token is valid, so the position iterator was advanced forward by the token's size.
				int tokenSize = std::distance(m_rng.front().value().begin(), m_rng.front().value().end());
				if(tokenSize > pos.columnNumber)
					pos.columnNumber -= tokenSize;
			}

			return pos;
		}

		//Gets the current token as a std::string.
		std::string GetTokenString() const
		{
			return std::string(m_rng.front().value().begin(), m_rng.front().value().end());
		}

		pos_iterator &m_currIt;
		Range m_rng;
		std::stack<FilePosition> m_posStack;
		ParsedResources m_resources;

		class PosStackPusher
		{
		public:
			PosStackPusher(SceneGraphParser<Range> &parser)
				: m_parser(parser)
			{
				m_parser.m_posStack.push(m_parser.GetPositionForCurrToken());
			}

			~PosStackPusher()
			{
				m_parser.m_posStack.pop();
			}

		private:
			SceneGraphParser<Range> &m_parser;
		};
	};

	template<typename Range>
	SceneGraphParser<Range> MakeParser(pos_iterator &posIt, const Range &rng)
	{
		return SceneGraphParser<Range>(posIt, rng);
	}

	glmesh::Mesh * DefaultLoader::LoadMesh( boost::string_ref basePath,
		boost::string_ref filename ) const
	{
		return NULL;
	}

	LoadedTexture DefaultLoader::LoadTexture( boost::string_ref basePath,
		boost::string_ref filename ) const
	{
		std::auto_ptr<glimg::ImageSet> pSet;
		if(boost::algorithm::iends_with(filename, ".dds"))
		{
			pSet.reset(glimg::loaders::dds::LoadFromFile(
				std::string(filename.data(), filename.size())));
		}
		else
		{
			pSet.reset(glimg::loaders::stb::LoadFromFile(
				std::string(filename.data(), filename.size())));
		}

		LoadedTexture tex;
		tex.texName = glimg::CreateTexture(pSet.get(), 0);
		tex.texType = glimg::GetTextureType(pSet.get(), 0);

		return tex;
	}

	std::string DefaultLoader::LoadShader( boost::string_ref basePath, boost::string_ref filename ) const
	{
		std::string file(filename.data(), filename.size());
		std::ifstream loadFile(file.c_str(), std::ios::in | std::ios::binary);
		return std::string((std::istreambuf_iterator<char>(loadFile)),
			std::istreambuf_iterator<char>());
	}

	SceneGraph * ParseFromMemory( boost::string_ref graphString, const BaseLoader & loader )
	{
		pos_iterator currIt((graphString.begin()), graphString.end());
		currIt.set_tabchars(4);
		simple_lexer<lexer_type> lexing;

		try
		{
			using boost::adaptors::filtered;

			token_range rng(lexing.begin(currIt, pos_iterator(), NULL), lexing.end());

			ThrowOnInvalid validity;
			SkipWhitespace skipper;
			MakeParser(currIt, rng
				| boost::adaptors::filtered(validity)
				| boost::adaptors::filtered(skipper)).ParseSceneGraph();
		}
		catch(BaseParseError &e)
		{
			std::stringstream str;
			str << e.what() << std::endl;

			if(!e.IsOutOfData())
			{
				const classic::file_position_base<std::string> &pos = currIt.get_position();

				size_t column = pos.column - e.GetSizeOfToken();

				std::string line = currIt.get_currentline();
				line = boost::algorithm::replace_all_copy(line, "\t", "    ");

				str <<
					"In file \"" << pos.file <<
					"\" line " << pos.line << " column " << column << std::endl <<
					line << std::endl;
				if(column > 1)
					str << std::setw(column - 1) << " ";
				str << "^- here" << std::endl;
			}

			throw MalformedSceneFile(str.str());
		}
	}

	SceneGraph * ParseFromFile( boost::string_ref filename, const BaseLoader & loader )
	{
		std::string file(filename.data(), filename.size());
		std::ifstream loadFile(file.c_str(), std::ios::in | std::ios::binary);
		std::string txtFile((std::istreambuf_iterator<char>(loadFile)),
			std::istreambuf_iterator<char>());

		return ParseFromMemory(txtFile, loader);
	}
}
