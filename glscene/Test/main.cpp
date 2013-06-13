#include <string>
#include <exception>
#include <stdexcept>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

#include <glload/gl_3_3_comp.h>
#include <glload/gl_load.hpp>
#include <GL/freeglut.h>
#include <glscene/glscene.h>
#include <glutil/Debug.h>
#include <glmesh/glmesh.h>


GLuint g_texture;

void init()
{
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

//Called to update the display.
//You should call glutSwapBuffers after all of your rendering to display what you rendered.
//If you need continuous updates of the screen, call glutPostRedisplay() at the end of the function.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glLoadIdentity();									// Reset The Current Modelview Matrix

	glDepthRange(0.0f, 0.5f);


	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, g_texture);
	glEnable(GL_TEXTURE_2D);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_BLEND);
	glBlendEquation(GL_FUNC_ADD);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDepthRange(0.5f, 1.0f);
	glBegin(GL_QUADS);
	{
		//Gray square.
		glColor3ub(128, 128, 128);

		//Draw our four points, clockwise.
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1, 1, -0.5);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(1, 1, -0.5);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(1, -1, 0.5);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1, -1, 0.5);
	}
	glEnd();

	glDisable(GL_BLEND);


	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glutSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	glViewport(0, 0, w, h);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	//Give me an orthographic projection.
	glOrtho(-1, 1, -1, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
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
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	int width = 640;
	int height = 480;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;

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

	{
		const char *layerNames[] =
		{
			"main",
		};

		glscene::SceneGraph graph(layerNames);

		try
		{
			graph.GetResources().DefineUniform("special", "special_glsl", 5.0f);
			graph.GetResources().SetUniform("special", 5.0f);
			graph.GetResources().DefineMesh("special", glmesh::gen::Icosahedron());
		}
		catch(glscene::UniformResourceTypeMismatchException &e)
		{
			printf("%s\n", e.what());
			throw;
		}
	}

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
