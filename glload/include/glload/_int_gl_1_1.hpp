#ifndef OPENGL_GEN_CORE_1_1_HPP
#define OPENGL_GEN_CORE_1_1_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		DEPTH_BUFFER_BIT                 = 0x00000100,
		STENCIL_BUFFER_BIT               = 0x00000400,
		COLOR_BUFFER_BIT                 = 0x00004000,
		FALSE_                           = 0,
		TRUE_                            = 1,
		POINTS                           = 0x0000,
		LINES                            = 0x0001,
		LINE_LOOP                        = 0x0002,
		LINE_STRIP                       = 0x0003,
		TRIANGLE_STRIP                   = 0x0005,
		TRIANGLE_FAN                     = 0x0006,
		NEVER                            = 0x0200,
		LESS                             = 0x0201,
		LEQUAL                           = 0x0203,
		GREATER                          = 0x0204,
		NOTEQUAL                         = 0x0205,
		GEQUAL                           = 0x0206,
		ALWAYS                           = 0x0207,
		ONE                              = 1,
		SRC_COLOR                        = 0x0300,
		ONE_MINUS_SRC_COLOR              = 0x0301,
		SRC_ALPHA                        = 0x0302,
		ONE_MINUS_SRC_ALPHA              = 0x0303,
		DST_ALPHA                        = 0x0304,
		ONE_MINUS_DST_ALPHA              = 0x0305,
		DST_COLOR                        = 0x0306,
		ONE_MINUS_DST_COLOR              = 0x0307,
		SRC_ALPHA_SATURATE               = 0x0308,
		FRONT_LEFT                       = 0x0400,
		FRONT_RIGHT                      = 0x0401,
		BACK_LEFT                        = 0x0402,
		BACK_RIGHT                       = 0x0403,
		FRONT                            = 0x0404,
		BACK                             = 0x0405,
		LEFT                             = 0x0406,
		RIGHT                            = 0x0407,
		FRONT_AND_BACK                   = 0x0408,
		INVALID_ENUM                     = 0x0500,
		INVALID_VALUE                    = 0x0501,
		INVALID_OPERATION                = 0x0502,
		OUT_OF_MEMORY                    = 0x0505,
		POINT_SIZE                       = 0x0B11,
		POINT_SIZE_RANGE                 = 0x0B12,
		POINT_SIZE_GRANULARITY           = 0x0B13,
		LINE_SMOOTH                      = 0x0B20,
		LINE_WIDTH                       = 0x0B21,
		LINE_WIDTH_RANGE                 = 0x0B22,
		LINE_WIDTH_GRANULARITY           = 0x0B23,
		POLYGON_MODE                     = 0x0B40,
		POLYGON_SMOOTH                   = 0x0B41,
		CULL_FACE                        = 0x0B44,
		CULL_FACE_MODE                   = 0x0B45,
		FRONT_FACE                       = 0x0B46,
		DEPTH_TEST                       = 0x0B71,
		DEPTH_WRITEMASK                  = 0x0B72,
		DEPTH_CLEAR_VALUE                = 0x0B73,
		DEPTH_FUNC                       = 0x0B74,
		STENCIL_TEST                     = 0x0B90,
		STENCIL_CLEAR_VALUE              = 0x0B91,
		STENCIL_FUNC                     = 0x0B92,
		STENCIL_VALUE_MASK               = 0x0B93,
		STENCIL_FAIL                     = 0x0B94,
		STENCIL_PASS_DEPTH_FAIL          = 0x0B95,
		STENCIL_PASS_DEPTH_PASS          = 0x0B96,
		STENCIL_REF                      = 0x0B97,
		STENCIL_WRITEMASK                = 0x0B98,
		DITHER                           = 0x0BD0,
		BLEND_DST                        = 0x0BE0,
		BLEND_SRC                        = 0x0BE1,
		BLEND                            = 0x0BE2,
		LOGIC_OP_MODE                    = 0x0BF0,
		COLOR_LOGIC_OP                   = 0x0BF2,
		DRAW_BUFFER                      = 0x0C01,
		READ_BUFFER                      = 0x0C02,
		COLOR_CLEAR_VALUE                = 0x0C22,
		COLOR_WRITEMASK                  = 0x0C23,
		DOUBLEBUFFER                     = 0x0C32,
		STEREO                           = 0x0C33,
		LINE_SMOOTH_HINT                 = 0x0C52,
		POLYGON_SMOOTH_HINT              = 0x0C53,
		UNPACK_SWAP_BYTES                = 0x0CF0,
		UNPACK_LSB_FIRST                 = 0x0CF1,
		UNPACK_ROW_LENGTH                = 0x0CF2,
		UNPACK_SKIP_ROWS                 = 0x0CF3,
		UNPACK_SKIP_PIXELS               = 0x0CF4,
		UNPACK_ALIGNMENT                 = 0x0CF5,
		PACK_SWAP_BYTES                  = 0x0D00,
		PACK_LSB_FIRST                   = 0x0D01,
		PACK_ROW_LENGTH                  = 0x0D02,
		PACK_SKIP_ROWS                   = 0x0D03,
		PACK_SKIP_PIXELS                 = 0x0D04,
		PACK_ALIGNMENT                   = 0x0D05,
		MAX_TEXTURE_SIZE                 = 0x0D33,
		MAX_VIEWPORT_DIMS                = 0x0D3A,
		SUBPIXEL_BITS                    = 0x0D50,
		POLYGON_OFFSET_UNITS             = 0x2A00,
		POLYGON_OFFSET_POINT             = 0x2A01,
		POLYGON_OFFSET_LINE              = 0x2A02,
		POLYGON_OFFSET_FILL              = 0x8037,
		POLYGON_OFFSET_FACTOR            = 0x8038,
		TEXTURE_BINDING_1D               = 0x8068,
		TEXTURE_BINDING_2D               = 0x8069,
		TEXTURE_WIDTH                    = 0x1000,
		TEXTURE_HEIGHT                   = 0x1001,
		TEXTURE_INTERNAL_FORMAT          = 0x1003,
		TEXTURE_BORDER_COLOR             = 0x1004,
		TEXTURE_RED_SIZE                 = 0x805C,
		TEXTURE_GREEN_SIZE               = 0x805D,
		TEXTURE_BLUE_SIZE                = 0x805E,
		TEXTURE_ALPHA_SIZE               = 0x805F,
		DONT_CARE                        = 0x1100,
		FASTEST                          = 0x1101,
		NICEST                           = 0x1102,
		BYTE                             = 0x1400,
		UNSIGNED_BYTE                    = 0x1401,
		SHORT                            = 0x1402,
		UNSIGNED_SHORT                   = 0x1403,
		INT                              = 0x1404,
		UNSIGNED_INT                     = 0x1405,
		FLOAT                            = 0x1406,
		CLEAR                            = 0x1500,
		AND                              = 0x1501,
		AND_REVERSE                      = 0x1502,
		COPY                             = 0x1503,
		AND_INVERTED                     = 0x1504,
		NOOP                             = 0x1505,
		XOR                              = 0x1506,
		OR                               = 0x1507,
		NOR                              = 0x1508,
		EQUIV                            = 0x1509,
		INVERT                           = 0x150A,
		OR_REVERSE                       = 0x150B,
		COPY_INVERTED                    = 0x150C,
		OR_INVERTED                      = 0x150D,
		NAND                             = 0x150E,
		SET                              = 0x150F,
		TEXTURE                          = 0x1702,
		COLOR                            = 0x1800,
		DEPTH                            = 0x1801,
		STENCIL                          = 0x1802,
		STENCIL_INDEX                    = 0x1901,
		DEPTH_COMPONENT                  = 0x1902,
		RED                              = 0x1903,
		GREEN                            = 0x1904,
		BLUE                             = 0x1905,
		ALPHA                            = 0x1906,
		RGB                              = 0x1907,
		RGBA                             = 0x1908,
		POINT                            = 0x1B00,
		LINE                             = 0x1B01,
		FILL                             = 0x1B02,
		KEEP                             = 0x1E00,
		REPLACE                          = 0x1E01,
		INCR                             = 0x1E02,
		DECR                             = 0x1E03,
		VENDOR                           = 0x1F00,
		RENDERER                         = 0x1F01,
		VERSION                          = 0x1F02,
		EXTENSIONS                       = 0x1F03,
		NEAREST                          = 0x2600,
		LINEAR                           = 0x2601,
		NEAREST_MIPMAP_NEAREST           = 0x2700,
		LINEAR_MIPMAP_NEAREST            = 0x2701,
		NEAREST_MIPMAP_LINEAR            = 0x2702,
		LINEAR_MIPMAP_LINEAR             = 0x2703,
		TEXTURE_MAG_FILTER               = 0x2800,
		TEXTURE_MIN_FILTER               = 0x2801,
		TEXTURE_WRAP_S                   = 0x2802,
		TEXTURE_WRAP_T                   = 0x2803,
		PROXY_TEXTURE_1D                 = 0x8063,
		PROXY_TEXTURE_2D                 = 0x8064,
		REPEAT                           = 0x2901,
		R3_G3_B2                         = 0x2A10,
		RGB4                             = 0x804F,
		RGB5                             = 0x8050,
		RGB8                             = 0x8051,
		RGB10                            = 0x8052,
		RGB12                            = 0x8053,
		RGB16                            = 0x8054,
		RGBA2                            = 0x8055,
		RGBA4                            = 0x8056,
		RGB5_A1                          = 0x8057,
		RGBA8                            = 0x8058,
		RGB10_A2                         = 0x8059,
		RGBA12                           = 0x805A,
		RGBA16                           = 0x805B,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glCullFace)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glFrontFace)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glHint)(GLenum target, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glLineWidth)(GLfloat width);
		typedef void (CODEGEN_FUNCPTR * Proc_glPointSize)(GLfloat size);
		typedef void (CODEGEN_FUNCPTR * Proc_glPolygonMode)(GLenum face, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameterf)(GLenum target, GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameteri)(GLenum target, GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexParameteriv)(GLenum target, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawBuffer)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glClear)(GLbitfield mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearStencil)(GLint s);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearDepth)(GLdouble depth);
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilMask)(GLuint mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glDepthMask)(GLboolean flag);
		typedef void (CODEGEN_FUNCPTR * Proc_glDisable)(GLenum cap);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnable)(GLenum cap);
		typedef void (CODEGEN_FUNCPTR * Proc_glFinish)();
		typedef void (CODEGEN_FUNCPTR * Proc_glFlush)();
		typedef void (CODEGEN_FUNCPTR * Proc_glBlendFunc)(GLenum sfactor, GLenum dfactor);
		typedef void (CODEGEN_FUNCPTR * Proc_glLogicOp)(GLenum opcode);
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilFunc)(GLenum func, GLint ref, GLuint mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass);
		typedef void (CODEGEN_FUNCPTR * Proc_glDepthFunc)(GLenum func);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelStoref)(GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelStorei)(GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glReadBuffer)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBooleanv)(GLenum pname, GLboolean *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetDoublev)(GLenum pname, GLdouble *params);
		typedef GLenum (CODEGEN_FUNCPTR * Proc_glGetError)();
		typedef void (CODEGEN_FUNCPTR * Proc_glGetFloatv)(GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetIntegerv)(GLenum pname, GLint *params);
		typedef const GLubyte * (CODEGEN_FUNCPTR * Proc_glGetString)(GLenum name);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexParameteriv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint *params);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsEnabled)(GLenum cap);
		typedef void (CODEGEN_FUNCPTR * Proc_glDepthRange)(GLdouble ren_near, GLdouble ren_far);
		typedef void (CODEGEN_FUNCPTR * Proc_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawArrays)(GLenum mode, GLint first, GLsizei count);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPointerv)(GLenum pname, GLvoid* *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glPolygonOffset)(GLfloat factor, GLfloat units);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glBindTexture)(GLenum target, GLuint texture);
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteTextures)(GLsizei n, const GLuint *textures);
		typedef void (CODEGEN_FUNCPTR * Proc_glGenTextures)(GLsizei n, GLuint *textures);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsTexture)(GLuint texture);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexub)(GLubyte c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexubv)(const GLubyte *c);
	}
	
	extern _detail::Proc_glCullFace CullFace;
	extern _detail::Proc_glFrontFace FrontFace;
	extern _detail::Proc_glHint Hint;
	extern _detail::Proc_glLineWidth LineWidth;
	extern _detail::Proc_glPointSize PointSize;
	extern _detail::Proc_glPolygonMode PolygonMode;
	extern _detail::Proc_glScissor Scissor;
	extern _detail::Proc_glTexParameterf TexParameterf;
	extern _detail::Proc_glTexParameterfv TexParameterfv;
	extern _detail::Proc_glTexParameteri TexParameteri;
	extern _detail::Proc_glTexParameteriv TexParameteriv;
	extern _detail::Proc_glTexImage1D TexImage1D;
	extern _detail::Proc_glTexImage2D TexImage2D;
	extern _detail::Proc_glDrawBuffer DrawBuffer;
	extern _detail::Proc_glClear Clear;
	extern _detail::Proc_glClearColor ClearColor;
	extern _detail::Proc_glClearStencil ClearStencil;
	extern _detail::Proc_glClearDepth ClearDepth;
	extern _detail::Proc_glStencilMask StencilMask;
	extern _detail::Proc_glColorMask ColorMask;
	extern _detail::Proc_glDepthMask DepthMask;
	extern _detail::Proc_glDisable Disable;
	extern _detail::Proc_glEnable Enable;
	extern _detail::Proc_glFinish Finish;
	extern _detail::Proc_glFlush Flush;
	extern _detail::Proc_glBlendFunc BlendFunc;
	extern _detail::Proc_glLogicOp LogicOp;
	extern _detail::Proc_glStencilFunc StencilFunc;
	extern _detail::Proc_glStencilOp StencilOp;
	extern _detail::Proc_glDepthFunc DepthFunc;
	extern _detail::Proc_glPixelStoref PixelStoref;
	extern _detail::Proc_glPixelStorei PixelStorei;
	extern _detail::Proc_glReadBuffer ReadBuffer;
	extern _detail::Proc_glReadPixels ReadPixels;
	extern _detail::Proc_glGetBooleanv GetBooleanv;
	extern _detail::Proc_glGetDoublev GetDoublev;
	extern _detail::Proc_glGetError GetError;
	extern _detail::Proc_glGetFloatv GetFloatv;
	extern _detail::Proc_glGetIntegerv GetIntegerv;
	extern _detail::Proc_glGetString GetString;
	extern _detail::Proc_glGetTexImage GetTexImage;
	extern _detail::Proc_glGetTexParameterfv GetTexParameterfv;
	extern _detail::Proc_glGetTexParameteriv GetTexParameteriv;
	extern _detail::Proc_glGetTexLevelParameterfv GetTexLevelParameterfv;
	extern _detail::Proc_glGetTexLevelParameteriv GetTexLevelParameteriv;
	extern _detail::Proc_glIsEnabled IsEnabled;
	extern _detail::Proc_glDepthRange DepthRange;
	extern _detail::Proc_glViewport Viewport;
	extern _detail::Proc_glDrawArrays DrawArrays;
	extern _detail::Proc_glDrawElements DrawElements;
	extern _detail::Proc_glGetPointerv GetPointerv;
	extern _detail::Proc_glPolygonOffset PolygonOffset;
	extern _detail::Proc_glCopyTexImage1D CopyTexImage1D;
	extern _detail::Proc_glCopyTexImage2D CopyTexImage2D;
	extern _detail::Proc_glCopyTexSubImage1D CopyTexSubImage1D;
	extern _detail::Proc_glCopyTexSubImage2D CopyTexSubImage2D;
	extern _detail::Proc_glTexSubImage1D TexSubImage1D;
	extern _detail::Proc_glTexSubImage2D TexSubImage2D;
	extern _detail::Proc_glBindTexture BindTexture;
	extern _detail::Proc_glDeleteTextures DeleteTextures;
	extern _detail::Proc_glGenTextures GenTextures;
	extern _detail::Proc_glIsTexture IsTexture;
	extern _detail::Proc_glIndexub Indexub;
	extern _detail::Proc_glIndexubv Indexubv;
	
}
#endif /*OPENGL_GEN_CORE_1_1_HPP*/
