#ifndef _INT_GL_1_5_REM_3_1_HPP
#define _INT_GL_1_5_REM_3_1_HPP


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
	enum _int_gl_1_5_rem_3_1
	{
		GL_VERTEX_ARRAY_BUFFER_BINDING   = 0x8896,
		GL_NORMAL_ARRAY_BUFFER_BINDING   = 0x8897,
		GL_COLOR_ARRAY_BUFFER_BINDING    = 0x8898,
		GL_INDEX_ARRAY_BUFFER_BINDING    = 0x8899,
		GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING = 0x889A,
		GL_EDGE_FLAG_ARRAY_BUFFER_BINDING = 0x889B,
		GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING = 0x889C,
		GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING = 0x889D,
		GL_WEIGHT_ARRAY_BUFFER_BINDING   = 0x889E,
		GL_FOG_COORD_SRC                 = 0x8450,
		GL_FOG_COORD                     = 0x8451,
		GL_CURRENT_FOG_COORD             = 0x8453,
		GL_FOG_COORD_ARRAY_TYPE          = 0x8454,
		GL_FOG_COORD_ARRAY_STRIDE        = 0x8455,
		GL_FOG_COORD_ARRAY_POINTER       = 0x8456,
		GL_FOG_COORD_ARRAY               = 0x8457,
		GL_FOG_COORD_ARRAY_BUFFER_BINDING = 0x889D,
		GL_SRC0_RGB                      = 0x8580,
		GL_SRC1_RGB                      = 0x8581,
		GL_SRC2_RGB                      = 0x8582,
		GL_SRC0_ALPHA                    = 0x8588,
		GL_SRC2_ALPHA                    = 0x858A,
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

#endif //_INT_GL_1_5_REM_3_1_HPP

