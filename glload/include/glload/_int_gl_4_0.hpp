#ifndef OPENGL_GEN_CORE_4_0_HPP
#define OPENGL_GEN_CORE_4_0_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		SAMPLE_SHADING                   = 0x8C36,
		MIN_SAMPLE_SHADING_VALUE         = 0x8C37,
		MIN_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5E,
		MAX_PROGRAM_TEXTURE_GATHER_OFFSET = 0x8E5F,
		MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS = 0x8F9F,
		TEXTURE_BINDING_CUBE_MAP_ARRAY   = 0x900A,
		PROXY_TEXTURE_CUBE_MAP_ARRAY     = 0x900B,
		SAMPLER_CUBE_MAP_ARRAY           = 0x900C,
		SAMPLER_CUBE_MAP_ARRAY_SHADOW    = 0x900D,
		INT_SAMPLER_CUBE_MAP_ARRAY       = 0x900E,
		UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY = 0x900F,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glMinSampleShading)(GLfloat value);
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendEquationi)(GLuint buf, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendFunci)(GLuint buf, GLenum src, GLenum dst);
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
	}
	
	extern _detail::Proc_glMinSampleShading MinSampleShading;
	extern _detail::Proc_glBlendEquationi BlendEquationi;
	extern _detail::Proc_glBlendEquationSeparatei BlendEquationSeparatei;
	extern _detail::Proc_glBlendFunci BlendFunci;
	extern _detail::Proc_glBlendFuncSeparatei BlendFuncSeparatei;
	
}
#endif /*OPENGL_GEN_CORE_4_0_HPP*/
