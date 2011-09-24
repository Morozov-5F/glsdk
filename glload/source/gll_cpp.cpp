
#include <stdlib.h>
#include <string.h>
#include "gll_gl_ext.h"
#include "gll_gl_ext_base.h"
#include "glload/gll.hpp"

#include "glload/gll.h"


namespace glload
{
	int LoadFunctions()
	{
		return ::LoadFunctions();
	}

	int GetMajorVersion()
	{
		return ::GetMajorVersion();
	}

	int GetMinorVersion()
	{
		return ::GetMinorVersion();
	}

	bool IsVersionGEQ( int iMajorVersion, int iMinorVersion )
	{
		return ::IsVersionGEQ(iMajorVersion, iMinorVersion) != 0;
	}

#ifdef WIN32
	int LoadWinFunctions(void *hdc)
	{
		return ::LoadWinFunctions(hdc);
	}
#endif //WIN32

#ifdef LOAD_X11
   	int LoadGLXFunctions(void *display, int screen)
   	{
		return ::LoadGLXFunctions(display, screen);
   	}
#endif //LOAD_X11
}


