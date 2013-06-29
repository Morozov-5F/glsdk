
#include "pch.h"

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

template<typename T>
class array_ref
{
public:
	typedef T value_type;
	typedef const T * pointer;
	typedef const T & reference;
	typedef const T & const_reference;
	typedef const T * const_iterator;
	typedef const_iterator iterator;
	typedef std::reverse_iterator< const_iterator > const_reverse_iterator;
	typedef const_reverse_iterator reverse_iterator;
	typedef size_t size_type;
	typedef ptrdiff_t difference_type;

	// construct/copy
	array_ref() : m_data(NULL), m_size(0) {}

	array_ref(const T *arr, size_t length) : m_data(arr), m_size(length) {}
	array_ref(const std::vector<T> & v) : m_data(&v[0]), m_size(v.size()) {}
	template<size_t N>
	array_ref(const T(&a)[N]) : m_data(a), m_size(N) {}
	template<size_t N>
	array_ref(const boost::array< T, N > & a) : m_data(a.data()), m_size(N) {}

	const_iterator begin() const {return m_data;}
	const_iterator end() const {return m_data + m_size;}
	const_iterator cbegin() const {return m_data;}
	const_iterator cend() const {return m_data + m_size;}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
	const_reverse_iterator rend() const {return const_reverse_iterator(begin());}
	const_reverse_iterator crbegin() const  {return const_reverse_iterator(cend());}
	const_reverse_iterator crend() const {return const_reverse_iterator(cbegin());}

	size_type size() const {return m_size;}
	size_type max_size() const {return std::numeric_limits<size_type>::max();}
	bool empty() const {return m_size == 0;}

	const T & operator[](size_t i) const {return m_data[i];}
	const T & at(size_t i) const
	{
		if(i >= m_size)
			throw std::out_of_range();
		return m_data[i];
	}
	const T & front() const {return m_data[0];}
	const T & back() const {return m_data[m_size - 1];}
	const T * data() const {return m_data;}

	std::vector<T> vec() const {return std::vector<T>(m_data, m_data + m_size);}
	std::basic_string<T> str() const {return std::basic_string<T>(m_data, m_data + m_size);}

	void clear() {m_size = 0; m_data = NULL;}
	void remove_prefix(size_type n)
	{
		m_data += n;
		m_size -= n;
		if(m_size <= 0)
			clear();
	}

	void remove_suffix(size_type n)
	{
		m_size -= n;
		if(m_size <= 0)
			clear();
	}

	void pop_front() {remove_prefix(1);}
	void pop_back() {remove_suffix(1);}
private:
	const T *m_data;
	size_t m_size;
};


typedef boost::variant<float, glm::vec2, glm::vec3, glm::vec4> VectorTypes;
typedef boost::variant<int, glm::ivec2, glm::ivec3, glm::ivec4> IntVectorTypes;
typedef boost::variant<unsigned int, glm::uvec2, glm::uvec3, glm::uvec4> UIntVectorTypes;
typedef boost::variant<glm::mat2, glm::mat3, glm::mat4> MatrixTypes;
typedef boost::variant<VectorTypes, IntVectorTypes, UIntVectorTypes, MatrixTypes> UniformData;

boost::string_ref g_uniformTypeList[] =
{
	"uint",
	"uvec2",
	"uvec3",
	"uvec4",
	"int",
	"ivec2",
	"ivec3",
	"ivec4",
	"float",
	"vec2",
	"vec3",
	"vec4",
	"mat2",
	"mat3",
	"mat4",
};

const int NUM_UNSIGNED_INDICES = 4;
const int NUM_INTEGER_INDICES = 8;

bool IsUnifTypeUnsigned(int typeIx) {return typeIx < NUM_UNSIGNED_INDICES;}
bool IsUnifTypeInteger(int typeIx) {return typeIx < NUM_INTEGER_INDICES;}

namespace lex = boost::spirit::lex;
namespace qi = boost::spirit::qi;

#define PREFIX_MASK 0xFFFFF000
#define KEYWORD_ID_PREFIX 0x1000
#define WHITESPACE_ID_PREFIX 0x2000
#define STRING_ID_PREFIX 0x3000
#define NUMBER_ID_PREFIX 0x4000
#define SYMBOL_ID_PREFIX 0x5000

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

template <typename Token>
std::string GetTokenCatName(const Token &t)
{
	return GetTokenCatName(t.id());
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

template <typename Token>
std::string GetTokenName(const Token &t)
{
	return GetTokenName(t.id());
}

template <typename Token>
std::string GetTokenErrorName(const Token &t)
{
	return GetTokenErrorName(t.id());
}

struct PrintToks
{
	// the function operator gets called for each of the matched tokens
	// c, l, w are references to the counters used to keep track of the numbers
	template <typename Token>
	bool operator()(Token const& t) const
	{
		std::cout << GetTokenCatName(t) << ": " << GetTokenName(t) << std::endl;

//		const classic::file_position_base<std::string> &pos = t.value().begin().get_position();
//		std::cout << pos.column << std::endl;
//		std::cout << typeid(t).name() << std::endl;

		return true;
	}
};

namespace classic = boost::spirit::classic;
//typedef std::string::const_iterator pos_iterator;
typedef classic::position_iterator2<std::string::const_iterator> pos_iterator;
//typedef boost::spirit::line_pos_iterator<std::string::const_iterator> pos_iterator;
//typedef std::string::const_iterator pos_iterator;


typedef pos_iterator base_iterator_type;
typedef lex::lexertl::token<base_iterator_type> token_type;
typedef lex::lexertl::lexer<token_type> lexer_type;

typedef simple_lexer<lexer_type>::iterator_type token_iterator;
typedef boost::iterator_range<token_iterator> token_range;


class BaseParseError : public std::runtime_error
{
public:
	explicit BaseParseError(const std::string &desc)
		: std::runtime_error(desc)
		, tokenSize()
		, outOfData(false)
	{}

	BaseParseError(const std::string &desc, ptrdiff_t _size)
		: std::runtime_error(desc)
		, tokenSize(_size)
		, outOfData(false)
	{}

	BaseParseError(const std::string &desc, ptrdiff_t _size, bool _outOfData)
		: std::runtime_error(desc)
		, tokenSize(_size)
		, outOfData(_outOfData)
	{}

	ptrdiff_t GetSizeOfToken() const {return tokenSize;}
	bool IsOutOfData() const {return outOfData;}

private:
	ptrdiff_t tokenSize;
	bool outOfData;
};

class BadTokenError : public BaseParseError
{
public:
	BadTokenError()
		: BaseParseError("Malformed data!")
	{}
};

class expect_category_t {};
expect_category_t exp_cat;
class expect_message_t {};
expect_message_t exp_message;

class UnexpectedDataError : public BaseParseError
{
public:
	//The message should be fit the sentence, "Got XXX instead of <message>".
	//Punctuation not included.
	template<typename Token>
	UnexpectedDataError(const Token &t, const std::string &message, expect_message_t)
		: BaseParseError(GetErrorMismatch(t, message),
			std::distance(t.value().begin(), t.value().end()))
	{}

	template<typename Token>
	UnexpectedDataError(size_t idExpected, const Token &t)
		: BaseParseError(GetErrorExact(idExpected, t),
			std::distance(t.value().begin(), t.value().end()))
	{}

	template<typename Token>
	UnexpectedDataError(size_t prefix, const Token &t, expect_category_t)
		: BaseParseError(GetErrorCategory(prefix, t),
			std::distance(t.value().begin(), t.value().end()))
	{}

	//Thrown when out of data.
	UnexpectedDataError(size_t idExpected)
		: BaseParseError(GetErrorExact(idExpected), 0, true) {}

	//Thrown when out of data.
	UnexpectedDataError(size_t prefix, expect_category_t)
		: BaseParseError(GetErrorCategory(prefix), 0, true) {}

private:

	template<typename Token>
	static std::string GetErrorMismatch(const Token &t, const std::string &message)
	{
		return "Got '" +
			std::string(t.value().begin(), t.value().end()) + "' instead of " + message;
	}

	template<typename Token>
	static std::string GetErrorExact(size_t idExpected, const Token &t)
	{
		return GetExpected(idExpected) + "Got '" +
			std::string(t.value().begin(), t.value().end()) + "' instead.";
	}

	template<typename Token>
	static std::string GetErrorCategory(size_t prefix, const Token &t)
	{
		return GetPrefixExpected(prefix) + "Got '" +
			std::string(t.value().begin(), t.value().end()) + "' instead.";
	}

	static std::string GetErrorExact(size_t idExpected)
	{
		return GetExpected(idExpected) + "Ran out of data instead.";
	}

	static std::string GetErrorCategory(size_t prefix)
	{
		return GetPrefixExpected(prefix) + "Ran out of data instead.";
	}

	///String should end in punctuation followed by a space.
	static std::string GetExpected(size_t idExpected)
	{
		switch(GetPrefixFromId(idExpected))
		{
		case KEYWORD_ID_PREFIX:
			return std::string("Expected to find the keyword '") + GetTokenErrorName(idExpected) + "'. ";
		case STRING_ID_PREFIX:
			return std::string("Expected to find a ") + GetTokenErrorName(idExpected) + " style string. ";
		case NUMBER_ID_PREFIX:
			return std::string("Expected to find ") + GetTokenErrorName(idExpected) + " number. ";
		case SYMBOL_ID_PREFIX:
			return std::string("Expected to find the symbol '") + GetTokenErrorName(idExpected) + "' ";
		default:
			return "...? ";
		}
	}

	static std::string GetPrefixExpected(size_t prefix)
	{
		return "Expected to get a " + GetTokenCatName(prefix) + ". ";
	}
};

std::string ExtractEnum(const token_type &tok)
{
	std::string enumerator(tok.value().begin(), tok.value().end());
	return std::string(enumerator.begin() + 1, enumerator.end() - 1);
}

class uniform_unsigned_mismatch_t {};
class uniform_scalar_mismatch_t {};
class uniform_float_mismatch_t {};
class uniform_size_mismatch_t {};
uniform_unsigned_mismatch_t unf_type_unsigned;
uniform_scalar_mismatch_t unif_type_scalar;
uniform_float_mismatch_t unf_type_float;
uniform_size_mismatch_t unf_type_size;

class UniformTypeMismatchError : public BaseParseError
{
public:
	template<typename Token>
	UniformTypeMismatchError(const Token &t, const boost::string_ref &typeName, uniform_unsigned_mismatch_t)
		: BaseParseError(GetUnsignedError(t, std::string(typeName.begin(), typeName.end())),
		std::distance(t.value().begin(), t.value().end()))
	{}

	template<typename Token>
	UniformTypeMismatchError(const Token &t, const boost::string_ref &typeName, uniform_scalar_mismatch_t)
		: BaseParseError(GetScalarError(t, std::string(typeName.begin(), typeName.end())),
		std::distance(t.value().begin(), t.value().end()))
	{}

	template<typename Token>
	UniformTypeMismatchError(const Token &t, const boost::string_ref &typeName, uniform_float_mismatch_t)
		: BaseParseError(GetFloatError(t, std::string(typeName.begin(), typeName.end())),
		std::distance(t.value().begin(), t.value().end()))
	{}

	template<typename Token>
	UniformTypeMismatchError(const Token &t, const boost::string_ref &typeName,
		int expectedSize, bool overflow)

		: BaseParseError(
			GetSizeError(t, std::string(typeName.begin(), typeName.end()), expectedSize, overflow),
			std::distance(t.value().begin(), t.value().end()))
	{}

private:

	template<typename Token>
	std::string GetUnsignedError(const Token &t, const std::string &typeName)
	{
		return "Uniform value '" + std::string(t.value().begin(), t.value().end()) +
			"' should be unsigned to match the uniform's type '" + typeName + "'.";
	}

	template<typename Token>
	std::string GetScalarError(const Token &, const std::string &typeName)
	{
		return "The vector uniform type '" + typeName + "' can only be constructed by vectors of values."
			" You must surround a single value with `()` syntax.";
	}

	template<typename Token>
	std::string GetFloatError(const Token &t, const std::string &typeName)
	{
		return "Uniform value '" + std::string(t.value().begin(), t.value().end()) +
			"' is a float, but the uniform's type is the integer type '" + typeName + "'.";
	}

	template<typename Token>
	std::string GetSizeError(const Token &, const std::string &typeName,
		int expectedSize, bool overflow)
	{
		const char *manyFew = overflow ? "too many." : "too few.";

		return "Uniform type '" + typeName + "' requires " +
			boost::lexical_cast<std::string>(expectedSize) + " parameters. You have provided " + manyFew;
	}
};

class MultipleUseOfCommandError : public BaseParseError
{
public:
	template<typename Token>
	MultipleUseOfCommandError(const Token &t, size_t owningKeyword)
		: BaseParseError(GetError(t, owningKeyword),
		std::distance(t.value().begin(), t.value().end()))
	{}


private:
	template<typename Token>
	std::string GetError(const Token &t, size_t owningKeyword)
	{
		return "The '" + std::string(t.value().begin(), t.value().end()) +
			"' command can only be used once within a '" + GetTokenErrorName(owningKeyword) + "' definition.";
	}
};

template<typename Mapped>
struct EnumData
{
	boost::string_ref enumName;
	array_ref<boost::string_ref> enumerators;
	array_ref<Mapped> mapping;
};

template<> struct EnumData<void>
{
	boost::string_ref enumName;
	array_ref<boost::string_ref> enumerators;
};

class IncorrectEnumError : public BaseParseError
{
public:
	template<typename Token, typename Mapped>
	IncorrectEnumError(const Token &t, const EnumData<Mapped> &data)
		: BaseParseError(GetError(t, data),
		std::distance(t.value().begin(), t.value().end()))
	{}

private:
	template<typename Token, typename Mapped>
	std::string GetError(const Token &t, const EnumData<Mapped> &data)
	{
		std::string enumeration(data.enumName.begin(), data.enumName.end());
		return "The enumerator '" + ExtractEnum(t) + "' cannot be used with '" + enumeration + "'.";
	}
};

const EnumData<void> g_uniformTypeEnumeration = {"enum", array_ref<boost::string_ref>(g_uniformTypeList)};

boost::string_ref g_magFilterEnumNames[] =
{
	"nearest",
	"linear",
};

boost::string_ref g_minFilterEnumNames[] =
{
	"nearest",
	"linear",
	"nearest_mip_nearest",
	"nearest_mip_linear",
	"linear_mip_nearest",
	"linear_mip_linear",
};

boost::string_ref g_wrapModeEnumNames[] =
{
	"edge_clamp",
	"border_clamp",
	"repeat",
	"mirror_repeat",
};

boost::string_ref g_compareModeEnumNames[] =
{
	"less",
	"less_equal",
	"greater",
	"greater_equal",
	"equal",
	"not_equal",
	"pass",
	"fail",
};

const EnumData<void> g_magFilterEnumeration = {"mag", array_ref<boost::string_ref>(g_magFilterEnumNames)};
const EnumData<void> g_minFilterEnumeration = {"min", array_ref<boost::string_ref>(g_minFilterEnumNames)};
const EnumData<void> g_wrapModeEnumeration = {"wrap", array_ref<boost::string_ref>(g_wrapModeEnumNames)};
const EnumData<void> g_compareModeEnumeration = {"compare", array_ref<boost::string_ref>(g_compareModeEnumNames)};

struct ThrowOnInvalid
{
	bool operator()(const token_type &tok) const
	{
		if(!token_is_valid(tok))
			throw BadTokenError();
		return true;
	}
};

struct SkipWhitespace
{
	bool operator()(const token_type &tok) const
	{
		return GetPrefixFromId(tok.id()) != WHITESPACE_ID_PREFIX;
	}
};

UniformData CreateDefaultUniform(int typeIx)
{
	switch(typeIx)
	{
	case 0: return UIntVectorTypes((unsigned int)0);
	case 1: return UIntVectorTypes(glm::uvec2(0));
	case 2: return UIntVectorTypes(glm::uvec3(0));
	case 3: return UIntVectorTypes(glm::uvec4(0));

	case 4: return IntVectorTypes(int());
	case 5: return IntVectorTypes(glm::ivec2(0));
	case 6: return IntVectorTypes(glm::ivec3(0));
	case 7: return IntVectorTypes(glm::ivec4(0));

	case 8: return VectorTypes(float());
	case 9: return VectorTypes(glm::vec2(0.0f));
	case 10: return VectorTypes(glm::vec3(0.0f));
	case 11: return VectorTypes(glm::vec4(0.0f));

	case 12: return MatrixTypes(glm::mat2(1.0f));
	case 13: return MatrixTypes(glm::mat3(1.0f));
	case 14: return MatrixTypes(glm::mat4(1.0f));
	}

	return UniformData();
}

template<typename T>
UniformData ConstructFromSingleValue(T val, int typeIx)
{
	switch(typeIx)
	{
	case 0: return UIntVectorTypes((unsigned int)(val));
	case 1: return UIntVectorTypes(glm::uvec2(val));
	case 2: return UIntVectorTypes(glm::uvec3(val));
	case 3: return UIntVectorTypes(glm::uvec4(val));

	case 4: return IntVectorTypes(int(val));
	case 5: return IntVectorTypes(glm::ivec2(val));
	case 6: return IntVectorTypes(glm::ivec3(val));
	case 7: return IntVectorTypes(glm::ivec4(val));

	case 8: return VectorTypes(float(val));
	case 9: return VectorTypes(glm::vec2(val));
	case 10: return VectorTypes(glm::vec3(val));
	case 11: return VectorTypes(glm::vec4(val));

	case 12: return MatrixTypes(glm::mat2(val));
	case 13: return MatrixTypes(glm::mat3(val));
	case 14: return MatrixTypes(glm::mat4(val));
	}

	return UniformData();
}

int GetUniformTypeLength(int typeIx)
{
	switch(typeIx)
	{
	case 0:
	case 4:
	case 8:
		return 1;
	case 1:
	case 5:
	case 9:
		return 2;
	case 2:
	case 6:
	case 10:
		return 3;
	case 3:
	case 7:
	case 11:
		return 4;
	case 12:
		return 4;
	case 13:
		return 9;
	case 14:
		return 16;
	}
	return 0;
}

typedef boost::variant<unsigned int, int, float> ParsedValue;

struct UniformFromSingleValue : public boost::static_visitor<UniformData>
{
	UniformFromSingleValue(int _typeIx) : typeIx(_typeIx) {}

	template<typename T>
	UniformData operator()(const T &t) const
	{
		return ConstructFromSingleValue(t, typeIx);
	}

private:
	int typeIx;
};

static size_t g_integerTokenIds[] =
{TOK_UNSIGNED_INTEGER, TOK_SIGNED_INTEGER};

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
UniformData MakeUniformData(const std::vector<T> &arr, int typeIx)
{
	BOOST_ASSERT(arr.size() == GetUniformTypeLength(typeIx));
	switch(typeIx)
	{
	case 0: return UIntVectorTypes((unsigned int)(arr[0]));
	case 1: return UIntVectorTypes(glm::uvec2(arr[0], arr[1]));
	case 2: return UIntVectorTypes(glm::uvec3(arr[0], arr[1], arr[2]));
	case 3: return UIntVectorTypes(glm::uvec4(arr[0], arr[1], arr[2], arr[3]));

	case 4: return IntVectorTypes(int(arr[0]));
	case 5: return IntVectorTypes(glm::ivec2(arr[0], arr[1]));
	case 6: return IntVectorTypes(glm::ivec3(arr[0], arr[1], arr[2]));
	case 7: return IntVectorTypes(glm::ivec4(arr[0], arr[1], arr[2], arr[3]));

	case 8: return VectorTypes(float(arr[0]));
	case 9: return VectorTypes(glm::vec2(arr[0], arr[1]));
	case 10: return VectorTypes(glm::vec3(arr[0], arr[1], arr[2]));
	case 11: return VectorTypes(glm::vec4(arr[0], arr[1], arr[2], arr[3]));

	case 12: return MatrixTypes(glm::mat2(
				 arr[0], arr[1],
				 arr[2], arr[3]));
	case 13: return MatrixTypes(glm::mat3(
				 arr[0], arr[1], arr[2],
				 arr[0], arr[1], arr[2],
				 arr[0], arr[1], arr[2]));
	case 14: return MatrixTypes(glm::mat4(
				 arr[0], arr[1], arr[2], arr[3],
				 arr[4], arr[5], arr[6], arr[7],
				 arr[8], arr[9], arr[10], arr[11],
				 arr[12], arr[13], arr[14], arr[15]));
	}

	return UniformData();
}

UniformData BuildUniformData(const std::vector<ParsedValue> &parsed, int typeIx)
{
	if(IsUnifTypeUnsigned(typeIx))
		return MakeUniformData(ConvertParsedVector<unsigned int>(parsed), typeIx);
	else if(IsUnifTypeInteger(typeIx))
		return MakeUniformData(ConvertParsedVector<int>(parsed), typeIx);
	else
		return MakeUniformData(ConvertParsedVector<float>(parsed), typeIx);
}

typedef boost::container::flat_set<size_t> TokenChecker;

template<typename Token>
void CheckMultipleKeyword(TokenChecker &hasBeenFound, const Token &tok, size_t owningId)
{
	if(hasBeenFound.find(tok.id()) != hasBeenFound.end())
		throw MultipleUseOfCommandError(tok, owningId);
	hasBeenFound.insert(tok.id());
}

static size_t g_validSamplerTokens[] =
{
	TOK_MAG,
	TOK_MIN,
	TOK_COMPARE,
	TOK_WRAP_S,
	TOK_WRAP_T,
	TOK_WRAP_R,
	TOK_ANISO,
};

struct FilePosition
{
	std::string fileName;
	int lineNumber;
	int columnNumber;
	std::string theLine;
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
		ExpectToken(TOK_RESOURCES);
		EatOneToken();

		while(!m_rng.empty() && m_rng.front().id() != TOK_END)
		{
			ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
			typename Range::value_type tok = m_rng.front();
			switch(tok.id())
			{
			case TOK_UNIFORM:
				{
					EatOneToken();
					ParseIdentifier();
					ExpectAndEatToken(TOK_TYPE);
					int uniformType = ParseEnumerator(g_uniformTypeEnumeration);
					UniformData data = ParseUniformData(uniformType);
				}
				break;
			case TOK_SAMPLER:
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
		ExpectAndEatToken(TOK_SAMPLER);
		ParseIdentifier();

		TokenChecker hasBeenFound;

		while(!m_rng.empty() && m_rng.front().id() != TOK_END)
		{
			ExpectCategory(m_rng.front(), KEYWORD_ID_PREFIX);
			if(!HasTokenOneOfNoEmpty(g_validSamplerTokens))
				throw UnexpectedDataError(m_rng.front(), "a valid sampler parameter.", exp_message);

			typename Range::value_type tok = m_rng.front();
			CheckMultipleKeyword(hasBeenFound, tok, TOK_SAMPLER);
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
					std::string theFloat(m_rng.front().value().begin(), m_rng.front().value().end());
					boost::lexical_cast<float>(theFloat);
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

				std::string theInt(m_rng.front().value().begin(), m_rng.front().value().end());
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

				std::string theFloat(m_rng.front().value().begin(), m_rng.front().value().end());

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

				std::string theInt(m_rng.front().value().begin(), m_rng.front().value().end());

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

				std::string theFloat(m_rng.front().value().begin(), m_rng.front().value().end());

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

	pos_iterator &m_currIt;
	Range m_rng;
};

template<typename Range>
SceneGraphParser<Range> MakeParser(pos_iterator &posIt, const Range &rng)
{
	return SceneGraphParser<Range>(posIt, rng);
}


int main()
{
	std::ifstream loadFile("test.txt", std::ios::in | std::ios::binary);

	simple_lexer<lexer_type> lexing;

	std::string txtFile((std::istreambuf_iterator<char>(loadFile)),
		std::istreambuf_iterator<char>());

	std::string::const_iterator first = txtFile.begin();
	std::string::const_iterator last = txtFile.end();
	pos_iterator currIt((txtFile.begin()), txtFile.end());
	currIt.set_tabchars(4);

	try
	{
		using boost::adaptors::filtered;

		token_range rng(lexing.begin(currIt, pos_iterator(), NULL), lexing.end());

		ThrowOnInvalid validity;
		SkipWhitespace skipper;
		MakeParser(currIt, rng
			| boost::adaptors::filtered(validity)
			| boost::adaptors::filtered(skipper)).ParseSceneGraph();
/*
		ParseSceneGraph(rng
			| boost::adaptors::filtered(ThrowOnInvalid())
			| boost::adaptors::filtered(SkipWhitespace()));
*/
	}
	catch(BaseParseError &e)
	{
		std::cout << e.what() << std::endl;

		if(!e.IsOutOfData())
		{
			const classic::file_position_base<std::string> &pos = currIt.get_position();

			size_t column = pos.column - e.GetSizeOfToken();

			std::string line = currIt.get_currentline();
			line = boost::algorithm::replace_all_copy(line, "\t", "    ");

			std::cout <<
				"In file \"" << pos.file <<
				"\" line " << pos.line << " column " << column << std::endl <<
				line << std::endl;
			if(column > 1)
				std::cout << std::setw(column - 1) << " ";
			std::cout << "^- here" << std::endl;
		}
	}

	return 0;
}
