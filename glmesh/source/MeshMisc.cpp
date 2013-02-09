#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <glload/gl_all.hpp>
#include <glload/gl_load.hpp>

#include <boost/tuple/tuple.hpp>
#include "glmesh/BoostDraw.h"
#include "glmesh/CpuDataWriter.h"
#include "glmesh/VertexFormat.h"

#include "glmesh/Mesh.h"
#include "glmesh/Quadrics.h"
#include "GenHelper.h"
#include <glm/glm.hpp>


namespace glmesh
{
namespace gen
{
	Mesh *FullScreenQuad()
	{
		glmesh::AttributeList attribs;
		attribs.push_back(glmesh::AttribDesc(ATTR_POS, 2, glmesh::VDT_SIGN_SHORT, glmesh::ADT_NORM_FLOAT));
		VertexFormat fmt(attribs);

		CpuDataWriter writer(fmt, 4);

		writer.Attrib<GLshort>(-32768, 32767);
		writer.Attrib<GLshort>(-32768, -32768);
		writer.Attrib<GLshort>(32767, 32767);
		writer.Attrib<GLshort>(32767, -32768);

		std::vector<GLuint> buffer(1);
		buffer[0] = writer.TransferToBuffer(gl::ARRAY_BUFFER, gl::STATIC_DRAW);
		gl::BindBuffer(gl::ARRAY_BUFFER, buffer[0]);

		MeshVariantMap variantMap;

		GLuint mainVao = 0;
		gl::GenVertexArrays(1, &mainVao);
		gl::BindVertexArray(mainVao);
		fmt.BindAttribute(0, 0);
		AddVariantToMap(variantMap, mainVao, 0);

		gl::BindVertexArray(0);
		gl::BindBuffer(gl::ARRAY_BUFFER, 0);

		RenderCmdList renderCmds;
		renderCmds.DrawArrays(gl::TRIANGLE_STRIP, 0, 4);

		Mesh *pRet = new Mesh(buffer, mainVao, renderCmds, variantMap);
		return pRet;
	}

	Mesh * GroundPlane( int numXVerts, int numYVerts, bool bDoubleSided )
	{
		numXVerts = std::max(numXVerts, 2);
		numYVerts = std::max(numYVerts, 2);

		//////////////////////////////////////////////////////////////////////////
		//Generate vertex data
		glmesh::AttributeList attribs;
		attribs.push_back(glmesh::AttribDesc(ATTR_POS, 2, glmesh::VDT_SIGN_SHORT, glmesh::ADT_NORM_FLOAT));
		attribs.push_back(glmesh::AttribDesc(ATTR_NORMAL, 4, glmesh::VDT_SIGN_BYTE, glmesh::ADT_NORM_FLOAT));
		attribs.push_back(glmesh::AttribDesc(ATTR_TEXCOORD, 2, glmesh::VDT_UNSIGN_SHORT, glmesh::ADT_NORM_FLOAT));
		VertexFormat fmt(attribs);

		int numVerts = numXVerts * numYVerts;
		numVerts = bDoubleSided ? numVerts * 2 : numVerts;

		CpuDataWriter writer(fmt, numVerts);

		glm::detail::tvec4<GLbyte> normal(0, 0, 127, 0);

		for(int zVert = 0; zVert < numYVerts; ++zVert)
		{
			const float perZ = zVert == numYVerts ? 1.0f : zVert / (float)(numYVerts - 1);

			for(int xVert = 0; xVert < numXVerts; ++xVert)
			{
				const float perX = xVert == numXVerts ? 1.0f : xVert / (float)(numXVerts - 1);

				glm::detail::tvec2<GLushort> texCoord(65535 * perX, 65535 * (1.0f - perZ));

				glm::detail::tvec2<int> intPos(texCoord.x, texCoord.y);
				glm::detail::tvec2<GLshort> pos(intPos.x - 32768, intPos.y - 32768);

				writer.Attrib(pos);
				writer.Attrib(normal);
				writer.Attrib(texCoord);
			}
		}

		if(bDoubleSided)
		{
			normal = glm::detail::tvec4<GLbyte>(0, 0, -128, 0);

			for(int zVert = 0; zVert < numYVerts; ++zVert)
			{
				const float perZ = zVert == numYVerts ? 1.0f : zVert / (float)(numYVerts - 1);

				for(int xVert = 0; xVert < numXVerts; ++xVert)
				{
					const float perX = xVert == numXVerts ? 1.0f : xVert / (float)(numXVerts - 1);

					glm::detail::tvec2<GLushort> texCoord(65535 * perX, 65535 * (1.0f - perZ));

					glm::detail::tvec2<int> intPos(texCoord.x, texCoord.y);
					glm::detail::tvec2<GLshort> pos(intPos.x - 32768, intPos.y - 32768);

					writer.Attrib(pos);
					writer.Attrib(normal);
					writer.Attrib(texCoord);
				}
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//Generate index data.

		const int numRows = numYVerts - 1;
		const int numIndices = numRows * numXVerts * 2 + 1; //2 indices per row, +1 for the restart index.
		std::vector<GLuint> indices;
		indices.reserve(numIndices * 2); //Enough space for double-sided.
		const GLuint restartIx = numIndices * 2;

		//Top side.
		for(int rowIx = 0; rowIx < numRows; ++rowIx)
		{
			for(int column = 0; column < numXVerts; ++column)
			{
				indices.push_back((rowIx * numXVerts) + column);
				indices.push_back(((rowIx + 1) * numXVerts) + column);
			}

			indices.push_back(restartIx);
		}

		if(bDoubleSided)
		{
			for(int rowIx = 0; rowIx < numRows; ++rowIx)
			{
				for(int column = 0; column < numXVerts; ++column)
				{
					//Reversed from front side.
					indices.push_back(((rowIx + 1) * numXVerts) + (column * 2));
					indices.push_back((rowIx * numXVerts) + (column * 2));
				}

				indices.push_back(restartIx);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//Build the buffers.
		std::vector<GLuint> buffers(2);
		gl::GenBuffers(2, &buffers[0]);
		writer.TransferToBuffer(gl::ARRAY_BUFFER, gl::STATIC_DRAW, buffers[0]);
		gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, buffers[1]);
		gl::BufferData(gl::ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
			&indices[0], gl::STATIC_DRAW);
		gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, 0);

		//Create VAOs.
		MeshVariantMap variantMap;

		gl::BindBuffer(gl::ARRAY_BUFFER, buffers[0]);

		std::vector<int> components;
		components.push_back(VAR_NORMAL);
		components.push_back(VAR_TEX_COORD);

		BuildVariations(variantMap, components, fmt, buffers[1]);

		gl::BindBuffer(gl::ARRAY_BUFFER, 0);

		//////////////////////////////////////////////////////////////////////////
		//Create rendering commands.
		RenderCmdList renderCmds;

		renderCmds.PrimitiveRestartIndex(restartIx);
		renderCmds.DrawElements(gl::TRIANGLE_STRIP, numIndices, gl::UNSIGNED_INT, 0);
		if(bDoubleSided)
		{
			renderCmds.DrawElements(gl::TRIANGLE_STRIP, numIndices, gl::UNSIGNED_INT,
				numIndices * sizeof(GLuint), numXVerts * numYVerts);
		}
		renderCmds.PrimitiveRestartIndex();

		GLuint mainVao = variantMap["lit-tex"];

		Mesh *pRet = new Mesh(buffers, mainVao, renderCmds, variantMap);
		return pRet;
	}
}
}
