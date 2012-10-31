#ifndef OPENGL_GEN_CORE_1_5_HPP
#define OPENGL_GEN_CORE_1_5_HPP

#include "_int_load_test.hpp"
namespace gl
{
	enum
	{
		BUFFER_SIZE                      = 0x8764,
		BUFFER_USAGE                     = 0x8765,
		QUERY_COUNTER_BITS               = 0x8864,
		CURRENT_QUERY                    = 0x8865,
		QUERY_RESULT                     = 0x8866,
		QUERY_RESULT_AVAILABLE           = 0x8867,
		ARRAY_BUFFER                     = 0x8892,
		ELEMENT_ARRAY_BUFFER             = 0x8893,
		ARRAY_BUFFER_BINDING             = 0x8894,
		ELEMENT_ARRAY_BUFFER_BINDING     = 0x8895,
		VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
		READ_ONLY                        = 0x88B8,
		BUFFER_ACCESS                    = 0x88BB,
		BUFFER_MAPPED                    = 0x88BC,
		BUFFER_MAP_POINTER               = 0x88BD,
		STREAM_DRAW                      = 0x88E0,
		STREAM_READ                      = 0x88E1,
		STREAM_COPY                      = 0x88E2,
		STATIC_DRAW                      = 0x88E4,
		STATIC_READ                      = 0x88E5,
		STATIC_COPY                      = 0x88E6,
		DYNAMIC_DRAW                     = 0x88E8,
		DYNAMIC_READ                     = 0x88E9,
		DYNAMIC_COPY                     = 0x88EA,
		SAMPLES_PASSED                   = 0x8914,
	};
	
	namespace _detail
	{
		typedef void (CODEGEN_FUNCPTR * Proc_glGenQueries)(GLsizei , GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteQueries)(GLsizei , const GLuint *);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsQuery)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glBeginQuery)(GLenum , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glEndQuery)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glGetQueryiv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetQueryObjectiv)(GLuint , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetQueryObjectuiv)(GLuint , GLenum , GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glBindBuffer)(GLenum , GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glDeleteBuffers)(GLsizei , const GLuint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGenBuffers)(GLsizei , GLuint *);
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glIsBuffer)(GLuint );
		typedef void (CODEGEN_FUNCPTR * Proc_glBufferData)(GLenum , GLsizeiptr , const GLvoid *, GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glBufferSubData)(GLenum , GLintptr , GLsizeiptr , const GLvoid *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBufferSubData)(GLenum , GLintptr , GLsizeiptr , GLvoid *);
		typedef GLvoid* (CODEGEN_FUNCPTR * Proc_glMapBuffer)(GLenum , GLenum );
		typedef GLboolean (CODEGEN_FUNCPTR * Proc_glUnmapBuffer)(GLenum );
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBufferParameteriv)(GLenum , GLenum , GLint *);
		typedef void (CODEGEN_FUNCPTR * Proc_glGetBufferPointerv)(GLenum , GLenum , GLvoid* *);
	}
	
	extern _detail::Proc_glGenQueries GenQueries;
	extern _detail::Proc_glDeleteQueries DeleteQueries;
	extern _detail::Proc_glIsQuery IsQuery;
	extern _detail::Proc_glBeginQuery BeginQuery;
	extern _detail::Proc_glEndQuery EndQuery;
	extern _detail::Proc_glGetQueryiv GetQueryiv;
	extern _detail::Proc_glGetQueryObjectiv GetQueryObjectiv;
	extern _detail::Proc_glGetQueryObjectuiv GetQueryObjectuiv;
	extern _detail::Proc_glBindBuffer BindBuffer;
	extern _detail::Proc_glDeleteBuffers DeleteBuffers;
	extern _detail::Proc_glGenBuffers GenBuffers;
	extern _detail::Proc_glIsBuffer IsBuffer;
	extern _detail::Proc_glBufferData BufferData;
	extern _detail::Proc_glBufferSubData BufferSubData;
	extern _detail::Proc_glGetBufferSubData GetBufferSubData;
	extern _detail::Proc_glMapBuffer MapBuffer;
	extern _detail::Proc_glUnmapBuffer UnmapBuffer;
	extern _detail::Proc_glGetBufferParameteriv GetBufferParameteriv;
	extern _detail::Proc_glGetBufferPointerv GetBufferPointerv;
	
}
#endif /*OPENGL_GEN_CORE_1_5_HPP*/
