#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/freeglut.h>

GLuint positionBufferObject;
GLuint program;
GLuint vao;

GLuint BuildShader(GLenum eShaderType, const std::string &shaderText)
{
	GLuint shader = gl::CreateShader(eShaderType);
	const char *strFileData = shaderText.c_str();
	gl::ShaderSource(shader, 1, &strFileData, NULL);

	gl::CompileShader(shader);

	GLint status;
	gl::GetShaderiv(shader, gl::GL_COMPILE_STATUS, &status);
	if (status == gl::GL_FALSE)
	{
		//With ARB_debug_output, we already get the info log on compile failure.
		if(!glext_ARB_debug_output)
		{
			GLint infoLogLength;
			gl::GetShaderiv(shader, gl::GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			gl::GetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

			const char *strShaderType = NULL;
			switch(eShaderType)
			{
			case gl::GL_VERTEX_SHADER: strShaderType = "vertex"; break;
			case gl::GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
			case gl::GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
			}

			fprintf(stderr, "Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
			delete[] strInfoLog;
		}

		throw std::runtime_error("Compile failure in shader.");
	}

	return shader;
}


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

	GLuint vertShader = BuildShader(gl::GL_VERTEX_SHADER, vertexShader);
	GLuint fragShader = BuildShader(gl::GL_FRAGMENT_SHADER, fragmentShader);

	program = gl::CreateProgram();
	gl::AttachShader(program, vertShader);
	gl::AttachShader(program, fragShader);	
	gl::LinkProgram(program);

	GLint status;
	gl::GetProgramiv (program, gl::GL_LINK_STATUS, &status);
	if (status == gl::GL_FALSE)
	{
		if(!glext_ARB_debug_output)
		{
			GLint infoLogLength;
			gl::GetProgramiv(program, gl::GL_INFO_LOG_LENGTH, &infoLogLength);

			GLchar *strInfoLog = new GLchar[infoLogLength + 1];
			gl::GetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
			fprintf(stderr, "Linker failure: %s\n", strInfoLog);
			delete[] strInfoLog;
		}

		throw std::runtime_error("Shader could not be linked.");
	}
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

	glutSwapBuffers();
}

//Called whenever the window is resized. The new window size is given, in pixels.
//This is an opportunity to call glViewport or glScissor to keep up with the change in size.
void reshape (int w, int h)
{
	gl::Viewport(0, 0, (GLsizei) w, (GLsizei) h);
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

void GLE_FUNCPTR DebugFunc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
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
	glutInit(&argc, argv);

	int width = 500;
	int height = 500;
	unsigned int displayMode = GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL;

	glutInitDisplayMode(displayMode);
	glutInitContextVersion (3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
#ifdef DEBUG
	glutInitContextFlags(GLUT_DEBUG);
#endif
	glutInitWindowSize (width, height); 
	glutInitWindowPosition (300, 200);
	glutCreateWindow (argv[0]);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glload::LoadFunctions();

	if(glext_ARB_debug_output)
	{
		gl::Enable(gl::GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
		gl::DebugMessageCallbackARB(DebugFunc, (void*)15);
	}

	init();

	glutDisplayFunc(display); 
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
