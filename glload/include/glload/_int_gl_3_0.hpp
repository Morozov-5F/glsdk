#ifndef OPENGL_GEN_CORE_3_0_HPP
#define OPENGL_GEN_CORE_3_0_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		COMPARE_REF_TO_TEXTURE           = 0x884E,
		CLIP_DISTANCE0                   = 0x3000,
		CLIP_DISTANCE1                   = 0x3001,
		CLIP_DISTANCE2                   = 0x3002,
		CLIP_DISTANCE3                   = 0x3003,
		CLIP_DISTANCE4                   = 0x3004,
		CLIP_DISTANCE5                   = 0x3005,
		CLIP_DISTANCE6                   = 0x3006,
		CLIP_DISTANCE7                   = 0x3007,
		MAX_CLIP_DISTANCES               = 0x0D32,
		MAJOR_VERSION                    = 0x821B,
		MINOR_VERSION                    = 0x821C,
		NUM_EXTENSIONS                   = 0x821D,
		CONTEXT_FLAGS                    = 0x821E,
		COMPRESSED_RED                   = 0x8225,
		COMPRESSED_RG                    = 0x8226,
		CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT = 0x00000001,
		RGBA32F                          = 0x8814,
		RGBA16F                          = 0x881A,
		RGB16F                           = 0x881B,
		VERTEX_ATTRIB_ARRAY_INTEGER      = 0x88FD,
		MAX_ARRAY_TEXTURE_LAYERS         = 0x88FF,
		MIN_PROGRAM_TEXEL_OFFSET         = 0x8904,
		MAX_PROGRAM_TEXEL_OFFSET         = 0x8905,
		CLAMP_READ_COLOR                 = 0x891C,
		FIXED_ONLY                       = 0x891D,
		PROXY_TEXTURE_1D_ARRAY           = 0x8C19,
		PROXY_TEXTURE_2D_ARRAY           = 0x8C1B,
		TEXTURE_BINDING_1D_ARRAY         = 0x8C1C,
		TEXTURE_BINDING_2D_ARRAY         = 0x8C1D,
		R11F_G11F_B10F                   = 0x8C3A,
		UNSIGNED_INT_10F_11F_11F_REV     = 0x8C3B,
		RGB9_E5                          = 0x8C3D,
		UNSIGNED_INT_5_9_9_9_REV         = 0x8C3E,
		TEXTURE_SHARED_SIZE              = 0x8C3F,
		TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76,
		TRANSFORM_FEEDBACK_BUFFER_MODE   = 0x8C7F,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
		TRANSFORM_FEEDBACK_VARYINGS      = 0x8C83,
		TRANSFORM_FEEDBACK_BUFFER_START  = 0x8C84,
		TRANSFORM_FEEDBACK_BUFFER_SIZE   = 0x8C85,
		PRIMITIVES_GENERATED             = 0x8C87,
		TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
		RASTERIZER_DISCARD               = 0x8C89,
		MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
		MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
		INTERLEAVED_ATTRIBS              = 0x8C8C,
		SEPARATE_ATTRIBS                 = 0x8C8D,
		TRANSFORM_FEEDBACK_BUFFER        = 0x8C8E,
		TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
		RGBA32UI                         = 0x8D70,
		RGBA16UI                         = 0x8D76,
		RGB16UI                          = 0x8D77,
		RGBA8UI                          = 0x8D7C,
		RGB8UI                           = 0x8D7D,
		RGBA32I                          = 0x8D82,
		RGBA16I                          = 0x8D88,
		RGB16I                           = 0x8D89,
		RGBA8I                           = 0x8D8E,
		RGB8I                            = 0x8D8F,
		RED_INTEGER                      = 0x8D94,
		GREEN_INTEGER                    = 0x8D95,
		BLUE_INTEGER                     = 0x8D96,
		RGB_INTEGER                      = 0x8D98,
		RGBA_INTEGER                     = 0x8D99,
		BGR_INTEGER                      = 0x8D9A,
		BGRA_INTEGER                     = 0x8D9B,
		SAMPLER_1D_ARRAY                 = 0x8DC0,
		SAMPLER_2D_ARRAY                 = 0x8DC1,
		SAMPLER_1D_ARRAY_SHADOW          = 0x8DC3,
		SAMPLER_2D_ARRAY_SHADOW          = 0x8DC4,
		SAMPLER_CUBE_SHADOW              = 0x8DC5,
		UNSIGNED_INT_VEC2                = 0x8DC6,
		UNSIGNED_INT_VEC3                = 0x8DC7,
		UNSIGNED_INT_VEC4                = 0x8DC8,
		INT_SAMPLER_1D                   = 0x8DC9,
		INT_SAMPLER_2D                   = 0x8DCA,
		INT_SAMPLER_3D                   = 0x8DCB,
		INT_SAMPLER_CUBE                 = 0x8DCC,
		INT_SAMPLER_1D_ARRAY             = 0x8DCE,
		INT_SAMPLER_2D_ARRAY             = 0x8DCF,
		UNSIGNED_INT_SAMPLER_1D          = 0x8DD1,
		UNSIGNED_INT_SAMPLER_2D          = 0x8DD2,
		UNSIGNED_INT_SAMPLER_3D          = 0x8DD3,
		UNSIGNED_INT_SAMPLER_CUBE        = 0x8DD4,
		UNSIGNED_INT_SAMPLER_1D_ARRAY    = 0x8DD6,
		UNSIGNED_INT_SAMPLER_2D_ARRAY    = 0x8DD7,
		QUERY_WAIT                       = 0x8E13,
		QUERY_NO_WAIT                    = 0x8E14,
		QUERY_BY_REGION_WAIT             = 0x8E15,
		QUERY_BY_REGION_NO_WAIT          = 0x8E16,
		BUFFER_ACCESS_FLAGS              = 0x911F,
		BUFFER_MAP_LENGTH                = 0x9120,
		BUFFER_MAP_OFFSET                = 0x9121,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBooleani_v)(GLenum target, GLuint index, GLboolean *data);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetIntegeri_v)(GLenum target, GLuint index, GLint *data);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnablei)(GLenum target, GLuint index);
		typedef void (CODEGEN_FUNCPTR * Proc_glDisablei)(GLenum target, GLuint index);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsEnabledi)(GLenum target, GLuint index);
		typedef void (CODEGEN_FUNCPTR * Proc_glBeginTransformFeedback)(GLenum primitiveMode);
		typedef void (CODEGEN_FUNCPTR * Proc_glEndTransformFeedback)();
		typedef void (CODEGEN_FUNCPTR * Proc_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
		typedef void (CODEGEN_FUNCPTR * Proc_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer);
		typedef void (CODEGEN_FUNCPTR * Proc_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar* const *varyings, GLenum bufferMode);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
		typedef void (CODEGEN_FUNCPTR * Proc_glClampColor)(GLenum target, GLenum clamp);
		typedef void (CODEGEN_FUNCPTR * Proc_glBeginConditionalRender)(GLuint id, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glEndConditionalRender)();
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI1i)(GLuint index, GLint x);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI2i)(GLuint index, GLint x, GLint y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI1ui)(GLuint index, GLuint x);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI1iv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI2iv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI3iv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4iv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI1uiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI2uiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI3uiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4uiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4bv)(GLuint index, const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4sv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4ubv)(GLuint index, const GLubyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribI4usv)(GLuint index, const GLushort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetUniformuiv)(GLuint program, GLint location, GLuint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar *name);
		typedef GLint (CODEGEN_FUNCPTR * Proc_glGetFragDataLocation)(GLuint program, const GLchar *name);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1ui)(GLint location, GLuint v0);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2ui)(GLint location, GLuint v0, GLuint v1);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1uiv)(GLint location, GLsizei count, const GLuint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2uiv)(GLint location, GLsizei count, const GLuint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3uiv)(GLint location, GLsizei count, const GLuint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4uiv)(GLint location, GLsizei count, const GLuint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameterIiv)(GLenum target, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat *value);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
		typedef const GLubyte * (CODEGEN_FUNCPTR * Proc_glGetStringi)(GLenum name, GLuint index);
	}
	
	extern _detail::Proc_glColorMaski ColorMaski;
	extern _detail::Proc_glGetBooleani_v GetBooleani_v;
	extern _detail::Proc_glGetIntegeri_v GetIntegeri_v;
	extern _detail::Proc_glEnablei Enablei;
	extern _detail::Proc_glDisablei Disablei;
	extern _detail::Proc_glIsEnabledi IsEnabledi;
	extern _detail::Proc_glBeginTransformFeedback BeginTransformFeedback;
	extern _detail::Proc_glEndTransformFeedback EndTransformFeedback;
	extern _detail::Proc_glBindBufferRange BindBufferRange;
	extern _detail::Proc_glBindBufferBase BindBufferBase;
	extern _detail::Proc_glTransformFeedbackVaryings TransformFeedbackVaryings;
	extern _detail::Proc_glGetTransformFeedbackVarying GetTransformFeedbackVarying;
	extern _detail::Proc_glClampColor ClampColor;
	extern _detail::Proc_glBeginConditionalRender BeginConditionalRender;
	extern _detail::Proc_glEndConditionalRender EndConditionalRender;
	extern _detail::Proc_glVertexAttribIPointer VertexAttribIPointer;
	extern _detail::Proc_glGetVertexAttribIiv GetVertexAttribIiv;
	extern _detail::Proc_glGetVertexAttribIuiv GetVertexAttribIuiv;
	extern _detail::Proc_glVertexAttribI1i VertexAttribI1i;
	extern _detail::Proc_glVertexAttribI2i VertexAttribI2i;
	extern _detail::Proc_glVertexAttribI3i VertexAttribI3i;
	extern _detail::Proc_glVertexAttribI4i VertexAttribI4i;
	extern _detail::Proc_glVertexAttribI1ui VertexAttribI1ui;
	extern _detail::Proc_glVertexAttribI2ui VertexAttribI2ui;
	extern _detail::Proc_glVertexAttribI3ui VertexAttribI3ui;
	extern _detail::Proc_glVertexAttribI4ui VertexAttribI4ui;
	extern _detail::Proc_glVertexAttribI1iv VertexAttribI1iv;
	extern _detail::Proc_glVertexAttribI2iv VertexAttribI2iv;
	extern _detail::Proc_glVertexAttribI3iv VertexAttribI3iv;
	extern _detail::Proc_glVertexAttribI4iv VertexAttribI4iv;
	extern _detail::Proc_glVertexAttribI1uiv VertexAttribI1uiv;
	extern _detail::Proc_glVertexAttribI2uiv VertexAttribI2uiv;
	extern _detail::Proc_glVertexAttribI3uiv VertexAttribI3uiv;
	extern _detail::Proc_glVertexAttribI4uiv VertexAttribI4uiv;
	extern _detail::Proc_glVertexAttribI4bv VertexAttribI4bv;
	extern _detail::Proc_glVertexAttribI4sv VertexAttribI4sv;
	extern _detail::Proc_glVertexAttribI4ubv VertexAttribI4ubv;
	extern _detail::Proc_glVertexAttribI4usv VertexAttribI4usv;
	extern _detail::Proc_glGetUniformuiv GetUniformuiv;
	extern _detail::Proc_glBindFragDataLocation BindFragDataLocation;
	extern _detail::Proc_glGetFragDataLocation GetFragDataLocation;
	extern _detail::Proc_glUniform1ui Uniform1ui;
	extern _detail::Proc_glUniform2ui Uniform2ui;
	extern _detail::Proc_glUniform3ui Uniform3ui;
	extern _detail::Proc_glUniform4ui Uniform4ui;
	extern _detail::Proc_glUniform1uiv Uniform1uiv;
	extern _detail::Proc_glUniform2uiv Uniform2uiv;
	extern _detail::Proc_glUniform3uiv Uniform3uiv;
	extern _detail::Proc_glUniform4uiv Uniform4uiv;
	extern _detail::Proc_glTexParameterIiv TexParameterIiv;
	extern _detail::Proc_glTexParameterIuiv TexParameterIuiv;
	extern _detail::Proc_glGetTexParameterIiv GetTexParameterIiv;
	extern _detail::Proc_glGetTexParameterIuiv GetTexParameterIuiv;
	extern _detail::Proc_glClearBufferiv ClearBufferiv;
	extern _detail::Proc_glClearBufferuiv ClearBufferuiv;
	extern _detail::Proc_glClearBufferfv ClearBufferfv;
	extern _detail::Proc_glClearBufferfi ClearBufferfi;
	extern _detail::Proc_glGetStringi GetStringi;
	
}
#endif /*OPENGL_GEN_CORE_3_0_HPP*/
