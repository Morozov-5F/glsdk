#ifndef _INT_GL_3_0_REM_3_1_HPP
#define _INT_GL_3_0_REM_3_1_HPP


#ifndef APIENTRY
//	#define GLE_REMOVE_APIENTRY
	#if defined(__MINGW32__)
		#define APIENTRY __stdcall
	#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) || defined(__BORLANDC__)
		#define APIENTRY __stdcall
	#else
		#define APIENTRY
	#endif
#endif //APIENTRY

#ifndef GLE_FUNCPTR
	#define GLE_REMOVE_FUNCPTR
	#if defined(_WIN32)
		#define GLE_FUNCPTR APIENTRY
	#else
		#define GLE_FUNCPTR
	#endif
#endif //GLE_FUNCPTR

#ifndef GLAPI
	#define GLAPI extern
#endif


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus


#ifdef __cplusplus
}
#endif //__cplusplus



namespace gl
{
	enum _int_gl_3_0_rem_3_1
	{
		GL_CLAMP_VERTEX_COLOR            = 0x891A,
		GL_CLAMP_FRAGMENT_COLOR          = 0x891B,
		GL_ALPHA_INTEGER                 = 0x8D97,
	};


}

#ifdef GLE_REMOVE_FUNCPTR
	#undef GLE_REMOVE_FUNCPTR
	#undef GLE_FUNPTR
#endif //GLE_REMOVE_FUNCPTR
/*
#ifdef GLE_REMOVE_APIENTRY
	#undef GLE_REMOVE_APIENTRY
	#undef APIENTRY
#endif //GLE_REMOVE_APIENTRY
*/

#endif //_INT_GL_3_0_REM_3_1_HPP

