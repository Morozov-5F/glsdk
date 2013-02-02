
#include <string>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <memory>

#include <glload/gl_3_3.hpp>
#include <glload/gl_load.hpp>
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
}

class BasicDrawable : public Drawable
{
public:
	BasicDrawable()
	{
		gl::ClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		gl::ClearDepth(1.0);

		gl::Enable(gl::DEPTH_TEST);
		gl::DepthFunc(gl::LEQUAL);
		gl::Enable(gl::DEPTH_CLAMP);

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

		GLfloat groundPlaneData[] =
		{
			30.0f, 0.0f, 30.0f, 1.0f,
			30.0f, 0.0f, -30.0f, 1.0f,
			-30.0f, 0.0f, 30.0f, 1.0f,
			-30.0f, 0.0f, -30.0f, 1.0f,

			0.2f, 1.0f, 0.2f, 1.0f,
			0.9f, 0.5f, 0.3f, 1.0f,
			0.2f, 1.0f, 0.2f, 1.0f,
			0.9f, 0.5f, 0.3f, 1.0f,
		};

		GLuint vertShader = glutil::CompileShader(gl::VERTEX_SHADER, vertexShader);
		GLuint fragShader = glutil::CompileShader(gl::FRAGMENT_SHADER, fragmentShader);

		m_program = glutil::LinkProgram(vertShader, fragShader);

		gl::DeleteShader(vertShader);
		gl::DeleteShader(fragShader);

		m_unifModelToCameraMatrix = gl::GetUniformLocation(m_program, "modelToCameraMatrix");
		m_unifCameraToClipMatrix = gl::GetUniformLocation(m_program, "cameraToClipMatrix");

		std::vector<GLuint> buffers(1);
		gl::GenBuffers(1, &buffers[0]);

		gl::BindBuffer(gl::ARRAY_BUFFER, buffers[0]);
		gl::BufferData(gl::ARRAY_BUFFER, sizeof(groundPlaneData), groundPlaneData, gl::STATIC_DRAW);

		GLuint mainVao = 0;
		gl::GenVertexArrays(1, &mainVao);

		gl::BindVertexArray(mainVao);
		gl::EnableVertexAttribArray(0);
		gl::VertexAttribPointer(0, 4, gl::FLOAT, gl::FALSE_, 0, 0);
		gl::EnableVertexAttribArray(1);
		gl::VertexAttribPointer(1, 4, gl::FLOAT, gl::FALSE_, 0,
			reinterpret_cast<void*>(16 * sizeof(GLfloat)));

		gl::BindVertexArray(0);

		glmesh::RenderCmdList cmdList;
		cmdList.DrawArrays(gl::TRIANGLE_STRIP, 0, 4);

		glmesh::MeshVariantMap variants;
		glmesh::MeshVariantMap::value_type testVar("test", 0);
		gl::GenVertexArrays(1, &testVar.second);

		gl::BindVertexArray(testVar.second);
		gl::EnableVertexAttribArray(0);
		gl::VertexAttribPointer(0, 4, gl::FLOAT, gl::FALSE_, 0, 0);

		gl::BindVertexArray(0);
		
		gl::BindBuffer(gl::ARRAY_BUFFER, 0);

		variants.insert(testVar);
		variants["main"] = mainVao;

		m_pGroundPlane.reset(new glmesh::Mesh(buffers, mainVao, cmdList, variants));
	}

	~BasicDrawable()
	{
		gl::DeleteProgram(m_program);
	}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld)
	{
		gl::ClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		gl::ClearDepth(1.0f);
		gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

		//Set uniforms.
		gl::UseProgram(m_program);
		gl::UniformMatrix4fv(m_unifCameraToClipMatrix, 1, gl::FALSE_,
			glm::value_ptr(cameraToClip));

		{
			gl::UniformMatrix4fv(m_unifModelToCameraMatrix, 1, gl::FALSE_,
				glm::value_ptr(worldToCamera));

			m_pGroundPlane->Render("main");
		}

		gl::UseProgram(0);
	}

private:
	GLuint m_program;
	GLuint m_unifModelToCameraMatrix;
	GLuint m_unifCameraToClipMatrix;

	std::auto_ptr<glmesh::Mesh> m_pGroundPlane;
};


Drawable *CreateDrawable()
{
	return new BasicDrawable();
}
