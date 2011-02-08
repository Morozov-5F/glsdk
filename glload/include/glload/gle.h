
#ifndef GLE_FILE_H
#define GLE_FILE_H

namespace glload
{
	typedef enum LoadSucceeded
	{
		GLE_LOAD_FUNCTIONS_ALL,
		GLE_LOAD_FUNCTIONS_SOME,
		GLE_LOAD_FAILED,
	};

	int LoadFunctions();

#ifdef WIN32
	//Pass in a HDC as a void*.
	int LoadWinFunctions(void *hdc);
#endif //WIN32

	/**
	This function retrieves the major GL version number. Only works after gleLoadFunctions has been called.
	**/
	int GetMajorVersion();

	/**
	This function retrieves the minor GL version number. Only works after gleLoadFunctions has been called.

	\return Returns 0 if entirely successful.
	**/
	int GetMinorVersion();

	///Returns non-zero if the current GL version is greater than or equal to the given version.
	int IsVersionGEQ(int iMajorVersion, int iMinorVersion);
}


#endif //GLE_FILE_H

