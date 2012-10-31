#ifndef OPENGL_GEN_CORE_1_3_HPP
#define OPENGL_GEN_CORE_1_3_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		TEXTURE0                         = 0x84C0,
		TEXTURE1                         = 0x84C1,
		TEXTURE2                         = 0x84C2,
		TEXTURE3                         = 0x84C3,
		TEXTURE4                         = 0x84C4,
		TEXTURE5                         = 0x84C5,
		TEXTURE6                         = 0x84C6,
		TEXTURE7                         = 0x84C7,
		TEXTURE8                         = 0x84C8,
		TEXTURE9                         = 0x84C9,
		TEXTURE10                        = 0x84CA,
		TEXTURE11                        = 0x84CB,
		TEXTURE12                        = 0x84CC,
		TEXTURE13                        = 0x84CD,
		TEXTURE14                        = 0x84CE,
		TEXTURE15                        = 0x84CF,
		TEXTURE16                        = 0x84D0,
		TEXTURE17                        = 0x84D1,
		TEXTURE18                        = 0x84D2,
		TEXTURE19                        = 0x84D3,
		TEXTURE20                        = 0x84D4,
		TEXTURE21                        = 0x84D5,
		TEXTURE22                        = 0x84D6,
		TEXTURE23                        = 0x84D7,
		TEXTURE24                        = 0x84D8,
		TEXTURE25                        = 0x84D9,
		TEXTURE26                        = 0x84DA,
		TEXTURE27                        = 0x84DB,
		TEXTURE28                        = 0x84DC,
		TEXTURE29                        = 0x84DD,
		TEXTURE30                        = 0x84DE,
		TEXTURE31                        = 0x84DF,
		ACTIVE_TEXTURE                   = 0x84E0,
		MULTISAMPLE                      = 0x809D,
		SAMPLE_ALPHA_TO_COVERAGE         = 0x809E,
		SAMPLE_ALPHA_TO_ONE              = 0x809F,
		SAMPLE_COVERAGE                  = 0x80A0,
		SAMPLE_BUFFERS                   = 0x80A8,
		SAMPLE_COVERAGE_VALUE            = 0x80AA,
		SAMPLE_COVERAGE_INVERT           = 0x80AB,
		TEXTURE_BINDING_CUBE_MAP         = 0x8514,
		TEXTURE_CUBE_MAP_POSITIVE_X      = 0x8515,
		TEXTURE_CUBE_MAP_NEGATIVE_X      = 0x8516,
		TEXTURE_CUBE_MAP_POSITIVE_Y      = 0x8517,
		TEXTURE_CUBE_MAP_NEGATIVE_Y      = 0x8518,
		TEXTURE_CUBE_MAP_POSITIVE_Z      = 0x8519,
		TEXTURE_CUBE_MAP_NEGATIVE_Z      = 0x851A,
		PROXY_TEXTURE_CUBE_MAP           = 0x851B,
		MAX_CUBE_MAP_TEXTURE_SIZE        = 0x851C,
		COMPRESSED_RGB                   = 0x84ED,
		COMPRESSED_RGBA                  = 0x84EE,
		TEXTURE_COMPRESSION_HINT         = 0x84EF,
		TEXTURE_COMPRESSED_IMAGE_SIZE    = 0x86A0,
		NUM_COMPRESSED_TEXTURE_FORMATS   = 0x86A2,
		COMPRESSED_TEXTURE_FORMATS       = 0x86A3,
		CLAMP_TO_BORDER                  = 0x812D,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glActiveTexture)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glSampleCoverage)(GLfloat , GLboolean );
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexImage3D)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexImage2D)(GLenum , GLint , GLenum , GLsizei , GLsizei , GLint , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexImage1D)(GLenum , GLint , GLenum , GLsizei , GLint , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexSubImage3D)(GLenum , GLint , GLint , GLint , GLint , GLsizei , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexSubImage2D)(GLenum , GLint , GLint , GLint , GLsizei , GLsizei , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCompressedTexSubImage1D)(GLenum , GLint , GLint , GLsizei , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetCompressedTexImage)(GLenum , GLint , GLvoid *);
	}
	
	extern _detail::Proc_glActiveTexture ActiveTexture;
	extern _detail::Proc_glSampleCoverage SampleCoverage;
	extern _detail::Proc_glCompressedTexImage3D CompressedTexImage3D;
	extern _detail::Proc_glCompressedTexImage2D CompressedTexImage2D;
	extern _detail::Proc_glCompressedTexImage1D CompressedTexImage1D;
	extern _detail::Proc_glCompressedTexSubImage3D CompressedTexSubImage3D;
	extern _detail::Proc_glCompressedTexSubImage2D CompressedTexSubImage2D;
	extern _detail::Proc_glCompressedTexSubImage1D CompressedTexSubImage1D;
	extern _detail::Proc_glGetCompressedTexImage GetCompressedTexImage;
	
}
#endif /*OPENGL_GEN_CORE_1_3_HPP*/
