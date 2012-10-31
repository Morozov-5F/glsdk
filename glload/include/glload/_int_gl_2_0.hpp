#ifndef OPENGL_GEN_CORE_2_0_HPP
#define OPENGL_GEN_CORE_2_0_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		BLEND_EQUATION_RGB               = 0x8009,
		VERTEX_ATTRIB_ARRAY_ENABLED      = 0x8622,
		VERTEX_ATTRIB_ARRAY_SIZE         = 0x8623,
		VERTEX_ATTRIB_ARRAY_STRIDE       = 0x8624,
		VERTEX_ATTRIB_ARRAY_TYPE         = 0x8625,
		CURRENT_VERTEX_ATTRIB            = 0x8626,
		VERTEX_PROGRAM_POINT_SIZE        = 0x8642,
		VERTEX_ATTRIB_ARRAY_POINTER      = 0x8645,
		STENCIL_BACK_FUNC                = 0x8800,
		STENCIL_BACK_FAIL                = 0x8801,
		STENCIL_BACK_PASS_DEPTH_FAIL     = 0x8802,
		STENCIL_BACK_PASS_DEPTH_PASS     = 0x8803,
		MAX_DRAW_BUFFERS                 = 0x8824,
		DRAW_BUFFER0                     = 0x8825,
		DRAW_BUFFER1                     = 0x8826,
		DRAW_BUFFER2                     = 0x8827,
		DRAW_BUFFER3                     = 0x8828,
		DRAW_BUFFER4                     = 0x8829,
		DRAW_BUFFER5                     = 0x882A,
		DRAW_BUFFER6                     = 0x882B,
		DRAW_BUFFER7                     = 0x882C,
		DRAW_BUFFER8                     = 0x882D,
		DRAW_BUFFER9                     = 0x882E,
		DRAW_BUFFER10                    = 0x882F,
		DRAW_BUFFER11                    = 0x8830,
		DRAW_BUFFER12                    = 0x8831,
		DRAW_BUFFER13                    = 0x8832,
		DRAW_BUFFER14                    = 0x8833,
		DRAW_BUFFER15                    = 0x8834,
		BLEND_EQUATION_ALPHA             = 0x883D,
		MAX_VERTEX_ATTRIBS               = 0x8869,
		VERTEX_ATTRIB_ARRAY_NORMALIZED   = 0x886A,
		MAX_TEXTURE_IMAGE_UNITS          = 0x8872,
		FRAGMENT_SHADER                  = 0x8B30,
		VERTEX_SHADER                    = 0x8B31,
		MAX_FRAGMENT_UNIFORM_COMPONENTS  = 0x8B49,
		MAX_VERTEX_UNIFORM_COMPONENTS    = 0x8B4A,
		MAX_VARYING_FLOATS               = 0x8B4B,
		MAX_VERTEX_TEXTURE_IMAGE_UNITS   = 0x8B4C,
		MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
		SHADER_TYPE                      = 0x8B4F,
		FLOAT_VEC2                       = 0x8B50,
		FLOAT_VEC3                       = 0x8B51,
		FLOAT_VEC4                       = 0x8B52,
		INT_VEC2                         = 0x8B53,
		INT_VEC3                         = 0x8B54,
		INT_VEC4                         = 0x8B55,
		BOOL                             = 0x8B56,
		BOOL_VEC2                        = 0x8B57,
		BOOL_VEC3                        = 0x8B58,
		BOOL_VEC4                        = 0x8B59,
		FLOAT_MAT2                       = 0x8B5A,
		FLOAT_MAT3                       = 0x8B5B,
		FLOAT_MAT4                       = 0x8B5C,
		SAMPLER_1D                       = 0x8B5D,
		SAMPLER_2D                       = 0x8B5E,
		SAMPLER_3D                       = 0x8B5F,
		SAMPLER_CUBE                     = 0x8B60,
		SAMPLER_1D_SHADOW                = 0x8B61,
		SAMPLER_2D_SHADOW                = 0x8B62,
		DELETE_STATUS                    = 0x8B80,
		COMPILE_STATUS                   = 0x8B81,
		LINK_STATUS                      = 0x8B82,
		VALIDATE_STATUS                  = 0x8B83,
		INFO_LOG_LENGTH                  = 0x8B84,
		ATTACHED_SHADERS                 = 0x8B85,
		ACTIVE_UNIFORMS                  = 0x8B86,
		ACTIVE_UNIFORM_MAX_LENGTH        = 0x8B87,
		SHADER_SOURCE_LENGTH             = 0x8B88,
		ACTIVE_ATTRIBUTES                = 0x8B89,
		ACTIVE_ATTRIBUTE_MAX_LENGTH      = 0x8B8A,
		FRAGMENT_SHADER_DERIVATIVE_HINT  = 0x8B8B,
		SHADING_LANGUAGE_VERSION         = 0x8B8C,
		CURRENT_PROGRAM                  = 0x8B8D,
		POINT_SPRITE_COORD_ORIGIN        = 0x8CA0,
		LOWER_LEFT                       = 0x8CA1,
		UPPER_LEFT                       = 0x8CA2,
		STENCIL_BACK_REF                 = 0x8CA3,
		STENCIL_BACK_VALUE_MASK          = 0x8CA4,
		STENCIL_BACK_WRITEMASK           = 0x8CA5,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendEquationSeparate)(GLenum , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawBuffers)(GLsizei , const GLenum *);
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilOpSeparate)(GLenum , GLenum , GLenum , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilFuncSeparate)(GLenum , GLenum , GLint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilMaskSeparate)(GLenum , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glAttachShader)(GLuint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glBindAttribLocation)(GLuint , GLuint , const GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompileShader)(GLuint );
		typedef GLuint (CODEGEN_FUNCPTR * Proc_glCreateProgram)();
		typedef GLuint (CODEGEN_FUNCPTR * Proc_glCreateShader)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteProgram)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteShader)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glDetachShader)(GLuint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glDisableVertexAttribArray)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glEnableVertexAttribArray)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glGetActiveAttrib)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetActiveUniform)(GLuint , GLuint , GLsizei , GLsizei *, GLint *, GLenum *, GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetAttachedShaders)(GLuint , GLsizei , GLsizei *, GLuint *);
		typedef GLint (CODEGEN_FUNCPTR * Proc_glGetAttribLocation)(GLuint , const GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetProgramiv)(GLuint , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetProgramInfoLog)(GLuint , GLsizei , GLsizei *, GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetShaderiv)(GLuint , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetShaderInfoLog)(GLuint , GLsizei , GLsizei *, GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetShaderSource)(GLuint , GLsizei , GLsizei *, GLchar *);
		typedef GLint (CODEGEN_FUNCPTR * Proc_glGetUniformLocation)(GLuint , const GLchar *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetUniformfv)(GLuint , GLint , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetUniformiv)(GLuint , GLint , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribdv)(GLuint , GLenum , GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribfv)(GLuint , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribiv)(GLuint , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetVertexAttribPointerv)(GLuint , GLenum , GLvoid* *);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsProgram)(GLuint );
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsShader)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glLinkProgram)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glShaderSource)(GLuint , GLsizei , const GLchar* const *, const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUseProgram)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1f)(GLint , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2f)(GLint , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3f)(GLint , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4f)(GLint , GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1i)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3i)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4i)(GLint , GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1fv)(GLint , GLsizei , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2fv)(GLint , GLsizei , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3fv)(GLint , GLsizei , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4fv)(GLint , GLsizei , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform1iv)(GLint , GLsizei , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform2iv)(GLint , GLsizei , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform3iv)(GLint , GLsizei , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniform4iv)(GLint , GLsizei , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniformMatrix2fv)(GLint , GLsizei , GLboolean , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniformMatrix3fv)(GLint , GLsizei , GLboolean , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glUniformMatrix4fv)(GLint , GLsizei , GLboolean , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glValidateProgram)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribPointer)(GLuint , GLint , GLenum , GLboolean , GLsizei , const GLvoid *);
	}
	
	extern _detail::Proc_glBlendEquationSeparate BlendEquationSeparate;
	extern _detail::Proc_glDrawBuffers DrawBuffers;
	extern _detail::Proc_glStencilOpSeparate StencilOpSeparate;
	extern _detail::Proc_glStencilFuncSeparate StencilFuncSeparate;
	extern _detail::Proc_glStencilMaskSeparate StencilMaskSeparate;
	extern _detail::Proc_glAttachShader AttachShader;
	extern _detail::Proc_glBindAttribLocation BindAttribLocation;
	extern _detail::Proc_glCompileShader CompileShader;
	extern _detail::Proc_glCreateProgram CreateProgram;
	extern _detail::Proc_glCreateShader CreateShader;
	extern _detail::Proc_glDeleteProgram DeleteProgram;
	extern _detail::Proc_glDeleteShader DeleteShader;
	extern _detail::Proc_glDetachShader DetachShader;
	extern _detail::Proc_glDisableVertexAttribArray DisableVertexAttribArray;
	extern _detail::Proc_glEnableVertexAttribArray EnableVertexAttribArray;
	extern _detail::Proc_glGetActiveAttrib GetActiveAttrib;
	extern _detail::Proc_glGetActiveUniform GetActiveUniform;
	extern _detail::Proc_glGetAttachedShaders GetAttachedShaders;
	extern _detail::Proc_glGetAttribLocation GetAttribLocation;
	extern _detail::Proc_glGetProgramiv GetProgramiv;
	extern _detail::Proc_glGetProgramInfoLog GetProgramInfoLog;
	extern _detail::Proc_glGetShaderiv GetShaderiv;
	extern _detail::Proc_glGetShaderInfoLog GetShaderInfoLog;
	extern _detail::Proc_glGetShaderSource GetShaderSource;
	extern _detail::Proc_glGetUniformLocation GetUniformLocation;
	extern _detail::Proc_glGetUniformfv GetUniformfv;
	extern _detail::Proc_glGetUniformiv GetUniformiv;
	extern _detail::Proc_glGetVertexAttribdv GetVertexAttribdv;
	extern _detail::Proc_glGetVertexAttribfv GetVertexAttribfv;
	extern _detail::Proc_glGetVertexAttribiv GetVertexAttribiv;
	extern _detail::Proc_glGetVertexAttribPointerv GetVertexAttribPointerv;
	extern _detail::Proc_glIsProgram IsProgram;
	extern _detail::Proc_glIsShader IsShader;
	extern _detail::Proc_glLinkProgram LinkProgram;
	extern _detail::Proc_glShaderSource ShaderSource;
	extern _detail::Proc_glUseProgram UseProgram;
	extern _detail::Proc_glUniform1f Uniform1f;
	extern _detail::Proc_glUniform2f Uniform2f;
	extern _detail::Proc_glUniform3f Uniform3f;
	extern _detail::Proc_glUniform4f Uniform4f;
	extern _detail::Proc_glUniform1i Uniform1i;
	extern _detail::Proc_glUniform2i Uniform2i;
	extern _detail::Proc_glUniform3i Uniform3i;
	extern _detail::Proc_glUniform4i Uniform4i;
	extern _detail::Proc_glUniform1fv Uniform1fv;
	extern _detail::Proc_glUniform2fv Uniform2fv;
	extern _detail::Proc_glUniform3fv Uniform3fv;
	extern _detail::Proc_glUniform4fv Uniform4fv;
	extern _detail::Proc_glUniform1iv Uniform1iv;
	extern _detail::Proc_glUniform2iv Uniform2iv;
	extern _detail::Proc_glUniform3iv Uniform3iv;
	extern _detail::Proc_glUniform4iv Uniform4iv;
	extern _detail::Proc_glUniformMatrix2fv UniformMatrix2fv;
	extern _detail::Proc_glUniformMatrix3fv UniformMatrix3fv;
	extern _detail::Proc_glUniformMatrix4fv UniformMatrix4fv;
	extern _detail::Proc_glValidateProgram ValidateProgram;
	extern _detail::Proc_glVertexAttribPointer VertexAttribPointer;
	
}
#endif /*OPENGL_GEN_CORE_2_0_HPP*/
