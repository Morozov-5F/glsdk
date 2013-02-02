#ifndef OPENGL_GEN_CORE_3_1_HPP
#define OPENGL_GEN_CORE_3_1_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		SAMPLER_2D_RECT                  = 0x8B63,
		SAMPLER_2D_RECT_SHADOW           = 0x8B64,
		SAMPLER_BUFFER                   = 0x8DC2,
		INT_SAMPLER_2D_RECT              = 0x8DCD,
		INT_SAMPLER_BUFFER               = 0x8DD0,
		UNSIGNED_INT_SAMPLER_2D_RECT     = 0x8DD5,
		UNSIGNED_INT_SAMPLER_BUFFER      = 0x8DD8,
		MAX_TEXTURE_BUFFER_SIZE          = 0x8C2B,
		TEXTURE_BINDING_BUFFER           = 0x8C2C,
		TEXTURE_BUFFER_DATA_STORE_BINDING = 0x8C2D,
		TEXTURE_BINDING_RECTANGLE        = 0x84F6,
		PROXY_TEXTURE_RECTANGLE          = 0x84F7,
		MAX_RECTANGLE_TEXTURE_SIZE       = 0x84F8,
		PRIMITIVE_RESTART                = 0x8F9D,
		PRIMITIVE_RESTART_INDEX          = 0x8F9E,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices, GLsizei instancecount);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer);
		typedef void (CODEGEN_FUNCPTR * Proc_glPrimitiveRestartIndex)(GLuint index);
	}
	
	extern _detail::Proc_glDrawArraysInstanced DrawArraysInstanced;
	extern _detail::Proc_glDrawElementsInstanced DrawElementsInstanced;
	extern _detail::Proc_glTexBuffer TexBuffer;
	extern _detail::Proc_glPrimitiveRestartIndex PrimitiveRestartIndex;
	
}
#endif /*OPENGL_GEN_CORE_3_1_HPP*/
