#ifndef OPENGL_GEN_CORE_3_1_H
#define OPENGL_GEN_CORE_3_1_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E

typedef void (CODEGEN_FUNCPTR * PFNGLDRAWARRAYSINSTANCEDPROC)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef void (CODEGEN_FUNCPTR * PFNGLDRAWELEMENTSINSTANCEDPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXBUFFERPROC)(GLenum target, GLenum internalformat, GLuint buffer);
typedef void (CODEGEN_FUNCPTR * PFNGLPRIMITIVERESTARTINDEXPROC)(GLuint index);

extern PFNGLDRAWARRAYSINSTANCEDPROC _funcptr_glDrawArraysInstanced;
#define glDrawArraysInstanced _funcptr_glDrawArraysInstanced
extern PFNGLDRAWELEMENTSINSTANCEDPROC _funcptr_glDrawElementsInstanced;
#define glDrawElementsInstanced _funcptr_glDrawElementsInstanced
extern PFNGLTEXBUFFERPROC _funcptr_glTexBuffer;
#define glTexBuffer _funcptr_glTexBuffer
extern PFNGLPRIMITIVERESTARTINDEXPROC _funcptr_glPrimitiveRestartIndex;
#define glPrimitiveRestartIndex _funcptr_glPrimitiveRestartIndex

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_3_1_H*/
