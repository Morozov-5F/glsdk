
#ifndef DEBUG_UTIL_H
#define DEBUG_UTIL_H


namespace glutil
{
	///\addtogroup module_glutil_debug
	///@{

	///Possible locations for debug outputs.
	enum OutputLocation
	{
		STD_OUT,	///<Output to standard out.
		STD_ERR,	///<Output to standard error.
	};

	/**
	\brief Registers a function for automatically outputting debug messages.

	This function only works with ARB_debug_output. If you have registered a function
	before calling this one, then the registered function will pass the function through,
	including your specialized data.
	
	\return true if the function was registered.
	**/
	bool RegisterDebugOutput(OutputLocation eLoc);

	///@}
}


#endif //DEBUG_UTIL_H
