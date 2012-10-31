#ifndef OPENGL_GEN_CORE_REM1_3_H
#define OPENGL_GEN_CORE_REM1_3_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#define GL_MAX_TEXTURE_UNITS 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#define GL_MULTISAMPLE_BIT 0x20000000
#define GL_NORMAL_MAP 0x8511
#define GL_REFLECTION_MAP 0x8512
#define GL_COMPRESSED_ALPHA 0x84E9
#define GL_COMPRESSED_LUMINANCE 0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define GL_COMPRESSED_INTENSITY 0x84EC
#define GL_COMBINE 0x8570
#define GL_COMBINE_RGB 0x8571
#define GL_COMBINE_ALPHA 0x8572
#define GL_SOURCE0_RGB 0x8580
#define GL_SOURCE1_RGB 0x8581
#define GL_SOURCE2_RGB 0x8582
#define GL_SOURCE0_ALPHA 0x8588
#define GL_SOURCE1_ALPHA 0x8589
#define GL_SOURCE2_ALPHA 0x858A
#define GL_OPERAND0_RGB 0x8590
#define GL_OPERAND1_RGB 0x8591
#define GL_OPERAND2_RGB 0x8592
#define GL_OPERAND0_ALPHA 0x8598
#define GL_OPERAND1_ALPHA 0x8599
#define GL_OPERAND2_ALPHA 0x859A
#define GL_RGB_SCALE 0x8573
#define GL_ADD_SIGNED 0x8574
#define GL_INTERPOLATE 0x8575
#define GL_SUBTRACT 0x84E7
#define GL_CONSTANT 0x8576
#define GL_PRIMARY_COLOR 0x8577
#define GL_PREVIOUS 0x8578
#define GL_DOT3_RGB 0x86AE
#define GL_DOT3_RGBA 0x86AF

typedef void (CODEGEN_FUNCPTR * PFNGLCLIENTACTIVETEXTUREPROC)(GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1DPROC)(GLenum , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1DVPROC)(GLenum , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1FPROC)(GLenum , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1FVPROC)(GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1IPROC)(GLenum , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1IVPROC)(GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1SPROC)(GLenum , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD1SVPROC)(GLenum , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2DPROC)(GLenum , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2DVPROC)(GLenum , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2FPROC)(GLenum , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2FVPROC)(GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2IPROC)(GLenum , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2IVPROC)(GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2SPROC)(GLenum , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD2SVPROC)(GLenum , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3DPROC)(GLenum , GLdouble , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3DVPROC)(GLenum , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3FPROC)(GLenum , GLfloat , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3FVPROC)(GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3IPROC)(GLenum , GLint , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3IVPROC)(GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3SPROC)(GLenum , GLshort , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD3SVPROC)(GLenum , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4DPROC)(GLenum , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4DVPROC)(GLenum , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4FPROC)(GLenum , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4FVPROC)(GLenum , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4IPROC)(GLenum , GLint , GLint , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4IVPROC)(GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4SPROC)(GLenum , GLshort , GLshort , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLMULTITEXCOORD4SVPROC)(GLenum , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXFPROC)(const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLLOADTRANSPOSEMATRIXDPROC)(const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXFPROC)(const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTTRANSPOSEMATRIXDPROC)(const GLdouble *);

extern PFNGLCLIENTACTIVETEXTUREPROC _funcptr_glClientActiveTexture;
#define glClientActiveTexture _funcptr_glClientActiveTexture
extern PFNGLMULTITEXCOORD1DPROC _funcptr_glMultiTexCoord1d;
#define glMultiTexCoord1d _funcptr_glMultiTexCoord1d
extern PFNGLMULTITEXCOORD1DVPROC _funcptr_glMultiTexCoord1dv;
#define glMultiTexCoord1dv _funcptr_glMultiTexCoord1dv
extern PFNGLMULTITEXCOORD1FPROC _funcptr_glMultiTexCoord1f;
#define glMultiTexCoord1f _funcptr_glMultiTexCoord1f
extern PFNGLMULTITEXCOORD1FVPROC _funcptr_glMultiTexCoord1fv;
#define glMultiTexCoord1fv _funcptr_glMultiTexCoord1fv
extern PFNGLMULTITEXCOORD1IPROC _funcptr_glMultiTexCoord1i;
#define glMultiTexCoord1i _funcptr_glMultiTexCoord1i
extern PFNGLMULTITEXCOORD1IVPROC _funcptr_glMultiTexCoord1iv;
#define glMultiTexCoord1iv _funcptr_glMultiTexCoord1iv
extern PFNGLMULTITEXCOORD1SPROC _funcptr_glMultiTexCoord1s;
#define glMultiTexCoord1s _funcptr_glMultiTexCoord1s
extern PFNGLMULTITEXCOORD1SVPROC _funcptr_glMultiTexCoord1sv;
#define glMultiTexCoord1sv _funcptr_glMultiTexCoord1sv
extern PFNGLMULTITEXCOORD2DPROC _funcptr_glMultiTexCoord2d;
#define glMultiTexCoord2d _funcptr_glMultiTexCoord2d
extern PFNGLMULTITEXCOORD2DVPROC _funcptr_glMultiTexCoord2dv;
#define glMultiTexCoord2dv _funcptr_glMultiTexCoord2dv
extern PFNGLMULTITEXCOORD2FPROC _funcptr_glMultiTexCoord2f;
#define glMultiTexCoord2f _funcptr_glMultiTexCoord2f
extern PFNGLMULTITEXCOORD2FVPROC _funcptr_glMultiTexCoord2fv;
#define glMultiTexCoord2fv _funcptr_glMultiTexCoord2fv
extern PFNGLMULTITEXCOORD2IPROC _funcptr_glMultiTexCoord2i;
#define glMultiTexCoord2i _funcptr_glMultiTexCoord2i
extern PFNGLMULTITEXCOORD2IVPROC _funcptr_glMultiTexCoord2iv;
#define glMultiTexCoord2iv _funcptr_glMultiTexCoord2iv
extern PFNGLMULTITEXCOORD2SPROC _funcptr_glMultiTexCoord2s;
#define glMultiTexCoord2s _funcptr_glMultiTexCoord2s
extern PFNGLMULTITEXCOORD2SVPROC _funcptr_glMultiTexCoord2sv;
#define glMultiTexCoord2sv _funcptr_glMultiTexCoord2sv
extern PFNGLMULTITEXCOORD3DPROC _funcptr_glMultiTexCoord3d;
#define glMultiTexCoord3d _funcptr_glMultiTexCoord3d
extern PFNGLMULTITEXCOORD3DVPROC _funcptr_glMultiTexCoord3dv;
#define glMultiTexCoord3dv _funcptr_glMultiTexCoord3dv
extern PFNGLMULTITEXCOORD3FPROC _funcptr_glMultiTexCoord3f;
#define glMultiTexCoord3f _funcptr_glMultiTexCoord3f
extern PFNGLMULTITEXCOORD3FVPROC _funcptr_glMultiTexCoord3fv;
#define glMultiTexCoord3fv _funcptr_glMultiTexCoord3fv
extern PFNGLMULTITEXCOORD3IPROC _funcptr_glMultiTexCoord3i;
#define glMultiTexCoord3i _funcptr_glMultiTexCoord3i
extern PFNGLMULTITEXCOORD3IVPROC _funcptr_glMultiTexCoord3iv;
#define glMultiTexCoord3iv _funcptr_glMultiTexCoord3iv
extern PFNGLMULTITEXCOORD3SPROC _funcptr_glMultiTexCoord3s;
#define glMultiTexCoord3s _funcptr_glMultiTexCoord3s
extern PFNGLMULTITEXCOORD3SVPROC _funcptr_glMultiTexCoord3sv;
#define glMultiTexCoord3sv _funcptr_glMultiTexCoord3sv
extern PFNGLMULTITEXCOORD4DPROC _funcptr_glMultiTexCoord4d;
#define glMultiTexCoord4d _funcptr_glMultiTexCoord4d
extern PFNGLMULTITEXCOORD4DVPROC _funcptr_glMultiTexCoord4dv;
#define glMultiTexCoord4dv _funcptr_glMultiTexCoord4dv
extern PFNGLMULTITEXCOORD4FPROC _funcptr_glMultiTexCoord4f;
#define glMultiTexCoord4f _funcptr_glMultiTexCoord4f
extern PFNGLMULTITEXCOORD4FVPROC _funcptr_glMultiTexCoord4fv;
#define glMultiTexCoord4fv _funcptr_glMultiTexCoord4fv
extern PFNGLMULTITEXCOORD4IPROC _funcptr_glMultiTexCoord4i;
#define glMultiTexCoord4i _funcptr_glMultiTexCoord4i
extern PFNGLMULTITEXCOORD4IVPROC _funcptr_glMultiTexCoord4iv;
#define glMultiTexCoord4iv _funcptr_glMultiTexCoord4iv
extern PFNGLMULTITEXCOORD4SPROC _funcptr_glMultiTexCoord4s;
#define glMultiTexCoord4s _funcptr_glMultiTexCoord4s
extern PFNGLMULTITEXCOORD4SVPROC _funcptr_glMultiTexCoord4sv;
#define glMultiTexCoord4sv _funcptr_glMultiTexCoord4sv
extern PFNGLLOADTRANSPOSEMATRIXFPROC _funcptr_glLoadTransposeMatrixf;
#define glLoadTransposeMatrixf _funcptr_glLoadTransposeMatrixf
extern PFNGLLOADTRANSPOSEMATRIXDPROC _funcptr_glLoadTransposeMatrixd;
#define glLoadTransposeMatrixd _funcptr_glLoadTransposeMatrixd
extern PFNGLMULTTRANSPOSEMATRIXFPROC _funcptr_glMultTransposeMatrixf;
#define glMultTransposeMatrixf _funcptr_glMultTransposeMatrixf
extern PFNGLMULTTRANSPOSEMATRIXDPROC _funcptr_glMultTransposeMatrixd;
#define glMultTransposeMatrixd _funcptr_glMultTransposeMatrixd

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_REM1_3_H*/
