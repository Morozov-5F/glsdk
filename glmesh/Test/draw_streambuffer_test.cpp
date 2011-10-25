
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
		0.75f, -0.75f, 0.0f, 1.0f,
		-0.75f, -0.75f, 0.0f, 1.0f,

		0.6f, 0.8f, 0.0f, 1.0f,
		0.9f, 0.2f, 0.4f, 1.0f,
		0.1f, 0.2f, 0.7f, 1.0f,
	};

	const float g_groundData[] = {
		30.0f, 0.0f, 30.0f, 1.0f,
		30.0f, 0.0f, -30.0f, 1.0f,
		-30.0f, 0.0f, 30.0f, 1.0f,
		-30.0f, 0.0f, -30.0f, 1.0f,

		0.2f, 1.0f, 0.2f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
		0.2f, 1.0f, 0.2f, 1.0f,
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
	}

	~BasicDrawable()
	{
		gl::DeleteProgram(m_program);
	}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld)
	{

		gl::Clear(gl::GL_COLOR_BUFFER_BIT | gl::GL_DEPTH_BUFFER_BIT);
		
		//Update data in stream buffer.
		size_t triOffset = 0;
		{
			glmesh::StreamBuffer::Map buffMap(m_streamBuf, sizeof(g_vertexData));
			triOffset = m_streamBuf.GetBufferPosition();

			memcpy(buffMap.GetPtr(), g_vertexData, sizeof(g_vertexData));
		}
		size_t groundOffset = 0;
		{
			glmesh::StreamBuffer::Map buffMap(m_streamBuf, sizeof(g_groundData));
			groundOffset = m_streamBuf.GetBufferPosition();

			memcpy(buffMap.GetPtr(), g_groundData, sizeof(g_groundData));
		}

		//Set uniforms.
		gl::UseProgram(m_program);
		gl::UniformMatrix4fv(m_unifCameraToClipMatrix, 1, gl::GL_FALSE,
			glm::value_ptr(cameraToClip));

		//Bind the buffer.
		gl::BindVertexArray(m_streamBuf.GetVao());
		gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_streamBuf.GetBuffer());

		gl::EnableVertexAttribArray(0);
		gl::EnableVertexAttribArray(1);

		//Draw mobile triangle.
		gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, (void*)triOffset);
		gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, 0,
			(void*)(triOffset + (sizeof(g_vertexData) / 2)));

		gl::UniformMatrix4fv(m_unifModelToCameraMatrix, 1, gl::GL_FALSE,
			glm::value_ptr(worldToCamera * modelToWorld));

		gl::DrawArrays(gl::GL_TRIANGLES, 0, 3);

		//Draw ground plane.
		gl::VertexAttribPointer(0, 4, gl::GL_FLOAT, gl::GL_FALSE, 0, (void*)groundOffset);
		gl::VertexAttribPointer(1, 4, gl::GL_FLOAT, gl::GL_FALSE, 0,
			(void*)(groundOffset + (sizeof(g_groundData) / 2)));

		gl::UniformMatrix4fv(m_unifModelToCameraMatrix, 1, gl::GL_FALSE,
			glm::value_ptr(worldToCamera));

		gl::DrawArrays(gl::GL_TRIANGLE_STRIP, 0, 4);

		gl::DisableVertexAttribArray(0);
		gl::DisableVertexAttribArray(1);

		gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);
		gl::BindVertexArray(0);
		gl::UseProgram(0);
	}

private:
	glmesh::StreamBuffer m_streamBuf;
	GLuint m_program;
	GLuint m_unifModelToCameraMatrix;
	GLuint m_unifCameraToClipMatrix;
};


Drawable *CreateDrawable()
{
	return new BasicDrawable();
}
