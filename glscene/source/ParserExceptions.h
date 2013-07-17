#ifndef GLSDK_GLSCENE_PARSER_EXCEPTIONS_H
#define GLSDK_GLSCENE_PARSER_EXCEPTIONS_H

#include "ParserUtils.h"
#include "ParserEnums.h"
#include <sstream>
#include <boost/optional.hpp>
#include <boost/foreach.hpp>


namespace glscene { namespace _detail
{
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

		BaseParseError(const std::string &desc, const FilePosition &pos)
			: std::runtime_error(desc)
			, tokenSize()
			, outOfData(false)
			, oPos(pos)
		{}

		ptrdiff_t GetSizeOfToken() const {return tokenSize;}
		bool IsOutOfData() const {return outOfData;}

		bool HasPosition() const {return oPos.is_initialized();}
		const FilePosition &GetPosition() const {return oPos.get();}

	private:
		ptrdiff_t tokenSize;
		bool outOfData;
		boost::optional<FilePosition> oPos;
	};

	class BadTokenError : public BaseParseError
	{
	public:
		template<typename Token>
		BadTokenError(const Token &t)
			: BaseParseError(
			GetError(std::string(t.value().begin(), t.value().end())),
			std::distance(t.value().begin(), t.value().end()))
		{}

	private:
		std::string GetError(const std::string &token)
		{
			//Things to test:
			//Starts with `,`; likely attempt to comma-deliniate a list.
			//Starts with `<`; illegal identifier character.
			//Starts with `{`; possible capital letter or other illegal enum character.
			//Starts with `[`; illegal GLSL identifier character.
			//Otherwise, just generic error.

			return "Malformed data!";
		}
	};

	class expect_category_t {};
	class expect_message_t {};

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
				return std::string("Expected to find the command name '") + GetTokenErrorName(idExpected) + "'. ";
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

	class uniform_unsigned_mismatch_t {};
	class uniform_scalar_mismatch_t {};
	class uniform_float_mismatch_t {};
	class uniform_size_mismatch_t {};

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
			std::stringstream str;
			str << "The enumerator '" << ExtractEnum(t) << "' cannot be used with the '" << enumeration << "' enumeration." << std::endl;
			str << "Valid enumerators for this enumeration are: ";
			BOOST_FOREACH(boost::string_ref theEnum, data.enumerators)
			{
				str << "\n\t'" << std::string(theEnum.begin(), theEnum.size()) << "'";
			}
			return str.str();
		}
	};


}}

#endif //GLSDK_GLSCENE_PARSER_EXCEPTIONS_H
