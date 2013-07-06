#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <iterator>
#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/glfw.h>
#include <glscene/glscene.h>
#include <glutil/glutil.h>
#include <glmesh/glmesh.h>
#include <glimg/glimg.h>
#include <boost/typeof/typeof.hpp>
#include <boost/utility/string_ref.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


int g_width = 640;
int g_height = 480;


void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);
}


//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	glViewport(0, 0, g_width, g_height);						// Reset The Current Viewport
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Clear Screen And Depth Buffer

	glfwSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	g_width = w;
	g_height = h;
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

/*
	g_objectPole.MouseClick((glutil::MouseButtons)poleButton, action == GLFW_PRESS, modifiers, mousePos);

	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseClick(
			(glutil::MouseButtons)poleButton, action == GLFW_PRESS, modifiers, mousePos);
*/
}

void GLFWCALL mouse_move_callback(int x, int y)
{
/*
	g_objectPole.MouseMove(glm::ivec2(x, y));
	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseMove(glm::ivec2(x, y));
*/
}

void GLFWCALL mouse_wheel_callback(int pos)
{
	static int lastPos = pos;

	int delta = pos - lastPos;

	glm::ivec2 mousePos(0, 0);
	glfwGetMousePos(&mousePos.x, &mousePos.y);
	int modifiers = calc_glfw_modifiers();

/*
	g_objectPole.MouseWheel(delta, modifiers, mousePos);
	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseWheel(delta, modifiers, mousePos);
*/

	lastPos = pos;
}

void GLFWCALL character_callback(int unicodePoint, int action)
{
	//Only interested in pressing.
	if(action == GLFW_RELEASE)
		return;

	if(unicodePoint > 127)
		return;

/*
	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).CharPress((char)unicodePoint);
*/
}



int main(int argc, char** argv)
{
	if(!glfwInit())
		return -1;

	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 3);
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef DEBUG
	glfwOpenWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

	if(!glfwOpenWindow(g_width, g_height, 8, 8, 8, 8, 24, 8, GLFW_WINDOW))
	{
		glfwTerminate();
		return -1;
	}

	glfwEnable(GLFW_KEY_REPEAT);
	glfwSetWindowTitle("Test");
	glfwSetWindowSizeCallback(reshape);
	glfwSetMouseButtonCallback(mouse_button_callback);
	glfwSetMousePosCallback(mouse_move_callback);
	glfwSetMouseWheelCallback(mouse_wheel_callback);
	glfwSetCharCallback(character_callback);

	glload::LoadFunctions();
	glutil::RegisterDebugOutput(glutil::STD_OUT);

	init();

	{
		try
		{
			glscene::ParseFromFile("test.glscene");
		}
		catch(std::runtime_error &e)
		{
			printf("%s\n", e.what());
		}

/*
		//Main loop
		while(true)
		{
			display();

			if(glfwGetKey(GLFW_KEY_ESC) || !glfwGetWindowParam(GLFW_OPENED))
				break;

			glfwSleep(0.005f);
		}
*/
	}

	glfwTerminate();
	return 0;
}
