#ifndef OPENGL_GEN_CORE_1_2_HPP
#define OPENGL_GEN_CORE_1_2_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		UNSIGNED_BYTE_3_3_2              = 0x8032,
		UNSIGNED_SHORT_4_4_4_4           = 0x8033,
		UNSIGNED_SHORT_5_5_5_1           = 0x8034,
		UNSIGNED_INT_8_8_8_8             = 0x8035,
		UNSIGNED_INT_10_10_10_2          = 0x8036,
		TEXTURE_BINDING_3D               = 0x806A,
		PACK_SKIP_IMAGES                 = 0x806B,
		PACK_IMAGE_HEIGHT                = 0x806C,
		UNPACK_SKIP_IMAGES               = 0x806D,
		UNPACK_IMAGE_HEIGHT              = 0x806E,
		PROXY_TEXTURE_3D                 = 0x8070,
		TEXTURE_DEPTH                    = 0x8071,
		TEXTURE_WRAP_R                   = 0x8072,
		MAX_3D_TEXTURE_SIZE              = 0x8073,
		UNSIGNED_BYTE_2_3_3_REV          = 0x8362,
		UNSIGNED_SHORT_5_6_5             = 0x8363,
		UNSIGNED_SHORT_5_6_5_REV         = 0x8364,
		UNSIGNED_SHORT_4_4_4_4_REV       = 0x8365,
		UNSIGNED_SHORT_1_5_5_5_REV       = 0x8366,
		UNSIGNED_INT_8_8_8_8_REV         = 0x8367,
		BGR                              = 0x80E0,
		MAX_ELEMENTS_VERTICES            = 0x80E8,
		MAX_ELEMENTS_INDICES             = 0x80E9,
		CLAMP_TO_EDGE                    = 0x812F,
		TEXTURE_MIN_LOD                  = 0x813A,
		TEXTURE_MAX_LOD                  = 0x813B,
		TEXTURE_BASE_LEVEL               = 0x813C,
		TEXTURE_MAX_LEVEL                = 0x813D,
		SMOOTH_POINT_SIZE_RANGE          = 0x0B12,
		SMOOTH_POINT_SIZE_GRANULARITY    = 0x0B13,
		SMOOTH_LINE_WIDTH_RANGE          = 0x0B22,
		SMOOTH_LINE_WIDTH_GRANULARITY    = 0x0B23,
		ALIASED_LINE_WIDTH_RANGE         = 0x846E,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendEquation)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid *indices);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
	}
	
	extern _detail::Proc_glBlendColor BlendColor;
	extern _detail::Proc_glBlendEquation BlendEquation;
	extern _detail::Proc_glDrawRangeElements DrawRangeElements;
	extern _detail::Proc_glTexImage3D TexImage3D;
	extern _detail::Proc_glTexSubImage3D TexSubImage3D;
	extern _detail::Proc_glCopyTexSubImage3D CopyTexSubImage3D;
	
}
#endif /*OPENGL_GEN_CORE_1_2_HPP*/
