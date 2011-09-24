#ifndef _INT_GL_2_1_REM_3_1_HPP
#define _INT_GL_2_1_REM_3_1_HPP


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
	enum _int_gl_2_1_rem_3_1
	{
		GL_CURRENT_RASTER_SECONDARY_COLOR = 0x845F,
		GL_SLUMINANCE_ALPHA              = 0x8C44,
		GL_SLUMINANCE8_ALPHA8            = 0x8C45,
		GL_SLUMINANCE                    = 0x8C46,
		GL_SLUMINANCE8                   = 0x8C47,
		GL_COMPRESSED_SLUMINANCE         = 0x8C4A,
		GL_COMPRESSED_SLUMINANCE_ALPHA   = 0x8C4B,
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

#endif //_INT_GL_2_1_REM_3_1_HPP

