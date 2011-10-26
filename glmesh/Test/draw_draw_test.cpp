
#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <utility>

#include <glload/gl_3_3.hpp>
#include <glload/gll.hpp>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/half_float.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glutil/glutil.h>
#include <glmesh/glmesh.h>
#include "framework_draw.h"

namespace
{
	const float g_vertexData[] = {
		0.75f, 0.75f, 0.0f, 1.0f,
		0.6f, 0.8f, 0.0f, 1.0f,

		0.75f, -0.75f, 0.0f, 1.0f,
		0.9f, 0.2f, 0.4f, 1.0f,

		-0.75f, -0.75f, 0.0f, 1.0f,
		0.1f, 0.2f, 0.7f, 1.0f,
	};

	const float g_groundData[] = {
		30.0f, 0.0f, 30.0f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,

		30.0f, 0.0f, -30.0f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,

		-30.0f, 0.0f, 30.0f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,

		-30.0f, 0.0f, -30.0f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
	};
}

class BasicDrawable : public Drawable
{
public:
	BasicDrawable()
		: m_streamBuf(1024)
	{
		gl::ClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		gl::ClearDepth(1.0);

		gl::Enable(gl::GL_DEPTH_TEST);
		gl::DepthFunc(gl::GL_LEQUAL);
		gl::Enable(gl::GL_DEPTH_CLAMP);

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

		m_program = glutil::LinkProgram(vertShader, fragShader);

		gl::DeleteShader(vertShader);
		gl::DeleteShader(fragShader);

		m_unifModelToCameraMatrix = gl::GetUniformLocation(m_program, "modelToCameraMatrix");
		m_unifCameraToClipMatrix = gl::GetUniformLocation(m_program, "cameraToClipMatrix");

		glmesh::AttributeList attribs;
		attribs.push_back(glmesh::AttribDesc(0, 4, glmesh::VDT_HALF_FLOAT, glmesh::ADT_FLOAT));
		attribs.push_back(glmesh::AttribDesc(1, 4, glmesh::VDT_UNSIGN_BYTE, glmesh::ADT_NORM_FLOAT));
		m_vertFmt = glmesh::VertexFormat(attribs);
	}

	~BasicDrawable()
	{
		gl::DeleteProgram(m_program);
	}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld)
	{
		gl::Clear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);
		
		//Set uniforms.
		gl::UseProgram(m_program);
		gl::UniformMatrix4fv(m_unifCameraToClipMatrix, 1, gl::GL_FALSE,
			glm::value_ptr(cameraToClip));

		{
			gl::UniformMatrix4fv(m_unifModelToCameraMatrix, 1, gl::GL_FALSE,
				glm::value_ptr(worldToCamera * modelToWorld));

			glmesh::Draw immMode(gl::GL_TRIANGLES, 3, m_vertFmt, m_streamBuf);

			immMode.Attrib<glm::half>(glm::hvec4(0.75f, 0.75f, 0.0f, 1.0f));
			immMode.Attrib<GLubyte>(153, 204, 0, 255);

			immMode.Attrib<glm::half>(glm::hvec4(0.75f, -0.75f, 0.0f, 1.0f));
			immMode.Attrib<GLubyte>(230, 51, 0, 255);

			immMode.Attrib<glm::half>(glm::hvec4(-0.75f, -0.75f, 0.0f, 1.0f));
			immMode.Attrib<GLubyte>(26, 51, 179, 255);

			immMode.Render();
		}

		{
			gl::UniformMatrix4fv(m_unifModelToCameraMatrix, 1, gl::GL_FALSE,
				glm::value_ptr(worldToCamera));

			glmesh::Draw immMode(gl::GL_TRIANGLE_STRIP, 4, m_vertFmt, m_streamBuf);

			immMode.Attrib<glm::half>(glm::hvec4(30.0f, 0.0f, 30.0f, 1.0f));
			immMode.Attrib<GLubyte>(51, 255, 51, 255);

			immMode.Attrib<glm::half>(glm::hvec4(30.0f, 0.0f, -30.0f, 1.0f));
			immMode.Attrib<GLubyte>(51, 255, 51, 255);

			immMode.Attrib<glm::half>(glm::hvec4(-30.0f, 0.0f, 30.0f, 1.0f));
			immMode.Attrib<GLubyte>(51, 255, 51, 255);

			immMode.Attrib<glm::half>(glm::hvec4(-30.0f, 0.0f, -30.0f, 1.0f));
			immMode.Attrib<GLubyte>(51, 255, 51, 255);

			immMode.Render();
		}

		gl::UseProgram(0);
	}

private:
	glmesh::StreamBuffer m_streamBuf;
	glmesh::VertexFormat m_vertFmt;
	GLuint m_program;
	GLuint m_unifModelToCameraMatrix;
	GLuint m_unifCameraToClipMatrix;
};


Drawable *CreateDrawable()
{
	return new BasicDrawable();
}
