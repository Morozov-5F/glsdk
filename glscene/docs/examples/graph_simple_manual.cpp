#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <iterator>
#include <glload/gl_3_3_comp.h>
#include <glload/gl_load.hpp>
#include <GL/glfw.h>
#include <glscene/glscene.h>
#include <glutil/glutil.h>
#include <glmesh/glmesh.h>
#include <boost/typeof/typeof.hpp>
#include <boost/utility/string_ref.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


GLuint g_texture;

glscene::SceneGraph *g_pGraph = NULL;
int g_width = 640;
int g_height = 480;

const boost::string_ref g_namePerspMat = "perspective matrix";
const boost::string_ref g_nameCamera = "main-camera";
const boost::string_ref g_nameGroundNode = "ground";
const boost::string_ref g_nameObjectNode = "object";
const boost::string_ref g_nameMainStyle = "main";

glm::vec3 g_objPos(0.0f, 3.0f, 0.0f);

glutil::ViewData g_viewData = {g_objPos, glm::angleAxis(0.0f, glm::vec3(1.0f, 0.0f, 0.0f)), 5.0f, 0.0f};
glutil::ViewScale g_viewScale = {
	0.5f, 30.0f,
	1.5f, 0.1f,
	0.5f, 0.125f,
	90.0f/250.0f};
glutil::ViewPole g_viewPole(g_viewData, g_viewScale, glutil::MB_LEFT_BTN, false);

glutil::ObjectData g_objData = {g_objPos, glm::fquat(1.0f, 0.0f, 0.0f, 0.0f)};
glutil::ObjectPole g_objectPole(g_objData, 90.0f/250.0f,
								glutil::MB_RIGHT_BTN, NULL);

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}

std::string LoadShaderFile(const std::string &filename)
{
	std::ifstream file(filename.c_str(), std::ios::binary | std::ios::in);
	if(!file)
		throw std::runtime_error("Could not open the file " + filename);
	return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

void BuildGraph(glscene::SceneGraph &graph)
{
	graph.GetResources().DefineCamera(g_nameCamera, g_viewData, g_viewScale, glutil::MB_LEFT_BTN, false);
	g_objectPole.SetLookatProvider(&graph.GetResources().GetCamera(g_nameCamera));

	{
		glmesh::gen::Color arr[] = {
			glmesh::gen::Color(128, 0, 128, 255),		//+y
			glmesh::gen::Color(192, 64, 64, 255),		//+x
			glmesh::gen::Color(128, 0, 128, 255),		//-y
			glmesh::gen::Color(192, 64, 64, 255),		//-x
			glmesh::gen::Color(64, 128, 255, 255),		//+z
			glmesh::gen::Color(64, 128, 255, 255),		//-z
		};

		graph.GetResources().DefineMesh("object", glmesh::gen::CubePyramid(2, arr));
		graph.GetResources().DefineMesh("ground", glmesh::gen::GroundPlane(2, 2));
	}

	const std::string groundVertexShader = LoadShaderFile("ground.vert");
	const std::string groundFragShader = LoadShaderFile("ground.frag");
	GLuint prog = glutil::LinkProgram(groundVertexShader, groundFragShader);

	{
		glscene::ProgramInfo progData;
		progData.modelToCameraMatrixUniformName = std::string("modelToCamera");

		graph.GetResources().DefineProgram("ground", prog, progData);
	}
	graph.GetResources().DefineUniform(g_namePerspMat, "cameraToPerspective", glm::mat4(1.0f));

	const std::string objectVertexShader = LoadShaderFile("object.vert");
	const std::string objectFragShader = LoadShaderFile("object.frag");
	prog = glutil::LinkProgram(objectVertexShader, objectFragShader);
	{
		glscene::ProgramInfo progData;
		progData.modelToCameraMatrixUniformName = std::string("modelToCamera");

		graph.GetResources().DefineProgram("object", prog, progData);
	}

	glscene::NodeData &ground = graph.CreateChildNode(graph.GetRootNode(), g_nameGroundNode);
	AddToLayer(ground, 0);

	SetDecomposed(GetNodeTM(ground),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat(0.707107f, 0.707107f, 0.0f, 0.0f));

	SetDecomposed(GetObjectTM(ground),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat(),
		glm::vec3(10.0f, 10.0f, 1.0f));

	{
		glscene::StyleInfo style;
		style.meshResourceId = "ground";
		glscene::SingleProgramBinding programBind;
		programBind.programId = "ground";
		programBind.uniformIds.push_back(std::string(g_namePerspMat.begin(), g_namePerspMat.end()));
		style.progBinding = programBind;

		graph.DefineNodeStyle(ground, g_nameMainStyle, style);
	}

	glscene::NodeData &object = graph.CreateChildNode(graph.GetRootNode(), g_nameObjectNode);
	AddToLayer(object, 0);

	SetDecomposed(GetNodeTM(object), g_objPos);
	SetDecomposed(GetObjectTM(object),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat(),
		glm::vec3(0.1f, 0.1f, 0.1f));

	{
		glscene::StyleInfo style;
		style.meshResourceId = "object";
		style.meshVariantString = std::string("lit-color");
		glscene::SingleProgramBinding programBind;
		programBind.programId = "object";
		programBind.uniformIds.push_back(std::string(g_namePerspMat.data(), g_namePerspMat.size()));
		style.progBinding = programBind;

		graph.DefineNodeStyle(object, g_nameMainStyle, style);
	}
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	glViewport(0, 0, g_width, g_height);						// Reset The Current Viewport
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			// Clear Screen And Depth Buffer

	glm::mat4 persp = glm::perspective(45.0f, g_width/(float)g_height, 0.1f, 100.0f);
	g_pGraph->GetResources().SetUniform(g_namePerspMat, persp);
	SetMatrixCompose(GetNodeTM(*g_pGraph->FindNode(g_nameObjectNode)),
		g_objectPole.CalcMatrix());

	g_pGraph->Render(g_pGraph->GetResources().GetCamera(g_nameCamera).CalcMatrix(), glscene::ORDER_ARBITRARY, 0, "main");
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

	g_objectPole.MouseClick((glutil::MouseButtons)poleButton, action == GLFW_PRESS,
		modifiers, mousePos);

	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseClick(
			(glutil::MouseButtons)poleButton, action == GLFW_PRESS, modifiers, mousePos);
}

void GLFWCALL mouse_move_callback(int x, int y)
{
	g_objectPole.MouseMove(glm::ivec2(x, y));
	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseMove(glm::ivec2(x, y));
}

void GLFWCALL mouse_wheel_callback(int pos)
{
	static int lastPos = pos;

	int delta = pos - lastPos;

	glm::ivec2 mousePos(0, 0);
	glfwGetMousePos(&mousePos.x, &mousePos.y);
	int modifiers = calc_glfw_modifiers();

	g_objectPole.MouseWheel(delta, modifiers, mousePos);
	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).MouseWheel(delta, modifiers, mousePos);

	lastPos = pos;
}

void GLFWCALL character_callback(int unicodePoint, int action)
{
	//Only interested in pressing.
	if(action == GLFW_RELEASE)
		return;

	if(unicodePoint > 127)
		return;

	if(g_pGraph)
		g_pGraph->GetResources().GetCamera(g_nameCamera).CharPress((char)unicodePoint);
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
		const char *layerNames[] =
		{
			"main",
		};

		glscene::SceneGraph graph(layerNames);
		g_pGraph = &graph;

		try
		{
			BuildGraph(graph);
		}
		catch(std::runtime_error &e)
		{
			printf("%s\n", e.what());
			throw;
		}

		//Main loop
		while(true)
		{
			display();

			if(glfwGetKey(GLFW_KEY_ESC) || !glfwGetWindowParam(GLFW_OPENED))
				break;

			glfwSleep(0.005f);
		}
	}

	glfwTerminate();
	return 0;
}
