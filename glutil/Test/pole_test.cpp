#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include <glload/gl_3_3.hpp>
#include <glload/gl_load.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
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
	gl::BindBuffer(gl::ARRAY_BUFFER, objectBuffer);
	gl::BufferData(gl::ARRAY_BUFFER, g_sizeObjectBuffer, vertexData, gl::STATIC_DRAW);
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);

	gl::GenBuffers(1, &groundBuffer);
	gl::BindBuffer(gl::ARRAY_BUFFER, groundBuffer);
	gl::BufferData(gl::ARRAY_BUFFER, g_sizeGroundBuffer, groundData, gl::STATIC_DRAW);
	gl::BindBuffer(gl::ARRAY_BUFFER, 0);


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

	GLuint vertShader = glutil::CompileShader(gl::VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(gl::FRAGMENT_SHADER, fragmentShader);

	program = glutil::LinkProgram(vertShader, fragShader);

	gl::DeleteShader(vertShader);
	gl::DeleteShader(fragShader);

	unifModelToCameraMatrix = gl::GetUniformLocation(program, "modelToCameraMatrix");
	unifCameraToClipMatrix = gl::GetUniformLocation(program, "cameraToClipMatrix");
}

glm::ivec2 g_windowSize(0, 0);

glm::vec3 g_objPos(0.0f, 3.0f, 0.0f);

glutil::ViewData g_viewData = {g_objPos, glm::angleAxis(0.0f, glm::vec3(1.0f, 0.0f, 0.0f)), 20.0f, 0.0f};
glutil::ViewScale g_viewScale = {1.0f, 50.0f, 0.5f, 0.1f, 2.0f, 0.25f, 90.0f/250.0f};
glutil::ViewPole g_viewPole(g_viewData, g_viewScale, glutil::MB_LEFT_BTN, true);

glutil::ObjectData g_objData = {g_objPos, glm::fquat(1.0f, 0.0f, 0.0f, 0.0f)};
glutil::ObjectPole g_objectPole(g_objData, 90.0f/250.0f,
								glutil::MB_RIGHT_BTN, &g_viewPole);


void DrawGround(glutil::MatrixStack &matStack)
{
	gl::UseProgram(program);

	gl::UniformMatrix4fv(unifModelToCameraMatrix, 1, gl::FALSE_,
		glm::value_ptr(matStack.Top()));

	gl::BindBuffer(gl::ARRAY_BUFFER, groundBuffer);
	gl::EnableVertexAttribArray(0);
	gl::EnableVertexAttribArray(1);

	gl::VertexAttribPointer(0, 4, gl::FLOAT, gl::FALSE_, 0, 0);
	gl::VertexAttribPointer(1, 4, gl::FLOAT, gl::FALSE_, 0, (void*)(g_sizeGroundBuffer / 2));

	gl::DrawArrays(gl::TRIANGLE_STRIP, 0, 4);

	gl::DisableVertexAttribArray(0);
	gl::DisableVertexAttribArray(1);
	gl::UseProgram(0);
}

void DrawObject(glutil::MatrixStack &matStack)
{
	gl::UseProgram(program);

	glutil::PushStack pusher(matStack);

	matStack *= g_objectPole.CalcMatrix();

	gl::UniformMatrix4fv(unifModelToCameraMatrix, 1, gl::FALSE_,
		glm::value_ptr(matStack.Top()));

	gl::BindBuffer(gl::ARRAY_BUFFER, objectBuffer);
	gl::EnableVertexAttribArray(0);
	gl::EnableVertexAttribArray(1);

	gl::VertexAttribPointer(0, 4, gl::FLOAT, gl::FALSE_, 0, 0);
	gl::VertexAttribPointer(1, 4, gl::FLOAT, gl::FALSE_, 0, (void*)(g_sizeObjectBuffer / 2));

	gl::DrawArrays(gl::TRIANGLES, 0, 3);

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
	gl::ClearDepth(1.0);
	gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

	gl::Enable(gl::DEPTH_TEST);
	gl::DepthFunc(gl::LEQUAL);
	gl::Enable(gl::DEPTH_CLAMP);

	gl::UseProgram(program);

	glm::mat4 perspectiveMat = glm::perspective(50.0f, g_windowSize.x / (float)g_windowSize.y,
		1.f, 100.0f);
	gl::UniformMatrix4fv(unifCameraToClipMatrix, 1, gl::FALSE_,
		glm::value_ptr(perspectiveMat));

	glutil::MatrixStack matStack;
	matStack *= g_viewPole.CalcMatrix();

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

void GLFWCALL mouse_button_callback(int button, int action)
{
	glm::ivec2 mousePos(0, 0);
	glfwGetMousePos(&mousePos.x, &mousePos.y);
	int modifiers = calc_glfw_modifiers();

	int poleButton = 0;

	switch(button)
	{
	case GLFW_MOUSE_BUTTON_LEFT: poleButton = glutil::MB_LEFT_BTN; break;
	case GLFW_MOUSE_BUTTON_MIDDLE: poleButton = glutil::MB_MIDDLE_BTN; break;
	case GLFW_MOUSE_BUTTON_RIGHT: poleButton = glutil::MB_RIGHT_BTN; break;
	}

	g_objectPole.MouseClick((glutil::MouseButtons)poleButton, action == GLFW_PRESS,
		modifiers, mousePos);

	g_viewPole.MouseClick((glutil::MouseButtons)poleButton, action == GLFW_PRESS,
		modifiers, mousePos);
}

void GLFWCALL mouse_move_callback(int x, int y)
{
	g_objectPole.MouseMove(glm::ivec2(x, y));
	g_viewPole.MouseMove(glm::ivec2(x, y));
}

void GLFWCALL mouse_wheel_callback(int pos)
{
	static int lastPos = pos;

	int delta = pos - lastPos;

	glm::ivec2 mousePos(0, 0);
	glfwGetMousePos(&mousePos.x, &mousePos.y);
	int modifiers = calc_glfw_modifiers();

	g_objectPole.MouseWheel(delta, modifiers, mousePos);
	g_viewPole.MouseWheel(delta, modifiers, mousePos);

	lastPos = pos;
}

void GLFWCALL character_callback(int unicodePoint, int action)
{
	//Only interested in pressing.
	if(action == GLFW_RELEASE)
		return;

	if(unicodePoint > 127)
		return;

	g_viewPole.CharPress((char)unicodePoint);
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
		glutil::WH_LEFT, glutil::WV_CENTER);

	glfwSetWindowPos(wndPos.x, wndPos.y);

	if(!glload::LoadFunctions())
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowTitle("GLFW Demo");

	glutil::RegisterDebugOutput(glutil::STD_OUT);

	init();

	glfwEnable(GLFW_KEY_REPEAT);

	glfwSetWindowSizeCallback(reshape);
	glfwSetMouseButtonCallback(mouse_button_callback);
	glfwSetMousePosCallback(mouse_move_callback);
	glfwSetMouseWheelCallback(mouse_wheel_callback);
	glfwSetCharCallback(character_callback);

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
