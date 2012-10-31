#ifndef WINDOWSGL_GEN_TYPE_HPP
#define WINDOWSGL_GEN_TYPE_HPP
#ifdef __wglext_h_
#error Attempt to include auto-generated WGL header after wglext.h
#endif

#define __wglext_h_

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN 1
#endif
#ifndef NOMINMAX
	#define NOMINMAX
#endif
#include <windows.h>

#ifdef CODEGEN_FUNCPTR
#undef CODEGEN_FUNCPTR
#endif /*CODEGEN_FUNCPTR*/
#define CODEGEN_FUNCPTR WINAPI

#ifndef GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS
#define GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS

	typedef unsigned int GLenum;
	typedef unsigned char GLboolean;
	typedef unsigned int GLbitfield;
	typedef signed char GLbyte;
	typedef short GLshort;
	typedef int GLint;
	typedef int GLsizei;
	typedef unsigned char GLubyte;
	typedef unsigned short GLushort;
	typedef unsigned int GLuint;
	typedef float GLfloat;
	typedef float GLclampf;
	typedef double GLdouble;
	typedef double GLclampd;
	#define GLvoid void

#endif /*GL_LOAD_GEN_BASIC_OPENGL_TYPEDEFS*/

#ifndef WGL_ARB_pbuffer
	DECLARE_HANDLE(HPBUFFERARB);
#endif
#ifndef WGL_EXT_pbuffer
	DECLARE_HANDLE(HPBUFFEREXT);
#endif
#ifndef WGL_NV_present_video
	DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
#endif
#ifndef WGL_NV_video_output
	DECLARE_HANDLE(HPVIDEODEV);
#endif
#ifndef WGL_NV_gpu_affinity
	DECLARE_HANDLE(HPGPUNV);
	DECLARE_HANDLE(HGPUNV);
	typedef struct _GPU_DEVICE {
	    DWORD  cb;
	    CHAR   DeviceName[32];
	    CHAR   DeviceString[128];
	    DWORD  Flags;
	    RECT   rcVirtualScreen;
	} GPU_DEVICE, *PGPU_DEVICE;
#endif
#ifndef WGL_NV_video_capture
	DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
#endif
#endif /*WINDOWSGL_GEN_TYPE_HPP*/
