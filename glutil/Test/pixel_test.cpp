
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glutil/glutil.h>

GLint g_cameraToClipMatrixUnif = 0;

GLuint g_program = 0;

void InitializeProgram()
{
	const std::string vertexShader(
		"#version 330\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 color;\n"
		"\n"
		"smooth out vec4 theColor;\n"
		"\n"
		"uniform mat4 cameraToClipMatrix;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	gl_Position = cameraToClipMatrix * position;\n"
		"	theColor = color;\n"
		"}\n"
		);

	const std::string fragmentShader(
		"#version 330\n"
		"\n"
		"smooth in vec4 theColor;\n"
		"out vec4 outputColor;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	outputColor = theColor;\n"
		"}\n"
		);

	GLuint vertShader = glutil::CompileShader(gl::GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(gl::GL_FRAGMENT_SHADER, fragmentShader);

	g_program = glutil::LinkProgram(vertShader, fragShader);

	gl::DeleteShader(vertShader);
	gl::DeleteShader(fragShader);

	g_cameraToClipMatrixUnif = gl::GetUniformLocation(g_program, "cameraToClipMatrix");
}

GLuint g_dataBufferObject;
GLuint g_vao;


void InitializeVertexData()
{
	const GLfloat vertexData[] = {
		 90.0f,	 80.0f,	0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		 90.0f,	 16.0f,	0.0f, 1.0f,
		0.0f, 1.0f, 0.0f, 1.0f,
		410.0f,	 80.0f,	0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
		410.0f,	 16.0f,	0.0f, 1.0f,
		0.0f, 0.0f, 0.0f, 1.0f,
	};

	gl::GenBuffers(1, &g_dataBufferObject);

	gl::BindBuffer(gl::GL_ARRAY_BUFFER, g_dataBufferObject);
	gl::BufferData(gl::GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, gl::GL_STATIC_DRAW);

	gl::GenVertexArrays(1, &g_vao);

	gl::BindVertexArray(g_vao);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, g_dataBufferObject);
	gl::EnableVertexAttribArray(0);
	gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 32, (void*)0);
	gl::EnableVertexAttribArray(1);
	gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, 32, (void*)16);

	gl::BindVertexArray(0);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);
}

//Called after the window and OpenGL are initialized. Called exactly once, before the main loop.
void init()
{
	InitializeProgram();
	InitializeVertexData();
}

glm::ivec2 g_windowSize(500, 500);

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	gl::ClearColor(0.0f, 0.8f, 0.3f, 0.0f);
	gl::Clear(gl::GL_COLOR_BUFFER_BIT);

	gl::UseProgram(g_program);

	glutil::MatrixStack persMatrix;
	persMatrix.PixelPerfectOrtho(g_windowSize, glm::vec2(-1.0f, 1.0f), false);

	gl::UniformMatrix4fv(g_cameraToClipMatrixUnif, 1, gl::GL_FALSE, glm::value_ptr(persMatrix.Top()));
	gl::BindVertexArray(g_vao);

	gl::DrawArrays(gl::GL_TRIANGLE_STRIP, 0, 4);

	gl::BindVertexArray(0);
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
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, gl::GL_TRUE);
#endif

	if(!glfwOpenWindow(g_windowSize.x, g_windowSize.y, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
	{
		glfwTerminate();
		return -1;
	}

	GLFWvidmode desktopMode;
	glfwGetDesktopMode(&desktopMode);

	glm::ivec2 desktopSize(desktopMode.Width, desktopMode.Height);
	glm::ivec2 wndPos = glutil::CalcWindowPosition(g_windowSize, desktopSize,
		glutil::WH_RIGHT, glutil::WV_CENTER);

	glfwSetWindowPos(wndPos.x, wndPos.y);

	if(glload::LoadFunctions() == glload::LS_LOAD_FAILED)
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

		glfwSleep(0.010);
	}

	glfwTerminate();
	return 0;
}
