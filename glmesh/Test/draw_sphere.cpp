
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
	struct ProgramData
	{
		GLuint program;
		GLuint unifModelToCameraMatrix;
		GLuint unifCameraToClipMatrix;

		ProgramData()
			: program(0)
		{}

		~ProgramData()
		{
			if(program)
				gl::DeleteProgram(program);
		}

		void Load(const std::string &vertexShader, const std::string &fragmentShader)
		{
			try
			{
				GLuint vertShader = glutil::CompileShader(gl::VERTEX_SHADER, vertexShader);
				GLuint fragShader = glutil::CompileShader(gl::FRAGMENT_SHADER, fragmentShader);

				program = glutil::LinkProgram(vertShader, fragShader);

				gl::DeleteShader(vertShader);
				gl::DeleteShader(fragShader);
			}
			catch(glutil::ShaderException &e)
			{
				printf("%s\n", e.what());

				throw;
			}

			unifModelToCameraMatrix = gl::GetUniformLocation(program, "modelToCameraMatrix");
			unifCameraToClipMatrix = gl::GetUniformLocation(program, "cameraToClipMatrix");
		}
	};
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

		gl::Enable(gl::CULL_FACE);

		const std::string groundVertexShader(
			"#version 330\n"
			"\n"
			"layout(location = 0) in vec4 position;\n"
			"\n"
			"\n"
			"uniform mat4 cameraToClipMatrix;\n"
			"uniform mat4 modelToCameraMatrix;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	vec4 cameraPos = modelToCameraMatrix * position;\n"
			"	gl_Position = cameraToClipMatrix * cameraPos;\n"
			"}\n"
			);

		const std::string groundFragmentShader(
			"#version 330\n"
			"\n"
			"layout(location = 0) out vec4 outputColor;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	outputColor = vec4(0, 0.7, 0.7, 1.0);\n"
			"}\n"
			);

		m_ground.Load(groundVertexShader, groundFragmentShader);

		const std::string objVertexShader(
			"#version 330\n"
			"\n"
			"layout(location = 0) in vec4 position;\n"
			"layout(location = 2) in vec3 normal;\n"
			"layout(location = 5) in vec2 texCoord;\n"
			"\n"
			"smooth out vec3 modelNormal;\n"
			"smooth out vec2 textureCoordinates;\n"
			"\n"
			"uniform mat4 cameraToClipMatrix;\n"
			"uniform mat4 modelToCameraMatrix;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	vec4 cameraPos = modelToCameraMatrix * position;\n"
			"	gl_Position = cameraToClipMatrix * cameraPos;\n"
			"	modelNormal = normal;\n"
			"   textureCoordinates = texCoord;\n"
			"}\n"
			);

		const std::string objFragmentShader(
			"#version 330\n"
			"\n"
			"smooth in vec3 modelNormal;\n"
			"smooth in vec2 textureCoordinates;\n"
			"out vec4 outputColor;\n"
			"\n"
			"void main()\n"
			"{\n"
			"	outputColor = vec4(modelNormal, 1.0);\n"
			"}\n"
			);

		m_object.Load(objVertexShader, objFragmentShader);

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

		m_pGroundPlane.reset(glmesh::gen::GroundPlane(7, 3));
		m_pSphere.reset(glmesh::gen::UnitSphere(6, 8));
	}

	~BasicDrawable()
	{}

	virtual void Draw(const glm::mat4 &cameraToClip, const glm::mat4 &worldToCamera,
		const glm::mat4 &modelToWorld)
	{
		gl::ClearColor(0.9f, 0.9f, 0.9f, 1.0f);
		gl::ClearDepth(1.0f);
		gl::Clear(gl::COLOR_BUFFER_BIT | gl::DEPTH_BUFFER_BIT);

		//Set uniforms.
		gl::UseProgram(m_ground.program);
		gl::UniformMatrix4fv(m_ground.unifCameraToClipMatrix, 1, gl::FALSE_,
			glm::value_ptr(cameraToClip));

		{
			glm::mat4 groundMat = glm::rotate(worldToCamera, -90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
			groundMat = glm::scale(groundMat, glm::vec3(20, 20, 20));
			gl::UniformMatrix4fv(m_ground.unifModelToCameraMatrix, 1, gl::FALSE_,
				glm::value_ptr(groundMat));

			m_pGroundPlane->Render();
		}

		gl::UseProgram(m_object.program);
		gl::UniformMatrix4fv(m_object.unifCameraToClipMatrix, 1, gl::FALSE_,
			glm::value_ptr(cameraToClip));

		{
			gl::UniformMatrix4fv(m_object.unifModelToCameraMatrix, 1, gl::FALSE_,
				glm::value_ptr(worldToCamera * modelToWorld));

			m_pSphere->Render();
		}

		gl::UseProgram(0);
	}

private:
	ProgramData m_ground;
	ProgramData m_object;

	std::auto_ptr<glmesh::Mesh> m_pGroundPlane;
	std::auto_ptr<glmesh::Mesh> m_pSphere;
};


Drawable *CreateDrawable()
{
	return new BasicDrawable();
}
