#ifndef OPENGL_GEN_CORE_3_3_H
#define OPENGL_GEN_CORE_3_3_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE

typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXATTRIBDIVISORPROC)(GLuint index, GLuint divisor);

extern PFNGLVERTEXATTRIBDIVISORPROC _funcptr_glVertexAttribDivisor;
#define glVertexAttribDivisor _funcptr_glVertexAttribDivisor

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_3_3_H*/
