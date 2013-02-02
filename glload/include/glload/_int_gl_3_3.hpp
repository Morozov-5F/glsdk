#ifndef OPENGL_GEN_CORE_3_3_HPP
#define OPENGL_GEN_CORE_3_3_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		VERTEX_ATTRIB_ARRAY_DIVISOR      = 0x88FE,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glVertexAttribDivisor)(GLuint index, GLuint divisor);
	}
	
	extern _detail::Proc_glVertexAttribDivisor VertexAttribDivisor;
	
}
#endif /*OPENGL_GEN_CORE_3_3_HPP*/
