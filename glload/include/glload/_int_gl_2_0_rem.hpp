#ifndef OPENGL_GEN_CORE_REM2_0_HPP
#define OPENGL_GEN_CORE_REM2_0_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		VERTEX_PROGRAM_TWO_SIDE          = 0x8643,
		POINT_SPRITE                     = 0x8861,
		COORD_REPLACE                    = 0x8862,
		MAX_TEXTURE_COORDS               = 0x8871,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1d)(GLuint index, GLdouble x);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1dv)(GLuint index, const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1f)(GLuint index, GLfloat x);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1fv)(GLuint index, const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1s)(GLuint index, GLshort x);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1sv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2dv)(GLuint index, const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2fv)(GLuint index, const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2sv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3dv)(GLuint index, const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3fv)(GLuint index, const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3sv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nbv)(GLuint index, const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Niv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nsv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nubv)(GLuint index, const GLubyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nuiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nusv)(GLuint index, const GLushort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4bv)(GLuint index, const GLbyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4dv)(GLuint index, const GLdouble *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4fv)(GLuint index, const GLfloat *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4iv)(GLuint index, const GLint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4sv)(GLuint index, const GLshort *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4ubv)(GLuint index, const GLubyte *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4uiv)(GLuint index, const GLuint *v);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4usv)(GLuint index, const GLushort *v);
	}
	
	extern _detail::Proc_glVertexAttrib1d VertexAttrib1d;
	extern _detail::Proc_glVertexAttrib1dv VertexAttrib1dv;
	extern _detail::Proc_glVertexAttrib1f VertexAttrib1f;
	extern _detail::Proc_glVertexAttrib1fv VertexAttrib1fv;
	extern _detail::Proc_glVertexAttrib1s VertexAttrib1s;
	extern _detail::Proc_glVertexAttrib1sv VertexAttrib1sv;
	extern _detail::Proc_glVertexAttrib2d VertexAttrib2d;
	extern _detail::Proc_glVertexAttrib2dv VertexAttrib2dv;
	extern _detail::Proc_glVertexAttrib2f VertexAttrib2f;
	extern _detail::Proc_glVertexAttrib2fv VertexAttrib2fv;
	extern _detail::Proc_glVertexAttrib2s VertexAttrib2s;
	extern _detail::Proc_glVertexAttrib2sv VertexAttrib2sv;
	extern _detail::Proc_glVertexAttrib3d VertexAttrib3d;
	extern _detail::Proc_glVertexAttrib3dv VertexAttrib3dv;
	extern _detail::Proc_glVertexAttrib3f VertexAttrib3f;
	extern _detail::Proc_glVertexAttrib3fv VertexAttrib3fv;
	extern _detail::Proc_glVertexAttrib3s VertexAttrib3s;
	extern _detail::Proc_glVertexAttrib3sv VertexAttrib3sv;
	extern _detail::Proc_glVertexAttrib4Nbv VertexAttrib4Nbv;
	extern _detail::Proc_glVertexAttrib4Niv VertexAttrib4Niv;
	extern _detail::Proc_glVertexAttrib4Nsv VertexAttrib4Nsv;
	extern _detail::Proc_glVertexAttrib4Nub VertexAttrib4Nub;
	extern _detail::Proc_glVertexAttrib4Nubv VertexAttrib4Nubv;
	extern _detail::Proc_glVertexAttrib4Nuiv VertexAttrib4Nuiv;
	extern _detail::Proc_glVertexAttrib4Nusv VertexAttrib4Nusv;
	extern _detail::Proc_glVertexAttrib4bv VertexAttrib4bv;
	extern _detail::Proc_glVertexAttrib4d VertexAttrib4d;
	extern _detail::Proc_glVertexAttrib4dv VertexAttrib4dv;
	extern _detail::Proc_glVertexAttrib4f VertexAttrib4f;
	extern _detail::Proc_glVertexAttrib4fv VertexAttrib4fv;
	extern _detail::Proc_glVertexAttrib4iv VertexAttrib4iv;
	extern _detail::Proc_glVertexAttrib4s VertexAttrib4s;
	extern _detail::Proc_glVertexAttrib4sv VertexAttrib4sv;
	extern _detail::Proc_glVertexAttrib4ubv VertexAttrib4ubv;
	extern _detail::Proc_glVertexAttrib4uiv VertexAttrib4uiv;
	extern _detail::Proc_glVertexAttrib4usv VertexAttrib4usv;
	
}
#endif /*OPENGL_GEN_CORE_REM2_0_HPP*/
