
#include "pch.h"
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <boost/foreach.hpp>
#include "IdString.h"



namespace glscene
{
	IdString::IdString( boost::string_ref value )
	{
		ConstIdString(value);
	}

	IdString::IdString( const std::string &value )
	{
		ConstIdString(boost::string_ref(value));
	}

	void IdString::ConstIdString( boost::string_ref value )
	{
		//Use the djb2 hash algorithm.
		boost::uint32_t currHash = 5381;
		BOOST_FOREACH(char c, value)
		{
			currHash = ((currHash << 5) + currHash) + c;
		}

		stringData.theHash = currHash;

		//Copy the string.
		if(value.size() > SIZE_ACTUAL_STRING - 1)
		{
			const size_t firstChars = (SIZE_ACTUAL_STRING / 2);
			const size_t lastChars = ((SIZE_ACTUAL_STRING + 1) / 2);
			std::copy(value.begin(), value.begin() + firstChars, &stringData.strString[0]);
			std::copy(value.end() - lastChars, value.end(), &stringData.strString[firstChars]);
			stringData.strString[SIZE_ACTUAL_STRING - 1] = '\0';
		}
		else
		{
			std::copy(value.begin(), value.end(), &stringData.strString[0]);
			std::fill(&stringData.strString[value.size()], &stringData.strString[SIZE_ACTUAL_STRING], '\0');
		}
	}

	bool IdString::operator<( const IdString &rhs ) const
	{
		for(int iLoop = 0; iLoop < NUM_INTEGERS; iLoop++)
		{
			if(iIntegers[iLoop] < rhs.iIntegers[iLoop])
				return true;
			if(iIntegers[iLoop] != rhs.iIntegers[iLoop])
				return false;
		}

		return false;
	}

	bool IdString::operator==( const IdString &rhs ) const
	{
		for(int iLoop = 0; iLoop < NUM_INTEGERS; iLoop++)
		{
			if(iIntegers[iLoop] != rhs.iIntegers[iLoop])
				return false;
		}

		return true;
	}
}
