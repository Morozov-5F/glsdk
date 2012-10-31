#ifndef OPENGL_GEN_CORE_REM1_4_HPP
#define OPENGL_GEN_CORE_REM1_4_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		POINT_SIZE_MIN                   = 0x8126,
		POINT_SIZE_MAX                   = 0x8127,
		POINT_DISTANCE_ATTENUATION       = 0x8129,
		GENERATE_MIPMAP                  = 0x8191,
		GENERATE_MIPMAP_HINT             = 0x8192,
		FOG_COORDINATE_SOURCE            = 0x8450,
		FOG_COORDINATE                   = 0x8451,
		FRAGMENT_DEPTH                   = 0x8452,
		CURRENT_FOG_COORDINATE           = 0x8453,
		FOG_COORDINATE_ARRAY_TYPE        = 0x8454,
		FOG_COORDINATE_ARRAY_STRIDE      = 0x8455,
		FOG_COORDINATE_ARRAY_POINTER     = 0x8456,
		FOG_COORDINATE_ARRAY             = 0x8457,
		COLOR_SUM                        = 0x8458,
		CURRENT_SECONDARY_COLOR          = 0x8459,
		SECONDARY_COLOR_ARRAY_SIZE       = 0x845A,
		SECONDARY_COLOR_ARRAY_TYPE       = 0x845B,
		SECONDARY_COLOR_ARRAY_STRIDE     = 0x845C,
		SECONDARY_COLOR_ARRAY_POINTER    = 0x845D,
		SECONDARY_COLOR_ARRAY            = 0x845E,
		TEXTURE_FILTER_CONTROL           = 0x8500,
		DEPTH_TEXTURE_MODE               = 0x884B,
		COMPARE_R_TO_TEXTURE             = 0x884E,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glFogCoordf)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glFogCoordfv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogCoordd)(GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glFogCoorddv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogCoordPointer)(GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3b)(GLbyte , GLbyte , GLbyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3bv)(const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3ub)(GLubyte , GLubyte , GLubyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3ubv)(const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3ui)(GLuint , GLuint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3uiv)(const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3us)(GLushort , GLushort , GLushort );
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColor3usv)(const GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSecondaryColorPointer)(GLint , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2d)(GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2f)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2i)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2s)(GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos2sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glWindowPos3sv)(const GLshort *);
	}
	
	extern _detail::Proc_glFogCoordf FogCoordf;
	extern _detail::Proc_glFogCoordfv FogCoordfv;
	extern _detail::Proc_glFogCoordd FogCoordd;
	extern _detail::Proc_glFogCoorddv FogCoorddv;
	extern _detail::Proc_glFogCoordPointer FogCoordPointer;
	extern _detail::Proc_glSecondaryColor3b SecondaryColor3b;
	extern _detail::Proc_glSecondaryColor3bv SecondaryColor3bv;
	extern _detail::Proc_glSecondaryColor3d SecondaryColor3d;
	extern _detail::Proc_glSecondaryColor3dv SecondaryColor3dv;
	extern _detail::Proc_glSecondaryColor3f SecondaryColor3f;
	extern _detail::Proc_glSecondaryColor3fv SecondaryColor3fv;
	extern _detail::Proc_glSecondaryColor3i SecondaryColor3i;
	extern _detail::Proc_glSecondaryColor3iv SecondaryColor3iv;
	extern _detail::Proc_glSecondaryColor3s SecondaryColor3s;
	extern _detail::Proc_glSecondaryColor3sv SecondaryColor3sv;
	extern _detail::Proc_glSecondaryColor3ub SecondaryColor3ub;
	extern _detail::Proc_glSecondaryColor3ubv SecondaryColor3ubv;
	extern _detail::Proc_glSecondaryColor3ui SecondaryColor3ui;
	extern _detail::Proc_glSecondaryColor3uiv SecondaryColor3uiv;
	extern _detail::Proc_glSecondaryColor3us SecondaryColor3us;
	extern _detail::Proc_glSecondaryColor3usv SecondaryColor3usv;
	extern _detail::Proc_glSecondaryColorPointer SecondaryColorPointer;
	extern _detail::Proc_glWindowPos2d WindowPos2d;
	extern _detail::Proc_glWindowPos2dv WindowPos2dv;
	extern _detail::Proc_glWindowPos2f WindowPos2f;
	extern _detail::Proc_glWindowPos2fv WindowPos2fv;
	extern _detail::Proc_glWindowPos2i WindowPos2i;
	extern _detail::Proc_glWindowPos2iv WindowPos2iv;
	extern _detail::Proc_glWindowPos2s WindowPos2s;
	extern _detail::Proc_glWindowPos2sv WindowPos2sv;
	extern _detail::Proc_glWindowPos3d WindowPos3d;
	extern _detail::Proc_glWindowPos3dv WindowPos3dv;
	extern _detail::Proc_glWindowPos3f WindowPos3f;
	extern _detail::Proc_glWindowPos3fv WindowPos3fv;
	extern _detail::Proc_glWindowPos3i WindowPos3i;
	extern _detail::Proc_glWindowPos3iv WindowPos3iv;
	extern _detail::Proc_glWindowPos3s WindowPos3s;
	extern _detail::Proc_glWindowPos3sv WindowPos3sv;
	
}
#endif /*OPENGL_GEN_CORE_REM1_4_HPP*/
