
#ifndef GLSDK_LOAD_HPP
#define GLSDK_LOAD_HPP

#include "glload/gl_load.hpp"

#ifdef WIN32
#include <windows.h>
#include "glload/wgl_load.hpp"
#endif

#ifdef LOAD_X11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <GL/glx.h>
#include "glload/glx_load.hpp"
#endif

#endif //GLSDK_LOAD_HPP

