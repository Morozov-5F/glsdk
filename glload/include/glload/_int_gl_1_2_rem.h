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

typedef void (CODEGEN_FUNCPTR * PFNGLTEXIMAGE3DPROC)(GLenum , GLint , GLint , GLsizei , GLsizei , GLsizei , GLint , GLenum , GLenum , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCOLORTABLEPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCOLORTABLEPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORSUBTABLEPROC)(GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCOLORSUBTABLEPROC)(GLenum , GLsizei , GLint , GLint , GLsizei );
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFPROC)(GLenum , GLenum , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIPROC)(GLenum , GLenum , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER1DPROC)(GLenum , GLenum , GLint , GLint , GLsizei );
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYCONVOLUTIONFILTER2DPROC)(GLenum , GLenum , GLint , GLint , GLsizei , GLsizei );
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCONVOLUTIONPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETSEPARABLEFILTERPROC)(GLenum , GLenum , GLenum , GLvoid *, GLvoid *, GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLSEPARABLEFILTER2DPROC)(GLenum , GLenum , GLsizei , GLsizei , GLenum , GLenum , const GLvoid *, const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETHISTOGRAMPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPROC)(GLenum , GLboolean , GLenum , GLenum , GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPARAMETERFVPROC)(GLenum , GLenum , GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMINMAXPARAMETERIVPROC)(GLenum , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLHISTOGRAMPROC)(GLenum , GLsizei , GLenum , GLboolean );
typedef void (CODEGEN_FUNCPTR * PFNGLMINMAXPROC)(GLenum , GLenum , GLboolean );
typedef void (CODEGEN_FUNCPTR * PFNGLRESETHISTOGRAMPROC)(GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLRESETMINMAXPROC)(GLenum );

extern PFNGLTEXIMAGE3DPROC _funcptr_glTexImage3D;
#define glTexImage3D _funcptr_glTexImage3D
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
