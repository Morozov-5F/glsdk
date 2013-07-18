
#include "pch.h"

#include <boost/container/flat_map.hpp>
#include <boost/variant.hpp>
#include "glscene/SceneGraph.h"
#include <glload/gl_all.hpp>
#include <glmesh/Mesh.h>
#include <glmesh/GenMeshMisc.h>
#include <glmesh/GenPlatonic.h>
#include <glmesh/GenQuadrics.h>
#include <glmesh/GenDescriptors.h>
#include <glutil/Shader.h>
#include "NodeData.h"
#include "ResourceData.h"
#include "TransformData.h"
#include "ParsedData.h"
#include "glscene/Parse.h"
#include "ParserEnums.h"

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

namespace glscene { namespace _detail {

	std::string GetBasePath(const FilePosition &pos) {return std::string();}

	void ApplyUniforms(ResourceData &refs, const ParsedUniformMap &uniforms)
	{
		BOOST_FOREACH(const ParsedUniformMap::value_type &unifDef, uniforms)
		{
			refs.DefineUniform(unifDef.first, unifDef.second.glslUniformName, unifDef.second.data);
		}
	}

	void ApplySamplers(ResourceData &refs, const ParsedSamplerMap &samplers)
	{
		BOOST_FOREACH(const ParsedSamplerMap::value_type &splDef, samplers)
		{
			refs.DefineSampler(splDef.first, splDef.second.sampler);
		}
	}

	void ApplyCameras(ResourceData &refs, const ParsedCameraMap &cameras)
	{
		BOOST_FOREACH(const ParsedCameraMap::value_type &camDef, cameras)
		{
			refs.DefineCamera(camDef.first, camDef.second.view,
				camDef.second.scale, camDef.second.actionButton,
				camDef.second.bRightKeyboardCtrls);
		}
	}

	void ApplyUniformBuffers(ResourceData &refs, const ParsedBufferMap &uniformBuffers)
	{
		BOOST_FOREACH(const ParsedBufferMap::value_type &bufDef, uniformBuffers)
		{
			if(bufDef.second.creationUsage)
			{
				GLuint buf;
				gl::GenBuffers(1, &buf);
				gl::BindBuffer(gl::UNIFORM_BUFFER, buf);
				gl::BufferData(gl::UNIFORM_BUFFER, bufDef.second.size, NULL, bufDef.second.creationUsage.get());
				gl::BindBuffer(gl::UNIFORM_BUFFER, 0);

				refs.DefineUniformBufferBinding(bufDef.first, buf, 0, bufDef.second.size, true);
			}
			else
				refs.DefineUniformBufferBindingIncomplete(bufDef.first, bufDef.second.size);
		}
	}

	void ApplyStorageBuffers(ResourceData &refs, const ParsedBufferMap &uniformBuffers)
	{
		BOOST_FOREACH(const ParsedBufferMap::value_type &bufDef, uniformBuffers)
		{
			if(bufDef.second.creationUsage)
			{
				GLuint buf;
				gl::GenBuffers(1, &buf);
				gl::BindBuffer(gl::SHADER_STORAGE_BUFFER, buf);
				gl::BufferData(gl::SHADER_STORAGE_BUFFER, bufDef.second.size,
					NULL, bufDef.second.creationUsage.get());
				gl::BindBuffer(gl::SHADER_STORAGE_BUFFER, 0);

				refs.DefineStorageBufferBinding(bufDef.first, buf, 0, bufDef.second.size, true);
			}
			else
				refs.DefineStorageBufferBindingIncomplete(bufDef.first, bufDef.second.size);
		}
	}

	void ApplyPrograms(ResourceData &refs, const ParsedProgramMap &programs, const BaseLoader &loader)
	{
		BOOST_FOREACH(const ParsedProgramMap::value_type &progDef, programs)
		{
			std::string baseFile = GetBasePath(progDef.second.pos);
			boost::container::stable_vector<glutil::UniqueShader> shaders;
			BOOST_FOREACH(const ParsedShader &shaderDef, progDef.second.shaders)
			{
				shaders.emplace_back(glutil::CompileShader(shaderDef.shaderType,
					loader.LoadShader(baseFile, shaderDef.filename)));
			}

			std::vector<GLuint> shaderList;
			shaderList.reserve(shaders.size());
			BOOST_FOREACH(const glutil::UniqueShader &shader, shaders)
			{
				shaderList.push_back(shader);
			}

			GLuint prog = glutil::LinkProgram(shaderList, progDef.second.isSeparate);

			refs.DefineProgram(progDef.first, prog, progDef.second.info, true);
		}
	}

	namespace
	{
		glmesh::Mesh *GenerateGroundPlane(const std::vector<int> &params)
		{
			return glmesh::gen::GroundPlane(params[0], params[1]);
		}

		glmesh::Mesh *GenerateUnitAxes(const std::vector<int> &params)
		{
			return glmesh::gen::Axes();
		}

		glmesh::Mesh *GenerateCubeBlock(const std::vector<int> &params)
		{
			return glmesh::gen::CubeBlock(params[0]);
		}

		glmesh::Mesh *GenerateCubePyramid(const std::vector<int> &params)
		{
			return glmesh::gen::CubePyramid(params[0]);
		}

		glmesh::Mesh *GenerateTetrahedron(const std::vector<int> &params)
		{
			return glmesh::gen::Tetrahedron();
		}

		glmesh::Mesh *GenerateCube(const std::vector<int> &params)
		{
			return glmesh::gen::Cube();
		}

		glmesh::Mesh *GenerateOctahedron(const std::vector<int> &params)
		{
			return glmesh::gen::Octahedron();
		}

		glmesh::Mesh *GenerateDodecahedron(const std::vector<int> &params)
		{
			return glmesh::gen::Dodecahedron();
		}

		glmesh::Mesh *GenerateIcosahedron(const std::vector<int> &params)
		{
			return glmesh::gen::Icosahedron();
		}

		glmesh::Mesh *GenerateUnitSphere(const std::vector<int> &params)
		{
			return glmesh::gen::UnitSphere(params[0], params[1]);
		}

		typedef glmesh::Mesh *(*MeshGenerator)(const std::vector<int> &params);

		MeshGenerator g_meshGenerators[] =
		{
			GenerateGroundPlane,
			GenerateUnitAxes,
			GenerateCubeBlock,
			GenerateCubePyramid,
			GenerateTetrahedron,
			GenerateCube,
			GenerateOctahedron,
			GenerateDodecahedron,
			GenerateIcosahedron,
			GenerateUnitSphere,
		};

		BOOST_STATIC_ASSERT(ARRAY_COUNT(g_meshGenerators) == ARRAY_COUNT(g_meshCreateEnumNames));
	}

	struct BuildMesh : public boost::static_visitor<glmesh::Mesh *>
	{
		BuildMesh(const BaseLoader &_loader, const std::vector<int> &_params, const std::string &_basePath)
			: loader(_loader)
			, params(_params)
			, basePath(_basePath)
		{}

		glmesh::Mesh *operator()(boost::blank) const
		{
			return NULL;
		}

		glmesh::Mesh *operator()(int index) const
		{
			return g_meshGenerators[index](params);
		}

		glmesh::Mesh *operator()(const std::string &filename) const
		{
			return loader.LoadMesh(basePath, filename);
		}

		const BaseLoader &loader;
		const std::vector<int> &params;
		const std::string &basePath;
	};

	void ApplyMeshes(ResourceData &refs, const ParsedMeshMap &meshes, const BaseLoader &loader)
	{
		BOOST_FOREACH(const ParsedMeshMap::value_type &meshDef, meshes)
		{
			glmesh::Mesh *pMesh = boost::apply_visitor(
				BuildMesh(loader, meshDef.second.params, GetBasePath(meshDef.second.pos)),
				meshDef.second.generator);

			if(!pMesh)
				refs.DefineMeshIncomplete(meshDef.first);
			else
				refs.DefineMesh(meshDef.first, pMesh, true);
		}
	}

	void ApplyTextures(ResourceData &refs, const ParsedTextureMap &textures, const BaseLoader &loader)
	{
		BOOST_FOREACH(const ParsedTextureMap::value_type &texDef, textures)
		{
			if(texDef.second.filename)
			{
				LoadedTexture tex = loader.LoadTexture(GetBasePath(texDef.second.pos),
					texDef.second.filename.get());
				refs.DefineTexture(texDef.first, tex.texName, tex.texType, true);
			}
			else
				refs.DefineTextureIncomplete(texDef.first);
		}
	}

	NodeData &CreateBaseNode(NodeData &rootNode, SceneGraph &graph, const ParsedNodeDef &nodeDef)
	{
		if(nodeDef.name)
		{
			boost::string_ref name = nodeDef.name.get().str();
			return graph.CreateChildNode(rootNode, name);
		}
		return graph.CreateChildNode(rootNode);
	}

	typedef boost::container::flat_map<std::string, int> LayerToIndexMap;

	struct ApplyTransform : public boost::static_visitor<ComposableMatrix>
	{
		ComposableMatrix operator()(const glm::mat4 &matrix) const
		{
			return matrix;
		}

		ComposableMatrix operator()(const ParsedDecomposedTransform &matrix) const
		{
			return matrix.mat;
		}
	};

	void ApplyNode(NodeData &rootNode, SceneGraph &graph, const ParsedNodeDef &nodeDef,
		const LayerToIndexMap &layerToIndex)
	{
		NodeData &node = CreateBaseNode(rootNode, graph, nodeDef);

		//Set the layers.
		BOOST_FOREACH(const std::string &layerName, nodeDef.layers)
		{
			AddToLayer(node, layerToIndex.find(layerName)->second);
		}

		//Set the transforms.
		node.GetNodeTM().SetComposable(boost::apply_visitor(ApplyTransform(), nodeDef.nodeTM.trans));
		node.GetObjectTM().SetComposable(boost::apply_visitor(ApplyTransform(), nodeDef.objectTM.trans));

		//Set the styles.


		//Set the nodes.
		BOOST_FOREACH(const ParsedNodeDef *pChildNode, nodeDef.childNodes)
		{
			ApplyNode(node, graph, *pChildNode, layerToIndex);
		}
	}

	SceneGraph *CreateSceneGraph( const ParsedSceneGraphDef &graphData,
		const ParsedResources &resources, const BaseLoader & loader)
	{
		SceneGraph graph(graphData.layerOrder);

		ResourceData &refs = GetResources(graph.GetResources());
		ApplyUniforms(refs, resources.uniforms);
		ApplySamplers(refs, resources.samplers);
		ApplyCameras(refs, resources.cameras);
		ApplyUniformBuffers(refs, resources.uniformBuffers);
		ApplyStorageBuffers(refs, resources.storageBuffers);
		ApplyPrograms(refs, resources.programs, loader);
		ApplyMeshes(refs, resources.meshes, loader);
		ApplyTextures(refs, resources.textures, loader);

		LayerToIndexMap layerToIndex;
		layerToIndex.reserve(graphData.layerOrder.size());
		{
			int ix = 0;
			BOOST_FOREACH(const std::string &layerName, graphData.layerOrder)
			{
				layerToIndex[layerName] = ix;
				++ix;
			}
		}

		BOOST_FOREACH(const ParsedNodeDef &nodeDef, graphData.nodes)
		{
			//Only handle root nodes here. Children are handled recursively.
			if(!nodeDef.pParent)
			{
				ApplyNode(graph.GetRootNode(), graph, nodeDef, layerToIndex);
			}
		}
		

		const char *temp[1] = {"foo"};
		SceneGraph *pRet = new SceneGraph(temp);
		swap(*pRet, graph);
		return pRet;
	}
}}
