#ifndef OPENGL_GEN_CORE_REM1_1_H
#define OPENGL_GEN_CORE_REM1_1_H

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/
#define GL_CURRENT_BIT 0x00000001
#define GL_POINT_BIT 0x00000002
#define GL_LINE_BIT 0x00000004
#define GL_POLYGON_BIT 0x00000008
#define GL_POLYGON_STIPPLE_BIT 0x00000010
#define GL_PIXEL_MODE_BIT 0x00000020
#define GL_LIGHTING_BIT 0x00000040
#define GL_FOG_BIT 0x00000080
#define GL_ACCUM_BUFFER_BIT 0x00000200
#define GL_VIEWPORT_BIT 0x00000800
#define GL_TRANSFORM_BIT 0x00001000
#define GL_ENABLE_BIT 0x00002000
#define GL_HINT_BIT 0x00008000
#define GL_EVAL_BIT 0x00010000
#define GL_LIST_BIT 0x00020000
#define GL_TEXTURE_BIT 0x00040000
#define GL_SCISSOR_BIT 0x00080000
#define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
#define GL_ACCUM 0x0100
#define GL_LOAD 0x0101
#define GL_RETURN 0x0102
#define GL_MULT 0x0103
#define GL_ADD 0x0104
#define GL_AUX0 0x0409
#define GL_AUX1 0x040A
#define GL_AUX2 0x040B
#define GL_AUX3 0x040C
#define GL_2D 0x0600
#define GL_3D 0x0601
#define GL_3D_COLOR 0x0602
#define GL_3D_COLOR_TEXTURE 0x0603
#define GL_4D_COLOR_TEXTURE 0x0604
#define GL_PASS_THROUGH_TOKEN 0x0700
#define GL_POINT_TOKEN 0x0701
#define GL_LINE_TOKEN 0x0702
#define GL_POLYGON_TOKEN 0x0703
#define GL_BITMAP_TOKEN 0x0704
#define GL_DRAW_PIXEL_TOKEN 0x0705
#define GL_COPY_PIXEL_TOKEN 0x0706
#define GL_LINE_RESET_TOKEN 0x0707
#define GL_EXP 0x0800
#define GL_EXP2 0x0801
#define GL_COEFF 0x0A00
#define GL_ORDER 0x0A01
#define GL_DOMAIN 0x0A02
#define GL_PIXEL_MAP_I_TO_I 0x0C70
#define GL_PIXEL_MAP_S_TO_S 0x0C71
#define GL_PIXEL_MAP_I_TO_R 0x0C72
#define GL_PIXEL_MAP_I_TO_G 0x0C73
#define GL_PIXEL_MAP_I_TO_B 0x0C74
#define GL_PIXEL_MAP_I_TO_A 0x0C75
#define GL_PIXEL_MAP_R_TO_R 0x0C76
#define GL_PIXEL_MAP_G_TO_G 0x0C77
#define GL_PIXEL_MAP_B_TO_B 0x0C78
#define GL_PIXEL_MAP_A_TO_A 0x0C79
#define GL_VERTEX_ARRAY_POINTER 0x808E
#define GL_NORMAL_ARRAY_POINTER 0x808F
#define GL_COLOR_ARRAY_POINTER 0x8090
#define GL_INDEX_ARRAY_POINTER 0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#define GL_SELECTION_BUFFER_POINTER 0x0DF3
#define GL_CURRENT_COLOR 0x0B00
#define GL_CURRENT_INDEX 0x0B01
#define GL_CURRENT_NORMAL 0x0B02
#define GL_CURRENT_TEXTURE_COORDS 0x0B03
#define GL_CURRENT_RASTER_COLOR 0x0B04
#define GL_CURRENT_RASTER_INDEX 0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define GL_CURRENT_RASTER_POSITION 0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#define GL_CURRENT_RASTER_DISTANCE 0x0B09
#define GL_POINT_SMOOTH 0x0B10
#define GL_LINE_STIPPLE 0x0B24
#define GL_LINE_STIPPLE_PATTERN 0x0B25
#define GL_LINE_STIPPLE_REPEAT 0x0B26
#define GL_LIST_MODE 0x0B30
#define GL_MAX_LIST_NESTING 0x0B31
#define GL_LIST_BASE 0x0B32
#define GL_LIST_INDEX 0x0B33
#define GL_POLYGON_STIPPLE 0x0B42
#define GL_EDGE_FLAG 0x0B43
#define GL_LIGHTING 0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#define GL_LIGHT_MODEL_AMBIENT 0x0B53
#define GL_SHADE_MODEL 0x0B54
#define GL_COLOR_MATERIAL_FACE 0x0B55
#define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#define GL_COLOR_MATERIAL 0x0B57
#define GL_FOG_INDEX 0x0B61
#define GL_FOG_DENSITY 0x0B62
#define GL_FOG_START 0x0B63
#define GL_FOG_END 0x0B64
#define GL_FOG_MODE 0x0B65
#define GL_FOG_COLOR 0x0B66
#define GL_ACCUM_CLEAR_VALUE 0x0B80
#define GL_MATRIX_MODE 0x0BA0
#define GL_NORMALIZE 0x0BA1
#define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#define GL_PROJECTION_STACK_DEPTH 0x0BA4
#define GL_TEXTURE_STACK_DEPTH 0x0BA5
#define GL_MODELVIEW_MATRIX 0x0BA6
#define GL_PROJECTION_MATRIX 0x0BA7
#define GL_TEXTURE_MATRIX 0x0BA8
#define GL_ATTRIB_STACK_DEPTH 0x0BB0
#define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define GL_ALPHA_TEST 0x0BC0
#define GL_ALPHA_TEST_FUNC 0x0BC1
#define GL_ALPHA_TEST_REF 0x0BC2
#define GL_INDEX_LOGIC_OP 0x0BF1
#define GL_LOGIC_OP 0x0BF1
#define GL_AUX_BUFFERS 0x0C00
#define GL_INDEX_CLEAR_VALUE 0x0C20
#define GL_INDEX_WRITEMASK 0x0C21
#define GL_INDEX_MODE 0x0C30
#define GL_RGBA_MODE 0x0C31
#define GL_RENDER_MODE 0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define GL_POINT_SMOOTH_HINT 0x0C51
#define GL_FOG_HINT 0x0C54
#define GL_TEXTURE_GEN_S 0x0C60
#define GL_TEXTURE_GEN_T 0x0C61
#define GL_TEXTURE_GEN_R 0x0C62
#define GL_TEXTURE_GEN_Q 0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define GL_MAP_COLOR 0x0D10
#define GL_MAP_STENCIL 0x0D11
#define GL_INDEX_SHIFT 0x0D12
#define GL_INDEX_OFFSET 0x0D13
#define GL_RED_SCALE 0x0D14
#define GL_RED_BIAS 0x0D15
#define GL_ZOOM_X 0x0D16
#define GL_ZOOM_Y 0x0D17
#define GL_GREEN_SCALE 0x0D18
#define GL_GREEN_BIAS 0x0D19
#define GL_BLUE_SCALE 0x0D1A
#define GL_BLUE_BIAS 0x0D1B
#define GL_ALPHA_SCALE 0x0D1C
#define GL_ALPHA_BIAS 0x0D1D
#define GL_DEPTH_SCALE 0x0D1E
#define GL_DEPTH_BIAS 0x0D1F
#define GL_MAX_EVAL_ORDER 0x0D30
#define GL_MAX_LIGHTS 0x0D31
#define GL_MAX_CLIP_PLANES 0x0D32
#define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define GL_MAX_NAME_STACK_DEPTH 0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define GL_INDEX_BITS 0x0D51
#define GL_RED_BITS 0x0D52
#define GL_GREEN_BITS 0x0D53
#define GL_BLUE_BITS 0x0D54
#define GL_ALPHA_BITS 0x0D55
#define GL_DEPTH_BITS 0x0D56
#define GL_STENCIL_BITS 0x0D57
#define GL_ACCUM_RED_BITS 0x0D58
#define GL_ACCUM_GREEN_BITS 0x0D59
#define GL_ACCUM_BLUE_BITS 0x0D5A
#define GL_ACCUM_ALPHA_BITS 0x0D5B
#define GL_NAME_STACK_DEPTH 0x0D70
#define GL_AUTO_NORMAL 0x0D80
#define GL_MAP1_COLOR_4 0x0D90
#define GL_MAP1_INDEX 0x0D91
#define GL_MAP1_NORMAL 0x0D92
#define GL_MAP1_TEXTURE_COORD_1 0x0D93
#define GL_MAP1_TEXTURE_COORD_2 0x0D94
#define GL_MAP1_TEXTURE_COORD_3 0x0D95
#define GL_MAP1_TEXTURE_COORD_4 0x0D96
#define GL_MAP1_VERTEX_3 0x0D97
#define GL_MAP1_VERTEX_4 0x0D98
#define GL_MAP2_COLOR_4 0x0DB0
#define GL_MAP2_INDEX 0x0DB1
#define GL_MAP2_NORMAL 0x0DB2
#define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#define GL_MAP2_VERTEX_3 0x0DB7
#define GL_MAP2_VERTEX_4 0x0DB8
#define GL_MAP1_GRID_DOMAIN 0x0DD0
#define GL_MAP1_GRID_SEGMENTS 0x0DD1
#define GL_MAP2_GRID_DOMAIN 0x0DD2
#define GL_MAP2_GRID_SEGMENTS 0x0DD3
#define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#define GL_SELECTION_BUFFER_SIZE 0x0DF4
#define GL_VERTEX_ARRAY 0x8074
#define GL_NORMAL_ARRAY 0x8075
#define GL_COLOR_ARRAY 0x8076
#define GL_INDEX_ARRAY 0x8077
#define GL_TEXTURE_COORD_ARRAY 0x8078
#define GL_EDGE_FLAG_ARRAY 0x8079
#define GL_VERTEX_ARRAY_SIZE 0x807A
#define GL_VERTEX_ARRAY_TYPE 0x807B
#define GL_VERTEX_ARRAY_STRIDE 0x807C
#define GL_NORMAL_ARRAY_TYPE 0x807E
#define GL_NORMAL_ARRAY_STRIDE 0x807F
#define GL_COLOR_ARRAY_SIZE 0x8081
#define GL_COLOR_ARRAY_TYPE 0x8082
#define GL_COLOR_ARRAY_STRIDE 0x8083
#define GL_INDEX_ARRAY_TYPE 0x8085
#define GL_INDEX_ARRAY_STRIDE 0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define GL_TEXTURE_COMPONENTS 0x1003
#define GL_TEXTURE_BORDER 0x1005
#define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#define GL_TEXTURE_INTENSITY_SIZE 0x8061
#define GL_TEXTURE_PRIORITY 0x8066
#define GL_TEXTURE_RESIDENT 0x8067
#define GL_AMBIENT 0x1200
#define GL_DIFFUSE 0x1201
#define GL_SPECULAR 0x1202
#define GL_POSITION 0x1203
#define GL_SPOT_DIRECTION 0x1204
#define GL_SPOT_EXPONENT 0x1205
#define GL_SPOT_CUTOFF 0x1206
#define GL_CONSTANT_ATTENUATION 0x1207
#define GL_LINEAR_ATTENUATION 0x1208
#define GL_QUADRATIC_ATTENUATION 0x1209
#define GL_COMPILE 0x1300
#define GL_COMPILE_AND_EXECUTE 0x1301
#define GL_2_BYTES 0x1407
#define GL_3_BYTES 0x1408
#define GL_4_BYTES 0x1409
#define GL_EMISSION 0x1600
#define GL_SHININESS 0x1601
#define GL_AMBIENT_AND_DIFFUSE 0x1602
#define GL_COLOR_INDEXES 0x1603
#define GL_MODELVIEW 0x1700
#define GL_PROJECTION 0x1701
#define GL_COLOR_INDEX 0x1900
#define GL_LUMINANCE 0x1909
#define GL_LUMINANCE_ALPHA 0x190A
#define GL_BITMAP 0x1A00
#define GL_RENDER 0x1C00
#define GL_FEEDBACK 0x1C01
#define GL_SELECT 0x1C02
#define GL_FLAT 0x1D00
#define GL_SMOOTH 0x1D01
#define GL_S 0x2000
#define GL_T 0x2001
#define GL_R 0x2002
#define GL_Q 0x2003
#define GL_MODULATE 0x2100
#define GL_DECAL 0x2101
#define GL_TEXTURE_ENV_MODE 0x2200
#define GL_TEXTURE_ENV_COLOR 0x2201
#define GL_TEXTURE_ENV 0x2300
#define GL_EYE_LINEAR 0x2400
#define GL_OBJECT_LINEAR 0x2401
#define GL_SPHERE_MAP 0x2402
#define GL_TEXTURE_GEN_MODE 0x2500
#define GL_OBJECT_PLANE 0x2501
#define GL_CLAMP 0x2900
#define GL_ALPHA4 0x803B
#define GL_ALPHA8 0x803C
#define GL_ALPHA12 0x803D
#define GL_ALPHA16 0x803E
#define GL_LUMINANCE4 0x803F
#define GL_LUMINANCE8 0x8040
#define GL_LUMINANCE12 0x8041
#define GL_LUMINANCE16 0x8042
#define GL_LUMINANCE4_ALPHA4 0x8043
#define GL_LUMINANCE6_ALPHA2 0x8044
#define GL_LUMINANCE8_ALPHA8 0x8045
#define GL_LUMINANCE12_ALPHA4 0x8046
#define GL_LUMINANCE12_ALPHA12 0x8047
#define GL_LUMINANCE16_ALPHA16 0x8048
#define GL_INTENSITY 0x8049
#define GL_INTENSITY4 0x804A
#define GL_INTENSITY8 0x804B
#define GL_INTENSITY12 0x804C
#define GL_INTENSITY16 0x804D
#define GL_V2F 0x2A20
#define GL_V3F 0x2A21
#define GL_C4UB_V2F 0x2A22
#define GL_C4UB_V3F 0x2A23
#define GL_C3F_V3F 0x2A24
#define GL_N3F_V3F 0x2A25
#define GL_C4F_N3F_V3F 0x2A26
#define GL_T2F_V3F 0x2A27
#define GL_T4F_V4F 0x2A28
#define GL_T2F_C4UB_V3F 0x2A29
#define GL_T2F_C3F_V3F 0x2A2A
#define GL_T2F_N3F_V3F 0x2A2B
#define GL_T2F_C4F_N3F_V3F 0x2A2C
#define GL_T4F_C4F_N3F_V4F 0x2A2D
#define GL_CLIP_PLANE0 0x3000
#define GL_CLIP_PLANE1 0x3001
#define GL_CLIP_PLANE2 0x3002
#define GL_CLIP_PLANE3 0x3003
#define GL_CLIP_PLANE4 0x3004
#define GL_CLIP_PLANE5 0x3005
#define GL_LIGHT0 0x4000
#define GL_LIGHT1 0x4001
#define GL_LIGHT2 0x4002
#define GL_LIGHT3 0x4003
#define GL_LIGHT4 0x4004
#define GL_LIGHT5 0x4005
#define GL_LIGHT6 0x4006
#define GL_LIGHT7 0x4007

typedef void (CODEGEN_FUNCPTR * PFNGLNEWLISTPROC)(GLuint list, GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLENDLISTPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLCALLLISTPROC)(GLuint list);
typedef void (CODEGEN_FUNCPTR * PFNGLCALLLISTSPROC)(GLsizei n, GLenum type, const GLvoid *lists);
typedef void (CODEGEN_FUNCPTR * PFNGLDELETELISTSPROC)(GLuint list, GLsizei range);
typedef GLuint (CODEGEN_FUNCPTR * PFNGLGENLISTSPROC)(GLsizei range);
typedef void (CODEGEN_FUNCPTR * PFNGLLISTBASEPROC)(GLuint base);
typedef void (CODEGEN_FUNCPTR * PFNGLBEGINPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLBITMAPPROC)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3BPROC)(GLbyte red, GLbyte green, GLbyte blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3BVPROC)(const GLbyte *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3DPROC)(GLdouble red, GLdouble green, GLdouble blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3FPROC)(GLfloat red, GLfloat green, GLfloat blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3IPROC)(GLint red, GLint green, GLint blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3SPROC)(GLshort red, GLshort green, GLshort blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3UBPROC)(GLubyte red, GLubyte green, GLubyte blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3UBVPROC)(const GLubyte *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3UIPROC)(GLuint red, GLuint green, GLuint blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3UIVPROC)(const GLuint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3USPROC)(GLushort red, GLushort green, GLushort blue);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR3USVPROC)(const GLushort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4BPROC)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4BVPROC)(const GLbyte *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4DPROC)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4FPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4IPROC)(GLint red, GLint green, GLint blue, GLint alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4SPROC)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4UBPROC)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4UBVPROC)(const GLubyte *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4UIPROC)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4UIVPROC)(const GLuint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4USPROC)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLOR4USVPROC)(const GLushort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLEDGEFLAGPROC)(GLboolean flag);
typedef void (CODEGEN_FUNCPTR * PFNGLEDGEFLAGVPROC)(const GLboolean *flag);
typedef void (CODEGEN_FUNCPTR * PFNGLENDPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXDPROC)(GLdouble c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXDVPROC)(const GLdouble *c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXFPROC)(GLfloat c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXFVPROC)(const GLfloat *c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXIPROC)(GLint c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXIVPROC)(const GLint *c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXSPROC)(GLshort c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXSVPROC)(const GLshort *c);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3BPROC)(GLbyte nx, GLbyte ny, GLbyte nz);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3BVPROC)(const GLbyte *v);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3DPROC)(GLdouble nx, GLdouble ny, GLdouble nz);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3FPROC)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3IPROC)(GLint nx, GLint ny, GLint nz);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3SPROC)(GLshort nx, GLshort ny, GLshort nz);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMAL3SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2DPROC)(GLdouble x, GLdouble y);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2FPROC)(GLfloat x, GLfloat y);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2IPROC)(GLint x, GLint y);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2SPROC)(GLshort x, GLshort y);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS2SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3IPROC)(GLint x, GLint y, GLint z);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS3SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (CODEGEN_FUNCPTR * PFNGLRASTERPOS4SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTDPROC)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTDVPROC)(const GLdouble *v1, const GLdouble *v2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTFPROC)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTFVPROC)(const GLfloat *v1, const GLfloat *v2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTIPROC)(GLint x1, GLint y1, GLint x2, GLint y2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTIVPROC)(const GLint *v1, const GLint *v2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTSPROC)(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
typedef void (CODEGEN_FUNCPTR * PFNGLRECTSVPROC)(const GLshort *v1, const GLshort *v2);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1DPROC)(GLdouble s);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1FPROC)(GLfloat s);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1IPROC)(GLint s);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1SPROC)(GLshort s);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD1SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2DPROC)(GLdouble s, GLdouble t);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2FPROC)(GLfloat s, GLfloat t);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2IPROC)(GLint s, GLint t);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2SPROC)(GLshort s, GLshort t);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD2SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3DPROC)(GLdouble s, GLdouble t, GLdouble r);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3FPROC)(GLfloat s, GLfloat t, GLfloat r);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3IPROC)(GLint s, GLint t, GLint r);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3SPROC)(GLshort s, GLshort t, GLshort r);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD3SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4DPROC)(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4FPROC)(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4IPROC)(GLint s, GLint t, GLint r, GLint q);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4SPROC)(GLshort s, GLshort t, GLshort r, GLshort q);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORD4SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2DPROC)(GLdouble x, GLdouble y);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2FPROC)(GLfloat x, GLfloat y);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2IPROC)(GLint x, GLint y);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2SPROC)(GLshort x, GLshort y);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX2SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3DPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3FPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3IPROC)(GLint x, GLint y, GLint z);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3SPROC)(GLshort x, GLshort y, GLshort z);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX3SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4DPROC)(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4DVPROC)(const GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4FPROC)(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4FVPROC)(const GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4IPROC)(GLint x, GLint y, GLint z, GLint w);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4IVPROC)(const GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4SPROC)(GLshort x, GLshort y, GLshort z, GLshort w);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEX4SVPROC)(const GLshort *v);
typedef void (CODEGEN_FUNCPTR * PFNGLCLIPPLANEPROC)(GLenum plane, const GLdouble *equation);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORMATERIALPROC)(GLenum face, GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLFOGFPROC)(GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLFOGFVPROC)(GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLFOGIPROC)(GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLFOGIVPROC)(GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTFPROC)(GLenum light, GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTFVPROC)(GLenum light, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTIPROC)(GLenum light, GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTIVPROC)(GLenum light, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTMODELFPROC)(GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTMODELFVPROC)(GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTMODELIPROC)(GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLLIGHTMODELIVPROC)(GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLLINESTIPPLEPROC)(GLint factor, GLushort pattern);
typedef void (CODEGEN_FUNCPTR * PFNGLMATERIALFPROC)(GLenum face, GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLMATERIALFVPROC)(GLenum face, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLMATERIALIPROC)(GLenum face, GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLMATERIALIVPROC)(GLenum face, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLPOLYGONSTIPPLEPROC)(const GLubyte *mask);
typedef void (CODEGEN_FUNCPTR * PFNGLSHADEMODELPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXENVFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXENVFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXENVIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXENVIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENDPROC)(GLenum coord, GLenum pname, GLdouble param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENDVPROC)(GLenum coord, GLenum pname, const GLdouble *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENFPROC)(GLenum coord, GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENFVPROC)(GLenum coord, GLenum pname, const GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENIPROC)(GLenum coord, GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXGENIVPROC)(GLenum coord, GLenum pname, const GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLFEEDBACKBUFFERPROC)(GLsizei size, GLenum type, GLfloat *buffer);
typedef void (CODEGEN_FUNCPTR * PFNGLSELECTBUFFERPROC)(GLsizei size, GLuint *buffer);
typedef GLint (CODEGEN_FUNCPTR * PFNGLRENDERMODEPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLINITNAMESPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLLOADNAMEPROC)(GLuint name);
typedef void (CODEGEN_FUNCPTR * PFNGLPASSTHROUGHPROC)(GLfloat token);
typedef void (CODEGEN_FUNCPTR * PFNGLPOPNAMEPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLPUSHNAMEPROC)(GLuint name);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARACCUMPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (CODEGEN_FUNCPTR * PFNGLCLEARINDEXPROC)(GLfloat c);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXMASKPROC)(GLuint mask);
typedef void (CODEGEN_FUNCPTR * PFNGLACCUMPROC)(GLenum op, GLfloat value);
typedef void (CODEGEN_FUNCPTR * PFNGLPOPATTRIBPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLPUSHATTRIBPROC)(GLbitfield mask);
typedef void (CODEGEN_FUNCPTR * PFNGLMAP1DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
typedef void (CODEGEN_FUNCPTR * PFNGLMAP1FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
typedef void (CODEGEN_FUNCPTR * PFNGLMAP2DPROC)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
typedef void (CODEGEN_FUNCPTR * PFNGLMAP2FPROC)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
typedef void (CODEGEN_FUNCPTR * PFNGLMAPGRID1DPROC)(GLint un, GLdouble u1, GLdouble u2);
typedef void (CODEGEN_FUNCPTR * PFNGLMAPGRID1FPROC)(GLint un, GLfloat u1, GLfloat u2);
typedef void (CODEGEN_FUNCPTR * PFNGLMAPGRID2DPROC)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef void (CODEGEN_FUNCPTR * PFNGLMAPGRID2FPROC)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD1DPROC)(GLdouble u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD1DVPROC)(const GLdouble *u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD1FPROC)(GLfloat u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD1FVPROC)(const GLfloat *u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD2DPROC)(GLdouble u, GLdouble v);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD2DVPROC)(const GLdouble *u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD2FPROC)(GLfloat u, GLfloat v);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALCOORD2FVPROC)(const GLfloat *u);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALMESH1PROC)(GLenum mode, GLint i1, GLint i2);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALPOINT1PROC)(GLint i);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALMESH2PROC)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef void (CODEGEN_FUNCPTR * PFNGLEVALPOINT2PROC)(GLint i, GLint j);
typedef void (CODEGEN_FUNCPTR * PFNGLALPHAFUNCPROC)(GLenum func, GLfloat ref);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELZOOMPROC)(GLfloat xfactor, GLfloat yfactor);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELTRANSFERFPROC)(GLenum pname, GLfloat param);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELTRANSFERIPROC)(GLenum pname, GLint param);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELMAPFVPROC)(GLenum map, GLsizei mapsize, const GLfloat *values);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELMAPUIVPROC)(GLenum map, GLsizei mapsize, const GLuint *values);
typedef void (CODEGEN_FUNCPTR * PFNGLPIXELMAPUSVPROC)(GLenum map, GLsizei mapsize, const GLushort *values);
typedef void (CODEGEN_FUNCPTR * PFNGLCOPYPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef void (CODEGEN_FUNCPTR * PFNGLDRAWPIXELSPROC)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
typedef void (CODEGEN_FUNCPTR * PFNGLGETCLIPPLANEPROC)(GLenum plane, GLdouble *equation);
typedef void (CODEGEN_FUNCPTR * PFNGLGETLIGHTFVPROC)(GLenum light, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETLIGHTIVPROC)(GLenum light, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMAPDVPROC)(GLenum target, GLenum query, GLdouble *v);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMAPFVPROC)(GLenum target, GLenum query, GLfloat *v);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMAPIVPROC)(GLenum target, GLenum query, GLint *v);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMATERIALFVPROC)(GLenum face, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETMATERIALIVPROC)(GLenum face, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETPIXELMAPFVPROC)(GLenum map, GLfloat *values);
typedef void (CODEGEN_FUNCPTR * PFNGLGETPIXELMAPUIVPROC)(GLenum map, GLuint *values);
typedef void (CODEGEN_FUNCPTR * PFNGLGETPIXELMAPUSVPROC)(GLenum map, GLushort *values);
typedef void (CODEGEN_FUNCPTR * PFNGLGETPOLYGONSTIPPLEPROC)(GLubyte *mask);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXENVFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXENVIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXGENDVPROC)(GLenum coord, GLenum pname, GLdouble *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXGENFVPROC)(GLenum coord, GLenum pname, GLfloat *params);
typedef void (CODEGEN_FUNCPTR * PFNGLGETTEXGENIVPROC)(GLenum coord, GLenum pname, GLint *params);
typedef GLboolean (CODEGEN_FUNCPTR * PFNGLISLISTPROC)(GLuint list);
typedef void (CODEGEN_FUNCPTR * PFNGLFRUSTUMPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (CODEGEN_FUNCPTR * PFNGLLOADIDENTITYPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLLOADMATRIXFPROC)(const GLfloat *m);
typedef void (CODEGEN_FUNCPTR * PFNGLLOADMATRIXDPROC)(const GLdouble *m);
typedef void (CODEGEN_FUNCPTR * PFNGLMATRIXMODEPROC)(GLenum mode);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTMATRIXFPROC)(const GLfloat *m);
typedef void (CODEGEN_FUNCPTR * PFNGLMULTMATRIXDPROC)(const GLdouble *m);
typedef void (CODEGEN_FUNCPTR * PFNGLORTHOPROC)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef void (CODEGEN_FUNCPTR * PFNGLPOPMATRIXPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLPUSHMATRIXPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLROTATEDPROC)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
typedef void (CODEGEN_FUNCPTR * PFNGLROTATEFPROC)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
typedef void (CODEGEN_FUNCPTR * PFNGLSCALEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (CODEGEN_FUNCPTR * PFNGLSCALEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (CODEGEN_FUNCPTR * PFNGLTRANSLATEDPROC)(GLdouble x, GLdouble y, GLdouble z);
typedef void (CODEGEN_FUNCPTR * PFNGLTRANSLATEFPROC)(GLfloat x, GLfloat y, GLfloat z);
typedef void (CODEGEN_FUNCPTR * PFNGLARRAYELEMENTPROC)(GLint i);
typedef void (CODEGEN_FUNCPTR * PFNGLCOLORPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLDISABLECLIENTSTATEPROC)(GLenum ren_array);
typedef void (CODEGEN_FUNCPTR * PFNGLEDGEFLAGPOINTERPROC)(GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLENABLECLIENTSTATEPROC)(GLenum ren_array);
typedef void (CODEGEN_FUNCPTR * PFNGLINDEXPOINTERPROC)(GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLINTERLEAVEDARRAYSPROC)(GLenum format, GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLNORMALPOINTERPROC)(GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLTEXCOORDPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef void (CODEGEN_FUNCPTR * PFNGLVERTEXPOINTERPROC)(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef GLboolean (CODEGEN_FUNCPTR * PFNGLARETEXTURESRESIDENTPROC)(GLsizei n, const GLuint *textures, GLboolean *residences);
typedef void (CODEGEN_FUNCPTR * PFNGLPRIORITIZETEXTURESPROC)(GLsizei n, const GLuint *textures, const GLfloat *priorities);
typedef void (CODEGEN_FUNCPTR * PFNGLPOPCLIENTATTRIBPROC)();
typedef void (CODEGEN_FUNCPTR * PFNGLPUSHCLIENTATTRIBPROC)(GLbitfield mask);

extern PFNGLNEWLISTPROC _funcptr_glNewList;
#define glNewList _funcptr_glNewList
extern PFNGLENDLISTPROC _funcptr_glEndList;
#define glEndList _funcptr_glEndList
extern PFNGLCALLLISTPROC _funcptr_glCallList;
#define glCallList _funcptr_glCallList
extern PFNGLCALLLISTSPROC _funcptr_glCallLists;
#define glCallLists _funcptr_glCallLists
extern PFNGLDELETELISTSPROC _funcptr_glDeleteLists;
#define glDeleteLists _funcptr_glDeleteLists
extern PFNGLGENLISTSPROC _funcptr_glGenLists;
#define glGenLists _funcptr_glGenLists
extern PFNGLLISTBASEPROC _funcptr_glListBase;
#define glListBase _funcptr_glListBase
extern PFNGLBEGINPROC _funcptr_glBegin;
#define glBegin _funcptr_glBegin
extern PFNGLBITMAPPROC _funcptr_glBitmap;
#define glBitmap _funcptr_glBitmap
extern PFNGLCOLOR3BPROC _funcptr_glColor3b;
#define glColor3b _funcptr_glColor3b
extern PFNGLCOLOR3BVPROC _funcptr_glColor3bv;
#define glColor3bv _funcptr_glColor3bv
extern PFNGLCOLOR3DPROC _funcptr_glColor3d;
#define glColor3d _funcptr_glColor3d
extern PFNGLCOLOR3DVPROC _funcptr_glColor3dv;
#define glColor3dv _funcptr_glColor3dv
extern PFNGLCOLOR3FPROC _funcptr_glColor3f;
#define glColor3f _funcptr_glColor3f
extern PFNGLCOLOR3FVPROC _funcptr_glColor3fv;
#define glColor3fv _funcptr_glColor3fv
extern PFNGLCOLOR3IPROC _funcptr_glColor3i;
#define glColor3i _funcptr_glColor3i
extern PFNGLCOLOR3IVPROC _funcptr_glColor3iv;
#define glColor3iv _funcptr_glColor3iv
extern PFNGLCOLOR3SPROC _funcptr_glColor3s;
#define glColor3s _funcptr_glColor3s
extern PFNGLCOLOR3SVPROC _funcptr_glColor3sv;
#define glColor3sv _funcptr_glColor3sv
extern PFNGLCOLOR3UBPROC _funcptr_glColor3ub;
#define glColor3ub _funcptr_glColor3ub
extern PFNGLCOLOR3UBVPROC _funcptr_glColor3ubv;
#define glColor3ubv _funcptr_glColor3ubv
extern PFNGLCOLOR3UIPROC _funcptr_glColor3ui;
#define glColor3ui _funcptr_glColor3ui
extern PFNGLCOLOR3UIVPROC _funcptr_glColor3uiv;
#define glColor3uiv _funcptr_glColor3uiv
extern PFNGLCOLOR3USPROC _funcptr_glColor3us;
#define glColor3us _funcptr_glColor3us
extern PFNGLCOLOR3USVPROC _funcptr_glColor3usv;
#define glColor3usv _funcptr_glColor3usv
extern PFNGLCOLOR4BPROC _funcptr_glColor4b;
#define glColor4b _funcptr_glColor4b
extern PFNGLCOLOR4BVPROC _funcptr_glColor4bv;
#define glColor4bv _funcptr_glColor4bv
extern PFNGLCOLOR4DPROC _funcptr_glColor4d;
#define glColor4d _funcptr_glColor4d
extern PFNGLCOLOR4DVPROC _funcptr_glColor4dv;
#define glColor4dv _funcptr_glColor4dv
extern PFNGLCOLOR4FPROC _funcptr_glColor4f;
#define glColor4f _funcptr_glColor4f
extern PFNGLCOLOR4FVPROC _funcptr_glColor4fv;
#define glColor4fv _funcptr_glColor4fv
extern PFNGLCOLOR4IPROC _funcptr_glColor4i;
#define glColor4i _funcptr_glColor4i
extern PFNGLCOLOR4IVPROC _funcptr_glColor4iv;
#define glColor4iv _funcptr_glColor4iv
extern PFNGLCOLOR4SPROC _funcptr_glColor4s;
#define glColor4s _funcptr_glColor4s
extern PFNGLCOLOR4SVPROC _funcptr_glColor4sv;
#define glColor4sv _funcptr_glColor4sv
extern PFNGLCOLOR4UBPROC _funcptr_glColor4ub;
#define glColor4ub _funcptr_glColor4ub
extern PFNGLCOLOR4UBVPROC _funcptr_glColor4ubv;
#define glColor4ubv _funcptr_glColor4ubv
extern PFNGLCOLOR4UIPROC _funcptr_glColor4ui;
#define glColor4ui _funcptr_glColor4ui
extern PFNGLCOLOR4UIVPROC _funcptr_glColor4uiv;
#define glColor4uiv _funcptr_glColor4uiv
extern PFNGLCOLOR4USPROC _funcptr_glColor4us;
#define glColor4us _funcptr_glColor4us
extern PFNGLCOLOR4USVPROC _funcptr_glColor4usv;
#define glColor4usv _funcptr_glColor4usv
extern PFNGLEDGEFLAGPROC _funcptr_glEdgeFlag;
#define glEdgeFlag _funcptr_glEdgeFlag
extern PFNGLEDGEFLAGVPROC _funcptr_glEdgeFlagv;
#define glEdgeFlagv _funcptr_glEdgeFlagv
extern PFNGLENDPROC _funcptr_glEnd;
#define glEnd _funcptr_glEnd
extern PFNGLINDEXDPROC _funcptr_glIndexd;
#define glIndexd _funcptr_glIndexd
extern PFNGLINDEXDVPROC _funcptr_glIndexdv;
#define glIndexdv _funcptr_glIndexdv
extern PFNGLINDEXFPROC _funcptr_glIndexf;
#define glIndexf _funcptr_glIndexf
extern PFNGLINDEXFVPROC _funcptr_glIndexfv;
#define glIndexfv _funcptr_glIndexfv
extern PFNGLINDEXIPROC _funcptr_glIndexi;
#define glIndexi _funcptr_glIndexi
extern PFNGLINDEXIVPROC _funcptr_glIndexiv;
#define glIndexiv _funcptr_glIndexiv
extern PFNGLINDEXSPROC _funcptr_glIndexs;
#define glIndexs _funcptr_glIndexs
extern PFNGLINDEXSVPROC _funcptr_glIndexsv;
#define glIndexsv _funcptr_glIndexsv
extern PFNGLNORMAL3BPROC _funcptr_glNormal3b;
#define glNormal3b _funcptr_glNormal3b
extern PFNGLNORMAL3BVPROC _funcptr_glNormal3bv;
#define glNormal3bv _funcptr_glNormal3bv
extern PFNGLNORMAL3DPROC _funcptr_glNormal3d;
#define glNormal3d _funcptr_glNormal3d
extern PFNGLNORMAL3DVPROC _funcptr_glNormal3dv;
#define glNormal3dv _funcptr_glNormal3dv
extern PFNGLNORMAL3FPROC _funcptr_glNormal3f;
#define glNormal3f _funcptr_glNormal3f
extern PFNGLNORMAL3FVPROC _funcptr_glNormal3fv;
#define glNormal3fv _funcptr_glNormal3fv
extern PFNGLNORMAL3IPROC _funcptr_glNormal3i;
#define glNormal3i _funcptr_glNormal3i
extern PFNGLNORMAL3IVPROC _funcptr_glNormal3iv;
#define glNormal3iv _funcptr_glNormal3iv
extern PFNGLNORMAL3SPROC _funcptr_glNormal3s;
#define glNormal3s _funcptr_glNormal3s
extern PFNGLNORMAL3SVPROC _funcptr_glNormal3sv;
#define glNormal3sv _funcptr_glNormal3sv
extern PFNGLRASTERPOS2DPROC _funcptr_glRasterPos2d;
#define glRasterPos2d _funcptr_glRasterPos2d
extern PFNGLRASTERPOS2DVPROC _funcptr_glRasterPos2dv;
#define glRasterPos2dv _funcptr_glRasterPos2dv
extern PFNGLRASTERPOS2FPROC _funcptr_glRasterPos2f;
#define glRasterPos2f _funcptr_glRasterPos2f
extern PFNGLRASTERPOS2FVPROC _funcptr_glRasterPos2fv;
#define glRasterPos2fv _funcptr_glRasterPos2fv
extern PFNGLRASTERPOS2IPROC _funcptr_glRasterPos2i;
#define glRasterPos2i _funcptr_glRasterPos2i
extern PFNGLRASTERPOS2IVPROC _funcptr_glRasterPos2iv;
#define glRasterPos2iv _funcptr_glRasterPos2iv
extern PFNGLRASTERPOS2SPROC _funcptr_glRasterPos2s;
#define glRasterPos2s _funcptr_glRasterPos2s
extern PFNGLRASTERPOS2SVPROC _funcptr_glRasterPos2sv;
#define glRasterPos2sv _funcptr_glRasterPos2sv
extern PFNGLRASTERPOS3DPROC _funcptr_glRasterPos3d;
#define glRasterPos3d _funcptr_glRasterPos3d
extern PFNGLRASTERPOS3DVPROC _funcptr_glRasterPos3dv;
#define glRasterPos3dv _funcptr_glRasterPos3dv
extern PFNGLRASTERPOS3FPROC _funcptr_glRasterPos3f;
#define glRasterPos3f _funcptr_glRasterPos3f
extern PFNGLRASTERPOS3FVPROC _funcptr_glRasterPos3fv;
#define glRasterPos3fv _funcptr_glRasterPos3fv
extern PFNGLRASTERPOS3IPROC _funcptr_glRasterPos3i;
#define glRasterPos3i _funcptr_glRasterPos3i
extern PFNGLRASTERPOS3IVPROC _funcptr_glRasterPos3iv;
#define glRasterPos3iv _funcptr_glRasterPos3iv
extern PFNGLRASTERPOS3SPROC _funcptr_glRasterPos3s;
#define glRasterPos3s _funcptr_glRasterPos3s
extern PFNGLRASTERPOS3SVPROC _funcptr_glRasterPos3sv;
#define glRasterPos3sv _funcptr_glRasterPos3sv
extern PFNGLRASTERPOS4DPROC _funcptr_glRasterPos4d;
#define glRasterPos4d _funcptr_glRasterPos4d
extern PFNGLRASTERPOS4DVPROC _funcptr_glRasterPos4dv;
#define glRasterPos4dv _funcptr_glRasterPos4dv
extern PFNGLRASTERPOS4FPROC _funcptr_glRasterPos4f;
#define glRasterPos4f _funcptr_glRasterPos4f
extern PFNGLRASTERPOS4FVPROC _funcptr_glRasterPos4fv;
#define glRasterPos4fv _funcptr_glRasterPos4fv
extern PFNGLRASTERPOS4IPROC _funcptr_glRasterPos4i;
#define glRasterPos4i _funcptr_glRasterPos4i
extern PFNGLRASTERPOS4IVPROC _funcptr_glRasterPos4iv;
#define glRasterPos4iv _funcptr_glRasterPos4iv
extern PFNGLRASTERPOS4SPROC _funcptr_glRasterPos4s;
#define glRasterPos4s _funcptr_glRasterPos4s
extern PFNGLRASTERPOS4SVPROC _funcptr_glRasterPos4sv;
#define glRasterPos4sv _funcptr_glRasterPos4sv
extern PFNGLRECTDPROC _funcptr_glRectd;
#define glRectd _funcptr_glRectd
extern PFNGLRECTDVPROC _funcptr_glRectdv;
#define glRectdv _funcptr_glRectdv
extern PFNGLRECTFPROC _funcptr_glRectf;
#define glRectf _funcptr_glRectf
extern PFNGLRECTFVPROC _funcptr_glRectfv;
#define glRectfv _funcptr_glRectfv
extern PFNGLRECTIPROC _funcptr_glRecti;
#define glRecti _funcptr_glRecti
extern PFNGLRECTIVPROC _funcptr_glRectiv;
#define glRectiv _funcptr_glRectiv
extern PFNGLRECTSPROC _funcptr_glRects;
#define glRects _funcptr_glRects
extern PFNGLRECTSVPROC _funcptr_glRectsv;
#define glRectsv _funcptr_glRectsv
extern PFNGLTEXCOORD1DPROC _funcptr_glTexCoord1d;
#define glTexCoord1d _funcptr_glTexCoord1d
extern PFNGLTEXCOORD1DVPROC _funcptr_glTexCoord1dv;
#define glTexCoord1dv _funcptr_glTexCoord1dv
extern PFNGLTEXCOORD1FPROC _funcptr_glTexCoord1f;
#define glTexCoord1f _funcptr_glTexCoord1f
extern PFNGLTEXCOORD1FVPROC _funcptr_glTexCoord1fv;
#define glTexCoord1fv _funcptr_glTexCoord1fv
extern PFNGLTEXCOORD1IPROC _funcptr_glTexCoord1i;
#define glTexCoord1i _funcptr_glTexCoord1i
extern PFNGLTEXCOORD1IVPROC _funcptr_glTexCoord1iv;
#define glTexCoord1iv _funcptr_glTexCoord1iv
extern PFNGLTEXCOORD1SPROC _funcptr_glTexCoord1s;
#define glTexCoord1s _funcptr_glTexCoord1s
extern PFNGLTEXCOORD1SVPROC _funcptr_glTexCoord1sv;
#define glTexCoord1sv _funcptr_glTexCoord1sv
extern PFNGLTEXCOORD2DPROC _funcptr_glTexCoord2d;
#define glTexCoord2d _funcptr_glTexCoord2d
extern PFNGLTEXCOORD2DVPROC _funcptr_glTexCoord2dv;
#define glTexCoord2dv _funcptr_glTexCoord2dv
extern PFNGLTEXCOORD2FPROC _funcptr_glTexCoord2f;
#define glTexCoord2f _funcptr_glTexCoord2f
extern PFNGLTEXCOORD2FVPROC _funcptr_glTexCoord2fv;
#define glTexCoord2fv _funcptr_glTexCoord2fv
extern PFNGLTEXCOORD2IPROC _funcptr_glTexCoord2i;
#define glTexCoord2i _funcptr_glTexCoord2i
extern PFNGLTEXCOORD2IVPROC _funcptr_glTexCoord2iv;
#define glTexCoord2iv _funcptr_glTexCoord2iv
extern PFNGLTEXCOORD2SPROC _funcptr_glTexCoord2s;
#define glTexCoord2s _funcptr_glTexCoord2s
extern PFNGLTEXCOORD2SVPROC _funcptr_glTexCoord2sv;
#define glTexCoord2sv _funcptr_glTexCoord2sv
extern PFNGLTEXCOORD3DPROC _funcptr_glTexCoord3d;
#define glTexCoord3d _funcptr_glTexCoord3d
extern PFNGLTEXCOORD3DVPROC _funcptr_glTexCoord3dv;
#define glTexCoord3dv _funcptr_glTexCoord3dv
extern PFNGLTEXCOORD3FPROC _funcptr_glTexCoord3f;
#define glTexCoord3f _funcptr_glTexCoord3f
extern PFNGLTEXCOORD3FVPROC _funcptr_glTexCoord3fv;
#define glTexCoord3fv _funcptr_glTexCoord3fv
extern PFNGLTEXCOORD3IPROC _funcptr_glTexCoord3i;
#define glTexCoord3i _funcptr_glTexCoord3i
extern PFNGLTEXCOORD3IVPROC _funcptr_glTexCoord3iv;
#define glTexCoord3iv _funcptr_glTexCoord3iv
extern PFNGLTEXCOORD3SPROC _funcptr_glTexCoord3s;
#define glTexCoord3s _funcptr_glTexCoord3s
extern PFNGLTEXCOORD3SVPROC _funcptr_glTexCoord3sv;
#define glTexCoord3sv _funcptr_glTexCoord3sv
extern PFNGLTEXCOORD4DPROC _funcptr_glTexCoord4d;
#define glTexCoord4d _funcptr_glTexCoord4d
extern PFNGLTEXCOORD4DVPROC _funcptr_glTexCoord4dv;
#define glTexCoord4dv _funcptr_glTexCoord4dv
extern PFNGLTEXCOORD4FPROC _funcptr_glTexCoord4f;
#define glTexCoord4f _funcptr_glTexCoord4f
extern PFNGLTEXCOORD4FVPROC _funcptr_glTexCoord4fv;
#define glTexCoord4fv _funcptr_glTexCoord4fv
extern PFNGLTEXCOORD4IPROC _funcptr_glTexCoord4i;
#define glTexCoord4i _funcptr_glTexCoord4i
extern PFNGLTEXCOORD4IVPROC _funcptr_glTexCoord4iv;
#define glTexCoord4iv _funcptr_glTexCoord4iv
extern PFNGLTEXCOORD4SPROC _funcptr_glTexCoord4s;
#define glTexCoord4s _funcptr_glTexCoord4s
extern PFNGLTEXCOORD4SVPROC _funcptr_glTexCoord4sv;
#define glTexCoord4sv _funcptr_glTexCoord4sv
extern PFNGLVERTEX2DPROC _funcptr_glVertex2d;
#define glVertex2d _funcptr_glVertex2d
extern PFNGLVERTEX2DVPROC _funcptr_glVertex2dv;
#define glVertex2dv _funcptr_glVertex2dv
extern PFNGLVERTEX2FPROC _funcptr_glVertex2f;
#define glVertex2f _funcptr_glVertex2f
extern PFNGLVERTEX2FVPROC _funcptr_glVertex2fv;
#define glVertex2fv _funcptr_glVertex2fv
extern PFNGLVERTEX2IPROC _funcptr_glVertex2i;
#define glVertex2i _funcptr_glVertex2i
extern PFNGLVERTEX2IVPROC _funcptr_glVertex2iv;
#define glVertex2iv _funcptr_glVertex2iv
extern PFNGLVERTEX2SPROC _funcptr_glVertex2s;
#define glVertex2s _funcptr_glVertex2s
extern PFNGLVERTEX2SVPROC _funcptr_glVertex2sv;
#define glVertex2sv _funcptr_glVertex2sv
extern PFNGLVERTEX3DPROC _funcptr_glVertex3d;
#define glVertex3d _funcptr_glVertex3d
extern PFNGLVERTEX3DVPROC _funcptr_glVertex3dv;
#define glVertex3dv _funcptr_glVertex3dv
extern PFNGLVERTEX3FPROC _funcptr_glVertex3f;
#define glVertex3f _funcptr_glVertex3f
extern PFNGLVERTEX3FVPROC _funcptr_glVertex3fv;
#define glVertex3fv _funcptr_glVertex3fv
extern PFNGLVERTEX3IPROC _funcptr_glVertex3i;
#define glVertex3i _funcptr_glVertex3i
extern PFNGLVERTEX3IVPROC _funcptr_glVertex3iv;
#define glVertex3iv _funcptr_glVertex3iv
extern PFNGLVERTEX3SPROC _funcptr_glVertex3s;
#define glVertex3s _funcptr_glVertex3s
extern PFNGLVERTEX3SVPROC _funcptr_glVertex3sv;
#define glVertex3sv _funcptr_glVertex3sv
extern PFNGLVERTEX4DPROC _funcptr_glVertex4d;
#define glVertex4d _funcptr_glVertex4d
extern PFNGLVERTEX4DVPROC _funcptr_glVertex4dv;
#define glVertex4dv _funcptr_glVertex4dv
extern PFNGLVERTEX4FPROC _funcptr_glVertex4f;
#define glVertex4f _funcptr_glVertex4f
extern PFNGLVERTEX4FVPROC _funcptr_glVertex4fv;
#define glVertex4fv _funcptr_glVertex4fv
extern PFNGLVERTEX4IPROC _funcptr_glVertex4i;
#define glVertex4i _funcptr_glVertex4i
extern PFNGLVERTEX4IVPROC _funcptr_glVertex4iv;
#define glVertex4iv _funcptr_glVertex4iv
extern PFNGLVERTEX4SPROC _funcptr_glVertex4s;
#define glVertex4s _funcptr_glVertex4s
extern PFNGLVERTEX4SVPROC _funcptr_glVertex4sv;
#define glVertex4sv _funcptr_glVertex4sv
extern PFNGLCLIPPLANEPROC _funcptr_glClipPlane;
#define glClipPlane _funcptr_glClipPlane
extern PFNGLCOLORMATERIALPROC _funcptr_glColorMaterial;
#define glColorMaterial _funcptr_glColorMaterial
extern PFNGLFOGFPROC _funcptr_glFogf;
#define glFogf _funcptr_glFogf
extern PFNGLFOGFVPROC _funcptr_glFogfv;
#define glFogfv _funcptr_glFogfv
extern PFNGLFOGIPROC _funcptr_glFogi;
#define glFogi _funcptr_glFogi
extern PFNGLFOGIVPROC _funcptr_glFogiv;
#define glFogiv _funcptr_glFogiv
extern PFNGLLIGHTFPROC _funcptr_glLightf;
#define glLightf _funcptr_glLightf
extern PFNGLLIGHTFVPROC _funcptr_glLightfv;
#define glLightfv _funcptr_glLightfv
extern PFNGLLIGHTIPROC _funcptr_glLighti;
#define glLighti _funcptr_glLighti
extern PFNGLLIGHTIVPROC _funcptr_glLightiv;
#define glLightiv _funcptr_glLightiv
extern PFNGLLIGHTMODELFPROC _funcptr_glLightModelf;
#define glLightModelf _funcptr_glLightModelf
extern PFNGLLIGHTMODELFVPROC _funcptr_glLightModelfv;
#define glLightModelfv _funcptr_glLightModelfv
extern PFNGLLIGHTMODELIPROC _funcptr_glLightModeli;
#define glLightModeli _funcptr_glLightModeli
extern PFNGLLIGHTMODELIVPROC _funcptr_glLightModeliv;
#define glLightModeliv _funcptr_glLightModeliv
extern PFNGLLINESTIPPLEPROC _funcptr_glLineStipple;
#define glLineStipple _funcptr_glLineStipple
extern PFNGLMATERIALFPROC _funcptr_glMaterialf;
#define glMaterialf _funcptr_glMaterialf
extern PFNGLMATERIALFVPROC _funcptr_glMaterialfv;
#define glMaterialfv _funcptr_glMaterialfv
extern PFNGLMATERIALIPROC _funcptr_glMateriali;
#define glMateriali _funcptr_glMateriali
extern PFNGLMATERIALIVPROC _funcptr_glMaterialiv;
#define glMaterialiv _funcptr_glMaterialiv
extern PFNGLPOLYGONSTIPPLEPROC _funcptr_glPolygonStipple;
#define glPolygonStipple _funcptr_glPolygonStipple
extern PFNGLSHADEMODELPROC _funcptr_glShadeModel;
#define glShadeModel _funcptr_glShadeModel
extern PFNGLTEXENVFPROC _funcptr_glTexEnvf;
#define glTexEnvf _funcptr_glTexEnvf
extern PFNGLTEXENVFVPROC _funcptr_glTexEnvfv;
#define glTexEnvfv _funcptr_glTexEnvfv
extern PFNGLTEXENVIPROC _funcptr_glTexEnvi;
#define glTexEnvi _funcptr_glTexEnvi
extern PFNGLTEXENVIVPROC _funcptr_glTexEnviv;
#define glTexEnviv _funcptr_glTexEnviv
extern PFNGLTEXGENDPROC _funcptr_glTexGend;
#define glTexGend _funcptr_glTexGend
extern PFNGLTEXGENDVPROC _funcptr_glTexGendv;
#define glTexGendv _funcptr_glTexGendv
extern PFNGLTEXGENFPROC _funcptr_glTexGenf;
#define glTexGenf _funcptr_glTexGenf
extern PFNGLTEXGENFVPROC _funcptr_glTexGenfv;
#define glTexGenfv _funcptr_glTexGenfv
extern PFNGLTEXGENIPROC _funcptr_glTexGeni;
#define glTexGeni _funcptr_glTexGeni
extern PFNGLTEXGENIVPROC _funcptr_glTexGeniv;
#define glTexGeniv _funcptr_glTexGeniv
extern PFNGLFEEDBACKBUFFERPROC _funcptr_glFeedbackBuffer;
#define glFeedbackBuffer _funcptr_glFeedbackBuffer
extern PFNGLSELECTBUFFERPROC _funcptr_glSelectBuffer;
#define glSelectBuffer _funcptr_glSelectBuffer
extern PFNGLRENDERMODEPROC _funcptr_glRenderMode;
#define glRenderMode _funcptr_glRenderMode
extern PFNGLINITNAMESPROC _funcptr_glInitNames;
#define glInitNames _funcptr_glInitNames
extern PFNGLLOADNAMEPROC _funcptr_glLoadName;
#define glLoadName _funcptr_glLoadName
extern PFNGLPASSTHROUGHPROC _funcptr_glPassThrough;
#define glPassThrough _funcptr_glPassThrough
extern PFNGLPOPNAMEPROC _funcptr_glPopName;
#define glPopName _funcptr_glPopName
extern PFNGLPUSHNAMEPROC _funcptr_glPushName;
#define glPushName _funcptr_glPushName
extern PFNGLCLEARACCUMPROC _funcptr_glClearAccum;
#define glClearAccum _funcptr_glClearAccum
extern PFNGLCLEARINDEXPROC _funcptr_glClearIndex;
#define glClearIndex _funcptr_glClearIndex
extern PFNGLINDEXMASKPROC _funcptr_glIndexMask;
#define glIndexMask _funcptr_glIndexMask
extern PFNGLACCUMPROC _funcptr_glAccum;
#define glAccum _funcptr_glAccum
extern PFNGLPOPATTRIBPROC _funcptr_glPopAttrib;
#define glPopAttrib _funcptr_glPopAttrib
extern PFNGLPUSHATTRIBPROC _funcptr_glPushAttrib;
#define glPushAttrib _funcptr_glPushAttrib
extern PFNGLMAP1DPROC _funcptr_glMap1d;
#define glMap1d _funcptr_glMap1d
extern PFNGLMAP1FPROC _funcptr_glMap1f;
#define glMap1f _funcptr_glMap1f
extern PFNGLMAP2DPROC _funcptr_glMap2d;
#define glMap2d _funcptr_glMap2d
extern PFNGLMAP2FPROC _funcptr_glMap2f;
#define glMap2f _funcptr_glMap2f
extern PFNGLMAPGRID1DPROC _funcptr_glMapGrid1d;
#define glMapGrid1d _funcptr_glMapGrid1d
extern PFNGLMAPGRID1FPROC _funcptr_glMapGrid1f;
#define glMapGrid1f _funcptr_glMapGrid1f
extern PFNGLMAPGRID2DPROC _funcptr_glMapGrid2d;
#define glMapGrid2d _funcptr_glMapGrid2d
extern PFNGLMAPGRID2FPROC _funcptr_glMapGrid2f;
#define glMapGrid2f _funcptr_glMapGrid2f
extern PFNGLEVALCOORD1DPROC _funcptr_glEvalCoord1d;
#define glEvalCoord1d _funcptr_glEvalCoord1d
extern PFNGLEVALCOORD1DVPROC _funcptr_glEvalCoord1dv;
#define glEvalCoord1dv _funcptr_glEvalCoord1dv
extern PFNGLEVALCOORD1FPROC _funcptr_glEvalCoord1f;
#define glEvalCoord1f _funcptr_glEvalCoord1f
extern PFNGLEVALCOORD1FVPROC _funcptr_glEvalCoord1fv;
#define glEvalCoord1fv _funcptr_glEvalCoord1fv
extern PFNGLEVALCOORD2DPROC _funcptr_glEvalCoord2d;
#define glEvalCoord2d _funcptr_glEvalCoord2d
extern PFNGLEVALCOORD2DVPROC _funcptr_glEvalCoord2dv;
#define glEvalCoord2dv _funcptr_glEvalCoord2dv
extern PFNGLEVALCOORD2FPROC _funcptr_glEvalCoord2f;
#define glEvalCoord2f _funcptr_glEvalCoord2f
extern PFNGLEVALCOORD2FVPROC _funcptr_glEvalCoord2fv;
#define glEvalCoord2fv _funcptr_glEvalCoord2fv
extern PFNGLEVALMESH1PROC _funcptr_glEvalMesh1;
#define glEvalMesh1 _funcptr_glEvalMesh1
extern PFNGLEVALPOINT1PROC _funcptr_glEvalPoint1;
#define glEvalPoint1 _funcptr_glEvalPoint1
extern PFNGLEVALMESH2PROC _funcptr_glEvalMesh2;
#define glEvalMesh2 _funcptr_glEvalMesh2
extern PFNGLEVALPOINT2PROC _funcptr_glEvalPoint2;
#define glEvalPoint2 _funcptr_glEvalPoint2
extern PFNGLALPHAFUNCPROC _funcptr_glAlphaFunc;
#define glAlphaFunc _funcptr_glAlphaFunc
extern PFNGLPIXELZOOMPROC _funcptr_glPixelZoom;
#define glPixelZoom _funcptr_glPixelZoom
extern PFNGLPIXELTRANSFERFPROC _funcptr_glPixelTransferf;
#define glPixelTransferf _funcptr_glPixelTransferf
extern PFNGLPIXELTRANSFERIPROC _funcptr_glPixelTransferi;
#define glPixelTransferi _funcptr_glPixelTransferi
extern PFNGLPIXELMAPFVPROC _funcptr_glPixelMapfv;
#define glPixelMapfv _funcptr_glPixelMapfv
extern PFNGLPIXELMAPUIVPROC _funcptr_glPixelMapuiv;
#define glPixelMapuiv _funcptr_glPixelMapuiv
extern PFNGLPIXELMAPUSVPROC _funcptr_glPixelMapusv;
#define glPixelMapusv _funcptr_glPixelMapusv
extern PFNGLCOPYPIXELSPROC _funcptr_glCopyPixels;
#define glCopyPixels _funcptr_glCopyPixels
extern PFNGLDRAWPIXELSPROC _funcptr_glDrawPixels;
#define glDrawPixels _funcptr_glDrawPixels
extern PFNGLGETCLIPPLANEPROC _funcptr_glGetClipPlane;
#define glGetClipPlane _funcptr_glGetClipPlane
extern PFNGLGETLIGHTFVPROC _funcptr_glGetLightfv;
#define glGetLightfv _funcptr_glGetLightfv
extern PFNGLGETLIGHTIVPROC _funcptr_glGetLightiv;
#define glGetLightiv _funcptr_glGetLightiv
extern PFNGLGETMAPDVPROC _funcptr_glGetMapdv;
#define glGetMapdv _funcptr_glGetMapdv
extern PFNGLGETMAPFVPROC _funcptr_glGetMapfv;
#define glGetMapfv _funcptr_glGetMapfv
extern PFNGLGETMAPIVPROC _funcptr_glGetMapiv;
#define glGetMapiv _funcptr_glGetMapiv
extern PFNGLGETMATERIALFVPROC _funcptr_glGetMaterialfv;
#define glGetMaterialfv _funcptr_glGetMaterialfv
extern PFNGLGETMATERIALIVPROC _funcptr_glGetMaterialiv;
#define glGetMaterialiv _funcptr_glGetMaterialiv
extern PFNGLGETPIXELMAPFVPROC _funcptr_glGetPixelMapfv;
#define glGetPixelMapfv _funcptr_glGetPixelMapfv
extern PFNGLGETPIXELMAPUIVPROC _funcptr_glGetPixelMapuiv;
#define glGetPixelMapuiv _funcptr_glGetPixelMapuiv
extern PFNGLGETPIXELMAPUSVPROC _funcptr_glGetPixelMapusv;
#define glGetPixelMapusv _funcptr_glGetPixelMapusv
extern PFNGLGETPOLYGONSTIPPLEPROC _funcptr_glGetPolygonStipple;
#define glGetPolygonStipple _funcptr_glGetPolygonStipple
extern PFNGLGETTEXENVFVPROC _funcptr_glGetTexEnvfv;
#define glGetTexEnvfv _funcptr_glGetTexEnvfv
extern PFNGLGETTEXENVIVPROC _funcptr_glGetTexEnviv;
#define glGetTexEnviv _funcptr_glGetTexEnviv
extern PFNGLGETTEXGENDVPROC _funcptr_glGetTexGendv;
#define glGetTexGendv _funcptr_glGetTexGendv
extern PFNGLGETTEXGENFVPROC _funcptr_glGetTexGenfv;
#define glGetTexGenfv _funcptr_glGetTexGenfv
extern PFNGLGETTEXGENIVPROC _funcptr_glGetTexGeniv;
#define glGetTexGeniv _funcptr_glGetTexGeniv
extern PFNGLISLISTPROC _funcptr_glIsList;
#define glIsList _funcptr_glIsList
extern PFNGLFRUSTUMPROC _funcptr_glFrustum;
#define glFrustum _funcptr_glFrustum
extern PFNGLLOADIDENTITYPROC _funcptr_glLoadIdentity;
#define glLoadIdentity _funcptr_glLoadIdentity
extern PFNGLLOADMATRIXFPROC _funcptr_glLoadMatrixf;
#define glLoadMatrixf _funcptr_glLoadMatrixf
extern PFNGLLOADMATRIXDPROC _funcptr_glLoadMatrixd;
#define glLoadMatrixd _funcptr_glLoadMatrixd
extern PFNGLMATRIXMODEPROC _funcptr_glMatrixMode;
#define glMatrixMode _funcptr_glMatrixMode
extern PFNGLMULTMATRIXFPROC _funcptr_glMultMatrixf;
#define glMultMatrixf _funcptr_glMultMatrixf
extern PFNGLMULTMATRIXDPROC _funcptr_glMultMatrixd;
#define glMultMatrixd _funcptr_glMultMatrixd
extern PFNGLORTHOPROC _funcptr_glOrtho;
#define glOrtho _funcptr_glOrtho
extern PFNGLPOPMATRIXPROC _funcptr_glPopMatrix;
#define glPopMatrix _funcptr_glPopMatrix
extern PFNGLPUSHMATRIXPROC _funcptr_glPushMatrix;
#define glPushMatrix _funcptr_glPushMatrix
extern PFNGLROTATEDPROC _funcptr_glRotated;
#define glRotated _funcptr_glRotated
extern PFNGLROTATEFPROC _funcptr_glRotatef;
#define glRotatef _funcptr_glRotatef
extern PFNGLSCALEDPROC _funcptr_glScaled;
#define glScaled _funcptr_glScaled
extern PFNGLSCALEFPROC _funcptr_glScalef;
#define glScalef _funcptr_glScalef
extern PFNGLTRANSLATEDPROC _funcptr_glTranslated;
#define glTranslated _funcptr_glTranslated
extern PFNGLTRANSLATEFPROC _funcptr_glTranslatef;
#define glTranslatef _funcptr_glTranslatef
extern PFNGLARRAYELEMENTPROC _funcptr_glArrayElement;
#define glArrayElement _funcptr_glArrayElement
extern PFNGLCOLORPOINTERPROC _funcptr_glColorPointer;
#define glColorPointer _funcptr_glColorPointer
extern PFNGLDISABLECLIENTSTATEPROC _funcptr_glDisableClientState;
#define glDisableClientState _funcptr_glDisableClientState
extern PFNGLEDGEFLAGPOINTERPROC _funcptr_glEdgeFlagPointer;
#define glEdgeFlagPointer _funcptr_glEdgeFlagPointer
extern PFNGLENABLECLIENTSTATEPROC _funcptr_glEnableClientState;
#define glEnableClientState _funcptr_glEnableClientState
extern PFNGLINDEXPOINTERPROC _funcptr_glIndexPointer;
#define glIndexPointer _funcptr_glIndexPointer
extern PFNGLINTERLEAVEDARRAYSPROC _funcptr_glInterleavedArrays;
#define glInterleavedArrays _funcptr_glInterleavedArrays
extern PFNGLNORMALPOINTERPROC _funcptr_glNormalPointer;
#define glNormalPointer _funcptr_glNormalPointer
extern PFNGLTEXCOORDPOINTERPROC _funcptr_glTexCoordPointer;
#define glTexCoordPointer _funcptr_glTexCoordPointer
extern PFNGLVERTEXPOINTERPROC _funcptr_glVertexPointer;
#define glVertexPointer _funcptr_glVertexPointer
extern PFNGLARETEXTURESRESIDENTPROC _funcptr_glAreTexturesResident;
#define glAreTexturesResident _funcptr_glAreTexturesResident
extern PFNGLPRIORITIZETEXTURESPROC _funcptr_glPrioritizeTextures;
#define glPrioritizeTextures _funcptr_glPrioritizeTextures
extern PFNGLPOPCLIENTATTRIBPROC _funcptr_glPopClientAttrib;
#define glPopClientAttrib _funcptr_glPopClientAttrib
extern PFNGLPUSHCLIENTATTRIBPROC _funcptr_glPushClientAttrib;
#define glPushClientAttrib _funcptr_glPushClientAttrib

#ifdef __cplusplus
}
#endif /*__cplusplus*/
#endif /*OPENGL_GEN_CORE_REM1_1_H*/
