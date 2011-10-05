#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glutil/glutil.h>

GLuint objectBuffer;
size_t g_sizeObjectBuffer;
GLuint groundBuffer;
size_t g_sizeGroundBuffer;
GLuint vao;

GLuint program;
GLuint unifCameraToClipMatrix;
GLuint unifModelToCameraMatrix;

void init()
{
	gl::GenVertexArrays(1, &vao);
	gl::BindVertexArray(vao);

	const float vertexData[] = {
		0.75f, 0.75f, 0.0f, 1.0f,
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,

		0.6f, 0.8f, 0.0f, 1.0f,
		0.9f, 0.2f, 0.4f, 1.0f,
		0.1f, 0.2f, 0.7f, 1.0f,
	};
	g_sizeObjectBuffer = sizeof(vertexData);

	const float groundData[] = {
		30.0f, 0.0f, 30.0f, 1.0f,
		30.0f, 0.0f, -30.0f, 1.0f,
		-30.0f, 0.0f, 30.0f, 1.0f,
		-30.0f, 0.0f, -30.0f, 1.0f,

		0.2f, 1.0f, 0.2f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
	};
	g_sizeGroundBuffer = sizeof(groundData);

	gl::GenBuffers(1, &objectBuffer);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, objectBuffer);
	gl::BufferData(gl::GL_ARRAY_BUFFER, g_sizeObjectBuffer, vertexData, gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);

	gl::GenBuffers(1, &groundBuffer);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, groundBuffer);
	gl::BufferData(gl::GL_ARRAY_BUFFER, g_sizeGroundBuffer, groundData, gl::GL_STATIC_DRAW);
	gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);


	const std::string vertexShader(
		"#version 330\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 1) in vec4 color;\n"
		"\n"
		"smooth out vec4 theColor;\n"
		"\n"
		"uniform mat4 cameraToClipMatrix;\n"
		"uniform mat4 modelToCameraMatrix;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	vec4 cameraPos = modelToCameraMatrix * position;\n"
		"	gl_Position = cameraToClipMatrix * cameraPos;\n"
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

	program = glutil::LinkProgram(vertShader, fragShader);

	gl::DeleteShader(vertShader);
	gl::DeleteShader(fragShader);

	unifModelToCameraMatrix = gl::GetUniformLocation(program, "modelToCameraMatrix");
	unifCameraToClipMatrix = gl::GetUniformLocation(program, "cameraToClipMatrix");
}

glm::ivec2 g_windowSize(0, 0);

glutil::ObjectPole g_objectPole(glm::vec3(0.0f, 0.0f, -10.0f), glm::fquat(1.0f, 0.0f, 0.0f, 0.0f),
								glutil::MB_LEFT_BTN, NULL);

void DrawGround(glutil::MatrixStack &matStack)
{
	gl::UseProgram(program);

	gl::UniformMatrix4fv(unifModelToCameraMatrix, 1, gl::GL_FALSE,
		glm::value_ptr(matStack.Top()));

	gl::BindBuffer(gl::GL_ARRAY_BUFFER, groundBuffer);
	gl::EnableVertexAttribArray(0);
	gl::EnableVertexAttribArray(1);

	gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, 0);
	gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, (void*)(g_sizeGroundBuffer / 2));

	gl::DrawArrays(gl::GL_TRIANGLE_STRIP, 0, 4);

	gl::DisableVertexAttribArray(0);
	gl::DisableVertexAttribArray(1);
	gl::UseProgram(0);
}

void DrawObject(glutil::MatrixStack &matStack)
{
	gl::UseProgram(program);

	glutil::PushStack pusher(matStack);

	matStack *= g_objectPole.CalcMatrix();

	gl::UniformMatrix4fv(unifModelToCameraMatrix, 1, gl::GL_FALSE,
		glm::value_ptr(matStack.Top()));

	gl::BindBuffer(gl::GL_ARRAY_BUFFER, objectBuffer);
	gl::EnableVertexAttribArray(0);
	gl::EnableVertexAttribArray(1);

	gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, 0);
	gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, (void*)(g_sizeObjectBuffer / 2));

	gl::DrawArrays(gl::GL_TRIANGLES, 0, 3);

	gl::DisableVertexAttribArray(0);
	gl::DisableVertexAttribArray(1);
	gl::UseProgram(0);
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	gl::ClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	gl::Clear(gl::GL_COLOR_BUFFER_BIT);

	gl::UseProgram(program);

	glm::mat4 perspectiveMat = glm::perspective(50.0f, g_windowSize.x / (float)g_windowSize.y,
		1.f, 100.0f);

	gl::UniformMatrix4fv(unifCameraToClipMatrix, 1, gl::GL_FALSE,
		glm::value_ptr(perspectiveMat));

	glutil::MatrixStack matStack;

	{
		glutil::PushStack pusher(matStack);

		DrawGround(matStack);
		DrawObject(matStack);
	}

	glfwSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	gl::Viewport(0, 0, (GLsizei) w, (GLsizei) h);
	g_windowSize.x = w;
	g_windowSize.y = h;
}

int calc_glfw_modifiers()
{
	int ret = 0;

	if((glfwGetKey(GLFW_KEY_LALT) == GLFW_PRESS) ||
		(glfwGetKey(GLFW_KEY_RALT) == GLFW_PRESS))
		ret |= glutil::MM_KEY_ALT;

	if((glfwGetKey(GLFW_KEY_LSHIFT) == GLFW_PRESS) ||
		(glfwGetKey(GLFW_KEY_RSHIFT) == GLFW_PRESS))
		ret |= glutil::MM_KEY_SHIFT;

	if((glfwGetKey(GLFW_KEY_LCTRL) == GLFW_PRESS) ||
		(glfwGetKey(GLFW_KEY_RCTRL) == GLFW_PRESS))
		ret |= glutil::MM_KEY_CTRL;

	return ret;
}

void mouse_button_callback(int button, int action)
{
	glm::ivec2 mousePos(0, 0);
	glfwGetMousePos(&mousePos.x, &mousePos.y);

	int poleButton = 0;

	switch(button)
	{
	case GLFW_MOUSE_BUTTON_LEFT: poleButton = glutil::MB_LEFT_BTN; break;
	case GLFW_MOUSE_BUTTON_MIDDLE: poleButton = glutil::MB_MIDDLE_BTN; break;
	case GLFW_MOUSE_BUTTON_RIGHT: poleButton = glutil::MB_RIGHT_BTN; break;
	}

	g_objectPole.MouseClick((glutil::MouseButtons)poleButton, action == GLFW_PRESS,
		calc_glfw_modifiers(), mousePos);
}

void mouse_move_callback(int x, int y)
{
	g_objectPole.MouseMove(glm::ivec2(x, y));
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

	glm::ivec2 desktopSize(desktopMode.Width, desktopMode.Height);
	glm::ivec2 wndPos = glutil::CalcWindowPosition(wndSize, desktopSize,
		glutil::WH_LEFT, glutil::WV_CENTER);

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
	glfwSetMouseButtonCallback(mouse_button_callback);
	glfwSetMousePosCallback(mouse_move_callback);

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
