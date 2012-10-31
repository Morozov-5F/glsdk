#ifndef OPENGL_GEN_CORE_1_4_HPP
#define OPENGL_GEN_CORE_1_4_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		BLEND_DST_RGB                    = 0x80C8,
		BLEND_SRC_RGB                    = 0x80C9,
		BLEND_DST_ALPHA                  = 0x80CA,
		BLEND_SRC_ALPHA                  = 0x80CB,
		POINT_FADE_THRESHOLD_SIZE        = 0x8128,
		DEPTH_COMPONENT16                = 0x81A5,
		DEPTH_COMPONENT24                = 0x81A6,
		DEPTH_COMPONENT32                = 0x81A7,
		MIRRORED_REPEAT                  = 0x8370,
		MAX_TEXTURE_LOD_BIAS             = 0x84FD,
		TEXTURE_LOD_BIAS                 = 0x8501,
		INCR_WRAP                        = 0x8507,
		DECR_WRAP                        = 0x8508,
		TEXTURE_DEPTH_SIZE               = 0x884A,
		TEXTURE_COMPARE_MODE             = 0x884C,
		TEXTURE_COMPARE_FUNC             = 0x884D,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendFuncSeparate)(GLenum , GLenum , GLenum , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiDrawArrays)(GLenum , const GLint *, const GLsizei *, GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultiDrawElements)(GLenum , const GLsizei *, GLenum , const GLvoid* const *, GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glPointParameterf)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPointParameterfv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPointParameteri)(GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glPointParameteriv)(GLenum , const GLint *);
	}
	
	extern _detail::Proc_glBlendFuncSeparate BlendFuncSeparate;
	extern _detail::Proc_glMultiDrawArrays MultiDrawArrays;
	extern _detail::Proc_glMultiDrawElements MultiDrawElements;
	extern _detail::Proc_glPointParameterf PointParameterf;
	extern _detail::Proc_glPointParameterfv PointParameterfv;
	extern _detail::Proc_glPointParameteri PointParameteri;
	extern _detail::Proc_glPointParameteriv PointParameteriv;
	
}
#endif /*OPENGL_GEN_CORE_1_4_HPP*/
