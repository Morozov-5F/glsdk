#ifndef OPENGL_GEN_CORE_REM1_2_HPP
#define OPENGL_GEN_CORE_REM1_2_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		RESCALE_NORMAL                   = 0x803A,
		LIGHT_MODEL_COLOR_CONTROL        = 0x81F8,
		SINGLE_COLOR                     = 0x81F9,
		SEPARATE_SPECULAR_COLOR          = 0x81FA,
		ALIASED_POINT_SIZE_RANGE         = 0x846D,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTable)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTableParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorTableParameteriv)(GLenum target, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyColorTable)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTable)(GLenum target, GLenum format, GLenum type, GLvoid *table);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTableParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetColorTableParameteriv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorSubTable)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyColorSubTable)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionFilter1D)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameterf)(GLenum target, GLenum pname, GLfloat params);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameteri)(GLenum target, GLenum pname, GLint params);
		typedef void (CODEGEN_FUNCPTR * Proc_glConvolutionParameteriv)(GLenum target, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyConvolutionFilter1D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyConvolutionFilter2D)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionFilter)(GLenum target, GLenum format, GLenum type, GLvoid *image);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetConvolutionParameteriv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetSeparableFilter)(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
		typedef void (CODEGEN_FUNCPTR * Proc_glSeparableFilter2D)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogram)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogramParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetHistogramParameteriv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmax)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmaxParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMinmaxParameteriv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glHistogram)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
		typedef void (CODEGEN_FUNCPTR * Proc_glMinmax)(GLenum target, GLenum internalformat, GLboolean sink);
		typedef void (CODEGEN_FUNCPTR * Proc_glResetHistogram)(GLenum target);
		typedef void (CODEGEN_FUNCPTR * Proc_glResetMinmax)(GLenum target);
	}
	
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
