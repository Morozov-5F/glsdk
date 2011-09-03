#ifndef _INT_GL_3_0_REM_3_1_H
#define _INT_GL_3_0_REM_3_1_H


#ifndef APIENTRY
	#define GLE_REMOVE_APIENTRY
	#if defined(__MINGW32__)
		#define APIENTRY __stdcall
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#define APIENTRY __stdcall
	#else
		#define APIENTRY
	#endif
#endif //APIENTRY

#ifdef GLE_FUNCPTR
#undef GLE_FUNCPTR
#endif //GLE_FUNCPTR

#if defined(_WIN32)
	#define GLE_FUNCPTR APIENTRY
#else
	#define GLE_FUNCPTR
#endif

#ifndef GLAPI
	#define GLAPI extern
#endif


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#define GL_CLAMP_VERTEX_COLOR 0x891A
#define GL_CLAMP_FRAGMENT_COLOR 0x891B
#define GL_ALPHA_INTEGER 0x8D97



#ifdef __cplusplus
}
#endif //__cplusplus


#ifdef GLE_REMOVE_APIENTRY
	#undef GLE_REMOVE_APIENTRY
	#undef APIENTRY
#endif //GLE_REMOVE_APIENTRY

#endif //_INT_GL_3_0_REM_3_1_H
