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

GLuint objectBuffer;
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

	gl::GenBuffers(1, &objectBuffer);
	gl::BindBuffer(gl::ARRAY_BUFFER, objectBuffer);
	gl::BufferData(gl::ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, gl::STATIC_DRAW);
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);

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

	GLuint vertShader = glutil::CompileShader(gl::VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(gl::FRAGMENT_SHADER, fragmentShader);

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
	gl::Clear(gl::COLOR_BUFFER_BIT);

	gl::UseProgram(program);

	gl::BindBuffer(gl::ARRAY_BUFFER, objectBuffer);
	gl::EnableVertexAttribArray(0);
	gl::VertexAttribPointer(0, 4, gl::FLOAT, gl::FALSE_, 0, 0);

	gl::DrawArrays(gl::TRIANGLES, 0, 3);

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

int main(int argc, char** argv)
{
	if(!glfwInit())
		return -1;

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DEBUG
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, gl::TRUE_);
#endif

	glm::ivec2 wndSize(500, 500);

	if(!glfwOpenWindow(wndSize.x, wndSize.y, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
	{
		glfwTerminate();
		return -1;
	}

	GLFWvidmode desktopMode;
	glfwGetDesktopMode(&desktopMode);

	glm::ivec2 desktopSize(desktopMode.Width, desktopMode.Height);
	glm::ivec2 wndPos = glutil::CalcWindowPosition(wndSize, desktopSize,
		glutil::WH_RIGHT, glutil::WV_BOTTOM);

	glfwSetWindowPos(wndPos.x, wndPos.y);

	if(!glload::LoadFunctions())
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowTitle("GLFW Demo");

	glutil::RegisterDebugOutput(glutil::STD_OUT);

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
