#ifndef OPENGL_GEN_CORE_REM1_2_H
#define OPENGL_GEN_CORE_REM1_2_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_RESCALE_NORMAL 0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define GL_SINGLE_COLOR 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE 0x846D

typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCOLORTABLEPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPROC)(GLenum target, GLenum format, GLenum type, GLvoid *table);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid *data);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCOLORSUBTABLEPROC)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *image);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *image);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat params);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum target, GLenum pname, GLint params);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONFILTERPROC)(GLenum target, GLenum format, GLenum type, GLvoid *image);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETSEPARABLEFILTERPROC)(GLenum target, GLenum format, GLenum type, GLvoid *row, GLvoid *column, GLvoid *span);
typedef void (CODEGEN_FUNCPTR * PFNGLSEPARABLEFILTER2DPROC)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *row, const GLvoid *column);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid *values);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLHISTOGRAMPROC)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef void (CODEGEN_FUNCPTR * PFNGLMINMAXPROC)(GLenum target, GLenum internalformat, GLboolean sink);
typedef void (CODEGEN_FUNCPTR * PFNGLRESETHISTOGRAMPROC)(GLenum target);
typedef void (CODEGEN_FUNCPTR * PFNGLRESETMINMAXPROC)(GLenum target);

extern PFNGLCOLORTABLEPROC _funcptr_glColorTable;
#define glColorTable _funcptr_glColorTable
extern PFNGLCOLORTABLEPARAMETERFVPROC _funcptr_glColorTableParameterfv;
#define glColorTableParameterfv _funcptr_glColorTableParameterfv
extern PFNGLCOLORTABLEPARAMETERIVPROC _funcptr_glColorTableParameteriv;
#define glColorTableParameteriv _funcptr_glColorTableParameteriv
extern PFNGLCOPYCOLORTABLEPROC _funcptr_glCopyColorTable;
#define glCopyColorTable _funcptr_glCopyColorTable
extern PFNGLGETCOLORTABLEPROC _funcptr_glGetColorTable;
#define glGetColorTable _funcptr_glGetColorTable
extern PFNGLGETCOLORTABLEPARAMETERFVPROC _funcptr_glGetColorTableParameterfv;
#define glGetColorTableParameterfv _funcptr_glGetColorTableParameterfv
extern PFNGLGETCOLORTABLEPARAMETERIVPROC _funcptr_glGetColorTableParameteriv;
#define glGetColorTableParameteriv _funcptr_glGetColorTableParameteriv
extern PFNGLCOLORSUBTABLEPROC _funcptr_glColorSubTable;
#define glColorSubTable _funcptr_glColorSubTable
extern PFNGLCOPYCOLORSUBTABLEPROC _funcptr_glCopyColorSubTable;
#define glCopyColorSubTable _funcptr_glCopyColorSubTable
extern PFNGLCONVOLUTIONFILTER1DPROC _funcptr_glConvolutionFilter1D;
#define glConvolutionFilter1D _funcptr_glConvolutionFilter1D
extern PFNGLCONVOLUTIONFILTER2DPROC _funcptr_glConvolutionFilter2D;
#define glConvolutionFilter2D _funcptr_glConvolutionFilter2D
extern PFNGLCONVOLUTIONPARAMETERFPROC _funcptr_glConvolutionParameterf;
#define glConvolutionParameterf _funcptr_glConvolutionParameterf
extern PFNGLCONVOLUTIONPARAMETERFVPROC _funcptr_glConvolutionParameterfv;
#define glConvolutionParameterfv _funcptr_glConvolutionParameterfv
extern PFNGLCONVOLUTIONPARAMETERIPROC _funcptr_glConvolutionParameteri;
#define glConvolutionParameteri _funcptr_glConvolutionParameteri
extern PFNGLCONVOLUTIONPARAMETERIVPROC _funcptr_glConvolutionParameteriv;
#define glConvolutionParameteriv _funcptr_glConvolutionParameteriv
extern PFNGLCOPYCONVOLUTIONFILTER1DPROC _funcptr_glCopyConvolutionFilter1D;
#define glCopyConvolutionFilter1D _funcptr_glCopyConvolutionFilter1D
extern PFNGLCOPYCONVOLUTIONFILTER2DPROC _funcptr_glCopyConvolutionFilter2D;
#define glCopyConvolutionFilter2D _funcptr_glCopyConvolutionFilter2D
extern PFNGLGETCONVOLUTIONFILTERPROC _funcptr_glGetConvolutionFilter;
#define glGetConvolutionFilter _funcptr_glGetConvolutionFilter
extern PFNGLGETCONVOLUTIONPARAMETERFVPROC _funcptr_glGetConvolutionParameterfv;
#define glGetConvolutionParameterfv _funcptr_glGetConvolutionParameterfv
extern PFNGLGETCONVOLUTIONPARAMETERIVPROC _funcptr_glGetConvolutionParameteriv;
#define glGetConvolutionParameteriv _funcptr_glGetConvolutionParameteriv
extern PFNGLGETSEPARABLEFILTERPROC _funcptr_glGetSeparableFilter;
#define glGetSeparableFilter _funcptr_glGetSeparableFilter
extern PFNGLSEPARABLEFILTER2DPROC _funcptr_glSeparableFilter2D;
#define glSeparableFilter2D _funcptr_glSeparableFilter2D
extern PFNGLGETHISTOGRAMPROC _funcptr_glGetHistogram;
#define glGetHistogram _funcptr_glGetHistogram
extern PFNGLGETHISTOGRAMPARAMETERFVPROC _funcptr_glGetHistogramParameterfv;
#define glGetHistogramParameterfv _funcptr_glGetHistogramParameterfv
extern PFNGLGETHISTOGRAMPARAMETERIVPROC _funcptr_glGetHistogramParameteriv;
#define glGetHistogramParameteriv _funcptr_glGetHistogramParameteriv
extern PFNGLGETMINMAXPROC _funcptr_glGetMinmax;
#define glGetMinmax _funcptr_glGetMinmax
extern PFNGLGETMINMAXPARAMETERFVPROC _funcptr_glGetMinmaxParameterfv;
#define glGetMinmaxParameterfv _funcptr_glGetMinmaxParameterfv
extern PFNGLGETMINMAXPARAMETERIVPROC _funcptr_glGetMinmaxParameteriv;
#define glGetMinmaxParameteriv _funcptr_glGetMinmaxParameteriv
extern PFNGLHISTOGRAMPROC _funcptr_glHistogram;
#define glHistogram _funcptr_glHistogram
extern PFNGLMINMAXPROC _funcptr_glMinmax;
#define glMinmax _funcptr_glMinmax
extern PFNGLRESETHISTOGRAMPROC _funcptr_glResetHistogram;
#define glResetHistogram _funcptr_glResetHistogram
extern PFNGLRESETMINMAXPROC _funcptr_glResetMinmax;
#define glResetMinmax _funcptr_glResetMinmax

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_REM1_2_H*/
