#ifndef OPENGL_GEN_CORE_REM2_0_H
#define OPENGL_GEN_CORE_REM2_0_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define GL_POINT_SPRITE 0x8861
#define GL_COORD_REPLACE 0x8862
#define GL_MAX_TEXTURE_COORDS 0x8871

typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1DPROC)(GLuint , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1DVPROC)(GLuint , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1FPROC)(GLuint , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1FVPROC)(GLuint , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1SPROC)(GLuint , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB1SVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2DPROC)(GLuint , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2DVPROC)(GLuint , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2FPROC)(GLuint , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2FVPROC)(GLuint , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2SPROC)(GLuint , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB2SVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3DPROC)(GLuint , GLdouble , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3DVPROC)(GLuint , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3FPROC)(GLuint , GLfloat , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3FVPROC)(GLuint , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3SPROC)(GLuint , GLshort , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB3SVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NBVPROC)(GLuint , const GLbyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NIVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NSVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NUBPROC)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NUBVPROC)(GLuint , const GLubyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NUIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4NUSVPROC)(GLuint , const GLushort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4BVPROC)(GLuint , const GLbyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4DPROC)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4DVPROC)(GLuint , const GLdouble *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4FPROC)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4FVPROC)(GLuint , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4IVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4SPROC)(GLuint , GLshort , GLshort , GLshort , GLshort );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4SVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4UBVPROC)(GLuint , const GLubyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4UIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIB4USVPROC)(GLuint , const GLushort *);

extern PFNGLVERTEXATTRIB1DPROC _funcptr_glVertexAttrib1d;
#define glVertexAttrib1d _funcptr_glVertexAttrib1d
extern PFNGLVERTEXATTRIB1DVPROC _funcptr_glVertexAttrib1dv;
#define glVertexAttrib1dv _funcptr_glVertexAttrib1dv
extern PFNGLVERTEXATTRIB1FPROC _funcptr_glVertexAttrib1f;
#define glVertexAttrib1f _funcptr_glVertexAttrib1f
extern PFNGLVERTEXATTRIB1FVPROC _funcptr_glVertexAttrib1fv;
#define glVertexAttrib1fv _funcptr_glVertexAttrib1fv
extern PFNGLVERTEXATTRIB1SPROC _funcptr_glVertexAttrib1s;
#define glVertexAttrib1s _funcptr_glVertexAttrib1s
extern PFNGLVERTEXATTRIB1SVPROC _funcptr_glVertexAttrib1sv;
#define glVertexAttrib1sv _funcptr_glVertexAttrib1sv
extern PFNGLVERTEXATTRIB2DPROC _funcptr_glVertexAttrib2d;
#define glVertexAttrib2d _funcptr_glVertexAttrib2d
extern PFNGLVERTEXATTRIB2DVPROC _funcptr_glVertexAttrib2dv;
#define glVertexAttrib2dv _funcptr_glVertexAttrib2dv
extern PFNGLVERTEXATTRIB2FPROC _funcptr_glVertexAttrib2f;
#define glVertexAttrib2f _funcptr_glVertexAttrib2f
extern PFNGLVERTEXATTRIB2FVPROC _funcptr_glVertexAttrib2fv;
#define glVertexAttrib2fv _funcptr_glVertexAttrib2fv
extern PFNGLVERTEXATTRIB2SPROC _funcptr_glVertexAttrib2s;
#define glVertexAttrib2s _funcptr_glVertexAttrib2s
extern PFNGLVERTEXATTRIB2SVPROC _funcptr_glVertexAttrib2sv;
#define glVertexAttrib2sv _funcptr_glVertexAttrib2sv
extern PFNGLVERTEXATTRIB3DPROC _funcptr_glVertexAttrib3d;
#define glVertexAttrib3d _funcptr_glVertexAttrib3d
extern PFNGLVERTEXATTRIB3DVPROC _funcptr_glVertexAttrib3dv;
#define glVertexAttrib3dv _funcptr_glVertexAttrib3dv
extern PFNGLVERTEXATTRIB3FPROC _funcptr_glVertexAttrib3f;
#define glVertexAttrib3f _funcptr_glVertexAttrib3f
extern PFNGLVERTEXATTRIB3FVPROC _funcptr_glVertexAttrib3fv;
#define glVertexAttrib3fv _funcptr_glVertexAttrib3fv
extern PFNGLVERTEXATTRIB3SPROC _funcptr_glVertexAttrib3s;
#define glVertexAttrib3s _funcptr_glVertexAttrib3s
extern PFNGLVERTEXATTRIB3SVPROC _funcptr_glVertexAttrib3sv;
#define glVertexAttrib3sv _funcptr_glVertexAttrib3sv
extern PFNGLVERTEXATTRIB4NBVPROC _funcptr_glVertexAttrib4Nbv;
#define glVertexAttrib4Nbv _funcptr_glVertexAttrib4Nbv
extern PFNGLVERTEXATTRIB4NIVPROC _funcptr_glVertexAttrib4Niv;
#define glVertexAttrib4Niv _funcptr_glVertexAttrib4Niv
extern PFNGLVERTEXATTRIB4NSVPROC _funcptr_glVertexAttrib4Nsv;
#define glVertexAttrib4Nsv _funcptr_glVertexAttrib4Nsv
extern PFNGLVERTEXATTRIB4NUBPROC _funcptr_glVertexAttrib4Nub;
#define glVertexAttrib4Nub _funcptr_glVertexAttrib4Nub
extern PFNGLVERTEXATTRIB4NUBVPROC _funcptr_glVertexAttrib4Nubv;
#define glVertexAttrib4Nubv _funcptr_glVertexAttrib4Nubv
extern PFNGLVERTEXATTRIB4NUIVPROC _funcptr_glVertexAttrib4Nuiv;
#define glVertexAttrib4Nuiv _funcptr_glVertexAttrib4Nuiv
extern PFNGLVERTEXATTRIB4NUSVPROC _funcptr_glVertexAttrib4Nusv;
#define glVertexAttrib4Nusv _funcptr_glVertexAttrib4Nusv
extern PFNGLVERTEXATTRIB4BVPROC _funcptr_glVertexAttrib4bv;
#define glVertexAttrib4bv _funcptr_glVertexAttrib4bv
extern PFNGLVERTEXATTRIB4DPROC _funcptr_glVertexAttrib4d;
#define glVertexAttrib4d _funcptr_glVertexAttrib4d
extern PFNGLVERTEXATTRIB4DVPROC _funcptr_glVertexAttrib4dv;
#define glVertexAttrib4dv _funcptr_glVertexAttrib4dv
extern PFNGLVERTEXATTRIB4FPROC _funcptr_glVertexAttrib4f;
#define glVertexAttrib4f _funcptr_glVertexAttrib4f
extern PFNGLVERTEXATTRIB4FVPROC _funcptr_glVertexAttrib4fv;
#define glVertexAttrib4fv _funcptr_glVertexAttrib4fv
extern PFNGLVERTEXATTRIB4IVPROC _funcptr_glVertexAttrib4iv;
#define glVertexAttrib4iv _funcptr_glVertexAttrib4iv
extern PFNGLVERTEXATTRIB4SPROC _funcptr_glVertexAttrib4s;
#define glVertexAttrib4s _funcptr_glVertexAttrib4s
extern PFNGLVERTEXATTRIB4SVPROC _funcptr_glVertexAttrib4sv;
#define glVertexAttrib4sv _funcptr_glVertexAttrib4sv
extern PFNGLVERTEXATTRIB4UBVPROC _funcptr_glVertexAttrib4ubv;
#define glVertexAttrib4ubv _funcptr_glVertexAttrib4ubv
extern PFNGLVERTEXATTRIB4UIVPROC _funcptr_glVertexAttrib4uiv;
#define glVertexAttrib4uiv _funcptr_glVertexAttrib4uiv
extern PFNGLVERTEXATTRIB4USVPROC _funcptr_glVertexAttrib4usv;
#define glVertexAttrib4usv _funcptr_glVertexAttrib4usv

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_REM2_0_H*/
