#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <glload/gl_all.hpp>
#include <glload/gl_load.hpp>

#include <boost/tuple/tuple.hpp>
#include <boost/range/size.hpp>
#include "glmesh/BoostDraw.h"
#include "glmesh/CpuDataWriter.h"
#include "glmesh/VertexFormat.h"

#include "glmesh/Mesh.h"
#include "glmesh/GenPlatonic.h"
#include "GenHelper.h"
#include <glm/glm.hpp>

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

namespace glmesh
{
namespace gen
{
	namespace
	{
		Mesh *TriangularMesh(const GLshort *positions, const GLbyte *normals, size_t numValues,
			const ColorArray &colorSequence, int numTrisPerColor = 1)
		{
			//////////////////////////////////////////////////////////////////////////
			//Generate vertex data
			glmesh::AttributeList attribs;
			attribs.push_back(glmesh::AttribDesc(ATTR_POS, 3, glmesh::VDT_SIGN_SHORT, glmesh::ADT_NORM_FLOAT));
			attribs.push_back(glmesh::AttribDesc(ATTR_NORMAL, 3, glmesh::VDT_SIGN_BYTE, glmesh::ADT_NORM_FLOAT));
			if(!colorSequence.empty())
				attribs.push_back(glmesh::AttribDesc(ATTR_COLOR, 4, glmesh::VDT_UNSIGN_BYTE, glmesh::ADT_NORM_FLOAT));

			VertexFormat fmt(attribs);

			CpuDataWriter writer(fmt, numValues / 3);

			const int numFloatsPerColor = numTrisPerColor * 9;
			size_t currColor = 0;
			for(size_t loc = 0; loc < numValues; loc += 3)
			{
				writer.Attrib(positions[loc], positions[loc + 1], positions[loc + 2]);
				writer.Attrib(normals[loc], normals[loc + 1], normals[loc + 2]);
				if(!colorSequence.empty())
				{
					writer.Attrib(colorSequence[currColor]);
					if((loc + 3) % numFloatsPerColor == 0)
					{
						++currColor;
						currColor %= colorSequence.size();
					}
				}
			}

			GLuint buffer;
			gl::GenBuffers(1, &buffer);
			writer.TransferToBuffer(gl::ARRAY_BUFFER, gl::STATIC_DRAW, buffer);

			//Create VAOs.
			MeshVariantMap variantMap;

			gl::BindBuffer(gl::ARRAY_BUFFER, buffer);

			std::vector<int> components;
			components.push_back(VAR_NORMAL);
			if(!colorSequence.empty())
				components.push_back(VAR_COLOR);

			BuildVariations(variantMap, components, fmt);

			gl::BindBuffer(gl::ARRAY_BUFFER, 0);

			//////////////////////////////////////////////////////////////////////////
			//Create rendering commands.
			RenderCmdList renderCmds;

			renderCmds.DrawArrays(gl::TRIANGLES, 0, numValues / 3);

			GLuint mainVao = colorSequence.empty() ? variantMap["lit"] : variantMap["lit-color"];

			Mesh *pRet = new Mesh(std::vector<GLuint>(1, buffer), mainVao, renderCmds, variantMap);
			return pRet;

		}

		const GLshort tetra_positions[] = 
		{
			0, -11583, -32768,
			-28377, -11583, 16384,
			0, 32767, 0,
			28377, -11583, 16384,
			0, -11583, -32768,
			0, 32767, 0,
			-28377, -11583, 16384,
			28377, -11583, 16384,
			0, 32767, 0,
			-28377, -11583, 16384,
			0, -11583, -32768,
			28377, -11583, 16384,
		};

		const GLbyte tetra_normals[] = 
		{
			-104, 43, -60,
			-104, 43, -60,
			-104, 43, -60,
			104, 43, -60,
			104, 43, -60,
			104, 43, -60,
			0, 43, 120,
			0, 43, 120,
			0, 43, 120,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
		};

		const GLshort cube_positions[] = 
		{
			//+y
			-32768,  32767, -32768,
			-32768,  32767,  32767,
			32767,  32767, -32768,

			32767,  32767, -32768,
			-32768,  32767,  32767,
			32767,  32767,  32767,

			//+x
			32767,  32767, -32768,
			32767,  32767,  32767,
			32767, -32768, -32768,

			32767, -32768, -32768,
			32767,  32767,  32767,
			32767, -32768,  32767,

			//+z
			-32768,  32767,  32767,
			-32768, -32768,  32767,
			32767,  32767,  32767,

			32767,  32767,  32767,
			-32768, -32768,  32767,
			32767, -32768,  32767,

			//-y
			32767, -32768, -32768,
			32767, -32768,  32767,
			-32768, -32768, -32768,

			-32768, -32768, -32768,
			32767, -32768,  32767,
			-32768, -32768,  32767,

			//-x
			-32768, -32768, -32768,
			-32768, -32768,  32767,
			-32768,  32767, -32768,

			-32768,  32767, -32768,
			-32768, -32768,  32767,
			-32768,  32767,  32767,

			//-z
			32767,  32767, -32768,
			32767, -32768, -32768,
			-32768,  32767, -32768,

			-32768,  32767, -32768,
			32767, -32768, -32768,
			-32768, -32768, -32768,
		};

		const GLbyte cube_normals[] = 
		{
			//+y
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,

			//+x
			127, 0, 0,
			127, 0, 0,
			127, 0, 0,
			127, 0, 0,
			127, 0, 0,
			127, 0, 0,

			//+z
			0, 0, 127,
			0, 0, 127,
			0, 0, 127,
			0, 0, 127,
			0, 0, 127,
			0, 0, 127,

			//-y
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,

			//-x
			-128, 0, 0,
			-128, 0, 0,
			-128, 0, 0,
			-128, 0, 0,
			-128, 0, 0,
			-128, 0, 0,

			//-z
			0, 0, -128,
			0, 0, -128,
			0, 0, -128,
			0, 0, -128,
			0, 0, -128,
			0, 0, -128,
		};

		BOOST_STATIC_ASSERT(ARRAY_COUNT(cube_positions) == ARRAY_COUNT(cube_normals));

		const GLshort octa_positions[] = 
		{
			0, 0, 32767,
			-32768, 0, 0,
			0, -32768, 0,
			0, -32768, 0,
			-32768, 0, 0,
			0, 0, -32768,
			0, -32768, 0,
			0, 0, -32768,
			32767, 0, 0,
			0, -32768, 0,
			32767, 0, 0,
			0, 0, 32767,
			-32768, 0, 0,
			0, 0, 32767,
			0, 32767, 0,
			0, 0, -32768,
			-32768, 0, 0,
			0, 32767, 0,
			32767, 0, 0,
			0, 0, -32768,
			0, 32767, 0,
			0, 0, 32767,
			32767, 0, 0,
			0, 32767, 0,
		};

		const GLbyte octa_normals[] = 
		{
			-74, -74, 74,
			-74, -74, 74,
			-74, -74, 74,
			-74, -74, -74,
			-74, -74, -74,
			-74, -74, -74,
			74, -74, -74,
			74, -74, -74,
			74, -74, -74,
			74, -74, 74,
			74, -74, 74,
			74, -74, 74,
			-74, 74, 74,
			-74, 74, 74,
			-74, 74, 74,
			-74, 74, -74,
			-74, 74, -74,
			-74, 74, -74,
			74, 74, -74,
			74, 74, -74,
			74, 74, -74,
			74, 74, 74,
			74, 74, 74,
			74, 74, 74,
		};

		const GLshort dodec_positions[] = 
		{
			-6152, 26050, 18927,
			16100, 26050, 11699,
			16099, 26052, -11696,
			-19901, 26050, 2,
			16099, 26052, -11696,
			-6152, 26050, -18927,
			-19901, 26050, 2,
			-6152, 26050, 18927,
			16099, 26052, -11696,
			16100, 26050, 11699,
			26051, 6147, 18927,
			16099, 26052, -11696,
			26051, 6147, 18927,
			32200, -6151, 2,
			26051, 6148, -18927,
			26051, 6147, 18927,
			26051, 6148, -18927,
			16099, 26052, -11696,
			16100, 26050, 11699,
			9948, -6151, 30624,
			26051, 6147, 18927,
			16100, 26050, 11699,
			-9950, 6148, 30624,
			9948, -6151, 30624,
			16100, 26050, 11699,
			-6152, 26050, 18927,
			-9950, 6148, 30624,
			-19901, 26050, 2,
			-32200, 6148, 0,
			-26049, -6151, 18928,
			-6152, 26050, 18927,
			-26049, -6151, 18928,
			-9950, 6148, 30624,
			-6152, 26050, 18927,
			-19901, 26050, 2,
			-26049, -6151, 18928,
			-6152, 26050, -18927,
			-9950, 6148, -30624,
			-26051, -6151, -18925,
			-6152, 26050, -18927,
			-26051, -6151, -18925,
			-32200, 6148, 0,
			-6152, 26050, -18927,
			-32200, 6148, 0,
			-19901, 26050, 2,
			-9950, 6148, -30624,
			16099, 26052, -11696,
			26051, 6148, -18927,
			16099, 26052, -11696,
			-9950, 6148, -30624,
			-6152, 26050, -18927,
			-9950, 6148, -30624,
			26051, 6148, -18927,
			9948, -6151, -30624,
			-16099, -26050, 11699,
			-16102, -26050, -11696,
			6149, -26052, -18925,
			-16099, -26050, 11699,
			6149, -26052, -18925,
			19899, -26052, 0,
			-16099, -26050, 11699,
			19899, -26052, 0,
			6148, -26050, 18928,
			-26051, -6151, -18925,
			-16102, -26050, -11696,
			-32200, 6148, 0,
			-16102, -26050, -11696,
			-16099, -26050, 11699,
			-26049, -6151, 18928,
			-16102, -26050, -11696,
			-26049, -6151, 18928,
			-32200, 6148, 0,
			9948, -6151, -30624,
			6149, -26052, -18925,
			-16102, -26050, -11696,
			-9950, 6148, -30624,
			-16102, -26050, -11696,
			-26051, -6151, -18925,
			-9950, 6148, -30624,
			9948, -6151, -30624,
			-16102, -26050, -11696,
			26051, 6148, -18927,
			6149, -26052, -18925,
			9948, -6151, -30624,
			26051, 6148, -18927,
			19899, -26052, 0,
			6149, -26052, -18925,
			26051, 6148, -18927,
			32200, -6151, 2,
			19899, -26052, 0,
			32200, -6151, 2,
			6148, -26050, 18928,
			19899, -26052, 0,
			26051, 6147, 18927,
			9948, -6151, 30624,
			6148, -26050, 18928,
			26051, 6147, 18927,
			6148, -26050, 18928,
			32200, -6151, 2,
			-26049, -6151, 18928,
			9948, -6151, 30624,
			-9950, 6148, 30624,
			-16099, -26050, 11699,
			9948, -6151, 30624,
			-26049, -6151, 18928,
			-16099, -26050, 11699,
			6148, -26050, 18928,
			9948, -6151, 30624,
		};

		const GLbyte dodec_normals[] = 
		{
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			0, 127, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			114, 57, 0,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			35, 57, 108,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, 67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			-92, 57, -67,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			35, 57, -108,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			0, -128, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-114, -57, 0,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			-35, -57, -108,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, -67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			92, -57, 67,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
			-35, -57, 108,
		};
		const GLshort icosa_positions[] = 
		{
			-9817, -15885, 30215,
			0, -32768, 0,
			25702, -15885, 18673,
			25702, -15885, -18673,
			25702, -15885, 18673,
			0, -32768, 0,
			-31770, -15885, 0,
			0, -32768, 0,
			-9817, -15885, 30215,
			-9817, -15885, -30215,
			0, -32768, 0,
			-31770, -15885, 0,
			25702, -15885, -18673,
			0, -32768, 0,
			-9817, -15885, -30215,
			31770, 15885, 0,
			25702, -15885, 18673,
			25702, -15885, -18673,
			9817, 15885, 30215,
			-9817, -15885, 30215,
			25702, -15885, 18673,
			-25702, 15885, 18673,
			-31770, -15885, 0,
			-9817, -15885, 30215,
			-25702, 15885, -18673,
			-9817, -15885, -30215,
			-31770, -15885, 0,
			9817, 15885, -30215,
			25702, -15885, -18673,
			-9817, -15885, -30215,
			9817, 15885, 30215,
			25702, -15885, 18673,
			31770, 15885, 0,
			-25702, 15885, 18673,
			-9817, -15885, 30215,
			9817, 15885, 30215,
			-25702, 15885, -18673,
			-31770, -15885, 0,
			-25702, 15885, 18673,
			9817, 15885, -30215,
			-9817, -15885, -30215,
			-25702, 15885, -18673,
			31770, 15885, 0,
			25702, -15885, -18673,
			9817, 15885, -30215,
			0, 32767, 0,
			9817, 15885, 30215,
			31770, 15885, 0,
			0, 32767, 0,
			-25702, 15885, 18673,
			9817, 15885, 30215,
			0, 32767, 0,
			-25702, 15885, -18673,
			-25702, 15885, 18673,
			0, 32767, 0,
			9817, 15885, -30215,
			-25702, 15885, -18673,
			0, 32767, 0,
			31770, 15885, 0,
			9817, 15885, -30215,
		};

		const GLbyte icosa_normals[] = 
		{
			24, -101, 74,
			24, -101, 74,
			24, -101, 74,
			77, -101, 0,
			77, -101, 0,
			77, -101, 0,
			-63, -101, 45,
			-63, -101, 45,
			-63, -101, 45,
			-63, -101, -45,
			-63, -101, -45,
			-63, -101, -45,
			24, -101, -74,
			24, -101, -74,
			24, -101, -74,
			125, -24, 0,
			125, -24, 0,
			125, -24, 0,
			39, -24, 119,
			39, -24, 119,
			39, -24, 119,
			-101, -24, 74,
			-101, -24, 74,
			-101, -24, 74,
			-101, -24, -74,
			-101, -24, -74,
			-101, -24, -74,
			39, -24, -119,
			39, -24, -119,
			39, -24, -119,
			101, 24, 74,
			101, 24, 74,
			101, 24, 74,
			-39, 24, 119,
			-39, 24, 119,
			-39, 24, 119,
			-125, 24, 0,
			-125, 24, 0,
			-125, 24, 0,
			-39, 24, -119,
			-39, 24, -119,
			-39, 24, -119,
			101, 24, -74,
			101, 24, -74,
			101, 24, -74,
			63, 101, 45,
			63, 101, 45,
			63, 101, 45,
			-24, 101, 74,
			-24, 101, 74,
			-24, 101, 74,
			-77, 101, 0,
			-77, 101, 0,
			-77, 101, 0,
			-24, 101, -74,
			-24, 101, -74,
			-24, 101, -74,
			63, 101, -45,
			63, 101, -45,
			63, 101, -45,
		};

	}

	Mesh * Tetrahedron(const ColorArray &colorSequence)
	{
		return TriangularMesh(tetra_positions, tetra_normals, boost::size(tetra_positions),
			colorSequence);
	}

	Mesh * Cube( const ColorArray &colorSequence /*= ColorArray()*/ )
	{
		return TriangularMesh(cube_positions, cube_normals, boost::size(cube_positions),
			colorSequence, 2);
	}

	Mesh * Octahedron( const ColorArray &colorSequence /*= ColorArray()*/ )
	{
		return TriangularMesh(octa_positions, octa_normals, boost::size(octa_positions),
			colorSequence);
	}

	Mesh * Icosahedron( const ColorArray &colorSequence /*= ColorArray()*/ )
	{
		return TriangularMesh(icosa_positions, icosa_normals, boost::size(icosa_positions),
			colorSequence);
	}

	Mesh * Dodecahedron( const ColorArray &colorSequence /*= ColorArray()*/ )
	{
		return TriangularMesh(dodec_positions, dodec_normals, boost::size(dodec_positions),
			colorSequence, 3);
	}
}
}

