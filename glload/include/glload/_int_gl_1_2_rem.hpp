#ifndef OPENGL_GEN_CORE_REM1_2_HPP
#define OPENGL_GEN_CORE_REM1_2_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		//RESCALE_NORMAL taken from 1.2
		//LIGHT_MODEL_COLOR_CONTROL taken from 1.2
		//SINGLE_COLOR taken from 1.2
		//SEPARATE_SPECULAR_COLOR taken from 1.2
		//ALIASED_POINT_SIZE_RANGE taken from 1.2
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glTexImage3D)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTable)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTableParameterfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTableParameteriv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyColorTable)(GLenum , GLenum , GLint , GLint , GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTable)(GLenum , GLenum , GLenum , GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTableParameterfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTableParameteriv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorSubTable)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyColorSubTable)(GLenum , GLsizei , GLint , GLint , GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionFilter1D)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionFilter2D)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameterf)(GLenum , GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameterfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameteri)(GLenum , GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameteriv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyConvolutionFilter1D)(GLenum , GLenum , GLint , GLint , GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyConvolutionFilter2D)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionFilter)(GLenum , GLenum , GLenum , GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionParameterfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionParameteriv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetSeparableFilter)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSeparableFilter2D)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogram)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogramParameterfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogramParameteriv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmax)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmaxParameterfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmaxParameteriv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glHistogram)(GLenum , GLsizei , GLenum , GLboolean );
		typedef void (CODEGEN_FUNCPTR * Proc_glMinmax)(GLenum , GLenum , GLboolean );
		typedef void (CODEGEN_FUNCPTR * Proc_glResetHistogram)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glResetMinmax)(GLenum );
	}
	
	extern _detail::Proc_glTexImage3D TexImage3D;
	extern _detail::Proc_glColorTable ColorTable;
	extern _detail::Proc_glColorTableParameterfv ColorTableParameterfv;
	extern _detail::Proc_glColorTableParameteriv ColorTableParameteriv;
	extern _detail::Proc_glCopyColorTable CopyColorTable;
	extern _detail::Proc_glGetColorTable GetColorTable;
	extern _detail::Proc_glGetColorTableParameterfv GetColorTableParameterfv;
	extern _detail::Proc_glGetColorTableParameteriv GetColorTableParameteriv;
	extern _detail::Proc_glColorSubTable ColorSubTable;
	extern _detail::Proc_glCopyColorSubTable CopyColorSubTable;
	extern _detail::Proc_glConvolutionFilter1D ConvolutionFilter1D;
	extern _detail::Proc_glConvolutionFilter2D ConvolutionFilter2D;
	extern _detail::Proc_glConvolutionParameterf ConvolutionParameterf;
	extern _detail::Proc_glConvolutionParameterfv ConvolutionParameterfv;
	extern _detail::Proc_glConvolutionParameteri ConvolutionParameteri;
	extern _detail::Proc_glConvolutionParameteriv ConvolutionParameteriv;
	extern _detail::Proc_glCopyConvolutionFilter1D CopyConvolutionFilter1D;
	extern _detail::Proc_glCopyConvolutionFilter2D CopyConvolutionFilter2D;
	extern _detail::Proc_glGetConvolutionFilter GetConvolutionFilter;
	extern _detail::Proc_glGetConvolutionParameterfv GetConvolutionParameterfv;
	extern _detail::Proc_glGetConvolutionParameteriv GetConvolutionParameteriv;
	extern _detail::Proc_glGetSeparableFilter GetSeparableFilter;
	extern _detail::Proc_glSeparableFilter2D SeparableFilter2D;
	extern _detail::Proc_glGetHistogram GetHistogram;
	extern _detail::Proc_glGetHistogramParameterfv GetHistogramParameterfv;
	extern _detail::Proc_glGetHistogramParameteriv GetHistogramParameteriv;
	extern _detail::Proc_glGetMinmax GetMinmax;
	extern _detail::Proc_glGetMinmaxParameterfv GetMinmaxParameterfv;
	extern _detail::Proc_glGetMinmaxParameteriv GetMinmaxParameteriv;
	extern _detail::Proc_glHistogram Histogram;
	extern _detail::Proc_glMinmax Minmax;
	extern _detail::Proc_glResetHistogram ResetHistogram;
	extern _detail::Proc_glResetMinmax ResetMinmax;
	
}
#endif /*OPENGL_GEN_CORE_REM1_2_HPP*/
