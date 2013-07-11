
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
#include "ParsedData.h"

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
		//Use the keyword pattern as the display name.
#define MAC(name, pattern, debug_name, display_name) {pattern, debug_name, pattern},
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

	const size_t g_validCameraTokens[] =
	{
		TOK_TARGET,
		TOK_ORIENT,
		TOK_SPIN,
		TOK_RADIUS,
		TOK_RADIUS_DELTA,
		TOK_POS_DELTA,
		TOK_ROTATION_SCALE,
	};

	const size_t g_requiredCameraTokens[] =
	{
		TOK_TARGET,
		TOK_RADIUS,
		TOK_RADIUS_DELTA,
		TOK_POS_DELTA,
		TOK_ROTATION_SCALE,
	};

	const size_t g_requiredProgramTokens[] =
	{
		TOK_VERT,
		TOK_TESS_CTRL,
		TOK_TESS_EVAL,
		TOK_GEOM,
		TOK_FRAG,
		TOK_MTC,
		TOK_NMTC,
		TOK_NCTM,
		TOK_SAMPLER,
		TOK_IMAGE,
		TOK_UNIFORM_BUFFER,
		TOK_STORAGE_BUFFER,
	};

	const size_t g_requiredMeshCreationTokens[] =
	{
		TOK_PLACEHOLDER,
		TOK_FILENAME,
		TOK_ENUMERATOR,
	};

	const size_t g_requiredTextureCreationTokens[] =
	{
		TOK_PLACEHOLDER,
		TOK_FILENAME,
	};

	const size_t g_unsignedIntStartTokens[] =
	{
		TOK_OPEN_PAREN,
		TOK_UNSIGNED_INTEGER,
	};

	const size_t g_layersTokens[] =
	{
		TOK_MINUS_SIGN,
		TOK_PLUS_SIGN,
		TOK_GRAPH_NAME,
	};

	const size_t g_nodeTransformTypesTokens[] =
	{
		TOK_NODE_TM,
		TOK_OBJECT_TM,
	};

	const size_t g_transformTokens[] =
	{
		TOK_TRANSLATE,
		TOK_SCALE,
		TOK_ORIENTATION,
		TOK_ANGLE_AXIS,
		TOK_MATRIX,
	};

	const size_t g_legalStyleTokens[] =
	{
		TOK_MESH,
		TOK_TEXTURE,
		TOK_UNIFORM_BUFFER,
		TOK_STORAGE_BUFFER,
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
			this->self.add("[a-zA-Z]+", 0x1);

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
		case KEYWORD_ID_PREFIX:				return "Command";
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
			if((tok.id() & PREFIX_MASK) == 0)
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

namespace
{
	struct throw_current_position_t{};
	throw_current_position_t curr_throw;
}

namespace glscene
{
	namespace classic = boost::spirit::classic;
	typedef classic::position_iterator2<boost::string_ref::const_iterator> pos_iterator;
	typedef pos_iterator base_iterator_type;
	typedef lex::lexertl::token<base_iterator_type> token_type;
	typedef lex::lexertl::lexer<token_type> lexer_type;

	typedef simple_lexer<lexer_type>::iterator_type token_iterator;
	typedef boost::iterator_range<token_iterator> token_range;

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
			while(HasToken(TOK_RESOURCES).get_value_or(false))
				ParseResources();
			ExpectToken(TOK_SCENE);
			ParseScene();
			if(HasAToken())
				ThrowParseError("Unexpected extra data found.", curr_throw);
		}

		void ParseResources()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_RESOURCES);

			while(!IsCurrToken(TOK_END))
			{
				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				typename Range::value_type tok = m_rng.front();
				switch(tok.id())
				{
				case TOK_UNIFORM_RES:
					ParseUniformDef();
					break;
				case TOK_SAMPLER_RES:
					ParseSamplerDef();
					break;
				case TOK_CAMERA_RES:
					ParseCameraDef();
					break;
				case TOK_UNIFORM_BUFFER_RES:
					ParseUniformBufferDef();
					break;
				case TOK_STORAGE_BUFFER_RES:
					ParseStorageBufferDef();
					break;
				case TOK_PROGRAM_RES:
					ParseProgramDef();
					break;
				case TOK_MESH_RES:
					ParseMeshDef();
					break;
				case TOK_TEXTURE_RES:
					ParseTextureDef();
					break;
				default:
					throw UnexpectedDataError(m_rng.front(), "a valid resource.", exp_message);
				}
			}

			ExpectAndEatEndToken();
		}

	private:
		void EatOneToken() {m_rng.advance_begin(1);}

		void ParseScene()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_SCENE);
			m_scene.pos = m_posStack.top();

			{
				PosStackPusher push(*this);
				ExpectAndEatToken(TOK_LAYER_DEFS);
				while(IsCurrToken(TOK_GRAPH_NAME))
				{
					std::string layerName = GetStringTokenData();
					if(m_scene.layers.find(layerName) != m_scene.layers.end())
						ThrowParseError("The layer '" + layerName + "' has already been defined.", curr_throw);
					m_scene.layers.insert(layerName);
					m_scene.layerOrder.push_back(layerName);
					EatOneToken();
				}
				if(m_scene.layers.empty())
					ThrowParseError("You must provide at least one layer name in a `layer_defs`.");
				if(!IsCurrTokenCategory(KEYWORD_ID_PREFIX))
					ThrowParseError("`layer_defs` members must be '' strings.", curr_throw);
			}

			if(IsCurrToken(TOK_STYLE_CHECK))
			{
				EatOneToken();
				while(IsCurrToken(TOK_IDENTIFIER))
				{
					std::string styleName = GetStringTokenData();
					IdString styleId = styleName;
					if(m_scene.styleChecks.find(styleId) != m_scene.styleChecks.end())
						ThrowParseError("The check style '" + styleName + "' has already been defined.", curr_throw);
					m_scene.styleChecks.insert(styleId);
					EatOneToken();
				}
				if(!IsCurrTokenCategory(KEYWORD_ID_PREFIX))
					ThrowParseError("`check_style` members must be identifier strings.", curr_throw);
			}

			if(!IsCurrToken(TOK_NODE))
				ThrowParseError("The `scene` command must have at least 1 `node` sub-command.");

			do
			{
				ParseNode(InheritedNodeData());
			} while (IsCurrToken(TOK_NODE));

			ExpectAndEatEndToken();
		}

		ParsedNodeDef *ParseNode(const InheritedNodeData &inherit)
		{
			ExpectToken(TOK_NODE);
			PosStackPusher push(*this);
			EatOneToken();

			m_scene.nodes.emplace_back();

			//Note: this is fine because `m_scene.nodes` is a stable_vector.
			size_t size = m_scene.nodes.size();
			ParsedNodeDef &node = m_scene.nodes[m_scene.nodes.size() - 1];	//stable_vector.back doesn't work.
			node.pParent = inherit.pParent;
			node.layers = inherit.layers;

			InheritedNodeData myData = inherit;
			myData.pParent = &node;

			if(IsCurrToken(TOK_IDENTIFIER))
			{
				IdString nodeId = ParseIdentifier(m_scene.nodeNamePositions, false, TOK_NODE);
				m_scene.nodeNamePositions[nodeId] = m_posStack.top();
				node.name = nodeId;
			}

			ExpectCategory(KEYWORD_ID_PREFIX);

			if(IsCurrToken(TOK_LAYERS))
			{
				ParseNodeLayers(node, myData);
			}

			ExpectCategory(KEYWORD_ID_PREFIX);

			TokenChecker hasBeenFound;
			while(IsCurrTokenOneOf(g_nodeTransformTypesTokens))
			{
				CheckMultipleCommand(hasBeenFound, m_rng.front(), TOK_NODE);
				if(IsCurrToken(TOK_NODE_TM))
					node.nodeTM = ParseTransform();
				else
					node.objectTM = ParseTransform();
			}

			ExpectCategory(KEYWORD_ID_PREFIX);

			while(IsCurrToken(TOK_LOCAL))
				ParseLocalDef(node, myData);

			ExpectCategory(KEYWORD_ID_PREFIX);

			while(IsCurrToken(TOK_STYLE))
				ParseStyleDef(node, myData);

			ExpectCategory(KEYWORD_ID_PREFIX);

			while(IsCurrToken(TOK_NODE))
				node.childNodes.push_back(ParseNode(myData));

			try
			{
				ExpectAndEatEndToken();
			}
			catch(BaseParseError &)
			{
				if(IsCurrTokenCategory(KEYWORD_ID_PREFIX))
					ThrowParseError("Incorrect command or command out of order in `node`.\n`layers` comes first, then transforms, `local`s, `style`s, and lastly `node`s.", curr_throw);
				else
					throw;
			}

			return &node;
		}

		void ParseNodeLayers(ParsedNodeDef &node, InheritedNodeData &myData)
		{
			PosStackPusher push(*this);
			EatOneToken();

			while(!IsCurrTokenCategory(KEYWORD_ID_PREFIX))
			{
				bool layerInherit = false;
				bool layerRemove = false;

				if(IsCurrToken(TOK_PLUS_SIGN))
				{
					EatOneToken();
					layerInherit = true;
				}

				if(IsCurrToken(TOK_MINUS_SIGN))
				{
					EatOneToken();
					layerRemove = true;
				}

				try
				{
					ExpectToken(TOK_GRAPH_NAME);
				}
				catch(BaseParseError &)
				{
					if(IsCurrToken(TOK_PLUS_SIGN))
						ThrowParseError("The `+` sign must always come before the `-` sign.", curr_throw);
					else
						ThrowParseError("Members of a `layers` list must be graph names, `+`, or `-`", curr_throw);
				}
				std::string layerName = GetStringTokenData();
				if(m_scene.layers.find(layerName) == m_scene.layers.end())
					ThrowParseError("The layer '" + layerName + "' was not listed in the scene graph `layer_defs`.", curr_throw);
				EatOneToken();

				if(layerRemove)
					node.layers.erase(layerName);
				else
					node.layers.insert(layerName);

				if(layerInherit)
				{
					if(layerRemove)
						myData.layers.erase(layerName);
					else
						myData.layers.insert(layerName);
				}
			}
		}

		ParsedTransformDef ParseTransform()
		{
			PosStackPusher push(*this);
			ParsedTransformDef ret;
			ret.pos = GetPositionForCurrToken();

			size_t tokId = m_rng.front().id();
			EatOneToken();

			//Start decomposed.
			ret.trans = ParsedDecomposedTransform();

			while(IsCurrTokenOneOf(g_transformTokens))
			{
				typename Range::value_type tok = m_rng.front();
				EatOneToken();
				switch(tok.id())
				{
				case TOK_TRANSLATE:
					ApplyTranslation(ret.trans, ParseVec3(tok, tokId));
					break;
				case TOK_SCALE:
					ApplyScale(ret.trans, ParseVec3(tok, tokId));
					break;
				case TOK_ORIENTATION:
					ApplyOrientation(ret.trans, ParseQuat(tok, tokId));
					break;
				case TOK_ANGLE_AXIS:
					{
						float angle = ParseSingleFloat(tok, tokId);
						glm::vec3 axis = ParseVec3(tok, tokId);
						ApplyOrientation(ret.trans, glm::angleAxis(angle, axis));
					}
					break;
				case TOK_MATRIX:
					ApplyMatrix(ret.trans, ParseMat4(tok, tokId));
					break;
				}
			}

			ExpectAndEatEndToken();

			return ret;
		}

		void ParseLocalDef(ParsedNodeDef &node, InheritedNodeData &dest)
		{
			ExpectToken(TOK_LOCAL);
			PosStackPusher push(*this);
			EatOneToken();

			IdString id = ParseIdentifier(node.localPositions, false, TOK_LOCAL);
			m_scene.allLocals.emplace_back(id);
			ParsedLocalDef &local = m_scene.allLocals[m_scene.allLocals.size() - 1];
			local.pos = m_posStack.top();
			node.localPositions[id] = local.pos;

			dest.scope.AddToScope(local);

			ParseStyleData(local.data, TOK_LOCAL);

			ExpectAndEatEndToken();
		}

		void ParseStyleDef(ParsedNodeDef &node, const InheritedNodeData &dest)
		{
			ExpectToken(TOK_STYLE);
			PosStackPusher push(*this);
			EatOneToken();

			ExpectToken(TOK_IDENTIFIER);
			IdString id(GetStringTokenData());
			if(node.styles.find(id) != node.styles.end())
				MultipleIdentifierOfSameType(GetStringTokenData(), TOK_STYLE, GetPosFromDef(*node.styles.find(id)));
			if(!m_scene.styleChecks.empty())
			{
				if(m_scene.styleChecks.find(id) == m_scene.styleChecks.end())
				{
					ThrowParseError("The style '" + GetStringTokenData() + "' was not listed in the check styles.",
						curr_throw);
				}
			}
			EatOneToken();

			ParsedStyleDef &style = node.styles[id];
			style.pos = m_posStack.top();

			if(IsCurrToken(TOK_USING))
			{
				EatOneToken();
				while(IsCurrToken(TOK_IDENTIFIER))
				{
					IdString usingId((GetStringTokenData()));
					const ParsedLocalDef *pLocal = dest.scope.IncludeLocal(usingId);
					if(!pLocal)
					{
						std::string msg = "The identifier name '" + std::string(usingId) +
							"' refers to a local definition that is not in scope at this point.";
						ThrowParseError(msg, curr_throw);
					}

					style.includes.push_back(pLocal);
					EatOneToken();
				}
				if(!IsCurrTokenCategory(KEYWORD_ID_PREFIX))
					ThrowParseError("`using` members must be identifier strings.", curr_throw);
			}

			ParseStyleData(style.data, TOK_STYLE);

			ExpectAndEatEndToken();
		}

		void ParseStyleData(ParsedStyleData &data, size_t owningId)
		{
			while(IsCurrTokenOneOf(g_legalStyleTokens))
			{
				FilePosition pos = GetPositionForCurrToken();
				typename Range::value_type tok = m_rng.front();
				switch(tok.id())
				{
				case TOK_MESH:
					{
						if(data.mesh.is_initialized())
							throw MultipleUseOfCommandError(tok, owningId);
						EatOneToken();
						data.mesh = ParsedMeshRefDef(ParseIdentifier(m_resources.meshes, true, tok.id()));
						ParsedMeshRefDef &def = data.mesh.get();
						def.pos = pos;
						if(IsCurrToken(TOK_GRAPH_NAME))
							def.variant = ParseGraphName();
					}
					break;
				case TOK_TEXTURE:
					{
						EatOneToken();
						unsigned int texUnit = ParseSingleUInt();
						IdString textureId = ParseIdentifier(m_resources.textures, true, tok.id());
						IdString samplerId = ParseIdentifier(m_resources.samplers, true, TOK_SAMPLER_RES);
						data.textures.push_back(ParsedTextureRefDef(textureId, samplerId));
						data.textures.back().pos = pos;
						data.textures.back().texUnit = texUnit;
					}
					break;
				case TOK_UNIFORM_BUFFER:
					{
						EatOneToken();
						unsigned int binding = ParseSingleUInt();
						IdString bufferId = ParseIdentifier(m_resources.uniformBuffers, true, tok.id());
						data.uniformBuffers.push_back(ParsedBufferRefDef(bufferId));
						ParsedBufferRefDef &bufferDef = data.uniformBuffers.back();
						bufferDef.pos = pos;
						bufferDef.buffBinding = binding;
						if(IsCurrTokenOneOf(g_unsignedIntStartTokens))
							bufferDef.offset = ParseSingleUInt();
					}
					break;
				case TOK_STORAGE_BUFFER:
					{
						EatOneToken();
						unsigned int binding = ParseSingleUInt();
						IdString bufferId = ParseIdentifier(m_resources.storageBuffers, true, tok.id());
						data.storageBuffers.push_back(ParsedBufferRefDef(bufferId));
						ParsedBufferRefDef &bufferDef = data.storageBuffers.back();
						bufferDef.pos = pos;
						bufferDef.buffBinding = binding;
						if(IsCurrTokenOneOf(g_unsignedIntStartTokens))
							bufferDef.offset = ParseSingleUInt();
					}
					break;
				}
			}
		}

		template<typename MapType>
		IdString ParseIdentifier(const MapType &search, bool mustFind, size_t currentCmd)
		{
			ExpectToken(TOK_IDENTIFIER);
			std::string idToken = GetTokenText();
			IdString ident(string_ref(&idToken[0] + 1, idToken.size() - 2));

			if(mustFind)
			{
				if(search.find(ident) == search.end())
					FailedToFindIdentifier(idToken, currentCmd);
			}
			else
			{
				MapType::const_iterator foundIt = search.find(ident);
				if(foundIt != search.end())
					MultipleIdentifierOfSameType(idToken, currentCmd, GetPosFromDef(*foundIt));
			}

			EatOneToken();
			return ident;
		}

		void FailedToFindIdentifier(const std::string &idToken, size_t currentCmd)
		{
			std::string msg = "The identifier name '" + idToken + "' refers to a " +
				GetTokenErrorName(currentCmd) + " that has not been defined.";
			ThrowParseError(msg, curr_throw);
		}

		void MultipleIdentifierOfSameType(const std::string &idToken, size_t currentCmd,
			const FilePosition &earlyDefPos)
		{
			std::stringstream str;
			str << "The identifier name '" << idToken << "' has already been used in a ";
			str << GetTokenErrorName(currentCmd) << " definition before. It may not be defined again." << std::endl;
			str << "\tIt was first defined in file '" << earlyDefPos.fileName << "' line ";
			str << earlyDefPos.lineNumber << " column " << earlyDefPos.columnNumber << std::endl;
			str << "\t" << earlyDefPos.theLine << std::endl;
			str << "\t";
			if(earlyDefPos.columnNumber > 1)
				str << std::setw(earlyDefPos.columnNumber - 1) << " ";
			str << "^- here" << std::endl;

			ThrowParseError(str.str(), curr_throw);
		}

		//Expects the top of the stack to be the position of the containing command.
		void ThrowIfNotFound(const TokenChecker &hasBeenFound,
			array_ref<size_t> expectedIds, const size_t mainId) const
		{
			BOOST_FOREACH(size_t id, expectedIds)
			{
				if(hasBeenFound.find(id) == hasBeenFound.end())
				{
					std::stringstream str;
					str << "The command '" << GetTokenErrorName(mainId) << "' must have a ";
					str << GetTokenErrorName(id) << " command within it." << std::endl;
					ThrowParseError(str.str());
				}
			}
		}

		void ParseSamplerDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_SAMPLER_RES);
			IdString ident = ParseIdentifier(m_resources.samplers, false, TOK_SAMPLER_RES);
			ParsedSamplerDef &samplerData = m_resources.samplers[ident];
			samplerData.pos = m_posStack.top();

			TokenChecker hasBeenFound;

			while(!m_rng.empty() && m_rng.front().id() != TOK_END)
			{
				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				if(!HasTokenOneOfNoEmpty(g_validSamplerTokens))
					throw UnexpectedDataError(m_rng.front(), "a valid sampler command.", exp_message);

				typename Range::value_type tok = m_rng.front();
				CheckMultipleCommand(hasBeenFound, tok, TOK_SAMPLER_RES);
				EatOneToken();

				switch(tok.id())
				{
				case TOK_MAG:
					samplerData.sampler.magFilter = ParseEnumerator(g_magFilterEnumeration);
					break;
				case TOK_MIN:
					samplerData.sampler.minFilter = ParseEnumerator(g_minFilterEnumeration);
					break;
				case TOK_COMPARE:
					samplerData.sampler.compareFunc = ParseEnumerator(g_compareModeEnumeration);
					break;
				case TOK_WRAP_S:
					samplerData.sampler.edgeFilterS = ParseEnumerator(g_wrapModeEnumeration);
					break;
				case TOK_WRAP_T:
					samplerData.sampler.edgeFilterT = ParseEnumerator(g_wrapModeEnumeration);
					break;
				case TOK_WRAP_R:
					samplerData.sampler.edgeFilterR = ParseEnumerator(g_wrapModeEnumeration);
					break;
				case TOK_ANISO:
					{
						ExpectCategory(NUMBER_ID_PREFIX);
						samplerData.sampler.maxAniso = boost::lexical_cast<float>(GetTokenText());
						if(samplerData.sampler.maxAniso < 1.0f)
						{
							std::string msg = "The maximum anisotropic filtering value must be 1.0 or greater.";
							ThrowParseError(msg, curr_throw);
						}
						EatOneToken();
					}
					break;
				}
			}

			ExpectAndEatEndToken();
		}

		void ParseCameraDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_CAMERA_RES);
			IdString ident = ParseIdentifier(m_resources.cameras, false, TOK_CAMERA_RES);
			ParsedCameraDef &cameraData = m_resources.cameras[ident];
			cameraData.pos = m_posStack.top();
			
			cameraData.actionButton = ParseEnumerator(g_cameraMouseButtonEnumeration);
			cameraData.bRightKeyboardCtrls = ParseEnumerator(g_cameraKeyboardSideEnumeration);
			cameraData.view.degSpinRotation = 0.0f;

			TokenChecker hasBeenFound;

			while(!m_rng.empty() && m_rng.front().id() != TOK_END)
			{
				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				if(!HasTokenOneOfNoEmpty(g_validCameraTokens))
					throw UnexpectedDataError(m_rng.front(), "a valid camera command.", exp_message);

				PosStackPusher push(*this);
				const typename Range::value_type tok = m_rng.front();
				CheckMultipleCommand(hasBeenFound, tok, TOK_CAMERA_RES);
				EatOneToken();

//				FilePosition pos = GetPositionForCurrToken();
				switch(tok.id())
				{
				case TOK_TARGET:
					cameraData.view.targetPos = ParseVec3(tok, TOK_CAMERA_RES);
					break;
				case TOK_ORIENT:
					cameraData.view.orient = ParseQuat(tok, TOK_CAMERA_RES);
					break;
				case TOK_SPIN:
					cameraData.view.degSpinRotation = ParseSingleFloat(tok, TOK_CAMERA_RES);
					if(cameraData.view.degSpinRotation < 0.0f)
						ThrowParseError("Spin angle must be greater than 0.");
					break;
				case TOK_RADIUS:
					{
						float initRadius = ParseSingleFloat(tok, TOK_CAMERA_RES);
						float minRadius = ParseSingleFloat(tok, TOK_CAMERA_RES);
						float maxRadius = ParseSingleFloat(tok, TOK_CAMERA_RES);

						if(minRadius < 0.0f)
							ThrowParseError("The minimum radius must be larger than 0.");

						if(maxRadius < 0.0f)
							ThrowParseError("The maximum radius must be larger than 0.");

						if(minRadius >= maxRadius)
							ThrowParseError("The minimum radius must be less than the maximum radius.");

						if(initRadius < minRadius)
							ThrowParseError("The initial radius must be larger than the minimum.");

						if(initRadius > maxRadius)
							ThrowParseError("The initial radius must be smaller than the maximum.");

						cameraData.view.radius = initRadius;
						cameraData.scale.minRadius = minRadius;
						cameraData.scale.maxRadius = maxRadius;
					}
					break;
				case TOK_RADIUS_DELTA:
					{
						float smallRadius = ParseSingleFloat(tok, TOK_CAMERA_RES);
						float largeRadius = ParseSingleFloat(tok, TOK_CAMERA_RES);

						if(smallRadius < 0.0f)
							ThrowParseError("The small radius delta must be larger than 0.");

						if(largeRadius < 0.0f)
							ThrowParseError("The large radius delta must be larger than 0.");

						if(smallRadius >= largeRadius)
							ThrowParseError("The minimum radius delta must be less than the maximum.");

						cameraData.scale.smallRadiusDelta = smallRadius;
						cameraData.scale.largeRadiusDelta = largeRadius;
					}
					break;
				case TOK_POS_DELTA:
					{
						float smallDelta = ParseSingleFloat(tok, TOK_CAMERA_RES);
						float largeDelta = ParseSingleFloat(tok, TOK_CAMERA_RES);

						if(smallDelta < 0.0f)
							ThrowParseError("The small position delta must be larger than 0.");

						if(largeDelta < 0.0f)
							ThrowParseError("The large position delta must be larger than 0.");

						if(smallDelta >= largeDelta)
							ThrowParseError("The minimum position delta must be less than the maximum.");

						cameraData.scale.smallPosOffset = smallDelta;
						cameraData.scale.largePosOffset = largeDelta;
					}
					break;
				case TOK_ROTATION_SCALE:
					{
						float rotScale = ParseSingleFloat(tok, TOK_CAMERA_RES);

						if(rotScale < 0.0f)
							ThrowParseError("The rotation scale must be larger than 0.");

						cameraData.scale.rotationScale = rotScale;
					}
					break;
				}
			}

			ThrowIfNotFound(hasBeenFound, g_requiredCameraTokens, TOK_CAMERA_RES);
			ExpectAndEatEndToken();
		}

		void ParseUniformBufferDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_UNIFORM_BUFFER_RES);
			IdString ident = ParseIdentifier(m_resources.uniformBuffers, false, TOK_UNIFORM_BUFFER_RES);
			ParsedBufferDef &bufferDef = m_resources.uniformBuffers[ident];
			bufferDef.pos = m_posStack.top();

			ParseBufferDef(bufferDef, TOK_UNIFORM_BUFFER_RES);
		}

		void ParseStorageBufferDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_STORAGE_BUFFER_RES);
			IdString ident = ParseIdentifier(m_resources.storageBuffers, false, TOK_STORAGE_BUFFER_RES);
			ParsedBufferDef &bufferDef = m_resources.storageBuffers[ident];
			bufferDef.pos = m_posStack.top();

			ParseBufferDef(bufferDef, TOK_STORAGE_BUFFER_RES);
		}

		void ParseBufferDef(ParsedBufferDef &bufferDef, size_t owningId)
		{
			bufferDef.size = ParseSingleUInt();
			boost::optional<bool> test = HasToken(TOK_PLACEHOLDER);
			if(!test)
			{
				ThrowParseError("Ran out of data instead of finding a buffer `placeholder` or enumeration.");
			}
			else if(test.get())
			{
				EatOneToken();
			}
			else
			{
				bufferDef.creationUsage = ParseEnumerator(g_bufferUsageEnumeration);
			}
		}

		void ParseMeshDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_MESH_RES);
			IdString ident = ParseIdentifier(m_resources.meshes, false, TOK_MESH_RES);
			ParsedMeshDef &meshDef = m_resources.meshes[ident];
			meshDef.pos = m_posStack.top();

			ExpectAToken();
			if(!HasTokenOneOfNoEmpty(g_requiredMeshCreationTokens))
				throw UnexpectedDataError(m_rng.front(), "a valid mesh creation parameter.", exp_message);

			switch(m_rng.front().id())
			{
			case TOK_PLACEHOLDER:
				meshDef.generator = boost::blank();
				EatOneToken();
				break;
			case TOK_FILENAME:
				meshDef.generator = ParseFilename();
				break;
			case TOK_ENUMERATOR:
				{
					int generatorIx = ParseEnumerator(g_meshCreateEnumeration);
					meshDef.generator = generatorIx;
					const int numParams = g_meshCreateNumParameters[generatorIx];
					for(int param = 0; param < numParams; ++param)
					{
						try
						{
							meshDef.params.push_back(ParseSingleUInt());
						}
						catch(BaseParseError &)
						{
							std::stringstream str;
							str << "The mesh generator '" << g_meshCreateEnumeration.enumerators[generatorIx] <<
								"' requires " << numParams << " parameters.";
							ThrowParseError(str.str());
						}
					}

					if(HasAToken() && HasTokenOneOfNoEmpty(g_unsignedIntStartTokens))
					{
						std::stringstream str;
						str << "The mesh generator '" << g_meshCreateEnumeration.enumerators[generatorIx] <<
							"' only takes " << numParams << " parameters.";
						ThrowParseError(str.str(), curr_throw);
					}
				}
				break;
			}
		}

		void ParseTextureDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_TEXTURE_RES);
			IdString ident = ParseIdentifier(m_resources.textures, false, TOK_TEXTURE_RES);
			ParsedTextureDef &textureDef = m_resources.textures[ident];
			textureDef.pos = m_posStack.top();

			ExpectAToken();
			if(!HasTokenOneOfNoEmpty(g_requiredTextureCreationTokens))
				throw UnexpectedDataError(m_rng.front(), "a valid texture creation parameter.", exp_message);

			switch(m_rng.front().id())
			{
			case TOK_PLACEHOLDER:
				textureDef.filename = boost::none;
				EatOneToken();
				break;
			case TOK_FILENAME:
				textureDef.filename = ParseFilename();
				break;
			}
		}

		void ParseProgramDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_PROGRAM_RES);
			IdString ident = ParseIdentifier(m_resources.programs, false, TOK_PROGRAM_RES);
			ParsedProgramDef &programDef = m_resources.programs[ident];
			programDef.pos = m_posStack.top();
			programDef.isSeparate = false;

			TokenChecker hasBeenFound;

			ExpectAToken();
			if(HasTokenNoEmpty(TOK_ENUMERATOR))
			{
				std::string testEnum = GetEnumFromToken(m_rng.front());
				if(testEnum != "separate")
				{
					ThrowParseError("Program resources can only use the 'separate' enumerator.", curr_throw);
				}
				EatOneToken();
				programDef.isSeparate = true;
			}

			while(!m_rng.empty() && m_rng.front().id() != TOK_END)
			{
				ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
				if(!HasTokenOneOfNoEmpty(g_requiredProgramTokens))
					throw UnexpectedDataError(m_rng.front(), "a valid program command.", exp_message);

				typename Range::value_type tok = m_rng.front();
				FilePosition pos = GetPositionForCurrToken();
				EatOneToken();

				switch(tok.id())
				{
				case TOK_VERT:
					programDef.shaders.push_back(ParseShader(gl::VERTEX_SHADER, pos));
					break;
				case TOK_TESS_CTRL:
					programDef.shaders.push_back(ParseShader(gl::TESS_CONTROL_SHADER, pos));
					break;
				case TOK_TESS_EVAL:
					programDef.shaders.push_back(ParseShader(gl::TESS_EVALUATION_SHADER, pos));
					break;
				case TOK_GEOM:
					programDef.shaders.push_back(ParseShader(gl::GEOMETRY_SHADER, pos));
					break;
				case TOK_FRAG:
					programDef.shaders.push_back(ParseShader(gl::FRAGMENT_SHADER, pos));
					break;
				case TOK_MTC:
					CheckMultipleCommand(hasBeenFound, tok, TOK_PROGRAM_RES);
					programDef.info.modelToCameraMatrixUniformName = ParseGlslIdentifier(tok);
					break;
				case TOK_NMTC:
					CheckMultipleCommand(hasBeenFound, tok, TOK_PROGRAM_RES);
					programDef.info.normalModelToCameraMatrixUniformName = ParseGlslIdentifier(tok);
					break;
				case TOK_NCTM:
					CheckMultipleCommand(hasBeenFound, tok, TOK_PROGRAM_RES);
					programDef.info.normalCameraToModelMatrixUniformName = ParseGlslIdentifier(tok);
					break;
				case TOK_SAMPLER:
					{
						std::string name = ParseGlslIdentifier(tok);
						programDef.info.samplerBindings.emplace(name, ParseSingleUInt());
					}
					break;
				case TOK_IMAGE:
					{
						std::string name = ParseGlslIdentifier(tok);
						programDef.info.imageBindings.emplace(name, ParseSingleUInt());
					}
					break;
				case TOK_UNIFORM_BUFFER:
					{
						std::string name = ParseGlslIdentifier(tok);
						programDef.info.uniformBlockBindings.emplace(name, ParseSingleUInt());
					}
					break;
				case TOK_STORAGE_BUFFER:
					{
						std::string name = ParseGlslIdentifier(tok);
						programDef.info.bufferVariableBindings.emplace(name, ParseSingleUInt());
					}
					break;
				}
			}

			ExpectAndEatEndToken();

			if(programDef.shaders.empty())
			{
				ThrowParseError("You must provide at least one shader file in a program resource.");
			}
		}

		ParsedShader ParseShader(GLenum shaderType, FilePosition pos)
		{
			ParsedShader ret;
			ret.filename = ParseFilename();
			ret.shaderType = shaderType;
			ret.pos = pos;
			return ret;
		}

		void ParseUniformDef()
		{
			PosStackPusher push(*this);

			ExpectAndEatToken(TOK_UNIFORM_RES);
			IdString ident = ParseIdentifier(m_resources.uniforms, false, TOK_UNIFORM_RES);
			ParsedUniformDef &uniformDef = m_resources.uniforms[ident];
			uniformDef.pos = m_posStack.top();

			uniformDef.glslUniformName = ParseGlslIdentifier();
			int uniformType = ParseEnumerator(g_uniformTypeEnumeration);
			uniformDef.data = ParseUniformData(uniformType);
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

					std::string theInt(GetTokenText());
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

					std::string theFloat(GetTokenText());

					EatOneToken();
					float val = boost::lexical_cast<float>(theFloat);
					return ConstructFromSingleValue(val, typeIx);
				}
			}
			else if(HasTokenNoEmpty(TOK_OPEN_PAREN))
			{
				std::vector<ParsedValue> vals = ParseUniformNumberList(typeIx);
				if(vals.size() == 1)
					return boost::apply_visitor(UniformFromSingleValue(typeIx), vals[0]);

				return BuildUniformData(vals, typeIx);
			}
			else
				//Not a number, so let the next statement handle it.
				return CreateDefaultUniform(typeIx);
		}

		std::vector<ParsedValue> ParseUniformNumberList(int typeIx)
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

					std::string theInt(GetTokenText());

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

					std::string theFloat(GetTokenText());

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
		Mapped ParseEnumerator(const EnumData<Mapped> &data)
		{
			ExpectToken(TOK_ENUMERATOR);
			size_t enumIx = GetEnumeratorIndex(data);
			EatOneToken();

			return data.mapping[enumIx];
		}

		size_t ParseEnumerator(const EnumData<void> &data)
		{
			ExpectToken(TOK_ENUMERATOR);
			size_t enumIx = GetEnumeratorIndex(data);
			EatOneToken();

			return enumIx;
		}

		template<typename Mapped>
		size_t GetEnumeratorIndex(const EnumData<Mapped> &data)
		{
			std::string testEnum = GetEnumFromToken(m_rng.front());

			const boost::string_ref *foundEnum = boost::find(data.enumerators, boost::string_ref(testEnum));
			size_t enumIx = foundEnum - data.enumerators.data();
			if(enumIx >= data.enumerators.size())
				throw IncorrectEnumError(m_rng.front(), data);

			return enumIx;
		}

		std::string GetEnumFromToken(const Token &tok)
		{
			std::string enumerator(tok.value().begin(), tok.value().end());
			return std::string(enumerator.begin() + 1, enumerator.end() - 1);
		}

		std::string ParseFilename()
		{
			ExpectToken(TOK_FILENAME);
			std::string rawToken = GetTokenText();
			EatOneToken();

			return std::string(rawToken.begin() + 1, rawToken.end() - 1);
		}

		std::string ParseGlslIdentifier(const Token &owningTok)
		{
			return ParseGlslIdentifier();
		}

		std::string ParseGlslIdentifier()
		{
			ExpectToken(TOK_GLSL_IDENT);
			std::string rawToken = GetTokenText();
			EatOneToken();

			return std::string(rawToken.begin() + 1, rawToken.end() - 1);
		}

		std::string ParseGraphName()
		{
			ExpectToken(TOK_GRAPH_NAME);
			std::string rawToken = GetTokenText();
			EatOneToken();

			return std::string(rawToken.begin() + 1, rawToken.end() - 1);
		}

		glm::mat4 ParseMat4(const Token &owningTok, size_t owningId)
		{
			ExpectAndEatToken(TOK_OPEN_PAREN);

			int count = 0;
			glm::mat4 ret;

			for(;
				!m_rng.empty() && !HasTokenNoEmpty(TOK_CLOSE_PAREN);
				EatOneToken(), ++count)
			{
				ExpectCategory(NUMBER_ID_PREFIX);
				if(3 == count)
				{
					std::string msg = "The '" + GetTokenErrorName(owningTok.id()) +
						"' mat4 only takes 16 numbers.";
					ThrowParseError(msg, curr_throw);
				}

				ret[count / 4][count % 4] = boost::lexical_cast<float>(GetTokenText());
			}

			ExpectToken(TOK_CLOSE_PAREN);

			if(3 != count && 1 != count)
			{
				std::string msg = "The '" + GetTokenErrorName(owningTok.id()) +
					"' mat4 requires 16 numbers.";
				ThrowParseError(msg, curr_throw);
			}

			if(1 == count)
				ret = glm::mat4(ret[0][0]);

			ExpectAndEatToken(TOK_CLOSE_PAREN);
			return ret;
		}

		glm::vec3 ParseVec3(const Token &owningTok, size_t owningId)
		{
			ExpectAndEatToken(TOK_OPEN_PAREN);

			int count = 0;
			glm::vec3 ret;

			for(;
				!m_rng.empty() && !HasTokenNoEmpty(TOK_CLOSE_PAREN);
				EatOneToken(), ++count)
			{
				ExpectCategory(NUMBER_ID_PREFIX);
				if(3 == count)
				{
					std::string msg = "The '" + GetTokenErrorName(owningTok.id()) + "' vec3 only takes 3 numbers.";
					ThrowParseError(msg, curr_throw);
				}

				ret[count] = boost::lexical_cast<float>(GetTokenText());
			}

			ExpectToken(TOK_CLOSE_PAREN);

			if(3 != count && 1 != count)
			{
				std::string msg = "The '" + GetTokenErrorName(owningTok.id()) + "' vec3 requires 3 numbers.";
				ThrowParseError(msg, curr_throw);
			}

			if(1 == count)
				ret = glm::vec3(ret.x);

			ExpectAndEatToken(TOK_CLOSE_PAREN);
			return ret;
		}

		glm::quat ParseQuat(const Token &owningTok, size_t owningId)
		{
			ExpectAndEatToken(TOK_OPEN_PAREN);

			int count = 0;
			glm::vec4 inputQuat;

			for(;
				!m_rng.empty() && !HasTokenNoEmpty(TOK_CLOSE_PAREN);
				EatOneToken(), ++count)
			{
				ExpectCategory(NUMBER_ID_PREFIX);
				if(4 == count)
				{
					std::string msg = "The '" + GetTokenErrorName(owningTok.id()) + "' quaternion takes 4 numbers.";
					ThrowParseError(msg, curr_throw);
				}

				inputQuat[count] = boost::lexical_cast<float>(GetTokenText());
			}

			ExpectToken(TOK_CLOSE_PAREN);

			if(4 != count)
			{
				std::string msg = "The '" + GetTokenErrorName(owningTok.id()) + "' quaternion requires 4 numbers.";
				ThrowParseError(msg, curr_throw);
			}

			ExpectAndEatToken(TOK_CLOSE_PAREN);
			return glm::normalize(glm::quat(inputQuat.w, inputQuat.x, inputQuat.y, inputQuat.z));
		}

		float ParseSingleFloat(const Token &owningTok, size_t owningId)
		{
			bool paren = false;
			ExpectAToken();
			if(HasToken(m_rng.front(), TOK_OPEN_PAREN))
			{
				paren = true;
				EatOneToken();
			}

			ExpectCategory(NUMBER_ID_PREFIX);
			float ret = boost::lexical_cast<float>(GetTokenText());
			EatOneToken();

			if(paren)
				ExpectAndEatToken(TOK_CLOSE_PAREN);

			return ret;
		}

		unsigned int ParseSingleUInt()
		{
			bool paren = false;
			ExpectAToken();
			if(HasToken(m_rng.front(), TOK_OPEN_PAREN))
			{
				paren = true;
				EatOneToken();
			}

			ExpectToken(TOK_UNSIGNED_INTEGER);
			unsigned int ret = boost::lexical_cast<unsigned int>(GetTokenText());
			EatOneToken();

			if(paren)
				ExpectAndEatToken(TOK_CLOSE_PAREN);

			return ret;
		}

		//Returns true if the current token has the identifier. Returns false if not. *Throws* if no current token.
		bool IsCurrToken(size_t idExpected)
		{
			if(m_rng.empty())
				throw UnexpectedDataError(idExpected);
			else
				return HasTokenNoEmpty(idExpected);
		}

		bool IsCurrTokenOneOf(array_ref<size_t> expecteds)
		{
			if(m_rng.empty())
				throw UnexpectedDataError(expecteds[0]);

			const Token &tok = m_rng.front();
			BOOST_FOREACH(size_t idExpected, expecteds)
			{
				if(HasToken(tok, idExpected))
					return true;
			}

			return false;
		}

		bool IsCurrTokenCategory(size_t prefix)
		{
			if(m_rng.empty())
				throw UnexpectedDataError(prefix, exp_cat);
			else
				return HasCategoryNoEmpty(prefix);
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

		void ExpectAndEatEndToken()
		{
			ExpectEndToken();
			EatOneToken();
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

		//Provides a special error message.
		void ExpectEndToken() const
		{
			if(m_rng.empty())
				ThrowParseError("This compound command needs an 'end' token.");
			else
			{
				if(m_rng.front().id() != TOK_END)
					ThrowParseError("This compound command needs an 'end' token.");
			}
		}

		//Throws if empty.
		void ExpectAToken() const
		{
			if(m_rng.empty())
				throw BaseParseError("Unexpected end of data.", 0, true);
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

		bool HasAToken() const
		{
			if(m_rng.empty())
				return false;
			return true;
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
				//Will not become negative. That shouldn't be possible, since non-space tokens can't straddle lines.
				if(tokenSize < pos.columnNumber)
					pos.columnNumber -= tokenSize;
			}

			return pos;
		}

		//Gets the current token as a std::string.
		std::string GetTokenText() const
		{
			return std::string(m_rng.front().value().begin(), m_rng.front().value().end());
		}

		//Assuming the current token is a string token, constructs a std::string from the contents.
		std::string GetStringTokenData() const
		{
			std::string rawToken = GetTokenText();
			return std::string(++rawToken.begin(), --rawToken.end());
		}

		void ThrowParseError(const std::string &msg) const
		{
			throw BaseParseError(msg, m_posStack.top());
		}

		void ThrowParseError(const std::string &msg, throw_current_position_t) const
		{
			throw BaseParseError(msg, GetPositionForCurrToken());
		}

		pos_iterator &m_currIt;
		Range m_rng;
		std::stack<FilePosition> m_posStack;
		ParsedResources m_resources;
		ParsedSceneGraphDef m_scene;

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

			return NULL;
		}
		catch(BaseParseError &e)
		{
			std::stringstream str;
			str << e.what() << std::endl;

			if(!e.IsOutOfData())
			{
				FilePosition pos;
				if(e.HasPosition())
					pos = e.GetPosition();
				else
				{
					const classic::file_position_base<std::string> &currPos = currIt.get_position();
					pos.columnNumber = currPos.column;
					pos.lineNumber = currPos.line;
					pos.fileName = currPos.file;
					pos.theLine = currIt.get_currentline();
				}

				size_t column = pos.columnNumber - e.GetSizeOfToken();

				std::string line = pos.theLine;
				line = boost::algorithm::replace_all_copy(line, "\t", "    ");

				str <<
					"In file \"" << pos.fileName <<
					"\" line " << pos.lineNumber << " column " << column << std::endl <<
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
