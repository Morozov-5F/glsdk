
#include "glload/gl_load.h"

#ifdef WIN32
#include <windows.h>
#include "glload/wgl_load.h"
#endif

#ifdef LOAD_X11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#include "glload/glx_load.h"
#endif

int LoadFunctions()
{
	return ogl_LoadFunctions();
}

int GetMajorVersion() { return ogl_GetMajorVersion(); }
int GetMinorVersion() { return ogl_GetMinorVersion(); }

int IsVersionGEQ( int iTestMajorVersion, int iTestMinorVersion )
{
	return ogl_IsVersionGEQ(iTestMajorVersion, iTestMinorVersion);
}

#ifdef WIN32
int LoadWinFunctions(void *hdc)
{
	HDC hDC = (HDC)hdc;
	return wgl_LoadFunctions(hDC);
}
#endif //WIN32

#ifdef LOAD_X11
int LoadGLXFunctions(void *display, int screen)
{
    Display *dpy = (Display*)display;
	return glx_LoadFunctions(display, screen);
}

#endif //LOAD_X11


