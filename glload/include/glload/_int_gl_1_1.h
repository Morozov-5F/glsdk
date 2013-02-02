#ifndef OPENGL_GEN_CORE_1_1_H
#define OPENGL_GEN_CORE_1_1_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_REPEAT 0x2901
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B

typedef void (CODEGEN_FUNCPTR * PFNGLCULLFACEPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (CODEGEN_FUNCPTR * PFNGLPOINTSIZEPROC)(GLfloat size);
typedef void (CODEGEN_FUNCPTR * PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXIMAGE1DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLDRAWBUFFERPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARPROC)(GLbitfield mask);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARDEPTHPROC)(GLdouble depth);
typedef void (CODEGEN_FUNCPTR * PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (CODEGEN_FUNCPTR * PFNGLDISABLEPROC)(GLenum cap);
typedef void (CODEGEN_FUNCPTR * PFNGLENABLEPROC)(GLenum cap);
typedef void (CODEGEN_FUNCPTR * PFNGLFINISHPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLFLUSHPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (CODEGEN_FUNCPTR * PFNGLLOGICOPPROC)(GLenum opcode);
typedef void (CODEGEN_FUNCPTR * PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (CODEGEN_FUNCPTR * PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (CODEGEN_FUNCPTR * PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLREADBUFFERPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble *params);
typedef GLenum (CODEGEN_FUNCPTR * PFNGLGETERRORPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETINTEGERVPROC)(GLenum pname, GLint *params);
typedef const GLubyte * (CODEGEN_FUNCPTR * PFNGLGETSTRINGPROC)(GLenum name);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint *params);
typedef GLboolean (CODEGEN_FUNCPTR * PFNGLISENABLEDPROC)(GLenum cap);
typedef void (CODEGEN_FUNCPTR * PFNGLDEPTHRANGEPROC)(GLdouble ren_near, GLdouble ren_far);
typedef void (CODEGEN_FUNCPTR * PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (CODEGEN_FUNCPTR * PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (CODEGEN_FUNCPTR * PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
typedef void (CODEGEN_FUNCPTR * PFNGLGETPOINTERVPROC)(GLenum pname, GLvoid* *params);
typedef void (CODEGEN_FUNCPTR * PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYTEXIMAGE1DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXSUBIMAGE1DPROC)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (CODEGEN_FUNCPTR * PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (CODEGEN_FUNCPTR * PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef GLboolean (CODEGEN_FUNCPTR * PFNGLISTEXTUREPROC)(GLuint texture);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXUBPROC)(GLubyte c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXUBVPROC)(const GLubyte *c);

extern PFNGLCULLFACEPROC _funcptr_glCullFace;
#define glCullFace _funcptr_glCullFace
extern PFNGLFRONTFACEPROC _funcptr_glFrontFace;
#define glFrontFace _funcptr_glFrontFace
extern PFNGLHINTPROC _funcptr_glHint;
#define glHint _funcptr_glHint
extern PFNGLLINEWIDTHPROC _funcptr_glLineWidth;
#define glLineWidth _funcptr_glLineWidth
extern PFNGLPOINTSIZEPROC _funcptr_glPointSize;
#define glPointSize _funcptr_glPointSize
extern PFNGLPOLYGONMODEPROC _funcptr_glPolygonMode;
#define glPolygonMode _funcptr_glPolygonMode
extern PFNGLSCISSORPROC _funcptr_glScissor;
#define glScissor _funcptr_glScissor
extern PFNGLTEXPARAMETERFPROC _funcptr_glTexParameterf;
#define glTexParameterf _funcptr_glTexParameterf
extern PFNGLTEXPARAMETERFVPROC _funcptr_glTexParameterfv;
#define glTexParameterfv _funcptr_glTexParameterfv
extern PFNGLTEXPARAMETERIPROC _funcptr_glTexParameteri;
#define glTexParameteri _funcptr_glTexParameteri
extern PFNGLTEXPARAMETERIVPROC _funcptr_glTexParameteriv;
#define glTexParameteriv _funcptr_glTexParameteriv
extern PFNGLTEXIMAGE1DPROC _funcptr_glTexImage1D;
#define glTexImage1D _funcptr_glTexImage1D
extern PFNGLTEXIMAGE2DPROC _funcptr_glTexImage2D;
#define glTexImage2D _funcptr_glTexImage2D
extern PFNGLDRAWBUFFERPROC _funcptr_glDrawBuffer;
#define glDrawBuffer _funcptr_glDrawBuffer
extern PFNGLCLEARPROC _funcptr_glClear;
#define glClear _funcptr_glClear
extern PFNGLCLEARCOLORPROC _funcptr_glClearColor;
#define glClearColor _funcptr_glClearColor
extern PFNGLCLEARSTENCILPROC _funcptr_glClearStencil;
#define glClearStencil _funcptr_glClearStencil
extern PFNGLCLEARDEPTHPROC _funcptr_glClearDepth;
#define glClearDepth _funcptr_glClearDepth
extern PFNGLSTENCILMASKPROC _funcptr_glStencilMask;
#define glStencilMask _funcptr_glStencilMask
extern PFNGLCOLORMASKPROC _funcptr_glColorMask;
#define glColorMask _funcptr_glColorMask
extern PFNGLDEPTHMASKPROC _funcptr_glDepthMask;
#define glDepthMask _funcptr_glDepthMask
extern PFNGLDISABLEPROC _funcptr_glDisable;
#define glDisable _funcptr_glDisable
extern PFNGLENABLEPROC _funcptr_glEnable;
#define glEnable _funcptr_glEnable
extern PFNGLFINISHPROC _funcptr_glFinish;
#define glFinish _funcptr_glFinish
extern PFNGLFLUSHPROC _funcptr_glFlush;
#define glFlush _funcptr_glFlush
extern PFNGLBLENDFUNCPROC _funcptr_glBlendFunc;
#define glBlendFunc _funcptr_glBlendFunc
extern PFNGLLOGICOPPROC _funcptr_glLogicOp;
#define glLogicOp _funcptr_glLogicOp
extern PFNGLSTENCILFUNCPROC _funcptr_glStencilFunc;
#define glStencilFunc _funcptr_glStencilFunc
extern PFNGLSTENCILOPPROC _funcptr_glStencilOp;
#define glStencilOp _funcptr_glStencilOp
extern PFNGLDEPTHFUNCPROC _funcptr_glDepthFunc;
#define glDepthFunc _funcptr_glDepthFunc
extern PFNGLPIXELSTOREFPROC _funcptr_glPixelStoref;
#define glPixelStoref _funcptr_glPixelStoref
extern PFNGLPIXELSTOREIPROC _funcptr_glPixelStorei;
#define glPixelStorei _funcptr_glPixelStorei
extern PFNGLREADBUFFERPROC _funcptr_glReadBuffer;
#define glReadBuffer _funcptr_glReadBuffer
extern PFNGLREADPIXELSPROC _funcptr_glReadPixels;
#define glReadPixels _funcptr_glReadPixels
extern PFNGLGETBOOLEANVPROC _funcptr_glGetBooleanv;
#define glGetBooleanv _funcptr_glGetBooleanv
extern PFNGLGETDOUBLEVPROC _funcptr_glGetDoublev;
#define glGetDoublev _funcptr_glGetDoublev
extern PFNGLGETERRORPROC _funcptr_glGetError;
#define glGetError _funcptr_glGetError
extern PFNGLGETFLOATVPROC _funcptr_glGetFloatv;
#define glGetFloatv _funcptr_glGetFloatv
extern PFNGLGETINTEGERVPROC _funcptr_glGetIntegerv;
#define glGetIntegerv _funcptr_glGetIntegerv
extern PFNGLGETSTRINGPROC _funcptr_glGetString;
#define glGetString _funcptr_glGetString
extern PFNGLGETTEXIMAGEPROC _funcptr_glGetTexImage;
#define glGetTexImage _funcptr_glGetTexImage
extern PFNGLGETTEXPARAMETERFVPROC _funcptr_glGetTexParameterfv;
#define glGetTexParameterfv _funcptr_glGetTexParameterfv
extern PFNGLGETTEXPARAMETERIVPROC _funcptr_glGetTexParameteriv;
#define glGetTexParameteriv _funcptr_glGetTexParameteriv
extern PFNGLGETTEXLEVELPARAMETERFVPROC _funcptr_glGetTexLevelParameterfv;
#define glGetTexLevelParameterfv _funcptr_glGetTexLevelParameterfv
extern PFNGLGETTEXLEVELPARAMETERIVPROC _funcptr_glGetTexLevelParameteriv;
#define glGetTexLevelParameteriv _funcptr_glGetTexLevelParameteriv
extern PFNGLISENABLEDPROC _funcptr_glIsEnabled;
#define glIsEnabled _funcptr_glIsEnabled
extern PFNGLDEPTHRANGEPROC _funcptr_glDepthRange;
#define glDepthRange _funcptr_glDepthRange
extern PFNGLVIEWPORTPROC _funcptr_glViewport;
#define glViewport _funcptr_glViewport
extern PFNGLDRAWARRAYSPROC _funcptr_glDrawArrays;
#define glDrawArrays _funcptr_glDrawArrays
extern PFNGLDRAWELEMENTSPROC _funcptr_glDrawElements;
#define glDrawElements _funcptr_glDrawElements
extern PFNGLGETPOINTERVPROC _funcptr_glGetPointerv;
#define glGetPointerv _funcptr_glGetPointerv
extern PFNGLPOLYGONOFFSETPROC _funcptr_glPolygonOffset;
#define glPolygonOffset _funcptr_glPolygonOffset
extern PFNGLCOPYTEXIMAGE1DPROC _funcptr_glCopyTexImage1D;
#define glCopyTexImage1D _funcptr_glCopyTexImage1D
extern PFNGLCOPYTEXIMAGE2DPROC _funcptr_glCopyTexImage2D;
#define glCopyTexImage2D _funcptr_glCopyTexImage2D
extern PFNGLCOPYTEXSUBIMAGE1DPROC _funcptr_glCopyTexSubImage1D;
#define glCopyTexSubImage1D _funcptr_glCopyTexSubImage1D
extern PFNGLCOPYTEXSUBIMAGE2DPROC _funcptr_glCopyTexSubImage2D;
#define glCopyTexSubImage2D _funcptr_glCopyTexSubImage2D
extern PFNGLTEXSUBIMAGE1DPROC _funcptr_glTexSubImage1D;
#define glTexSubImage1D _funcptr_glTexSubImage1D
extern PFNGLTEXSUBIMAGE2DPROC _funcptr_glTexSubImage2D;
#define glTexSubImage2D _funcptr_glTexSubImage2D
extern PFNGLBINDTEXTUREPROC _funcptr_glBindTexture;
#define glBindTexture _funcptr_glBindTexture
extern PFNGLDELETETEXTURESPROC _funcptr_glDeleteTextures;
#define glDeleteTextures _funcptr_glDeleteTextures
extern PFNGLGENTEXTURESPROC _funcptr_glGenTextures;
#define glGenTextures _funcptr_glGenTextures
extern PFNGLISTEXTUREPROC _funcptr_glIsTexture;
#define glIsTexture _funcptr_glIsTexture
extern PFNGLINDEXUBPROC _funcptr_glIndexub;
#define glIndexub _funcptr_glIndexub
extern PFNGLINDEXUBVPROC _funcptr_glIndexubv;
#define glIndexubv _funcptr_glIndexubv

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_1_1_H*/
