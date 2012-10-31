#ifndef OPENGL_GEN_CORE_REM1_3_HPP
#define OPENGL_GEN_CORE_REM1_3_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		CLIENT_ACTIVE_TEXTURE            = 0x84E1,
		MAX_TEXTURE_UNITS                = 0x84E2,
		TRANSPOSE_MODELVIEW_MATRIX       = 0x84E3,
		TRANSPOSE_PROJECTION_MATRIX      = 0x84E4,
		TRANSPOSE_TEXTURE_MATRIX         = 0x84E5,
		TRANSPOSE_COLOR_MATRIX           = 0x84E6,
		MULTISAMPLE_BIT                  = 0x20000000,
		NORMAL_MAP                       = 0x8511,
		REFLECTION_MAP                   = 0x8512,
		COMPRESSED_ALPHA                 = 0x84E9,
		COMPRESSED_LUMINANCE             = 0x84EA,
		COMPRESSED_LUMINANCE_ALPHA       = 0x84EB,
		COMPRESSED_INTENSITY             = 0x84EC,
		COMBINE                          = 0x8570,
		COMBINE_RGB                      = 0x8571,
		COMBINE_ALPHA                    = 0x8572,
		SOURCE0_RGB                      = 0x8580,
		SOURCE1_RGB                      = 0x8581,
		SOURCE2_RGB                      = 0x8582,
		SOURCE0_ALPHA                    = 0x8588,
		SOURCE1_ALPHA                    = 0x8589,
		SOURCE2_ALPHA                    = 0x858A,
		OPERAND0_RGB                     = 0x8590,
		OPERAND1_RGB                     = 0x8591,
		OPERAND2_RGB                     = 0x8592,
		OPERAND0_ALPHA                   = 0x8598,
		OPERAND1_ALPHA                   = 0x8599,
		OPERAND2_ALPHA                   = 0x859A,
		RGB_SCALE                        = 0x8573,
		ADD_SIGNED                       = 0x8574,
		INTERPOLATE                      = 0x8575,
		SUBTRACT                         = 0x84E7,
		CONSTANT                         = 0x8576,
		PRIMARY_COLOR                    = 0x8577,
		PREVIOUS                         = 0x8578,
		DOT3_RGB                         = 0x86AE,
		DOT3_RGBA                        = 0x86AF,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glClientActiveTexture)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1d)(GLenum , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1dv)(GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1f)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1fv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1i)(GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1iv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1s)(GLenum , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord1sv)(GLenum , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2d)(GLenum , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2dv)(GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2f)(GLenum , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2fv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2i)(GLenum , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2iv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2s)(GLenum , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord2sv)(GLenum , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3d)(GLenum , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3dv)(GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3f)(GLenum , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3fv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3i)(GLenum , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3iv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3s)(GLenum , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord3sv)(GLenum , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4d)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4dv)(GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4f)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4fv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4i)(GLenum , GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4iv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4s)(GLenum , GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiTexCoord4sv)(GLenum , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadTransposeMatrixf)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadTransposeMatrixd)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultTransposeMatrixf)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultTransposeMatrixd)(const GLdouble *);
	}
	
	extern _detail::Proc_glClientActiveTexture ClientActiveTexture;
	extern _detail::Proc_glMultiTexCoord1d MultiTexCoord1d;
	extern _detail::Proc_glMultiTexCoord1dv MultiTexCoord1dv;
	extern _detail::Proc_glMultiTexCoord1f MultiTexCoord1f;
	extern _detail::Proc_glMultiTexCoord1fv MultiTexCoord1fv;
	extern _detail::Proc_glMultiTexCoord1i MultiTexCoord1i;
	extern _detail::Proc_glMultiTexCoord1iv MultiTexCoord1iv;
	extern _detail::Proc_glMultiTexCoord1s MultiTexCoord1s;
	extern _detail::Proc_glMultiTexCoord1sv MultiTexCoord1sv;
	extern _detail::Proc_glMultiTexCoord2d MultiTexCoord2d;
	extern _detail::Proc_glMultiTexCoord2dv MultiTexCoord2dv;
	extern _detail::Proc_glMultiTexCoord2f MultiTexCoord2f;
	extern _detail::Proc_glMultiTexCoord2fv MultiTexCoord2fv;
	extern _detail::Proc_glMultiTexCoord2i MultiTexCoord2i;
	extern _detail::Proc_glMultiTexCoord2iv MultiTexCoord2iv;
	extern _detail::Proc_glMultiTexCoord2s MultiTexCoord2s;
	extern _detail::Proc_glMultiTexCoord2sv MultiTexCoord2sv;
	extern _detail::Proc_glMultiTexCoord3d MultiTexCoord3d;
	extern _detail::Proc_glMultiTexCoord3dv MultiTexCoord3dv;
	extern _detail::Proc_glMultiTexCoord3f MultiTexCoord3f;
	extern _detail::Proc_glMultiTexCoord3fv MultiTexCoord3fv;
	extern _detail::Proc_glMultiTexCoord3i MultiTexCoord3i;
	extern _detail::Proc_glMultiTexCoord3iv MultiTexCoord3iv;
	extern _detail::Proc_glMultiTexCoord3s MultiTexCoord3s;
	extern _detail::Proc_glMultiTexCoord3sv MultiTexCoord3sv;
	extern _detail::Proc_glMultiTexCoord4d MultiTexCoord4d;
	extern _detail::Proc_glMultiTexCoord4dv MultiTexCoord4dv;
	extern _detail::Proc_glMultiTexCoord4f MultiTexCoord4f;
	extern _detail::Proc_glMultiTexCoord4fv MultiTexCoord4fv;
	extern _detail::Proc_glMultiTexCoord4i MultiTexCoord4i;
	extern _detail::Proc_glMultiTexCoord4iv MultiTexCoord4iv;
	extern _detail::Proc_glMultiTexCoord4s MultiTexCoord4s;
	extern _detail::Proc_glMultiTexCoord4sv MultiTexCoord4sv;
	extern _detail::Proc_glLoadTransposeMatrixf LoadTransposeMatrixf;
	extern _detail::Proc_glLoadTransposeMatrixd LoadTransposeMatrixd;
	extern _detail::Proc_glMultTransposeMatrixf MultTransposeMatrixf;
	extern _detail::Proc_glMultTransposeMatrixd MultTransposeMatrixd;
	
}
#endif /*OPENGL_GEN_CORE_REM1_3_HPP*/