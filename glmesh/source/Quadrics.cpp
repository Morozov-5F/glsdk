
#include <vector>
#include <algorithm>
#include <cmath>
#include <glload/gl_all.hpp>
#include <glload/gll.hpp>

#include "glmesh/Mesh.h"
#include "glmesh/Quadrics.h"
#include <glm/glm.hpp>

namespace glmesh
{
	namespace gen
	{
		namespace
		{
			const float g_pi = 3.1415726f;
			const float g_2pi = g_pi * 2.0f;
		}

		Mesh * UnitSphere( int numHorizSlices, int numVertSlices, int attribFlags )
		{
			numHorizSlices = std::max(numHorizSlices, 1);
			numVertSlices = std::max(numVertSlices, 3);

			std::vector<glm::vec3> positions;
			std::vector<glm::vec3> normals;

			positions.reserve(2 + numHorizSlices * numVertSlices);
			normals.reserve(2 + numHorizSlices * numVertSlices);

			positions.push_back(glm::vec3(0.0f, 1.0f, 0.0f));
			normals.push_back(glm::vec3(0.0f, 1.0f, 0.0f));

			float radThetaDelta = g_pi / (numHorizSlices + 1);
			float radRhoDelta = g_2pi / numVertSlices;

			for(int ring = 0; ring < numHorizSlices; ++ring)
			{
				float radTheta = radThetaDelta * (ring + 1);
				float sinTheta = std::sin(radTheta);
				float cosTheta = std::cos(radTheta);

				for(int segment = 0; segment < numVertSlices; ++segment)
				{
					float radRho = radRhoDelta * segment;
					float sinRho = std::sin(-radRho);
					float cosRho = std::cos(-radRho);

					glm::vec3 currPos(sinTheta * cosRho, cosTheta, sinTheta * sinRho);
					positions.push_back(currPos);
					normals.push_back(currPos);
				}
			}

			positions.push_back(glm::vec3(0.0f, -1.0f, 0.0f));
			normals.push_back(glm::vec3(0.0f, -1.0f, 0.0f));

			std::vector<GLuint> indices;

			//The two fans at the top and bottom.
			size_t fanSize = 1 + numVertSlices + 1;
			size_t numIndices = fanSize * 2;
			numIndices += 1; //One for the primitive restart.

			size_t stripStart = numIndices;
			size_t stripSize = ((2 * numVertSlices) + 2);
			//One strip for each horizontal slice, minus 1.
			size_t numStrips = (numHorizSlices - 1);
			numIndices += stripSize * numStrips;

			indices.reserve(numIndices);

			//Top fan.
			indices.push_back(0);
			for(int segment = 1; segment <= numVertSlices; ++segment)
				indices.push_back(segment);
			indices.push_back(1);

			//Restart index.
			GLuint restartIndex = positions.size();
			indices.push_back(positions.size());

			//Bottom fan.
			size_t bottomIndex = positions.size() - 1;
			indices.push_back(bottomIndex);
			for(int segment = 1; segment <= numVertSlices; ++segment)
				indices.push_back(bottomIndex - segment);
			indices.push_back(bottomIndex - 1);

			//Strips.
			for(int ring = 0; ring < numHorizSlices - 1; ++ring)
			{
				GLuint topRingStart = 1 + (ring * numVertSlices);
				GLuint botRingStart = 1 + ((ring + 1) * numVertSlices);

				for(int segment = 0; segment < numVertSlices; ++segment)
				{
					indices.push_back(topRingStart + segment);
					indices.push_back(botRingStart + segment);
				}

				indices.push_back(topRingStart);
				indices.push_back(botRingStart);
			}

			//Build the buffers.
			size_t vertexBufferSize = 0;

			//Positions
			vertexBufferSize += positions.size() * (sizeof(GLshort) * 4);
			//Normals
			vertexBufferSize += normals.size() * (sizeof(GLshort) * 4);

			std::vector<GLubyte> data(vertexBufferSize);

			GLshort *pCurrPos = (GLshort*)&data[0];
			for(size_t vert = 0; vert < positions.size(); ++vert)
			{
				pCurrPos[0] = GLshort(positions[vert].x * 32767);
				pCurrPos[1] = GLshort(positions[vert].y * 32767);
				pCurrPos[2] = GLshort(positions[vert].z * 32767);

				pCurrPos[4] = GLshort(normals[vert].x * 32767);
				pCurrPos[5] = GLshort(normals[vert].y * 32767);
				pCurrPos[6] = GLshort(normals[vert].z * 32767);

				pCurrPos += 8;
			}

			pCurrPos = (GLshort*)&data[0];

			std::vector<GLuint> buffers(2);

			gl::GenBuffers(2, &buffers[0]);
			gl::BindBuffer(gl::GL_ARRAY_BUFFER, buffers[0]);
			gl::BufferData(gl::GL_ARRAY_BUFFER, data.size(), &data[0], gl::GL_STATIC_DRAW);

			//vertex data done. Now build the index buffer.
			gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			gl::BufferData(gl::GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
				&indices[0], gl::GL_STATIC_DRAW);
			gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, 0);

			//Create VAOs.
			MeshVariantMap variantMap;

			GLuint currVao = 0;
			gl::GenVertexArrays(1, &currVao);
			gl::BindVertexArray(currVao);
			gl::BindBuffer(gl::GL_ARRAY_BUFFER, buffers[0]);
			gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			gl::EnableVertexAttribArray(0);
			gl::VertexAttribPointer(0, 3, gl::GL_SHORT, gl::GL_TRUE, 8 * sizeof(GLshort), (void*)0);
			gl::EnableVertexAttribArray(2);
			gl::VertexAttribPointer(2, 3, gl::GL_SHORT, gl::GL_TRUE, 8 * sizeof(GLshort),
				(void*)(4 * sizeof(GLshort)));
			variantMap["lit"] = currVao;

			GLuint mainVao = currVao;

			gl::GenVertexArrays(1, &currVao);
			gl::BindVertexArray(currVao);
			gl::BindBuffer(gl::GL_ARRAY_BUFFER, buffers[0]);
			gl::BindBuffer(gl::GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
			gl::EnableVertexAttribArray(0);
			gl::VertexAttribPointer(0, 3, gl::GL_SHORT, gl::GL_TRUE, 8 * sizeof(GLshort), (void*)0);
			variantMap["unlit"] = currVao;

			gl::BindVertexArray(0);
			gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);

			//Create rendering commands.
			RenderCmdList renderCmds;
			if(glload::IsVersionGEQ(3, 1))
			{
				//Has primitive restart. Therefore, can draw two fans as one.
				renderCmds.PrimitiveRestartIndex(restartIndex);
				renderCmds.DrawElements(gl::GL_TRIANGLE_FAN, stripStart, gl::GL_UNSIGNED_INT, 0);
				renderCmds.PrimitiveRestartIndex();
			}
			else
			{
				//No restart.
				renderCmds.DrawElements(gl::GL_TRIANGLE_FAN, fanSize, gl::GL_UNSIGNED_INT, 0);
				renderCmds.DrawElements(gl::GL_TRIANGLE_FAN, fanSize, gl::GL_UNSIGNED_INT,
					(fanSize + 1) * sizeof(GLuint));
			}

			if(numStrips)
			{
				renderCmds.DrawElements(gl::GL_TRIANGLE_STRIP, stripSize * numStrips,
					gl::GL_UNSIGNED_INT, stripStart * sizeof(GLuint));
			}

			Mesh *pRet = new Mesh(buffers, mainVao, renderCmds, variantMap);
			return pRet;
		}
	}
}

