#ifndef OPENGL_GEN_CORE_4_0_H
#define OPENGL_GEN_CORE_4_0_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS 0x8F9F
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F

typedef void (CODEGEN_FUNCPTR * PFNGLMINSAMPLESHADINGPROC)(GLfloat value);
typedef void (CODEGEN_FUNCPTR * PFNGLBLENDEQUATIONIPROC)(GLuint buf, GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLBLENDEQUATIONSEPARATEIPROC)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef void (CODEGEN_FUNCPTR * PFNGLBLENDFUNCIPROC)(GLuint buf, GLenum src, GLenum dst);
typedef void (CODEGEN_FUNCPTR * PFNGLBLENDFUNCSEPARATEIPROC)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

extern PFNGLMINSAMPLESHADINGPROC _funcptr_glMinSampleShading;
#define glMinSampleShading _funcptr_glMinSampleShading
extern PFNGLBLENDEQUATIONIPROC _funcptr_glBlendEquationi;
#define glBlendEquationi _funcptr_glBlendEquationi
extern PFNGLBLENDEQUATIONSEPARATEIPROC _funcptr_glBlendEquationSeparatei;
#define glBlendEquationSeparatei _funcptr_glBlendEquationSeparatei
extern PFNGLBLENDFUNCIPROC _funcptr_glBlendFunci;
#define glBlendFunci _funcptr_glBlendFunci
extern PFNGLBLENDFUNCSEPARATEIPROC _funcptr_glBlendFuncSeparatei;
#define glBlendFuncSeparatei _funcptr_glBlendFuncSeparatei

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_4_0_H*/
