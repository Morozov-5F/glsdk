
#ifndef GLSDK_INTERNAL_GLSCENE_ID_STRING_H
#define GLSDK_INTERNAL_GLSCENE_ID_STRING_H

#include <string>
#include <boost/utility/string_ref.hpp>
#include <boost/cstdint.hpp>

namespace glscene
{
	/**
	\brief A fixed-length string with a built-in hash.
	
	This is a simple fixed-length string class that can store and compare strings of arbitrary length,
	usually. The idea is very simple. The class stores 27 characters of the string (if the string is longer,
	it culls out the *middle* characters, not the starting or ending ones). But it also stores a 32-bit hash of
	the *original* string.
	
	So the only way for an accidental equivalence to occur would be for the two strings to
	both generate the same hash *and* still be similar enough that only the missing middle characters (if any)
	are the only differences between them. This seems rather unlikely.

	The ordering of this string is also designed for maximum efficiency. It compares the hashes first;
	if they're equal, then it compares the strings. But it only compares them as an array of 32-bit unsigned.
	So the comparison is simply doing up to 8 integer compares (and usually only 1). The comparison is obviously
	not lexicographically ordered.
	**/
	class IdString
	{
	public:
		IdString(boost::string_ref value);
		IdString(const std::string &value);

		const char *c_str() const {return stringData.strString;}
		boost::uint32_t hash() const {return stringData.theHash;}

		operator std::string() const {return std::string(stringData.strString);}
		operator boost::string_ref() const {return boost::string_ref(stringData.strString);}

		bool operator<(const IdString &rhs) const;

		bool operator==(const IdString &rhs) const;
		bool operator!=(const IdString &rhs) const {return !(*this == rhs);}

	private:
		void ConstIdString(boost::string_ref value);

		enum
		{
			NUM_INTEGERS = 8,
			NUM_BYTES = 32,
			FIRST_CHARACTER = 4,
			SIZE_ACTUAL_STRING = NUM_BYTES - FIRST_CHARACTER,
		};

		union
		{
			boost::uint32_t iIntegers[NUM_INTEGERS];
			struct
			{
				boost::uint32_t theHash;
				char strString[SIZE_ACTUAL_STRING];
			} stringData;
		};
	};
}

#endif //GLSDK_INTERNAL_GLSCENE_ID_STRING_H
