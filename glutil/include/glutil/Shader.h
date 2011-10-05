
#ifndef SHADER_UTIL_H
#define SHADER_UTIL_H

/**
\file

\brief Includes functions to help load and validate shaders and programs.
**/

#include <exception>
#include <string>
#include <vector>

/**
\brief foo

**/
namespace glutil
{
	///\addtogroup module_glimg_exceptions
	///@{

	///Base class for all exceptions thrown by shader and program creation functions.
	class ShaderException : public std::exception
	{
	public:
		virtual ~ShaderException() throw() {}

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;

		ShaderException() {}
		ShaderException(const char *msg) : message(msg) {}
	};

	///Thrown if the user requests the creation of separate programs, but the implementation cannot do that.
	class SeparateShaderNotSupported : public ShaderException
	{
	public:
		SeparateShaderNotSupported();
	};

	///Thrown if the compilation or linking fails. The log will be stored in this exception.
	class CompileLinkException : public ShaderException
	{
	public:
		CompileLinkException(GLuint shader);
		CompileLinkException(GLuint program, bool);

		virtual ~CompileLinkException() throw() {}
	};
	///@}

	///\addtogroup module_glutil_program
	///@{

	/**
	\brief Creates a shader object and compiles it with the given text string.

	This function compiles a single string of shader text to produce an OpenGL shader object
	for the given shader stage.

	\param shaderType The shader stage that the shader object is created for.
	\param shaderText The GLSL shader text string.
	\return The successfully compiled shader object.

	\throw CompileLinkException Thrown if the shader compilation fails. The shader object will
	be destroyed, and the error log will be stored in the exception.
	**/
	GLuint CompileShader(GLenum shaderType, const char *shaderText);

	/** \copydoc CompileShader(GLenum, const char *) **/
	GLuint CompileShader(GLenum shaderType, const std::string &shaderText);

	/**
	\brief As CompileShader(GLenum, const char *), but with a list of strings.	
	**/
	GLuint CompileShader(GLenum shaderType, const char **shaderList, size_t numStrings);

	/**
	\brief As CompileShader(GLenum, const char *), but with a list of strings.	
	**/
	GLuint CompileShader(GLenum shaderType, const std::vector<std::string> &shaderList);

	/**
	\brief Links the two shader objects into a single program.

	This is a convenience function for the common case of pairing a vertex shader with a fragment
	shader. It takes the two shaders and links them together into a freshly-created program
	object.

	This function does not allow the user the chance to set pre-link parameters, like
	transform-feedback, vertex attributes, fragment data locations, or the like. Most of these
	can be hooked in via features like explicit_attrib_location and similar extensions.

	\throw CompileLinkException Thrown if the linking fails. The program will be
	destroyed, and the error log will be stored in the exception.
	**/
	GLuint LinkProgram(GLuint shaderOne, GLuint shaderTwo);

	///As LinkProgram(GLuint, GLuint), except that it is given a program to do the linking within.
	GLuint LinkProgram(GLuint program, GLuint shaderOne, GLuint shaderTwo);

	/**
	\brief Takes a single shader and links it into a program.

	This function is generally only useful when using separable programs.
	
	\param shader The shader to link.
	\param isSeparable If true, then the program will be linked with the GL_SEPARABLE_PROGRAM option.
	\return The successfully linked program object.

	\throw CompileLinkException Thrown if the linking fails. The program will be
	destroyed, and the error log will be stored in the exception.
	\throw SeparateShaderNotSupported If \a isSeparable is true, thrown when the current GL
	implementation does not support ARB_separate_shader_objects or GL 4.1 or above.
	**/
	GLuint LinkProgram(GLuint shader, bool isSeparable = false);

	/**
	\brief As LinkProgram(GLuint, bool), only with a list of shaders.
	**/
	GLuint LinkProgram(const std::vector<GLuint> &shaders, bool isSeparable = false);

	/**
	\brief Takes a program and links a number of shaders to it.

	\note If a CompileLinkException is thrown, the program object <em>will be destroyed.</em>

	\throw CompileLinkException Thrown if the linking fails. The program will be
	destroyed, and the error log will be stored in the exception.
	**/
	GLuint LinkProgram(GLuint program, const std::vector<GLuint> &shaders);

	/**
	\brief Creates a single-stage separable program from the given shader text.

	\param shaderType The shader stage that the shader object is created for.
	\param shaderText The GLSL shader text string.
	\return The successfully linked separable program object.
	
	\throw CompileLinkException Thrown if the compiling/linking fails. The program will be
	destroyed, and the error log will be stored in the exception.
	\throw SeparateShaderNotSupported Thrown when the current GL implementation
	does not support ARB_separate_shader_objects or GL 4.1 or above.
	**/
	GLuint MakeSeparableProgram(GLenum shaderType, const char *shaderText);

	/** \copydoc MakeSeparableProgram(GLenum, const char *) **/
	GLuint MakeSeparableProgram(GLenum shaderType, const std::string &shaderText);

	/**
	\brief As MakeSeparableProgram(GLenum, const char *), except with a list of strings.
	**/
	GLuint MakeSeparableProgram(GLenum shaderType, const char **shaderList, size_t numStrings);

	/**
	\brief As MakeSeparableProgram(GLenum, const char *), except with a list of strings.
	**/
	GLuint MakeSeparableProgram(GLenum shaderType, const std::vector<std::string> &shaderList);
	///@}
}

#endif //SHADER_UTIL_H
