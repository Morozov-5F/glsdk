
#include "pch.h"

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

namespace lex = boost::spirit::lex;
namespace qi = boost::spirit::qi;

#define PREFIX_MASK 0xFFFFF000
#define KEYWORD_ID_PREFIX 0x1000
#define WHITESPACE_ID_PREFIX 0x2000
#define STRING_ID_PREFIX 0x4000
#define NUMBER_ID_PREFIX 0x8000
#define SYMBOL_ID_PREFIX 0x10000

enum Keywords
{
	TOK_END,
	TOK_RESOURCES,
	TOK_UNIFORM,
	TOK_TYPE,
	NUM_KEYWORD_TOKENS,
};

static const char *g_keywordNames[] =
{
	"end",
	"resources",
	"uniform",
	"type",
};

BOOST_STATIC_ASSERT(ARRAY_COUNT(g_keywordNames) == NUM_KEYWORD_TOKENS);

enum Whitespace
{
	TOK_SPACE,
	TOK_CPP_COMMENT,
	NUM_WHITESPACE_TOKENS,
};

static const char *g_whitespacePatterns[] =
{
	"\\s+",
	"\\/\\/[^\\n]*\\n",
};

static const char *g_debugWhitespaceNames[] =
{
	"Space",
	"Comment",
};

BOOST_STATIC_ASSERT(ARRAY_COUNT(g_whitespacePatterns) == NUM_WHITESPACE_TOKENS);
BOOST_STATIC_ASSERT(ARRAY_COUNT(g_debugWhitespaceNames) == NUM_WHITESPACE_TOKENS);


enum StringTokens
{
	TOK_IDENTIFIER,
	TOK_GLSL_IDENT,
	TOK_ENUMERATOR,
	TOK_FILENAME,
	TOK_STORE_NAME,
	NUM_STRING_TOKENS,
};

static const char *g_stringPatterns[] =
{
	"<\\w+>",
	"\\[[a-zA-Z_]\\w*\\]",
	"\\{[a-zA-Z_]\\w*\\}",
	"\\\"[^\\\"\\n\\t]+\\\"",
	"\\\'[^\\\'\\n\\t]+\\\'",
};

static const char *g_debugStringNames[] =
{
	"Identifier",
	"Shader Identifier",
	"Enumerator",
	"Filename",
	"Stored Name",
};

BOOST_STATIC_ASSERT(ARRAY_COUNT(g_stringPatterns) == NUM_STRING_TOKENS);
BOOST_STATIC_ASSERT(ARRAY_COUNT(g_debugStringNames) == NUM_STRING_TOKENS);


enum NumberTokens
{
	TOK_INTEGER,
	TOK_FLOAT,
	NUM_NUMBER_TOKENS,
};

static const char *g_numberPatterns[] =
{
	"[\\+\\-]?\\d+",
	"[\\+\\-]?\\d+\\.\\d*",
};

static const char *g_debugNumberNames[] =
{
	"Integer",
	"Float",
};

BOOST_STATIC_ASSERT(ARRAY_COUNT(g_numberPatterns) == NUM_NUMBER_TOKENS);
BOOST_STATIC_ASSERT(ARRAY_COUNT(g_debugNumberNames) == NUM_NUMBER_TOKENS);


enum SymbolTokens
{
	TOK_OPEN_PAREN,
	TOK_CLOSE_PAREN,
	NUM_SYMBOL_TOKENS,
};

static const char *g_symbolPatterns[] =
{
	"\\(",
	"\\)",
};

static const char *g_debugSymbolNames[] =
{
	"Open Paren",
	"Close Paren",
};

BOOST_STATIC_ASSERT(ARRAY_COUNT(g_symbolPatterns) == NUM_SYMBOL_TOKENS);
BOOST_STATIC_ASSERT(ARRAY_COUNT(g_debugSymbolNames) == NUM_SYMBOL_TOKENS);


template <typename Lexer>
struct simple_lexer : lex::lexer<Lexer>
{
	simple_lexer()
	{
		for(int loop = 0; loop < NUM_KEYWORD_TOKENS; ++loop)
		{
			this->self.add(g_keywordNames[loop], loop | KEYWORD_ID_PREFIX);
		}

		for(int loop = 0; loop < NUM_WHITESPACE_TOKENS; ++loop)
		{
			this->self.add(g_whitespacePatterns[loop], loop | WHITESPACE_ID_PREFIX);
		}

		for(int loop = 0; loop < NUM_STRING_TOKENS; ++loop)
		{
			this->self.add(g_stringPatterns[loop], loop | STRING_ID_PREFIX);
		}

		for(int loop = 0; loop < NUM_NUMBER_TOKENS; ++loop)
		{
			this->self.add(g_whitespacePatterns[loop], loop | WHITESPACE_ID_PREFIX);
		}

		for(int loop = 0; loop < NUM_SYMBOL_TOKENS; ++loop)
		{
			this->self.add(g_symbolPatterns[loop], loop | SYMBOL_ID_PREFIX);
		}
	}
};

size_t GetPrefixFromId(size_t id)
{
	return id & PREFIX_MASK;
}

boost::string_ref GetTokenCatName(size_t id)
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
		return "UNKNOWN_TOKEN!";
	}
}

template <typename Token>
boost::string_ref GetTokenCatName(const Token &t)
{
	return GetTokenCatName(t.id());
}

boost::string_ref GetTokenName(size_t id)
{
	size_t prefix = GetPrefixFromId(id);
	switch(prefix)
	{
	case KEYWORD_ID_PREFIX:
		return g_keywordNames[id & ~KEYWORD_ID_PREFIX];
	case WHITESPACE_ID_PREFIX:
		return g_debugWhitespaceNames[id & ~WHITESPACE_ID_PREFIX];
	case STRING_ID_PREFIX:
		return g_debugStringNames[id & ~STRING_ID_PREFIX];
	case NUMBER_ID_PREFIX:
		return g_debugNumberNames[id & ~NUMBER_ID_PREFIX];
	case SYMBOL_ID_PREFIX:
		return g_debugSymbolNames[id & ~SYMBOL_ID_PREFIX];
	default:
		return "UNKNOWN_TOKEN!";
	}
}

template <typename Token>
boost::string_ref GetTokenName(const Token &t)
{
	return GetTokenName(t.id());
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

std::stringstream errMessages;

struct ExpectedError
{
	template <typename>
	struct result { typedef void type; };

	void operator()(boost::string_ref msg) const
	{
		errMessages << msg << std::endl;
	}

	void operator()(qi::info const& what) const
	{
		errMessages << "Next value should be a: " << what << "" << std::endl;
	}

	template<typename Iterator>
	void operator()(const Iterator &it) const
	{
		errMessages << "Blah" << std::endl;
	}
};

boost::phoenix::function<ExpectedError> const ExpectError = ExpectedError();

#ifdef USE_QI

template <typename Iterator, typename Lexer>
struct test_grammar	: qi::grammar<Iterator, qi::in_state_skipper<Lexer> >
{
	template<typename Tokens>
	test_grammar(const Tokens &toks)
		: test_grammar::base_type(root)
	{
		uniformResource = toks.keywordTokens[TOK_UNIFORM]
			> toks.stringTokens[TOK_IDENTIFIER]
			> toks.keywordTokens[TOK_TYPE]
			> toks.stringTokens[TOK_ENUMERATOR];

		resourceTypes = uniformResource;
		resource = toks.keywordTokens[TOK_RESOURCES] >> +resourceTypes > toks.keywordTokens[TOK_END];
		resourceList = +resource | (qi::eps[ExpectError("No resources listed.")] >> qi::eps(false));

		root = resourceList;

		cause_error = (qi::eps > qi::eps(false));

		using qi::on_error;
		using boost::phoenix::val;

		BOOST_SPIRIT_DEBUG_NODE(root);
		BOOST_SPIRIT_DEBUG_NODE(resource);
		BOOST_SPIRIT_DEBUG_NODE(resourceList);
		BOOST_SPIRIT_DEBUG_NODE(resourceTypes);
		BOOST_SPIRIT_DEBUG_NODE(uniformResource);

		qi::on_error<qi::fail>(resource, ExpectError(qi::_4));
		qi::on_error<qi::fail>(resourceTypes, ExpectError(qi::_3));
	}

	qi::rule<Iterator, qi::in_state_skipper<Lexer> > root;
	qi::rule<Iterator, qi::in_state_skipper<Lexer> > resource;
	qi::rule<Iterator, qi::in_state_skipper<Lexer> > resourceList;
	qi::rule<Iterator, qi::in_state_skipper<Lexer> > resourceTypes;
	qi::rule<Iterator, qi::in_state_skipper<Lexer> > uniformResource;
	qi::rule<Iterator, qi::in_state_skipper<Lexer> > cause_error;
};

typedef test_grammar<token_iterator, simple_lexer<lexer_type>::lexer_def> curr_grammar;

template <typename Iterator, typename Lexer, typename ParserExpr, typename Skipper>
inline bool tokenize_and_phrase_parse_proper(Iterator& first, Iterator last, Lexer const& lex,
											 ParserExpr const& expr, Skipper const& skipper)
{
	try
	{
		return lex::tokenize_and_phrase_parse(first, last, lex, expr, skipper);
	}
	catch(qi::expectation_failure<Lexer::iterator_type> &)
	{
		return false;
	}
}

#endif //USE_QI

int main()
{
	std::ifstream loadFile("test.txt", std::ios::in | std::ios::binary);


	simple_lexer<lexer_type> lexing;
#ifdef USE_QI
	curr_grammar gram(lexing);
#endif //USE_QI

	std::string txtFile((std::istreambuf_iterator<char>(loadFile)),
		std::istreambuf_iterator<char>());

	std::string::const_iterator first = txtFile.begin();
	std::string::const_iterator last = txtFile.end();
	pos_iterator currIt((txtFile.begin()), txtFile.end());

	errMessages.str(std::string());
#ifdef USE_QI
	bool r = tokenize_and_phrase_parse_proper(currIt, pos_iterator(), lexing, gram,
		qi::in_state("Skip")[lexing.self]);
#endif //USE_QI

	token_range tokens(lexing.begin(currIt, pos_iterator(), NULL), lexing.end());
	BOOST_FOREACH(token_type &tok, tokens)
	{
	}

//	bool r = lex::tokenize(currIt, pos_iterator(), lexing, PrintToks());

#ifdef USE_QI
	if(!r)
	{
		std::string fromError = errMessages.str();
		if(fromError.empty())
			std::cout << "ERROR: Parsing failed." << std::endl;
		else
			std::cout << fromError;

		const classic::file_position_base<std::string> &pos = currIt.get_position();

		std::cout <<
			"In file \"" << pos.file <<
			"\" line " << pos.line << " column " << pos.column << std::endl <<
			"'" << currIt.get_currentline() << "'" << std::endl <<
			std::setw(pos.column - 1) << " " << "^- here" << std::endl;
	}
#endif //USE_QI

	return 0;
}
