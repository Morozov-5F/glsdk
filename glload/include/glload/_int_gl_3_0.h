#ifndef OPENGL_GEN_CORE_3_0_H
#define OPENGL_GEN_CORE_3_0_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x0001
#define GL_RGBA32F 0x8814
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121

typedef void (CODEGEN_FUNCPTR * PFNGLCOLORMASKIPROC)(GLuint , GLboolean , GLboolean , GLboolean , GLboolean );
typedef void (CODEGEN_FUNCPTR * PFNGLGETBOOLEANI_VPROC)(GLenum , GLuint , GLboolean *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETINTEGERI_VPROC)(GLenum , GLuint , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLENABLEIPROC)(GLenum , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLDISABLEIPROC)(GLenum , GLuint );
typedef GLboolean (CODEGEN_FUNCPTR * PFNGLISENABLEDIPROC)(GLenum , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLBEGINTRANSFORMFEEDBACKPROC)(GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLENDTRANSFORMFEEDBACKPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLBINDBUFFERRANGEPROC)(GLenum , GLuint , GLuint , GLintptr , GLsizeiptr );
typedef void (CODEGEN_FUNCPTR * PFNGLBINDBUFFERBASEPROC)(GLenum , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLTRANSFORMFEEDBACKVARYINGSPROC)(GLuint , GLsizei , const GLchar* const *, GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)(GLuint , GLuint , GLsizei , GLsizei *, GLsizei *, GLenum *, GLchar *);
typedef void (CODEGEN_FUNCPTR * PFNGLCLAMPCOLORPROC)(GLenum , GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLBEGINCONDITIONALRENDERPROC)(GLuint , GLenum );
typedef void (CODEGEN_FUNCPTR * PFNGLENDCONDITIONALRENDERPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBIPOINTERPROC)(GLuint , GLint , GLenum , GLsizei , const GLvoid *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETVERTEXATTRIBIIVPROC)(GLuint , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETVERTEXATTRIBIUIVPROC)(GLuint , GLenum , GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI1IPROC)(GLuint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI2IPROC)(GLuint , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI3IPROC)(GLuint , GLint , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4IPROC)(GLuint , GLint , GLint , GLint , GLint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI1UIPROC)(GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI2UIPROC)(GLuint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI3UIPROC)(GLuint , GLuint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4UIPROC)(GLuint , GLuint , GLuint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI1IVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI2IVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI3IVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4IVPROC)(GLuint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI1UIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI2UIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI3UIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4UIVPROC)(GLuint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4BVPROC)(GLuint , const GLbyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4SVPROC)(GLuint , const GLshort *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4UBVPROC)(GLuint , const GLubyte *);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBI4USVPROC)(GLuint , const GLushort *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETUNIFORMUIVPROC)(GLuint , GLint , GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLBINDFRAGDATALOCATIONPROC)(GLuint , GLuint , const GLchar *);
typedef GLint (CODEGEN_FUNCPTR * PFNGLGETFRAGDATALOCATIONPROC)(GLuint , const GLchar *);
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM1UIPROC)(GLint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM2UIPROC)(GLint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM3UIPROC)(GLint , GLuint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM4UIPROC)(GLint , GLuint , GLuint , GLuint , GLuint );
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM1UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM2UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM3UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLUNIFORM4UIVPROC)(GLint , GLsizei , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERIIVPROC)(GLenum , GLenum , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERIUIVPROC)(GLenum , GLenum , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXPARAMETERIIVPROC)(GLenum , GLenum , GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXPARAMETERIUIVPROC)(GLenum , GLenum , GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARBUFFERIVPROC)(GLenum , GLint , const GLint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARBUFFERUIVPROC)(GLenum , GLint , const GLuint *);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARBUFFERFVPROC)(GLenum , GLint , const GLfloat *);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARBUFFERFIPROC)(GLenum , GLint , GLfloat , GLint );
typedef const GLubyte * (CODEGEN_FUNCPTR * PFNGLGETSTRINGIPROC)(GLenum , GLuint );

extern PFNGLCOLORMASKIPROC _funcptr_glColorMaski;
#define glColorMaski _funcptr_glColorMaski
extern PFNGLGETBOOLEANI_VPROC _funcptr_glGetBooleani_v;
#define glGetBooleani_v _funcptr_glGetBooleani_v
extern PFNGLGETINTEGERI_VPROC _funcptr_glGetIntegeri_v;
#define glGetIntegeri_v _funcptr_glGetIntegeri_v
extern PFNGLENABLEIPROC _funcptr_glEnablei;
#define glEnablei _funcptr_glEnablei
extern PFNGLDISABLEIPROC _funcptr_glDisablei;
#define glDisablei _funcptr_glDisablei
extern PFNGLISENABLEDIPROC _funcptr_glIsEnabledi;
#define glIsEnabledi _funcptr_glIsEnabledi
extern PFNGLBEGINTRANSFORMFEEDBACKPROC _funcptr_glBeginTransformFeedback;
#define glBeginTransformFeedback _funcptr_glBeginTransformFeedback
extern PFNGLENDTRANSFORMFEEDBACKPROC _funcptr_glEndTransformFeedback;
#define glEndTransformFeedback _funcptr_glEndTransformFeedback
extern PFNGLBINDBUFFERRANGEPROC _funcptr_glBindBufferRange;
#define glBindBufferRange _funcptr_glBindBufferRange
extern PFNGLBINDBUFFERBASEPROC _funcptr_glBindBufferBase;
#define glBindBufferBase _funcptr_glBindBufferBase
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC _funcptr_glTransformFeedbackVaryings;
#define glTransformFeedbackVaryings _funcptr_glTransformFeedbackVaryings
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC _funcptr_glGetTransformFeedbackVarying;
#define glGetTransformFeedbackVarying _funcptr_glGetTransformFeedbackVarying
extern PFNGLCLAMPCOLORPROC _funcptr_glClampColor;
#define glClampColor _funcptr_glClampColor
extern PFNGLBEGINCONDITIONALRENDERPROC _funcptr_glBeginConditionalRender;
#define glBeginConditionalRender _funcptr_glBeginConditionalRender
extern PFNGLENDCONDITIONALRENDERPROC _funcptr_glEndConditionalRender;
#define glEndConditionalRender _funcptr_glEndConditionalRender
extern PFNGLVERTEXATTRIBIPOINTERPROC _funcptr_glVertexAttribIPointer;
#define glVertexAttribIPointer _funcptr_glVertexAttribIPointer
extern PFNGLGETVERTEXATTRIBIIVPROC _funcptr_glGetVertexAttribIiv;
#define glGetVertexAttribIiv _funcptr_glGetVertexAttribIiv
extern PFNGLGETVERTEXATTRIBIUIVPROC _funcptr_glGetVertexAttribIuiv;
#define glGetVertexAttribIuiv _funcptr_glGetVertexAttribIuiv
extern PFNGLVERTEXATTRIBI1IPROC _funcptr_glVertexAttribI1i;
#define glVertexAttribI1i _funcptr_glVertexAttribI1i
extern PFNGLVERTEXATTRIBI2IPROC _funcptr_glVertexAttribI2i;
#define glVertexAttribI2i _funcptr_glVertexAttribI2i
extern PFNGLVERTEXATTRIBI3IPROC _funcptr_glVertexAttribI3i;
#define glVertexAttribI3i _funcptr_glVertexAttribI3i
extern PFNGLVERTEXATTRIBI4IPROC _funcptr_glVertexAttribI4i;
#define glVertexAttribI4i _funcptr_glVertexAttribI4i
extern PFNGLVERTEXATTRIBI1UIPROC _funcptr_glVertexAttribI1ui;
#define glVertexAttribI1ui _funcptr_glVertexAttribI1ui
extern PFNGLVERTEXATTRIBI2UIPROC _funcptr_glVertexAttribI2ui;
#define glVertexAttribI2ui _funcptr_glVertexAttribI2ui
extern PFNGLVERTEXATTRIBI3UIPROC _funcptr_glVertexAttribI3ui;
#define glVertexAttribI3ui _funcptr_glVertexAttribI3ui
extern PFNGLVERTEXATTRIBI4UIPROC _funcptr_glVertexAttribI4ui;
#define glVertexAttribI4ui _funcptr_glVertexAttribI4ui
extern PFNGLVERTEXATTRIBI1IVPROC _funcptr_glVertexAttribI1iv;
#define glVertexAttribI1iv _funcptr_glVertexAttribI1iv
extern PFNGLVERTEXATTRIBI2IVPROC _funcptr_glVertexAttribI2iv;
#define glVertexAttribI2iv _funcptr_glVertexAttribI2iv
extern PFNGLVERTEXATTRIBI3IVPROC _funcptr_glVertexAttribI3iv;
#define glVertexAttribI3iv _funcptr_glVertexAttribI3iv
extern PFNGLVERTEXATTRIBI4IVPROC _funcptr_glVertexAttribI4iv;
#define glVertexAttribI4iv _funcptr_glVertexAttribI4iv
extern PFNGLVERTEXATTRIBI1UIVPROC _funcptr_glVertexAttribI1uiv;
#define glVertexAttribI1uiv _funcptr_glVertexAttribI1uiv
extern PFNGLVERTEXATTRIBI2UIVPROC _funcptr_glVertexAttribI2uiv;
#define glVertexAttribI2uiv _funcptr_glVertexAttribI2uiv
extern PFNGLVERTEXATTRIBI3UIVPROC _funcptr_glVertexAttribI3uiv;
#define glVertexAttribI3uiv _funcptr_glVertexAttribI3uiv
extern PFNGLVERTEXATTRIBI4UIVPROC _funcptr_glVertexAttribI4uiv;
#define glVertexAttribI4uiv _funcptr_glVertexAttribI4uiv
extern PFNGLVERTEXATTRIBI4BVPROC _funcptr_glVertexAttribI4bv;
#define glVertexAttribI4bv _funcptr_glVertexAttribI4bv
extern PFNGLVERTEXATTRIBI4SVPROC _funcptr_glVertexAttribI4sv;
#define glVertexAttribI4sv _funcptr_glVertexAttribI4sv
extern PFNGLVERTEXATTRIBI4UBVPROC _funcptr_glVertexAttribI4ubv;
#define glVertexAttribI4ubv _funcptr_glVertexAttribI4ubv
extern PFNGLVERTEXATTRIBI4USVPROC _funcptr_glVertexAttribI4usv;
#define glVertexAttribI4usv _funcptr_glVertexAttribI4usv
extern PFNGLGETUNIFORMUIVPROC _funcptr_glGetUniformuiv;
#define glGetUniformuiv _funcptr_glGetUniformuiv
extern PFNGLBINDFRAGDATALOCATIONPROC _funcptr_glBindFragDataLocation;
#define glBindFragDataLocation _funcptr_glBindFragDataLocation
extern PFNGLGETFRAGDATALOCATIONPROC _funcptr_glGetFragDataLocation;
#define glGetFragDataLocation _funcptr_glGetFragDataLocation
extern PFNGLUNIFORM1UIPROC _funcptr_glUniform1ui;
#define glUniform1ui _funcptr_glUniform1ui
extern PFNGLUNIFORM2UIPROC _funcptr_glUniform2ui;
#define glUniform2ui _funcptr_glUniform2ui
extern PFNGLUNIFORM3UIPROC _funcptr_glUniform3ui;
#define glUniform3ui _funcptr_glUniform3ui
extern PFNGLUNIFORM4UIPROC _funcptr_glUniform4ui;
#define glUniform4ui _funcptr_glUniform4ui
extern PFNGLUNIFORM1UIVPROC _funcptr_glUniform1uiv;
#define glUniform1uiv _funcptr_glUniform1uiv
extern PFNGLUNIFORM2UIVPROC _funcptr_glUniform2uiv;
#define glUniform2uiv _funcptr_glUniform2uiv
extern PFNGLUNIFORM3UIVPROC _funcptr_glUniform3uiv;
#define glUniform3uiv _funcptr_glUniform3uiv
extern PFNGLUNIFORM4UIVPROC _funcptr_glUniform4uiv;
#define glUniform4uiv _funcptr_glUniform4uiv
extern PFNGLTEXPARAMETERIIVPROC _funcptr_glTexParameterIiv;
#define glTexParameterIiv _funcptr_glTexParameterIiv
extern PFNGLTEXPARAMETERIUIVPROC _funcptr_glTexParameterIuiv;
#define glTexParameterIuiv _funcptr_glTexParameterIuiv
extern PFNGLGETTEXPARAMETERIIVPROC _funcptr_glGetTexParameterIiv;
#define glGetTexParameterIiv _funcptr_glGetTexParameterIiv
extern PFNGLGETTEXPARAMETERIUIVPROC _funcptr_glGetTexParameterIuiv;
#define glGetTexParameterIuiv _funcptr_glGetTexParameterIuiv
extern PFNGLCLEARBUFFERIVPROC _funcptr_glClearBufferiv;
#define glClearBufferiv _funcptr_glClearBufferiv
extern PFNGLCLEARBUFFERUIVPROC _funcptr_glClearBufferuiv;
#define glClearBufferuiv _funcptr_glClearBufferuiv
extern PFNGLCLEARBUFFERFVPROC _funcptr_glClearBufferfv;
#define glClearBufferfv _funcptr_glClearBufferfv
extern PFNGLCLEARBUFFERFIPROC _funcptr_glClearBufferfi;
#define glClearBufferfi _funcptr_glClearBufferfi
extern PFNGLGETSTRINGIPROC _funcptr_glGetStringi;
#define glGetStringi _funcptr_glGetStringi

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_3_0_H*/
