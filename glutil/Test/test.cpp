#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glutil/glutil.h>

GLuint positionBufferObject;
GLuint program;
GLuint vao;

void init()
{
	gl::GenVertexArrays(1, &vao);
	gl::BindVertexArray(vao);

	const float vertexPositions[] = {
		0.75f, 0.75f, 0.0f, 1.0f,
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,
	};

	gl::GenBuffers(1, &positionBufferObject);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, positionBufferObject);
	gl::BufferData(gl::GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);

	const std::string vertexShader(
		"#version 330\n"
		"layout(location = 0) in vec4 position;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = position;\n"
		"}\n"
		);

	const std::string fragmentShader(
		"#version 330\n"
		"out vec4 outputColor;\n"
		"void main()\n"
		"{\n"
		"   outputColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);\n"
		"}\n"
		);

	GLuint vertShader = glutil::CompileShader(gl::GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(gl::GL_FRAGMENT_SHADER, fragmentShader);

	program = glutil::LinkProgram(vertShader, fragShader);

	gl::DeleteShader(vertShader);
	gl::DeleteShader(fragShader);
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	gl::ClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	gl::Clear(gl::GL_COLOR_BUFFER_BIT);

	gl::UseProgram(program);

	gl::BindBuffer(gl::GL_ARRAY_BUFFER, positionBufferObject);
	gl::EnableVertexAttribArray(0);
	gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, 0);

	gl::DrawArrays(gl::GL_TRIANGLES, 0, 3);

	gl::DisableVertexAttribArray(0);
	gl::UseProgram(0);

	glfwSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	gl::Viewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void APIENTRY DebugFunc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
						const GLchar* message, GLvoid* userParam)
{
	std::string srcName;
	switch(source)
	{
	case gl::GL_DEBUG_SOURCE_API_ARB: srcName = "API"; break;
	case gl::GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB: srcName = "Window System"; break;
	case gl::GL_DEBUG_SOURCE_SHADER_COMPILER_ARB: srcName = "Shader Compiler"; break;
	case gl::GL_DEBUG_SOURCE_THIRD_PARTY_ARB: srcName = "Third Party"; break;
	case gl::GL_DEBUG_SOURCE_APPLICATION_ARB: srcName = "Application"; break;
	case gl::GL_DEBUG_SOURCE_OTHER_ARB: srcName = "Other"; break;
	}

	std::string errorType;
	switch(type)
	{
	case gl::GL_DEBUG_TYPE_ERROR_ARB: errorType = "Error"; break;
	case gl::GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB: errorType = "Deprecated Functionality"; break;
	case gl::GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB: errorType = "Undefined Behavior"; break;
	case gl::GL_DEBUG_TYPE_PORTABILITY_ARB: errorType = "Portability"; break;
	case gl::GL_DEBUG_TYPE_PERFORMANCE_ARB: errorType = "Performance"; break;
	case gl::GL_DEBUG_TYPE_OTHER_ARB: errorType = "Other"; break;
	}

	std::string typeSeverity;
	switch(severity)
	{
	case gl::GL_DEBUG_SEVERITY_HIGH_ARB: typeSeverity = "High"; break;
	case gl::GL_DEBUG_SEVERITY_MEDIUM_ARB: typeSeverity = "Medium"; break;
	case gl::GL_DEBUG_SEVERITY_LOW_ARB: typeSeverity = "Low"; break;
	}

	printf("%s from %s,\t%s priority\nMessage: %s\n",
		errorType.c_str(), srcName.c_str(), typeSeverity.c_str(), message);
}

int main(int argc, char** argv)
{
	if(!glfwInit())
		return -1;

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DEBUG
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, gl::GL_TRUE);
#endif

	glm::ivec2 wndSize(500, 500);

	if(!glfwOpenWindow(wndSize.x, wndSize.y, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
	{
		glfwTerminate();
		return -1;
	}

	GLFWvidmode desktopMode;
	glfwGetDesktopMode(&desktopMode);

	glm::ivec2 wndPos(0, 0);
	wndPos.x = (desktopMode.Width - wndSize.x) / 2;
	wndPos.y = (desktopMode.Height - wndSize.y) / 2;

	glfwSetWindowPos(wndPos.x, wndPos.y);


	if(glload::LoadFunctions() == glload::LS_LOAD_FAILED)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowTitle("GLFW Demo");

	if(glext_ARB_debug_output)
	{
		gl::Enable(gl::GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		glDebugMessageCallbackARB(DebugFunc, (void*)15);
	}

	init();

	glfwSetWindowSizeCallback(reshape);

	//Main loop
	while(true)
	{
		display();

		if(glfwGetKey(GLFW_KEY_ESC) || !glfwGetWindowParam(GLFW_OPENED))
			break;
	}

	glfwTerminate();
	return 0;
}
