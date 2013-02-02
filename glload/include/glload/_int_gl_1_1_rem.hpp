#ifndef OPENGL_GEN_CORE_REM1_1_HPP
#define OPENGL_GEN_CORE_REM1_1_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		CURRENT_BIT                      = 0x00000001,
		POINT_BIT                        = 0x00000002,
		LINE_BIT                         = 0x00000004,
		POLYGON_BIT                      = 0x00000008,
		POLYGON_STIPPLE_BIT              = 0x00000010,
		PIXEL_MODE_BIT                   = 0x00000020,
		LIGHTING_BIT                     = 0x00000040,
		FOG_BIT                          = 0x00000080,
		ACCUM_BUFFER_BIT                 = 0x00000200,
		VIEWPORT_BIT                     = 0x00000800,
		TRANSFORM_BIT                    = 0x00001000,
		ENABLE_BIT                       = 0x00002000,
		HINT_BIT                         = 0x00008000,
		EVAL_BIT                         = 0x00010000,
		LIST_BIT                         = 0x00020000,
		TEXTURE_BIT                      = 0x00040000,
		SCISSOR_BIT                      = 0x00080000,
		ALL_ATTRIB_BITS                  = 0xFFFFFFFF,
		CLIENT_PIXEL_STORE_BIT           = 0x00000001,
		CLIENT_VERTEX_ARRAY_BIT          = 0x00000002,
		CLIENT_ALL_ATTRIB_BITS           = 0xFFFFFFFF,
		QUAD_STRIP                       = 0x0008,
		POLYGON                          = 0x0009,
		ACCUM                            = 0x0100,
		LOAD                             = 0x0101,
		RETURN                           = 0x0102,
		MULT                             = 0x0103,
		ADD                              = 0x0104,
		AUX0                             = 0x0409,
		AUX1                             = 0x040A,
		AUX2                             = 0x040B,
		AUX3                             = 0x040C,
		_2D                              = 0x0600,
		_3D                              = 0x0601,
		_3D_COLOR                        = 0x0602,
		_3D_COLOR_TEXTURE                = 0x0603,
		_4D_COLOR_TEXTURE                = 0x0604,
		PASS_THROUGH_TOKEN               = 0x0700,
		POINT_TOKEN                      = 0x0701,
		LINE_TOKEN                       = 0x0702,
		POLYGON_TOKEN                    = 0x0703,
		BITMAP_TOKEN                     = 0x0704,
		DRAW_PIXEL_TOKEN                 = 0x0705,
		COPY_PIXEL_TOKEN                 = 0x0706,
		LINE_RESET_TOKEN                 = 0x0707,
		EXP                              = 0x0800,
		EXP2                             = 0x0801,
		COEFF                            = 0x0A00,
		ORDER                            = 0x0A01,
		DOMAIN_                          = 0x0A02,
		PIXEL_MAP_I_TO_I                 = 0x0C70,
		PIXEL_MAP_S_TO_S                 = 0x0C71,
		PIXEL_MAP_I_TO_R                 = 0x0C72,
		PIXEL_MAP_I_TO_G                 = 0x0C73,
		PIXEL_MAP_I_TO_B                 = 0x0C74,
		PIXEL_MAP_I_TO_A                 = 0x0C75,
		PIXEL_MAP_R_TO_R                 = 0x0C76,
		PIXEL_MAP_G_TO_G                 = 0x0C77,
		PIXEL_MAP_B_TO_B                 = 0x0C78,
		PIXEL_MAP_A_TO_A                 = 0x0C79,
		VERTEX_ARRAY_POINTER             = 0x808E,
		NORMAL_ARRAY_POINTER             = 0x808F,
		COLOR_ARRAY_POINTER              = 0x8090,
		INDEX_ARRAY_POINTER              = 0x8091,
		TEXTURE_COORD_ARRAY_POINTER      = 0x8092,
		EDGE_FLAG_ARRAY_POINTER          = 0x8093,
		FEEDBACK_BUFFER_POINTER          = 0x0DF0,
		SELECTION_BUFFER_POINTER         = 0x0DF3,
		CURRENT_COLOR                    = 0x0B00,
		CURRENT_INDEX                    = 0x0B01,
		CURRENT_NORMAL                   = 0x0B02,
		CURRENT_TEXTURE_COORDS           = 0x0B03,
		CURRENT_RASTER_COLOR             = 0x0B04,
		CURRENT_RASTER_INDEX             = 0x0B05,
		CURRENT_RASTER_TEXTURE_COORDS    = 0x0B06,
		CURRENT_RASTER_POSITION          = 0x0B07,
		CURRENT_RASTER_POSITION_VALID    = 0x0B08,
		CURRENT_RASTER_DISTANCE          = 0x0B09,
		POINT_SMOOTH                     = 0x0B10,
		LINE_STIPPLE                     = 0x0B24,
		LINE_STIPPLE_PATTERN             = 0x0B25,
		LINE_STIPPLE_REPEAT              = 0x0B26,
		LIST_MODE                        = 0x0B30,
		MAX_LIST_NESTING                 = 0x0B31,
		LIST_BASE                        = 0x0B32,
		LIST_INDEX                       = 0x0B33,
		POLYGON_STIPPLE                  = 0x0B42,
		EDGE_FLAG                        = 0x0B43,
		LIGHTING                         = 0x0B50,
		LIGHT_MODEL_LOCAL_VIEWER         = 0x0B51,
		LIGHT_MODEL_TWO_SIDE             = 0x0B52,
		LIGHT_MODEL_AMBIENT              = 0x0B53,
		SHADE_MODEL                      = 0x0B54,
		COLOR_MATERIAL_FACE              = 0x0B55,
		COLOR_MATERIAL_PARAMETER         = 0x0B56,
		COLOR_MATERIAL                   = 0x0B57,
		FOG_INDEX                        = 0x0B61,
		FOG_DENSITY                      = 0x0B62,
		FOG_START                        = 0x0B63,
		FOG_END                          = 0x0B64,
		FOG_MODE                         = 0x0B65,
		FOG_COLOR                        = 0x0B66,
		ACCUM_CLEAR_VALUE                = 0x0B80,
		MATRIX_MODE                      = 0x0BA0,
		NORMALIZE                        = 0x0BA1,
		MODELVIEW_STACK_DEPTH            = 0x0BA3,
		PROJECTION_STACK_DEPTH           = 0x0BA4,
		TEXTURE_STACK_DEPTH              = 0x0BA5,
		MODELVIEW_MATRIX                 = 0x0BA6,
		PROJECTION_MATRIX                = 0x0BA7,
		TEXTURE_MATRIX                   = 0x0BA8,
		ATTRIB_STACK_DEPTH               = 0x0BB0,
		CLIENT_ATTRIB_STACK_DEPTH        = 0x0BB1,
		ALPHA_TEST                       = 0x0BC0,
		ALPHA_TEST_FUNC                  = 0x0BC1,
		ALPHA_TEST_REF                   = 0x0BC2,
		INDEX_LOGIC_OP                   = 0x0BF1,
		LOGIC_OP                         = 0x0BF1,
		AUX_BUFFERS                      = 0x0C00,
		INDEX_CLEAR_VALUE                = 0x0C20,
		INDEX_WRITEMASK                  = 0x0C21,
		INDEX_MODE                       = 0x0C30,
		RGBA_MODE                        = 0x0C31,
		RENDER_MODE                      = 0x0C40,
		PERSPECTIVE_CORRECTION_HINT      = 0x0C50,
		POINT_SMOOTH_HINT                = 0x0C51,
		FOG_HINT                         = 0x0C54,
		TEXTURE_GEN_S                    = 0x0C60,
		TEXTURE_GEN_T                    = 0x0C61,
		TEXTURE_GEN_R                    = 0x0C62,
		TEXTURE_GEN_Q                    = 0x0C63,
		PIXEL_MAP_I_TO_I_SIZE            = 0x0CB0,
		PIXEL_MAP_S_TO_S_SIZE            = 0x0CB1,
		PIXEL_MAP_I_TO_R_SIZE            = 0x0CB2,
		PIXEL_MAP_I_TO_G_SIZE            = 0x0CB3,
		PIXEL_MAP_I_TO_B_SIZE            = 0x0CB4,
		PIXEL_MAP_I_TO_A_SIZE            = 0x0CB5,
		PIXEL_MAP_R_TO_R_SIZE            = 0x0CB6,
		PIXEL_MAP_G_TO_G_SIZE            = 0x0CB7,
		PIXEL_MAP_B_TO_B_SIZE            = 0x0CB8,
		PIXEL_MAP_A_TO_A_SIZE            = 0x0CB9,
		MAP_COLOR                        = 0x0D10,
		MAP_STENCIL                      = 0x0D11,
		INDEX_SHIFT                      = 0x0D12,
		INDEX_OFFSET                     = 0x0D13,
		RED_SCALE                        = 0x0D14,
		RED_BIAS                         = 0x0D15,
		ZOOM_X                           = 0x0D16,
		ZOOM_Y                           = 0x0D17,
		GREEN_SCALE                      = 0x0D18,
		GREEN_BIAS                       = 0x0D19,
		BLUE_SCALE                       = 0x0D1A,
		BLUE_BIAS                        = 0x0D1B,
		ALPHA_SCALE                      = 0x0D1C,
		ALPHA_BIAS                       = 0x0D1D,
		DEPTH_SCALE                      = 0x0D1E,
		DEPTH_BIAS                       = 0x0D1F,
		MAX_EVAL_ORDER                   = 0x0D30,
		MAX_LIGHTS                       = 0x0D31,
		MAX_CLIP_PLANES                  = 0x0D32,
		MAX_PIXEL_MAP_TABLE              = 0x0D34,
		MAX_ATTRIB_STACK_DEPTH           = 0x0D35,
		MAX_MODELVIEW_STACK_DEPTH        = 0x0D36,
		MAX_NAME_STACK_DEPTH             = 0x0D37,
		MAX_PROJECTION_STACK_DEPTH       = 0x0D38,
		MAX_TEXTURE_STACK_DEPTH          = 0x0D39,
		MAX_CLIENT_ATTRIB_STACK_DEPTH    = 0x0D3B,
		INDEX_BITS                       = 0x0D51,
		RED_BITS                         = 0x0D52,
		GREEN_BITS                       = 0x0D53,
		BLUE_BITS                        = 0x0D54,
		ALPHA_BITS                       = 0x0D55,
		DEPTH_BITS                       = 0x0D56,
		STENCIL_BITS                     = 0x0D57,
		ACCUM_RED_BITS                   = 0x0D58,
		ACCUM_GREEN_BITS                 = 0x0D59,
		ACCUM_BLUE_BITS                  = 0x0D5A,
		ACCUM_ALPHA_BITS                 = 0x0D5B,
		NAME_STACK_DEPTH                 = 0x0D70,
		AUTO_NORMAL                      = 0x0D80,
		MAP1_COLOR_4                     = 0x0D90,
		MAP1_INDEX                       = 0x0D91,
		MAP1_NORMAL                      = 0x0D92,
		MAP1_TEXTURE_COORD_1             = 0x0D93,
		MAP1_TEXTURE_COORD_2             = 0x0D94,
		MAP1_TEXTURE_COORD_3             = 0x0D95,
		MAP1_TEXTURE_COORD_4             = 0x0D96,
		MAP1_VERTEX_3                    = 0x0D97,
		MAP1_VERTEX_4                    = 0x0D98,
		MAP2_COLOR_4                     = 0x0DB0,
		MAP2_INDEX                       = 0x0DB1,
		MAP2_NORMAL                      = 0x0DB2,
		MAP2_TEXTURE_COORD_1             = 0x0DB3,
		MAP2_TEXTURE_COORD_2             = 0x0DB4,
		MAP2_TEXTURE_COORD_3             = 0x0DB5,
		MAP2_TEXTURE_COORD_4             = 0x0DB6,
		MAP2_VERTEX_3                    = 0x0DB7,
		MAP2_VERTEX_4                    = 0x0DB8,
		MAP1_GRID_DOMAIN                 = 0x0DD0,
		MAP1_GRID_SEGMENTS               = 0x0DD1,
		MAP2_GRID_DOMAIN                 = 0x0DD2,
		MAP2_GRID_SEGMENTS               = 0x0DD3,
		FEEDBACK_BUFFER_SIZE             = 0x0DF1,
		FEEDBACK_BUFFER_TYPE             = 0x0DF2,
		SELECTION_BUFFER_SIZE            = 0x0DF4,
		VERTEX_ARRAY                     = 0x8074,
		NORMAL_ARRAY                     = 0x8075,
		COLOR_ARRAY                      = 0x8076,
		INDEX_ARRAY                      = 0x8077,
		TEXTURE_COORD_ARRAY              = 0x8078,
		EDGE_FLAG_ARRAY                  = 0x8079,
		VERTEX_ARRAY_SIZE                = 0x807A,
		VERTEX_ARRAY_TYPE                = 0x807B,
		VERTEX_ARRAY_STRIDE              = 0x807C,
		NORMAL_ARRAY_TYPE                = 0x807E,
		NORMAL_ARRAY_STRIDE              = 0x807F,
		COLOR_ARRAY_SIZE                 = 0x8081,
		COLOR_ARRAY_TYPE                 = 0x8082,
		COLOR_ARRAY_STRIDE               = 0x8083,
		INDEX_ARRAY_TYPE                 = 0x8085,
		INDEX_ARRAY_STRIDE               = 0x8086,
		TEXTURE_COORD_ARRAY_SIZE         = 0x8088,
		TEXTURE_COORD_ARRAY_TYPE         = 0x8089,
		TEXTURE_COORD_ARRAY_STRIDE       = 0x808A,
		EDGE_FLAG_ARRAY_STRIDE           = 0x808C,
		TEXTURE_COMPONENTS               = 0x1003,
		TEXTURE_BORDER                   = 0x1005,
		TEXTURE_LUMINANCE_SIZE           = 0x8060,
		TEXTURE_INTENSITY_SIZE           = 0x8061,
		TEXTURE_PRIORITY                 = 0x8066,
		TEXTURE_RESIDENT                 = 0x8067,
		AMBIENT                          = 0x1200,
		DIFFUSE                          = 0x1201,
		SPECULAR                         = 0x1202,
		POSITION                         = 0x1203,
		SPOT_DIRECTION                   = 0x1204,
		SPOT_EXPONENT                    = 0x1205,
		SPOT_CUTOFF                      = 0x1206,
		CONSTANT_ATTENUATION             = 0x1207,
		LINEAR_ATTENUATION               = 0x1208,
		QUADRATIC_ATTENUATION            = 0x1209,
		COMPILE                          = 0x1300,
		COMPILE_AND_EXECUTE              = 0x1301,
		_2_BYTES                         = 0x1407,
		_3_BYTES                         = 0x1408,
		_4_BYTES                         = 0x1409,
		EMISSION                         = 0x1600,
		SHININESS                        = 0x1601,
		AMBIENT_AND_DIFFUSE              = 0x1602,
		COLOR_INDEXES                    = 0x1603,
		MODELVIEW                        = 0x1700,
		PROJECTION                       = 0x1701,
		COLOR_INDEX                      = 0x1900,
		LUMINANCE                        = 0x1909,
		LUMINANCE_ALPHA                  = 0x190A,
		BITMAP                           = 0x1A00,
		RENDER                           = 0x1C00,
		FEEDBACK                         = 0x1C01,
		SELECT                           = 0x1C02,
		FLAT                             = 0x1D00,
		SMOOTH                           = 0x1D01,
		S                                = 0x2000,
		T                                = 0x2001,
		R                                = 0x2002,
		Q                                = 0x2003,
		MODULATE                         = 0x2100,
		DECAL                            = 0x2101,
		TEXTURE_ENV_MODE                 = 0x2200,
		TEXTURE_ENV_COLOR                = 0x2201,
		TEXTURE_ENV                      = 0x2300,
		EYE_LINEAR                       = 0x2400,
		OBJECT_LINEAR                    = 0x2401,
		SPHERE_MAP                       = 0x2402,
		TEXTURE_GEN_MODE                 = 0x2500,
		OBJECT_PLANE                     = 0x2501,
		CLAMP                            = 0x2900,
		ALPHA4                           = 0x803B,
		ALPHA8                           = 0x803C,
		ALPHA12                          = 0x803D,
		ALPHA16                          = 0x803E,
		LUMINANCE4                       = 0x803F,
		LUMINANCE8                       = 0x8040,
		LUMINANCE12                      = 0x8041,
		LUMINANCE16                      = 0x8042,
		LUMINANCE4_ALPHA4                = 0x8043,
		LUMINANCE6_ALPHA2                = 0x8044,
		LUMINANCE8_ALPHA8                = 0x8045,
		LUMINANCE12_ALPHA4               = 0x8046,
		LUMINANCE12_ALPHA12              = 0x8047,
		LUMINANCE16_ALPHA16              = 0x8048,
		INTENSITY                        = 0x8049,
		INTENSITY4                       = 0x804A,
		INTENSITY8                       = 0x804B,
		INTENSITY12                      = 0x804C,
		INTENSITY16                      = 0x804D,
		V2F                              = 0x2A20,
		V3F                              = 0x2A21,
		C4UB_V2F                         = 0x2A22,
		C4UB_V3F                         = 0x2A23,
		C3F_V3F                          = 0x2A24,
		N3F_V3F                          = 0x2A25,
		C4F_N3F_V3F                      = 0x2A26,
		T2F_V3F                          = 0x2A27,
		T4F_V4F                          = 0x2A28,
		T2F_C4UB_V3F                     = 0x2A29,
		T2F_C3F_V3F                      = 0x2A2A,
		T2F_N3F_V3F                      = 0x2A2B,
		T2F_C4F_N3F_V3F                  = 0x2A2C,
		T4F_C4F_N3F_V4F                  = 0x2A2D,
		CLIP_PLANE0                      = 0x3000,
		CLIP_PLANE1                      = 0x3001,
		CLIP_PLANE2                      = 0x3002,
		CLIP_PLANE3                      = 0x3003,
		CLIP_PLANE4                      = 0x3004,
		CLIP_PLANE5                      = 0x3005,
		LIGHT0                           = 0x4000,
		LIGHT1                           = 0x4001,
		LIGHT2                           = 0x4002,
		LIGHT3                           = 0x4003,
		LIGHT4                           = 0x4004,
		LIGHT5                           = 0x4005,
		LIGHT6                           = 0x4006,
		LIGHT7                           = 0x4007,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glNewList)(GLuint list, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glEndList)();
		typedef void (CODEGEN_FUNCPTR * Proc_glCallList)(GLuint list);
		typedef void (CODEGEN_FUNCPTR * Proc_glCallLists)(GLsizei n, GLenum type, const GLvoid *lists);
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteLists)(GLuint list, GLsizei range);
		typedef GLuint (CODEGEN_FUNCPTR * Proc_glGenLists)(GLsizei range);
		typedef void (CODEGEN_FUNCPTR * Proc_glListBase)(GLuint base);
		typedef void (CODEGEN_FUNCPTR * Proc_glBegin)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3b)(GLbyte red, GLbyte green, GLbyte blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3bv)(const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3d)(GLdouble red, GLdouble green, GLdouble blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3f)(GLfloat red, GLfloat green, GLfloat blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3i)(GLint red, GLint green, GLint blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3s)(GLshort red, GLshort green, GLshort blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ub)(GLubyte red, GLubyte green, GLubyte blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ubv)(const GLubyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ui)(GLuint red, GLuint green, GLuint blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3uiv)(const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3us)(GLushort red, GLushort green, GLushort blue);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3usv)(const GLushort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4bv)(const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4i)(GLint red, GLint green, GLint blue, GLint alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ubv)(const GLubyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4uiv)(const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4usv)(const GLushort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlag)(GLboolean flag);
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlagv)(const GLboolean *flag);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnd)();
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexd)(GLdouble c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexdv)(const GLdouble *c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexf)(GLfloat c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexfv)(const GLfloat *c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexi)(GLint c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexiv)(const GLint *c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexs)(GLshort c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexsv)(const GLshort *c);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3bv)(const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3i)(GLint nx, GLint ny, GLint nz);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3s)(GLshort nx, GLshort ny, GLshort nz);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2d)(GLdouble x, GLdouble y);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2f)(GLfloat x, GLfloat y);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2i)(GLint x, GLint y);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2s)(GLshort x, GLshort y);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3i)(GLint x, GLint y, GLint z);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3s)(GLshort x, GLshort y, GLshort z);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4i)(GLint x, GLint y, GLint z, GLint w);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectdv)(const GLdouble *v1, const GLdouble *v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectfv)(const GLfloat *v1, const GLfloat *v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRecti)(GLint x1, GLint y1, GLint x2, GLint y2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectiv)(const GLint *v1, const GLint *v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectsv)(const GLshort *v1, const GLshort *v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1d)(GLdouble s);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1f)(GLfloat s);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1i)(GLint s);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1s)(GLshort s);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2d)(GLdouble s, GLdouble t);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2f)(GLfloat s, GLfloat t);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2i)(GLint s, GLint t);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2s)(GLshort s, GLshort t);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3i)(GLint s, GLint t, GLint r);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3s)(GLshort s, GLshort t, GLshort r);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4i)(GLint s, GLint t, GLint r, GLint q);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2d)(GLdouble x, GLdouble y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2f)(GLfloat x, GLfloat y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2i)(GLint x, GLint y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2s)(GLshort x, GLshort y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3d)(GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3f)(GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3i)(GLint x, GLint y, GLint z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3s)(GLshort x, GLshort y, GLshort z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4dv)(const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4fv)(const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4i)(GLint x, GLint y, GLint z, GLint w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4iv)(const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4sv)(const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glClipPlane)(GLenum plane, const GLdouble *equation);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorMaterial)(GLenum face, GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogf)(GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogfv)(GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogi)(GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogiv)(GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightf)(GLenum light, GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightfv)(GLenum light, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glLighti)(GLenum light, GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightiv)(GLenum light, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModelf)(GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModelfv)(GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModeli)(GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModeliv)(GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glLineStipple)(GLint factor, GLushort pattern);
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialf)(GLenum face, GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialfv)(GLenum face, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glMateriali)(GLenum face, GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialiv)(GLenum face, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glPolygonStipple)(const GLubyte *mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glShadeModel)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvf)(GLenum target, GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvfv)(GLenum target, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvi)(GLenum target, GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnviv)(GLenum target, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGend)(GLenum coord, GLenum pname, GLdouble param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGendv)(GLenum coord, GLenum pname, const GLdouble *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGenf)(GLenum coord, GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGenfv)(GLenum coord, GLenum pname, const GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGeni)(GLenum coord, GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGeniv)(GLenum coord, GLenum pname, const GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat *buffer);
		typedef void (CODEGEN_FUNCPTR * Proc_glSelectBuffer)(GLsizei size, GLuint *buffer);
		typedef GLint (CODEGEN_FUNCPTR * Proc_glRenderMode)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glInitNames)();
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadName)(GLuint name);
		typedef void (CODEGEN_FUNCPTR * Proc_glPassThrough)(GLfloat token);
		typedef void (CODEGEN_FUNCPTR * Proc_glPopName)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushName)(GLuint name);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
		typedef void (CODEGEN_FUNCPTR * Proc_glClearIndex)(GLfloat c);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexMask)(GLuint mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glAccum)(GLenum op, GLfloat value);
		typedef void (CODEGEN_FUNCPTR * Proc_glPopAttrib)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushAttrib)(GLbitfield mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2);
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2);
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1d)(GLdouble u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1dv)(const GLdouble *u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1f)(GLfloat u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1fv)(const GLfloat *u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2d)(GLdouble u, GLdouble v);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2dv)(const GLdouble *u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2f)(GLfloat u, GLfloat v);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2fv)(const GLfloat *u);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalMesh1)(GLenum mode, GLint i1, GLint i2);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalPoint1)(GLint i);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalPoint2)(GLint i, GLint j);
		typedef void (CODEGEN_FUNCPTR * Proc_glAlphaFunc)(GLenum func, GLfloat ref);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelZoom)(GLfloat xfactor, GLfloat yfactor);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelTransferf)(GLenum pname, GLfloat param);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelTransferi)(GLenum pname, GLint param);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetClipPlane)(GLenum plane, GLdouble *equation);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetLightfv)(GLenum light, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetLightiv)(GLenum light, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapdv)(GLenum target, GLenum query, GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapfv)(GLenum target, GLenum query, GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapiv)(GLenum target, GLenum query, GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMaterialfv)(GLenum face, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMaterialiv)(GLenum face, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapfv)(GLenum map, GLfloat *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapuiv)(GLenum map, GLuint *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapusv)(GLenum map, GLushort *values);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPolygonStipple)(GLubyte *mask);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexEnviv)(GLenum target, GLenum pname, GLint *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGendv)(GLenum coord, GLenum pname, GLdouble *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat *params);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGeniv)(GLenum coord, GLenum pname, GLint *params);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsList)(GLuint list);
		typedef void (CODEGEN_FUNCPTR * Proc_glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadIdentity)();
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadMatrixf)(const GLfloat *m);
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadMatrixd)(const GLdouble *m);
		typedef void (CODEGEN_FUNCPTR * Proc_glMatrixMode)(GLenum mode);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultMatrixf)(const GLfloat *m);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultMatrixd)(const GLdouble *m);
		typedef void (CODEGEN_FUNCPTR * Proc_glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
		typedef void (CODEGEN_FUNCPTR * Proc_glPopMatrix)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushMatrix)();
		typedef void (CODEGEN_FUNCPTR * Proc_glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glScaled)(GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glScalef)(GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glTranslated)(GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glTranslatef)(GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glArrayElement)(GLint i);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glDisableClientState)(GLenum ren_array);
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlagPointer)(GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnableClientState)(GLenum ren_array);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glInterleavedArrays)(GLenum format, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormalPointer)(GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexPointer)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glAreTexturesResident)(GLsizei n, const GLuint *textures, GLboolean *residences);
		typedef void (CODEGEN_FUNCPTR * Proc_glPrioritizeTextures)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
		typedef void (CODEGEN_FUNCPTR * Proc_glPopClientAttrib)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushClientAttrib)(GLbitfield mask);
	}
	
	extern _detail::Proc_glNewList NewList;
	extern _detail::Proc_glEndList EndList;
	extern _detail::Proc_glCallList CallList;
	extern _detail::Proc_glCallLists CallLists;
	extern _detail::Proc_glDeleteLists DeleteLists;
	extern _detail::Proc_glGenLists GenLists;
	extern _detail::Proc_glListBase ListBase;
	extern _detail::Proc_glBegin Begin;
	extern _detail::Proc_glBitmap Bitmap;
	extern _detail::Proc_glColor3b Color3b;
	extern _detail::Proc_glColor3bv Color3bv;
	extern _detail::Proc_glColor3d Color3d;
	extern _detail::Proc_glColor3dv Color3dv;
	extern _detail::Proc_glColor3f Color3f;
	extern _detail::Proc_glColor3fv Color3fv;
	extern _detail::Proc_glColor3i Color3i;
	extern _detail::Proc_glColor3iv Color3iv;
	extern _detail::Proc_glColor3s Color3s;
	extern _detail::Proc_glColor3sv Color3sv;
	extern _detail::Proc_glColor3ub Color3ub;
	extern _detail::Proc_glColor3ubv Color3ubv;
	extern _detail::Proc_glColor3ui Color3ui;
	extern _detail::Proc_glColor3uiv Color3uiv;
	extern _detail::Proc_glColor3us Color3us;
	extern _detail::Proc_glColor3usv Color3usv;
	extern _detail::Proc_glColor4b Color4b;
	extern _detail::Proc_glColor4bv Color4bv;
	extern _detail::Proc_glColor4d Color4d;
	extern _detail::Proc_glColor4dv Color4dv;
	extern _detail::Proc_glColor4f Color4f;
	extern _detail::Proc_glColor4fv Color4fv;
	extern _detail::Proc_glColor4i Color4i;
	extern _detail::Proc_glColor4iv Color4iv;
	extern _detail::Proc_glColor4s Color4s;
	extern _detail::Proc_glColor4sv Color4sv;
	extern _detail::Proc_glColor4ub Color4ub;
	extern _detail::Proc_glColor4ubv Color4ubv;
	extern _detail::Proc_glColor4ui Color4ui;
	extern _detail::Proc_glColor4uiv Color4uiv;
	extern _detail::Proc_glColor4us Color4us;
	extern _detail::Proc_glColor4usv Color4usv;
	extern _detail::Proc_glEdgeFlag EdgeFlag;
	extern _detail::Proc_glEdgeFlagv EdgeFlagv;
	extern _detail::Proc_glEnd End;
	extern _detail::Proc_glIndexd Indexd;
	extern _detail::Proc_glIndexdv Indexdv;
	extern _detail::Proc_glIndexf Indexf;
	extern _detail::Proc_glIndexfv Indexfv;
	extern _detail::Proc_glIndexi Indexi;
	extern _detail::Proc_glIndexiv Indexiv;
	extern _detail::Proc_glIndexs Indexs;
	extern _detail::Proc_glIndexsv Indexsv;
	extern _detail::Proc_glNormal3b Normal3b;
	extern _detail::Proc_glNormal3bv Normal3bv;
	extern _detail::Proc_glNormal3d Normal3d;
	extern _detail::Proc_glNormal3dv Normal3dv;
	extern _detail::Proc_glNormal3f Normal3f;
	extern _detail::Proc_glNormal3fv Normal3fv;
	extern _detail::Proc_glNormal3i Normal3i;
	extern _detail::Proc_glNormal3iv Normal3iv;
	extern _detail::Proc_glNormal3s Normal3s;
	extern _detail::Proc_glNormal3sv Normal3sv;
	extern _detail::Proc_glRasterPos2d RasterPos2d;
	extern _detail::Proc_glRasterPos2dv RasterPos2dv;
	extern _detail::Proc_glRasterPos2f RasterPos2f;
	extern _detail::Proc_glRasterPos2fv RasterPos2fv;
	extern _detail::Proc_glRasterPos2i RasterPos2i;
	extern _detail::Proc_glRasterPos2iv RasterPos2iv;
	extern _detail::Proc_glRasterPos2s RasterPos2s;
	extern _detail::Proc_glRasterPos2sv RasterPos2sv;
	extern _detail::Proc_glRasterPos3d RasterPos3d;
	extern _detail::Proc_glRasterPos3dv RasterPos3dv;
	extern _detail::Proc_glRasterPos3f RasterPos3f;
	extern _detail::Proc_glRasterPos3fv RasterPos3fv;
	extern _detail::Proc_glRasterPos3i RasterPos3i;
	extern _detail::Proc_glRasterPos3iv RasterPos3iv;
	extern _detail::Proc_glRasterPos3s RasterPos3s;
	extern _detail::Proc_glRasterPos3sv RasterPos3sv;
	extern _detail::Proc_glRasterPos4d RasterPos4d;
	extern _detail::Proc_glRasterPos4dv RasterPos4dv;
	extern _detail::Proc_glRasterPos4f RasterPos4f;
	extern _detail::Proc_glRasterPos4fv RasterPos4fv;
	extern _detail::Proc_glRasterPos4i RasterPos4i;
	extern _detail::Proc_glRasterPos4iv RasterPos4iv;
	extern _detail::Proc_glRasterPos4s RasterPos4s;
	extern _detail::Proc_glRasterPos4sv RasterPos4sv;
	extern _detail::Proc_glRectd Rectd;
	extern _detail::Proc_glRectdv Rectdv;
	extern _detail::Proc_glRectf Rectf;
	extern _detail::Proc_glRectfv Rectfv;
	extern _detail::Proc_glRecti Recti;
	extern _detail::Proc_glRectiv Rectiv;
	extern _detail::Proc_glRects Rects;
	extern _detail::Proc_glRectsv Rectsv;
	extern _detail::Proc_glTexCoord1d TexCoord1d;
	extern _detail::Proc_glTexCoord1dv TexCoord1dv;
	extern _detail::Proc_glTexCoord1f TexCoord1f;
	extern _detail::Proc_glTexCoord1fv TexCoord1fv;
	extern _detail::Proc_glTexCoord1i TexCoord1i;
	extern _detail::Proc_glTexCoord1iv TexCoord1iv;
	extern _detail::Proc_glTexCoord1s TexCoord1s;
	extern _detail::Proc_glTexCoord1sv TexCoord1sv;
	extern _detail::Proc_glTexCoord2d TexCoord2d;
	extern _detail::Proc_glTexCoord2dv TexCoord2dv;
	extern _detail::Proc_glTexCoord2f TexCoord2f;
	extern _detail::Proc_glTexCoord2fv TexCoord2fv;
	extern _detail::Proc_glTexCoord2i TexCoord2i;
	extern _detail::Proc_glTexCoord2iv TexCoord2iv;
	extern _detail::Proc_glTexCoord2s TexCoord2s;
	extern _detail::Proc_glTexCoord2sv TexCoord2sv;
	extern _detail::Proc_glTexCoord3d TexCoord3d;
	extern _detail::Proc_glTexCoord3dv TexCoord3dv;
	extern _detail::Proc_glTexCoord3f TexCoord3f;
	extern _detail::Proc_glTexCoord3fv TexCoord3fv;
	extern _detail::Proc_glTexCoord3i TexCoord3i;
	extern _detail::Proc_glTexCoord3iv TexCoord3iv;
	extern _detail::Proc_glTexCoord3s TexCoord3s;
	extern _detail::Proc_glTexCoord3sv TexCoord3sv;
	extern _detail::Proc_glTexCoord4d TexCoord4d;
	extern _detail::Proc_glTexCoord4dv TexCoord4dv;
	extern _detail::Proc_glTexCoord4f TexCoord4f;
	extern _detail::Proc_glTexCoord4fv TexCoord4fv;
	extern _detail::Proc_glTexCoord4i TexCoord4i;
	extern _detail::Proc_glTexCoord4iv TexCoord4iv;
	extern _detail::Proc_glTexCoord4s TexCoord4s;
	extern _detail::Proc_glTexCoord4sv TexCoord4sv;
	extern _detail::Proc_glVertex2d Vertex2d;
	extern _detail::Proc_glVertex2dv Vertex2dv;
	extern _detail::Proc_glVertex2f Vertex2f;
	extern _detail::Proc_glVertex2fv Vertex2fv;
	extern _detail::Proc_glVertex2i Vertex2i;
	extern _detail::Proc_glVertex2iv Vertex2iv;
	extern _detail::Proc_glVertex2s Vertex2s;
	extern _detail::Proc_glVertex2sv Vertex2sv;
	extern _detail::Proc_glVertex3d Vertex3d;
	extern _detail::Proc_glVertex3dv Vertex3dv;
	extern _detail::Proc_glVertex3f Vertex3f;
	extern _detail::Proc_glVertex3fv Vertex3fv;
	extern _detail::Proc_glVertex3i Vertex3i;
	extern _detail::Proc_glVertex3iv Vertex3iv;
	extern _detail::Proc_glVertex3s Vertex3s;
	extern _detail::Proc_glVertex3sv Vertex3sv;
	extern _detail::Proc_glVertex4d Vertex4d;
	extern _detail::Proc_glVertex4dv Vertex4dv;
	extern _detail::Proc_glVertex4f Vertex4f;
	extern _detail::Proc_glVertex4fv Vertex4fv;
	extern _detail::Proc_glVertex4i Vertex4i;
	extern _detail::Proc_glVertex4iv Vertex4iv;
	extern _detail::Proc_glVertex4s Vertex4s;
	extern _detail::Proc_glVertex4sv Vertex4sv;
	extern _detail::Proc_glClipPlane ClipPlane;
	extern _detail::Proc_glColorMaterial ColorMaterial;
	extern _detail::Proc_glFogf Fogf;
	extern _detail::Proc_glFogfv Fogfv;
	extern _detail::Proc_glFogi Fogi;
	extern _detail::Proc_glFogiv Fogiv;
	extern _detail::Proc_glLightf Lightf;
	extern _detail::Proc_glLightfv Lightfv;
	extern _detail::Proc_glLighti Lighti;
	extern _detail::Proc_glLightiv Lightiv;
	extern _detail::Proc_glLightModelf LightModelf;
	extern _detail::Proc_glLightModelfv LightModelfv;
	extern _detail::Proc_glLightModeli LightModeli;
	extern _detail::Proc_glLightModeliv LightModeliv;
	extern _detail::Proc_glLineStipple LineStipple;
	extern _detail::Proc_glMaterialf Materialf;
	extern _detail::Proc_glMaterialfv Materialfv;
	extern _detail::Proc_glMateriali Materiali;
	extern _detail::Proc_glMaterialiv Materialiv;
	extern _detail::Proc_glPolygonStipple PolygonStipple;
	extern _detail::Proc_glShadeModel ShadeModel;
	extern _detail::Proc_glTexEnvf TexEnvf;
	extern _detail::Proc_glTexEnvfv TexEnvfv;
	extern _detail::Proc_glTexEnvi TexEnvi;
	extern _detail::Proc_glTexEnviv TexEnviv;
	extern _detail::Proc_glTexGend TexGend;
	extern _detail::Proc_glTexGendv TexGendv;
	extern _detail::Proc_glTexGenf TexGenf;
	extern _detail::Proc_glTexGenfv TexGenfv;
	extern _detail::Proc_glTexGeni TexGeni;
	extern _detail::Proc_glTexGeniv TexGeniv;
	extern _detail::Proc_glFeedbackBuffer FeedbackBuffer;
	extern _detail::Proc_glSelectBuffer SelectBuffer;
	extern _detail::Proc_glRenderMode RenderMode;
	extern _detail::Proc_glInitNames InitNames;
	extern _detail::Proc_glLoadName LoadName;
	extern _detail::Proc_glPassThrough PassThrough;
	extern _detail::Proc_glPopName PopName;
	extern _detail::Proc_glPushName PushName;
	extern _detail::Proc_glClearAccum ClearAccum;
	extern _detail::Proc_glClearIndex ClearIndex;
	extern _detail::Proc_glIndexMask IndexMask;
	extern _detail::Proc_glAccum Accum;
	extern _detail::Proc_glPopAttrib PopAttrib;
	extern _detail::Proc_glPushAttrib PushAttrib;
	extern _detail::Proc_glMap1d Map1d;
	extern _detail::Proc_glMap1f Map1f;
	extern _detail::Proc_glMap2d Map2d;
	extern _detail::Proc_glMap2f Map2f;
	extern _detail::Proc_glMapGrid1d MapGrid1d;
	extern _detail::Proc_glMapGrid1f MapGrid1f;
	extern _detail::Proc_glMapGrid2d MapGrid2d;
	extern _detail::Proc_glMapGrid2f MapGrid2f;
	extern _detail::Proc_glEvalCoord1d EvalCoord1d;
	extern _detail::Proc_glEvalCoord1dv EvalCoord1dv;
	extern _detail::Proc_glEvalCoord1f EvalCoord1f;
	extern _detail::Proc_glEvalCoord1fv EvalCoord1fv;
	extern _detail::Proc_glEvalCoord2d EvalCoord2d;
	extern _detail::Proc_glEvalCoord2dv EvalCoord2dv;
	extern _detail::Proc_glEvalCoord2f EvalCoord2f;
	extern _detail::Proc_glEvalCoord2fv EvalCoord2fv;
	extern _detail::Proc_glEvalMesh1 EvalMesh1;
	extern _detail::Proc_glEvalPoint1 EvalPoint1;
	extern _detail::Proc_glEvalMesh2 EvalMesh2;
	extern _detail::Proc_glEvalPoint2 EvalPoint2;
	extern _detail::Proc_glAlphaFunc AlphaFunc;
	extern _detail::Proc_glPixelZoom PixelZoom;
	extern _detail::Proc_glPixelTransferf PixelTransferf;
	extern _detail::Proc_glPixelTransferi PixelTransferi;
	extern _detail::Proc_glPixelMapfv PixelMapfv;
	extern _detail::Proc_glPixelMapuiv PixelMapuiv;
	extern _detail::Proc_glPixelMapusv PixelMapusv;
	extern _detail::Proc_glCopyPixels CopyPixels;
	extern _detail::Proc_glDrawPixels DrawPixels;
	extern _detail::Proc_glGetClipPlane GetClipPlane;
	extern _detail::Proc_glGetLightfv GetLightfv;
	extern _detail::Proc_glGetLightiv GetLightiv;
	extern _detail::Proc_glGetMapdv GetMapdv;
	extern _detail::Proc_glGetMapfv GetMapfv;
	extern _detail::Proc_glGetMapiv GetMapiv;
	extern _detail::Proc_glGetMaterialfv GetMaterialfv;
	extern _detail::Proc_glGetMaterialiv GetMaterialiv;
	extern _detail::Proc_glGetPixelMapfv GetPixelMapfv;
	extern _detail::Proc_glGetPixelMapuiv GetPixelMapuiv;
	extern _detail::Proc_glGetPixelMapusv GetPixelMapusv;
	extern _detail::Proc_glGetPolygonStipple GetPolygonStipple;
	extern _detail::Proc_glGetTexEnvfv GetTexEnvfv;
	extern _detail::Proc_glGetTexEnviv GetTexEnviv;
	extern _detail::Proc_glGetTexGendv GetTexGendv;
	extern _detail::Proc_glGetTexGenfv GetTexGenfv;
	extern _detail::Proc_glGetTexGeniv GetTexGeniv;
	extern _detail::Proc_glIsList IsList;
	extern _detail::Proc_glFrustum Frustum;
	extern _detail::Proc_glLoadIdentity LoadIdentity;
	extern _detail::Proc_glLoadMatrixf LoadMatrixf;
	extern _detail::Proc_glLoadMatrixd LoadMatrixd;
	extern _detail::Proc_glMatrixMode MatrixMode;
	extern _detail::Proc_glMultMatrixf MultMatrixf;
	extern _detail::Proc_glMultMatrixd MultMatrixd;
	extern _detail::Proc_glOrtho Ortho;
	extern _detail::Proc_glPopMatrix PopMatrix;
	extern _detail::Proc_glPushMatrix PushMatrix;
	extern _detail::Proc_glRotated Rotated;
	extern _detail::Proc_glRotatef Rotatef;
	extern _detail::Proc_glScaled Scaled;
	extern _detail::Proc_glScalef Scalef;
	extern _detail::Proc_glTranslated Translated;
	extern _detail::Proc_glTranslatef Translatef;
	extern _detail::Proc_glArrayElement ArrayElement;
	extern _detail::Proc_glColorPointer ColorPointer;
	extern _detail::Proc_glDisableClientState DisableClientState;
	extern _detail::Proc_glEdgeFlagPointer EdgeFlagPointer;
	extern _detail::Proc_glEnableClientState EnableClientState;
	extern _detail::Proc_glIndexPointer IndexPointer;
	extern _detail::Proc_glInterleavedArrays InterleavedArrays;
	extern _detail::Proc_glNormalPointer NormalPointer;
	extern _detail::Proc_glTexCoordPointer TexCoordPointer;
	extern _detail::Proc_glVertexPointer VertexPointer;
	extern _detail::Proc_glAreTexturesResident AreTexturesResident;
	extern _detail::Proc_glPrioritizeTextures PrioritizeTextures;
	extern _detail::Proc_glPopClientAttrib PopClientAttrib;
	extern _detail::Proc_glPushClientAttrib PushClientAttrib;
	
}
#endif /*OPENGL_GEN_CORE_REM1_1_HPP*/
