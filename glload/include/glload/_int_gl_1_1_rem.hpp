#ifndef OPENGL_GEN_CORE_REM1_1_HPP
#define OPENGL_GEN_CORE_REM1_1_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		//CURRENT_BIT taken from 1.1
		//POINT_BIT taken from 1.1
		//LINE_BIT taken from 1.1
		//POLYGON_BIT taken from 1.1
		//POLYGON_STIPPLE_BIT taken from 1.1
		//PIXEL_MODE_BIT taken from 1.1
		//LIGHTING_BIT taken from 1.1
		//FOG_BIT taken from 1.1
		//ACCUM_BUFFER_BIT taken from 1.1
		//VIEWPORT_BIT taken from 1.1
		//TRANSFORM_BIT taken from 1.1
		//ENABLE_BIT taken from 1.1
		//HINT_BIT taken from 1.1
		//EVAL_BIT taken from 1.1
		//LIST_BIT taken from 1.1
		//TEXTURE_BIT taken from 1.1
		//SCISSOR_BIT taken from 1.1
		//ALL_ATTRIB_BITS taken from 1.1
		//CLIENT_PIXEL_STORE_BIT taken from 1.1
		//CLIENT_VERTEX_ARRAY_BIT taken from 1.1
		//CLIENT_ALL_ATTRIB_BITS taken from 1.1
		//QUAD_STRIP taken from 1.1
		//POLYGON taken from 1.1
		//ACCUM taken from 1.1
		//LOAD taken from 1.1
		//RETURN taken from 1.1
		//MULT taken from 1.1
		//ADD taken from 1.1
		//AUX0 taken from 1.1
		//AUX1 taken from 1.1
		//AUX2 taken from 1.1
		//AUX3 taken from 1.1
		//2D taken from 1.1
		//3D taken from 1.1
		//3D_COLOR taken from 1.1
		//3D_COLOR_TEXTURE taken from 1.1
		//4D_COLOR_TEXTURE taken from 1.1
		//PASS_THROUGH_TOKEN taken from 1.1
		//POINT_TOKEN taken from 1.1
		//LINE_TOKEN taken from 1.1
		//POLYGON_TOKEN taken from 1.1
		//BITMAP_TOKEN taken from 1.1
		//DRAW_PIXEL_TOKEN taken from 1.1
		//COPY_PIXEL_TOKEN taken from 1.1
		//LINE_RESET_TOKEN taken from 1.1
		//EXP taken from 1.1
		//EXP2 taken from 1.1
		//COEFF taken from 1.1
		//ORDER taken from 1.1
		//DOMAIN taken from 1.1
		//PIXEL_MAP_I_TO_I taken from 1.1
		//PIXEL_MAP_S_TO_S taken from 1.1
		//PIXEL_MAP_I_TO_R taken from 1.1
		//PIXEL_MAP_I_TO_G taken from 1.1
		//PIXEL_MAP_I_TO_B taken from 1.1
		//PIXEL_MAP_I_TO_A taken from 1.1
		//PIXEL_MAP_R_TO_R taken from 1.1
		//PIXEL_MAP_G_TO_G taken from 1.1
		//PIXEL_MAP_B_TO_B taken from 1.1
		//PIXEL_MAP_A_TO_A taken from 1.1
		//VERTEX_ARRAY_POINTER taken from 1.1
		//NORMAL_ARRAY_POINTER taken from 1.1
		//COLOR_ARRAY_POINTER taken from 1.1
		//INDEX_ARRAY_POINTER taken from 1.1
		//TEXTURE_COORD_ARRAY_POINTER taken from 1.1
		//EDGE_FLAG_ARRAY_POINTER taken from 1.1
		//FEEDBACK_BUFFER_POINTER taken from 1.1
		//SELECTION_BUFFER_POINTER taken from 1.1
		//CURRENT_COLOR taken from 1.1
		//CURRENT_INDEX taken from 1.1
		//CURRENT_NORMAL taken from 1.1
		//CURRENT_TEXTURE_COORDS taken from 1.1
		//CURRENT_RASTER_COLOR taken from 1.1
		//CURRENT_RASTER_INDEX taken from 1.1
		//CURRENT_RASTER_TEXTURE_COORDS taken from 1.1
		//CURRENT_RASTER_POSITION taken from 1.1
		//CURRENT_RASTER_POSITION_VALID taken from 1.1
		//CURRENT_RASTER_DISTANCE taken from 1.1
		//POINT_SMOOTH taken from 1.1
		//LINE_STIPPLE taken from 1.1
		//LINE_STIPPLE_PATTERN taken from 1.1
		//LINE_STIPPLE_REPEAT taken from 1.1
		//LIST_MODE taken from 1.1
		//MAX_LIST_NESTING taken from 1.1
		//LIST_BASE taken from 1.1
		//LIST_INDEX taken from 1.1
		//POLYGON_STIPPLE taken from 1.1
		//EDGE_FLAG taken from 1.1
		//LIGHTING taken from 1.1
		//LIGHT_MODEL_LOCAL_VIEWER taken from 1.1
		//LIGHT_MODEL_TWO_SIDE taken from 1.1
		//LIGHT_MODEL_AMBIENT taken from 1.1
		//SHADE_MODEL taken from 1.1
		//COLOR_MATERIAL_FACE taken from 1.1
		//COLOR_MATERIAL_PARAMETER taken from 1.1
		//COLOR_MATERIAL taken from 1.1
		//FOG_INDEX taken from 1.1
		//FOG_DENSITY taken from 1.1
		//FOG_START taken from 1.1
		//FOG_END taken from 1.1
		//FOG_MODE taken from 1.1
		//FOG_COLOR taken from 1.1
		//ACCUM_CLEAR_VALUE taken from 1.1
		//MATRIX_MODE taken from 1.1
		//NORMALIZE taken from 1.1
		//MODELVIEW_STACK_DEPTH taken from 1.1
		//PROJECTION_STACK_DEPTH taken from 1.1
		//TEXTURE_STACK_DEPTH taken from 1.1
		//MODELVIEW_MATRIX taken from 1.1
		//PROJECTION_MATRIX taken from 1.1
		//TEXTURE_MATRIX taken from 1.1
		//ATTRIB_STACK_DEPTH taken from 1.1
		//CLIENT_ATTRIB_STACK_DEPTH taken from 1.1
		//ALPHA_TEST taken from 1.1
		//ALPHA_TEST_FUNC taken from 1.1
		//ALPHA_TEST_REF taken from 1.1
		//INDEX_LOGIC_OP taken from 1.1
		//LOGIC_OP taken from 1.1
		//AUX_BUFFERS taken from 1.1
		//INDEX_CLEAR_VALUE taken from 1.1
		//INDEX_WRITEMASK taken from 1.1
		//INDEX_MODE taken from 1.1
		//RGBA_MODE taken from 1.1
		//RENDER_MODE taken from 1.1
		//PERSPECTIVE_CORRECTION_HINT taken from 1.1
		//POINT_SMOOTH_HINT taken from 1.1
		//FOG_HINT taken from 1.1
		//TEXTURE_GEN_S taken from 1.1
		//TEXTURE_GEN_T taken from 1.1
		//TEXTURE_GEN_R taken from 1.1
		//TEXTURE_GEN_Q taken from 1.1
		//PIXEL_MAP_I_TO_I_SIZE taken from 1.1
		//PIXEL_MAP_S_TO_S_SIZE taken from 1.1
		//PIXEL_MAP_I_TO_R_SIZE taken from 1.1
		//PIXEL_MAP_I_TO_G_SIZE taken from 1.1
		//PIXEL_MAP_I_TO_B_SIZE taken from 1.1
		//PIXEL_MAP_I_TO_A_SIZE taken from 1.1
		//PIXEL_MAP_R_TO_R_SIZE taken from 1.1
		//PIXEL_MAP_G_TO_G_SIZE taken from 1.1
		//PIXEL_MAP_B_TO_B_SIZE taken from 1.1
		//PIXEL_MAP_A_TO_A_SIZE taken from 1.1
		//MAP_COLOR taken from 1.1
		//MAP_STENCIL taken from 1.1
		//INDEX_SHIFT taken from 1.1
		//INDEX_OFFSET taken from 1.1
		//RED_SCALE taken from 1.1
		//RED_BIAS taken from 1.1
		//ZOOM_X taken from 1.1
		//ZOOM_Y taken from 1.1
		//GREEN_SCALE taken from 1.1
		//GREEN_BIAS taken from 1.1
		//BLUE_SCALE taken from 1.1
		//BLUE_BIAS taken from 1.1
		//ALPHA_SCALE taken from 1.1
		//ALPHA_BIAS taken from 1.1
		//DEPTH_SCALE taken from 1.1
		//DEPTH_BIAS taken from 1.1
		//MAX_EVAL_ORDER taken from 1.1
		//MAX_LIGHTS taken from 1.1
		//MAX_CLIP_PLANES taken from 1.1
		//MAX_PIXEL_MAP_TABLE taken from 1.1
		//MAX_ATTRIB_STACK_DEPTH taken from 1.1
		//MAX_MODELVIEW_STACK_DEPTH taken from 1.1
		//MAX_NAME_STACK_DEPTH taken from 1.1
		//MAX_PROJECTION_STACK_DEPTH taken from 1.1
		//MAX_TEXTURE_STACK_DEPTH taken from 1.1
		//MAX_CLIENT_ATTRIB_STACK_DEPTH taken from 1.1
		//INDEX_BITS taken from 1.1
		//RED_BITS taken from 1.1
		//GREEN_BITS taken from 1.1
		//BLUE_BITS taken from 1.1
		//ALPHA_BITS taken from 1.1
		//DEPTH_BITS taken from 1.1
		//STENCIL_BITS taken from 1.1
		//ACCUM_RED_BITS taken from 1.1
		//ACCUM_GREEN_BITS taken from 1.1
		//ACCUM_BLUE_BITS taken from 1.1
		//ACCUM_ALPHA_BITS taken from 1.1
		//NAME_STACK_DEPTH taken from 1.1
		//AUTO_NORMAL taken from 1.1
		//MAP1_COLOR_4 taken from 1.1
		//MAP1_INDEX taken from 1.1
		//MAP1_NORMAL taken from 1.1
		//MAP1_TEXTURE_COORD_1 taken from 1.1
		//MAP1_TEXTURE_COORD_2 taken from 1.1
		//MAP1_TEXTURE_COORD_3 taken from 1.1
		//MAP1_TEXTURE_COORD_4 taken from 1.1
		//MAP1_VERTEX_3 taken from 1.1
		//MAP1_VERTEX_4 taken from 1.1
		//MAP2_COLOR_4 taken from 1.1
		//MAP2_INDEX taken from 1.1
		//MAP2_NORMAL taken from 1.1
		//MAP2_TEXTURE_COORD_1 taken from 1.1
		//MAP2_TEXTURE_COORD_2 taken from 1.1
		//MAP2_TEXTURE_COORD_3 taken from 1.1
		//MAP2_TEXTURE_COORD_4 taken from 1.1
		//MAP2_VERTEX_3 taken from 1.1
		//MAP2_VERTEX_4 taken from 1.1
		//MAP1_GRID_DOMAIN taken from 1.1
		//MAP1_GRID_SEGMENTS taken from 1.1
		//MAP2_GRID_DOMAIN taken from 1.1
		//MAP2_GRID_SEGMENTS taken from 1.1
		//FEEDBACK_BUFFER_SIZE taken from 1.1
		//FEEDBACK_BUFFER_TYPE taken from 1.1
		//SELECTION_BUFFER_SIZE taken from 1.1
		//VERTEX_ARRAY taken from 1.1
		//NORMAL_ARRAY taken from 1.1
		//COLOR_ARRAY taken from 1.1
		//INDEX_ARRAY taken from 1.1
		//TEXTURE_COORD_ARRAY taken from 1.1
		//EDGE_FLAG_ARRAY taken from 1.1
		//VERTEX_ARRAY_SIZE taken from 1.1
		//VERTEX_ARRAY_TYPE taken from 1.1
		//VERTEX_ARRAY_STRIDE taken from 1.1
		//NORMAL_ARRAY_TYPE taken from 1.1
		//NORMAL_ARRAY_STRIDE taken from 1.1
		//COLOR_ARRAY_SIZE taken from 1.1
		//COLOR_ARRAY_TYPE taken from 1.1
		//COLOR_ARRAY_STRIDE taken from 1.1
		//INDEX_ARRAY_TYPE taken from 1.1
		//INDEX_ARRAY_STRIDE taken from 1.1
		//TEXTURE_COORD_ARRAY_SIZE taken from 1.1
		//TEXTURE_COORD_ARRAY_TYPE taken from 1.1
		//TEXTURE_COORD_ARRAY_STRIDE taken from 1.1
		//EDGE_FLAG_ARRAY_STRIDE taken from 1.1
		//TEXTURE_COMPONENTS taken from 1.1
		//TEXTURE_BORDER taken from 1.1
		//TEXTURE_LUMINANCE_SIZE taken from 1.1
		//TEXTURE_INTENSITY_SIZE taken from 1.1
		//TEXTURE_PRIORITY taken from 1.1
		//TEXTURE_RESIDENT taken from 1.1
		//AMBIENT taken from 1.1
		//DIFFUSE taken from 1.1
		//SPECULAR taken from 1.1
		//POSITION taken from 1.1
		//SPOT_DIRECTION taken from 1.1
		//SPOT_EXPONENT taken from 1.1
		//SPOT_CUTOFF taken from 1.1
		//CONSTANT_ATTENUATION taken from 1.1
		//LINEAR_ATTENUATION taken from 1.1
		//QUADRATIC_ATTENUATION taken from 1.1
		//COMPILE taken from 1.1
		//COMPILE_AND_EXECUTE taken from 1.1
		//2_BYTES taken from 1.1
		//3_BYTES taken from 1.1
		//4_BYTES taken from 1.1
		//EMISSION taken from 1.1
		//SHININESS taken from 1.1
		//AMBIENT_AND_DIFFUSE taken from 1.1
		//COLOR_INDEXES taken from 1.1
		//MODELVIEW taken from 1.1
		//PROJECTION taken from 1.1
		//COLOR_INDEX taken from 1.1
		//LUMINANCE taken from 1.1
		//LUMINANCE_ALPHA taken from 1.1
		//BITMAP taken from 1.1
		//RENDER taken from 1.1
		//FEEDBACK taken from 1.1
		//SELECT taken from 1.1
		//FLAT taken from 1.1
		//SMOOTH taken from 1.1
		//S taken from 1.1
		//T taken from 1.1
		//R taken from 1.1
		//Q taken from 1.1
		//MODULATE taken from 1.1
		//DECAL taken from 1.1
		//TEXTURE_ENV_MODE taken from 1.1
		//TEXTURE_ENV_COLOR taken from 1.1
		//TEXTURE_ENV taken from 1.1
		//EYE_LINEAR taken from 1.1
		//OBJECT_LINEAR taken from 1.1
		//SPHERE_MAP taken from 1.1
		//TEXTURE_GEN_MODE taken from 1.1
		//OBJECT_PLANE taken from 1.1
		//CLAMP taken from 1.1
		//ALPHA4 taken from 1.1
		//ALPHA8 taken from 1.1
		//ALPHA12 taken from 1.1
		//ALPHA16 taken from 1.1
		//LUMINANCE4 taken from 1.1
		//LUMINANCE8 taken from 1.1
		//LUMINANCE12 taken from 1.1
		//LUMINANCE16 taken from 1.1
		//LUMINANCE4_ALPHA4 taken from 1.1
		//LUMINANCE6_ALPHA2 taken from 1.1
		//LUMINANCE8_ALPHA8 taken from 1.1
		//LUMINANCE12_ALPHA4 taken from 1.1
		//LUMINANCE12_ALPHA12 taken from 1.1
		//LUMINANCE16_ALPHA16 taken from 1.1
		//INTENSITY taken from 1.1
		//INTENSITY4 taken from 1.1
		//INTENSITY8 taken from 1.1
		//INTENSITY12 taken from 1.1
		//INTENSITY16 taken from 1.1
		//V2F taken from 1.1
		//V3F taken from 1.1
		//C4UB_V2F taken from 1.1
		//C4UB_V3F taken from 1.1
		//C3F_V3F taken from 1.1
		//N3F_V3F taken from 1.1
		//C4F_N3F_V3F taken from 1.1
		//T2F_V3F taken from 1.1
		//T4F_V4F taken from 1.1
		//T2F_C4UB_V3F taken from 1.1
		//T2F_C3F_V3F taken from 1.1
		//T2F_N3F_V3F taken from 1.1
		//T2F_C4F_N3F_V3F taken from 1.1
		//T4F_C4F_N3F_V4F taken from 1.1
		//CLIP_PLANE0 taken from 1.1
		//CLIP_PLANE1 taken from 1.1
		//CLIP_PLANE2 taken from 1.1
		//CLIP_PLANE3 taken from 1.1
		//CLIP_PLANE4 taken from 1.1
		//CLIP_PLANE5 taken from 1.1
		//LIGHT0 taken from 1.1
		//LIGHT1 taken from 1.1
		//LIGHT2 taken from 1.1
		//LIGHT3 taken from 1.1
		//LIGHT4 taken from 1.1
		//LIGHT5 taken from 1.1
		//LIGHT6 taken from 1.1
		//LIGHT7 taken from 1.1
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glNewList)(GLuint , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glEndList)();
		typedef void (CODEGEN_FUNCPTR * Proc_glCallList)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glCallLists)(GLsizei , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteLists)(GLuint , GLsizei );
		typedef GLuint (CODEGEN_FUNCPTR * Proc_glGenLists)(GLsizei );
		typedef void (CODEGEN_FUNCPTR * Proc_glListBase)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glBegin)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glBitmap)(GLsizei , GLsizei , GLfloat , GLfloat , GLfloat , GLfloat , const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3b)(GLbyte , GLbyte , GLbyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3bv)(const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ub)(GLubyte , GLubyte , GLubyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ubv)(const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3ui)(GLuint , GLuint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3uiv)(const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3us)(GLushort , GLushort , GLushort );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor3usv)(const GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4b)(GLbyte , GLbyte , GLbyte , GLbyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4bv)(const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4d)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4f)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4i)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4s)(GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ub)(GLubyte , GLubyte , GLubyte , GLubyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ubv)(const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4ui)(GLuint , GLuint , GLuint , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4uiv)(const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4us)(GLushort , GLushort , GLushort , GLushort );
		typedef void (CODEGEN_FUNCPTR * Proc_glColor4usv)(const GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlag)(GLboolean );
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlagv)(const GLboolean *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnd)();
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexd)(GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexdv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexf)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexfv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexi)(GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexiv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexs)(GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexsv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3b)(GLbyte , GLbyte , GLbyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3bv)(const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glNormal3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2d)(GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2f)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2i)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2s)(GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos2sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4d)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4f)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4i)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4s)(GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glRasterPos4sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectd)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glRectdv)(const GLdouble *, const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRectf)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glRectfv)(const GLfloat *, const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRecti)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glRectiv)(const GLint *, const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glRects)(GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glRectsv)(const GLshort *, const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1d)(GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1f)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1i)(GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1s)(GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord1sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2d)(GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2f)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2i)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2s)(GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord2sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4d)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4f)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4i)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4s)(GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoord4sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2d)(GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2f)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2i)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2s)(GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex2sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3d)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3f)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3i)(GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3s)(GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex3sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4d)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4f)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4i)(GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4iv)(const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4s)(GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertex4sv)(const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glClipPlane)(GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glColorMaterial)(GLenum , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glFogf)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glFogfv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glFogi)(GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glFogiv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightf)(GLenum , GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glLightfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLighti)(GLenum , GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glLightiv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModelf)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModelfv)(GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModeli)(GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glLightModeliv)(GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLineStipple)(GLint , GLushort );
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialf)(GLenum , GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMateriali)(GLenum , GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glMaterialiv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPolygonStipple)(const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glShadeModel)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvf)(GLenum , GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnvi)(GLenum , GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexEnviv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGend)(GLenum , GLenum , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGendv)(GLenum , GLenum , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGenf)(GLenum , GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGenfv)(GLenum , GLenum , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGeni)(GLenum , GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glTexGeniv)(GLenum , GLenum , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glFeedbackBuffer)(GLsizei , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glSelectBuffer)(GLsizei , GLuint *);
		typedef GLint (CODEGEN_FUNCPTR * Proc_glRenderMode)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glInitNames)();
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadName)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glPassThrough)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPopName)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushName)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glClearAccum)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glClearIndex)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexMask)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glAccum)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPopAttrib)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushAttrib)(GLbitfield );
		typedef void (CODEGEN_FUNCPTR * Proc_glMap1d)(GLenum , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap1f)(GLenum , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap2d)(GLenum , GLdouble , GLdouble , GLint , GLint , GLdouble , GLdouble , GLint , GLint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMap2f)(GLenum , GLfloat , GLfloat , GLint , GLint , GLfloat , GLfloat , GLint , GLint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid1d)(GLint , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid1f)(GLint , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid2d)(GLint , GLdouble , GLdouble , GLint , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glMapGrid2f)(GLint , GLfloat , GLfloat , GLint , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1d)(GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1f)(GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord1fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2d)(GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2dv)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2f)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalCoord2fv)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalMesh1)(GLenum , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalPoint1)(GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalMesh2)(GLenum , GLint , GLint , GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glEvalPoint2)(GLint , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glAlphaFunc)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelZoom)(GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelTransferf)(GLenum , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelTransferi)(GLenum , GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapfv)(GLenum , GLsizei , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapuiv)(GLenum , GLsizei , const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPixelMapusv)(GLenum , GLsizei , const GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glCopyPixels)(GLint , GLint , GLsizei , GLsizei , GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glDrawPixels)(GLsizei , GLsizei , GLenum , GLenum , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetClipPlane)(GLenum , GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetLightfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetLightiv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapdv)(GLenum , GLenum , GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMapiv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMaterialfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetMaterialiv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapfv)(GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapuiv)(GLenum , GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPixelMapusv)(GLenum , GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetPolygonStipple)(GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexEnvfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexEnviv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGendv)(GLenum , GLenum , GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGenfv)(GLenum , GLenum , GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetTexGeniv)(GLenum , GLenum , GLint *);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsList)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glFrustum)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadIdentity)();
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadMatrixf)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glLoadMatrixd)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMatrixMode)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glMultMatrixf)(const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glMultMatrixd)(const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glOrtho)(GLdouble , GLdouble , GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glPopMatrix)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushMatrix)();
		typedef void (CODEGEN_FUNCPTR * Proc_glRotated)(GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glRotatef)(GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glScaled)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glScalef)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glTranslated)(GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glTranslatef)(GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glArrayElement)(GLint );
		typedef void (CODEGEN_FUNCPTR * Proc_glColorPointer)(GLint , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glDisableClientState)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glEdgeFlagPointer)(GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glEnableClientState)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glIndexPointer)(GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glInterleavedArrays)(GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glNormalPointer)(GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glTexCoordPointer)(GLint , GLenum , GLsizei , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexPointer)(GLint , GLenum , GLsizei , const GLvoid *);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glAreTexturesResident)(GLsizei , const GLuint *, GLboolean *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPrioritizeTextures)(GLsizei , const GLuint *, const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glPopClientAttrib)();
		typedef void (CODEGEN_FUNCPTR * Proc_glPushClientAttrib)(GLbitfield );
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
