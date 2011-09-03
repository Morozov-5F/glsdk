#ifndef _INT_GL_2_1_REM_3_1_H
#define _INT_GL_2_1_REM_3_1_H


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


#define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define GL_SLUMINANCE_ALPHA 0x8C44
#define GL_SLUMINANCE8_ALPHA8 0x8C45
#define GL_SLUMINANCE 0x8C46
#define GL_SLUMINANCE8 0x8C47
#define GL_COMPRESSED_SLUMINANCE 0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B



#ifdef __cplusplus
}
#endif //__cplusplus


#ifdef GLE_REMOVE_APIENTRY
	#undef GLE_REMOVE_APIENTRY
	#undef APIENTRY
#endif //GLE_REMOVE_APIENTRY

#endif //_INT_GL_2_1_REM_3_1_H
