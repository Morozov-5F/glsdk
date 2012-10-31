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
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1d)(GLuint , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1dv)(GLuint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1f)(GLuint , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1fv)(GLuint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1s)(GLuint , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib1sv)(GLuint , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2d)(GLuint , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2dv)(GLuint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2f)(GLuint , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2fv)(GLuint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2s)(GLuint , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib2sv)(GLuint , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3d)(GLuint , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3dv)(GLuint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3f)(GLuint , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3fv)(GLuint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3s)(GLuint , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib3sv)(GLuint , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nbv)(GLuint , const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Niv)(GLuint , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nsv)(GLuint , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nub)(GLuint , GLubyte , GLubyte , GLubyte , GLubyte );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nubv)(GLuint , const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nuiv)(GLuint , const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4Nusv)(GLuint , const GLushort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4bv)(GLuint , const GLbyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4d)(GLuint , GLdouble , GLdouble , GLdouble , GLdouble );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4dv)(GLuint , const GLdouble *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4f)(GLuint , GLfloat , GLfloat , GLfloat , GLfloat );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4fv)(GLuint , const GLfloat *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4iv)(GLuint , const GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4s)(GLuint , GLshort , GLshort , GLshort , GLshort );
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4sv)(GLuint , const GLshort *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4ubv)(GLuint , const GLubyte *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4uiv)(GLuint , const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttrib4usv)(GLuint , const GLushort *);
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
