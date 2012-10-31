#ifndef OPENGL_GEN_CORE_REM1_3_HPP
#define OPENGL_GEN_CORE_REM1_3_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		//CLIENT_ACTIVE_TEXTURE taken from 1.3
		//MAX_TEXTURE_UNITS taken from 1.3
		//TRANSPOSE_MODELVIEW_MATRIX taken from 1.3
		//TRANSPOSE_PROJECTION_MATRIX taken from 1.3
		//TRANSPOSE_TEXTURE_MATRIX taken from 1.3
		//TRANSPOSE_COLOR_MATRIX taken from 1.3
		//MULTISAMPLE_BIT taken from 1.3
		//NORMAL_MAP taken from 1.3
		//REFLECTION_MAP taken from 1.3
		//COMPRESSED_ALPHA taken from 1.3
		//COMPRESSED_LUMINANCE taken from 1.3
		//COMPRESSED_LUMINANCE_ALPHA taken from 1.3
		//COMPRESSED_INTENSITY taken from 1.3
		//COMBINE taken from 1.3
		//COMBINE_RGB taken from 1.3
		//COMBINE_ALPHA taken from 1.3
		//SOURCE0_RGB taken from 1.3
		//SOURCE1_RGB taken from 1.3
		//SOURCE2_RGB taken from 1.3
		//SOURCE0_ALPHA taken from 1.3
		//SOURCE1_ALPHA taken from 1.3
		//SOURCE2_ALPHA taken from 1.3
		//OPERAND0_RGB taken from 1.3
		//OPERAND1_RGB taken from 1.3
		//OPERAND2_RGB taken from 1.3
		//OPERAND0_ALPHA taken from 1.3
		//OPERAND1_ALPHA taken from 1.3
		//OPERAND2_ALPHA taken from 1.3
		//RGB_SCALE taken from 1.3
		//ADD_SIGNED taken from 1.3
		//INTERPOLATE taken from 1.3
		//SUBTRACT taken from 1.3
		//CONSTANT taken from 1.3
		//PRIMARY_COLOR taken from 1.3
		//PREVIOUS taken from 1.3
		//DOT3_RGB taken from 1.3
		//DOT3_RGBA taken from 1.3
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
