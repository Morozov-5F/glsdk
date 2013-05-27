#include <vector>
#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

#include <glload/gl_3_3.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>
#include <glutil/glutil.h>
#include <glimg/glimg.h>
#include <glmesh/glmesh.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>


GLuint g_texture;
GLuint g_program;

GLint g_unifModelToCameraMatrix;
GLint g_unifCameraToClipMatrix;

glmesh::Mesh *g_pSphere = NULL;

void init()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	const std::string vertexShader(
		"#version 330\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"
		"layout(location = 2) in vec3 normal;\n"
		"\n"
		"smooth out vec3 modelNormal;\n"
		"\n"
		"uniform mat4 cameraToClipMatrix;\n"
		"uniform mat4 modelToCameraMatrix;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	vec4 cameraPos = modelToCameraMatrix * position;\n"
		"	gl_Position = cameraToClipMatrix * cameraPos;\n"
		"	modelNormal = normal;\n"
		"}\n"
		);

	const std::string fragmentShader(
		"#version 330\n"
		"\n"
		"smooth in vec3 modelNormal;\n"
		"out vec4 outputColor;\n"
		"uniform samplerCube cubeMap;\n"
		"\n"
		"void main()\n"
		"{\n"
		"	outputColor = texture(cubeMap, modelNormal); /*vec4(((modelNormal + 1.0) / 2.0), 1.0);*/\n"
		"}\n"
		);

	GLuint vertShader = glutil::CompileShader(GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = glutil::CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	g_program = glutil::LinkProgram(vertShader, fragShader);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	g_unifModelToCameraMatrix = glGetUniformLocation(g_program, "modelToCameraMatrix");
	g_unifCameraToClipMatrix = glGetUniformLocation(g_program, "cameraToClipMatrix");

	GLint cubeLoc = glGetUniformLocation(g_program, "cubeMap");
	glUseProgram(g_program);
	glUniform1i(cubeLoc, 0);
	glUseProgram(0);

	g_pSphere = glmesh::gen::UnitSphere(6, 8);

	std::auto_ptr<glimg::ImageSet> pImg(glimg::loaders::dds::LoadFromFile("pics\\cubemapdxt5test.dds"));
	g_texture = glimg::CreateTexture(pImg.get(), 0);
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glBindTexture(GL_TEXTURE_CUBE_MAP, g_texture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

glm::ivec2 g_windowSize(0, 0);

glm::vec3 g_objPos(0.0f, 3.0f, 0.0f);

glutil::ViewData g_viewData = {g_objPos, glm::angleAxis(0.0f, glm::vec3(1.0f, 0.0f, 0.0f)), 20.0f, 0.0f};
glutil::ViewScale g_viewScale = {1.0f, 50.0f, 0.5f, 0.1f, 2.0f, 0.25f, 90.0f/250.0f};
glutil::ViewPole g_viewPole(g_viewData, g_viewScale, glutil::MB_LEFT_BTN);

glutil::ObjectData g_objData = {g_objPos, glm::fquat(1.0f, 0.0f, 0.0f, 0.0f)};
glutil::ObjectPole g_objectPole(g_objData, 90.0f/250.0f,
								glutil::MB_RIGHT_BTN, &g_viewPole);

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	glEnable(GL_FRAMEBUFFER_SRGB);
	glClearColor(0.3f, 0.5f, 0.5f, 0.5f);
	glClearDepth(1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glActiveTexture(GL_TEXTURE0 + 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, g_texture);

	glUseProgram(g_program);
	glUniformMatrix4fv(g_unifCameraToClipMatrix, 1, GL_FALSE,
		glm::value_ptr(glm::perspective(50.0f, g_windowSize.x / (float)g_windowSize.y, 1.f, 100.0f)));

	glUniformMatrix4fv(g_unifModelToCameraMatrix, 1, GL_FALSE,
		glm::value_ptr(g_viewPole.CalcMatrix() * g_objectPole.CalcMatrix()));

	g_pSphere->Render("lit");

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glutSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	g_windowSize.x = w;
	g_windowSize.y = h;
}

//Called whenever a key on the keyboard was pressed.
//The key is given by the ''key'' parameter, which is in ASCII.
//It's often a good idea to have the escape key (ASCII value 27) call glutLeaveMainLoop() to
//exit the program.
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	}

	g_viewPole.CharPress(key);
	g_objectPole.CharPress(key);
	glutPostRedisplay();
}

inline int calc_glut_modifiers()
{
	int ret = 0;

	int modifiers = glutGetModifiers();
	if(modifiers & GLUT_ACTIVE_SHIFT)
		ret |= glutil::MM_KEY_SHIFT;
	if(modifiers & GLUT_ACTIVE_CTRL)
		ret |= glutil::MM_KEY_CTRL;
	if(modifiers & GLUT_ACTIVE_ALT)
		ret |= glutil::MM_KEY_ALT;

	return ret;
}

void MouseMotion(int x, int y)
{
	g_viewPole.MouseMove(glm::ivec2(x, y));
	g_objectPole.MouseMove(glm::ivec2(x, y));
	glutPostRedisplay();
}

void MouseButton(int button, int state, int x, int y)
{
	int modifiers = calc_glut_modifiers();

#ifdef LOAD_X11
	glm::ivec2 mouseLoc = glm::ivec2(x, y);
#endif //LOAD_X11

	glutil::MouseButtons eButton;

	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		eButton = glutil::MB_LEFT_BTN;
		break;
	case GLUT_MIDDLE_BUTTON:
		eButton = glutil::MB_MIDDLE_BTN;
		break;
	case GLUT_RIGHT_BUTTON:
		eButton = glutil::MB_RIGHT_BTN;
		break;
#ifdef LOAD_X11
		//Linux Mouse wheel support
	case 3:
		{
			forward.MouseWheel(1, modifiers, mouseLoc);
			return;
		}
	case 4:
		{
			forward.MouseWheel(-1, modifiers, mouseLoc);
			return;
		}
#endif
	default:
		return;
	}

	g_viewPole.MouseClick(eButton, state == GLUT_DOWN, modifiers, glm::ivec2(x, y));
	g_objectPole.MouseClick(eButton, state == GLUT_DOWN, modifiers, glm::ivec2(x, y));
	glutPostRedisplay();
}

void MouseWheel(int wheel, int direction, int x, int y)
{
	g_viewPole.MouseWheel(direction, calc_glut_modifiers(), glm::ivec2(x, y));
	g_objectPole.MouseWheel(direction, calc_glut_modifiers(), glm::ivec2(x, y));
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	int width = 640;
	int height = 480;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL | GLUT_SRGB;

	glutInitDisplayMode(displayMode);
	glutInitContextVersion (3, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
#ifdef DEBUG
	glutInitContextFlags(GLUT_DEBUG);
#endif
	glutInitWindowSize (width, height);
	glutInitWindowPosition (300, 200);
	glutCreateWindow (argv[0]);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glload::LoadFunctions();
	glutil::RegisterDebugOutput(glutil::STD_OUT);

	init();

	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutMouseWheelFunc(MouseWheel);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
