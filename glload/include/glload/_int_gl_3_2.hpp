#ifndef OPENGL_GEN_CORE_3_2_HPP
#define OPENGL_GEN_CORE_3_2_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		CONTEXT_CORE_PROFILE_BIT         = 0x00000001,
		CONTEXT_COMPATIBILITY_PROFILE_BIT = 0x00000002,
		LINES_ADJACENCY                  = 0x000A,
		LINE_STRIP_ADJACENCY             = 0x000B,
		TRIANGLES_ADJACENCY              = 0x000C,
		TRIANGLE_STRIP_ADJACENCY         = 0x000D,
		PROGRAM_POINT_SIZE               = 0x8642,
		MAX_GEOMETRY_TEXTURE_IMAGE_UNITS = 0x8C29,
		FRAMEBUFFER_ATTACHMENT_LAYERED   = 0x8DA7,
		FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS = 0x8DA8,
		GEOMETRY_SHADER                  = 0x8DD9,
		GEOMETRY_VERTICES_OUT            = 0x8916,
		GEOMETRY_INPUT_TYPE              = 0x8917,
		GEOMETRY_OUTPUT_TYPE             = 0x8918,
		MAX_GEOMETRY_UNIFORM_COMPONENTS  = 0x8DDF,
		MAX_GEOMETRY_OUTPUT_VERTICES     = 0x8DE0,
		MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS = 0x8DE1,
		MAX_VERTEX_OUTPUT_COMPONENTS     = 0x9122,
		MAX_GEOMETRY_INPUT_COMPONENTS    = 0x9123,
		MAX_GEOMETRY_OUTPUT_COMPONENTS   = 0x9124,
		MAX_FRAGMENT_INPUT_COMPONENTS    = 0x9125,
		CONTEXT_PROFILE_MASK             = 0x9126,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 *data);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level);
	}
	
	extern _detail::Proc_glGetInteger64i_v GetInteger64i_v;
	extern _detail::Proc_glGetBufferParameteri64v GetBufferParameteri64v;
	extern _detail::Proc_glFramebufferTexture FramebufferTexture;
	
}
#endif /*OPENGL_GEN_CORE_3_2_HPP*/
