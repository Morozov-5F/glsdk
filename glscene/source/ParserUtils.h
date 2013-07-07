#ifndef GLSDK_GLSCENE_PARSER_UTILITIES_H
#define GLSDK_GLSCENE_PARSER_UTILITIES_H

#define PREFIX_MASK 0xFFFFF000
#define KEYWORD_ID_PREFIX 0x1000
#define WHITESPACE_ID_PREFIX 0x2000
#define STRING_ID_PREFIX 0x3000
#define NUMBER_ID_PREFIX 0x4000
#define SYMBOL_ID_PREFIX 0x5000

#include <boost/utility/string_ref.hpp>
#include <glutil/array_ref.h>
#include <boost/variant.hpp>
#include <boost/container/flat_set.hpp>
#include "ResourceData.h"

namespace glscene { namespace _detail
{
	size_t GetPrefixFromId(size_t id);
	std::string GetTokenCatName(size_t id);

	template <typename Token>
	std::string GetTokenCatName(const Token &t)
	{
		return GetTokenCatName(t.id());
	}

	std::string GetTokenName(size_t id);
	std::string GetTokenErrorName(size_t id);

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

	template<typename Token>
	std::string ExtractEnum(const Token &tok)
	{
		std::string enumerator(tok.value().begin(), tok.value().end());
		return std::string(enumerator.begin() + 1, enumerator.end() - 1);
	}

	typedef boost::variant<unsigned int, int, float> ParsedValue;

	typedef boost::container::flat_set<size_t> TokenChecker;

	template<typename Token>
	void CheckMultipleCommand(TokenChecker &hasBeenFound, const Token &tok, size_t owningId)
	{
		if(hasBeenFound.find(tok.id()) != hasBeenFound.end())
			throw MultipleUseOfCommandError(tok, owningId);
		hasBeenFound.insert(tok.id());
	}

	struct FilePosition
	{
		std::string fileName;
		int lineNumber;
		int columnNumber;
		std::string theLine;
	};
}}

#endif //GLSDK_GLSCENE_PARSER_UTILITIES_H
