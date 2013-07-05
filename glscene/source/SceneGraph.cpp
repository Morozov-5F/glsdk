

#include "pch.h"

#include <vector>
#include <string>
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/range/adaptors.hpp>
#include <glload/gl_all.hpp>
#include "glscene/SceneGraph.h"
#include "glscene/ResourceRef.h"
#include "glscene/Style.h"
#include "ResourceData.h"
#include "TransformData.h"
#include "NodeData.h"
#include "IdString.h"

namespace glscene
{
	std::string UsingIncompleteResourceException::GetErrorName(
		const std::string &resource, const std::string &resourceType )
	{
		return std::string("The resource '") + resource + "' of type '" + resourceType +
			"' was defined but not provided.";
	}

	std::string NodeNameAlreadyExistsException::GetErrorName( const std::string &nodeName )
	{
		return "A node named '" + nodeName + "' already exists.";
	}

	std::string UndefinedLayerException::GetErrorName( const std::string &layerName )
	{
		return "The layer '" + layerName + "' was not defined.";
	}

	typedef boost::container::flat_map<std::string, size_t> LayerMap;
	typedef boost::container::flat_set<IdString> NodeNames;

	struct SceneGraphData
	{
		ResourceData resources;
		LayerMap layerMap;
		NodeData rootNode;
		NodeNames nodeNames;

		template<typename T>
		void AssignLayerMap(refs::array_ref<T> layerNames)
		{
			for(size_t index = 0; index < layerNames.size(); ++index)
			{
				layerMap.emplace(layerNames[index], index);
			}
		}

		SceneGraphData(size_t numLayers)
			: rootNode((int) numLayers)
		{}

		void RemoveNodeFromNameListRec(NodeData &node)
		{
			const boost::optional<IdString> &idName = node.GetNameId();
			if(idName)
				nodeNames.erase(idName.get());

			BOOST_FOREACH(NodeData *pChild, (node.m_children))
			{
				RemoveNodeFromNameListRec(*pChild);
			}
		}
	};


	SceneGraph::SceneGraph( refs::array_ref<const char*> layerNames )
		: m_pData(new SceneGraphData(layerNames.size()))
	{
		if(layerNames.empty())
			throw EmptyLayerListException();

		m_pData->AssignLayerMap(layerNames);
	}

	SceneGraph::SceneGraph( refs::array_ref<std::string> layerNames )
		: m_pData(new SceneGraphData(layerNames.size()))
	{
		if(layerNames.empty())
			throw EmptyLayerListException();

		m_pData->AssignLayerMap(layerNames);
	}

	SceneGraph::~SceneGraph()
	{}

	NodeData &SceneGraph::GetRootNode()
	{
		return m_pData->rootNode;
	}

	NodeData &SceneGraph::CreateChildNode( NodeData &parent, boost::optional<boost::string_ref> name )
	{
		boost::optional<IdString> nameId;
		if(name)
		{
			IdString theId = IdString(name.get());
			if(m_pData->nodeNames.find(theId) != m_pData->nodeNames.end())
				throw NodeNameAlreadyExistsException(theId.c_str());
			m_pData->nodeNames.emplace(theId);
			nameId = theId;
		}

		return parent.CreateChildNode(nameId);
	}

	ResourceRef SceneGraph::GetResources()
	{
		return ResourceRef(m_pData->resources);
	}

	int SceneGraph::GetLayerIndex( const std::string &layer ) const
	{
		LayerMap::const_iterator found = m_pData->layerMap.find(layer);
		if(found == m_pData->layerMap.end())
			throw UndefinedLayerException(layer);

		return (int)found->second;
	}

	NodeData *SceneGraph::FindNode( const boost::string_ref &name )
	{
		return m_pData->rootNode.FindByName(name);
	}

	void SceneGraph::DeleteNodeRecursive( NodeData &nodeToDelete )
	{
		//Verify that it's not the root.
		if(!nodeToDelete.GetParent())
			throw CannotDeleteRootNodeException();

		//First, remove all of the nodes to delete from the node name list.
		m_pData->RemoveNodeFromNameListRec(nodeToDelete);

		//Now, delete the node. The node's destructor will handle the recursion.
		delete &nodeToDelete;
	}

	void SceneGraph::DeleteNodeOnly( NodeData &nodeToDelete )
	{
		//Verify that it's not the root.
		if(!nodeToDelete.GetParent())
			throw CannotDeleteRootNodeException();

		//Re-parent all child nodes to this node's parent.
		nodeToDelete.ReparentChildrenToParent();

		//Recursive is OK, since we don't have children anymore.
		m_pData->RemoveNodeFromNameListRec(nodeToDelete);

		//Now, delete the node. Recursion remains OK, since we still don't have children.
		delete &nodeToDelete;
	}

	namespace
	{
		struct VerifyProgramData : public boost::static_visitor<>
		{
			VerifyProgramData(const ResourceData &_resources) : resources(_resources) {}

			void operator()(const SingleProgramBinding &binding) const
			{
				if(!resources.HasProgram(binding.programId))
					throw ResourceNotFoundException(binding.programId, "program");

				BOOST_FOREACH(const std::string &uniformId, binding.uniformIds)
				{
					if(!resources.HasUniform(uniformId))
						throw ResourceNotFoundException(uniformId, "uniform");
				}
			}

			void operator()(const SeparableProgramBinding &binding) const
			{
				BOOST_FOREACH(const ProgramMask &prog, binding.pipeline)
				{
					(*this)(prog.prog);
				}
			}

			const ResourceData &resources;
		};
	}

	void SceneGraph::DefineNodeStyle( NodeData &node, const boost::string_ref styleId,
		const StyleInfo &style )
	{
		const ResourceData &resources = m_pData->resources;

		//First, verify the style data against the resources.
		//1:  Verify that the mesh is a real mesh.
		if(!resources.HasMesh(style.meshResourceId))
			throw ResourceNotFoundException(style.meshResourceId, "mesh");

		//2:  Verify, for each program:
		//2a:   that the program is a real program.
		//2b:   that the uniforms are real uniforms.
		boost::apply_visitor(VerifyProgramData(resources), style.progBinding);

		boost::container::flat_set<GLuint> uniqueBindings;

		//3:  Verify, for each texture binding:
		BOOST_FOREACH(const TextureBinding &texBind, style.textureBindings)
		{
			//3a:   that the referenced texture is real.
			if(!resources.HasTexture(texBind.textureId))
				throw ResourceNotFoundException(texBind.textureId, "texture");
			//3b:   that the referenced sampler is real.
			if(!resources.HasSampler(texBind.samplerId))
				throw ResourceNotFoundException(texBind.samplerId, "sampler");
			//4:  Verify, for all texture bindings, that no two bindings bind to the same texture unit.
			if(uniqueBindings.find(texBind.textureUnit) != uniqueBindings.end())
				throw StyleMultipleBindingsException(texBind.textureId, "texture", (unsigned int)texBind.textureUnit);
			else
				uniqueBindings.insert(texBind.textureUnit);
		}
		uniqueBindings.clear();

		//5:  Verify, for each image binding, that the referenced texture is real.
		BOOST_FOREACH(const ImageBinding &imgBind, style.imageBindings)
		{
			if(!resources.HasTexture(imgBind.textureId))
				throw ResourceNotFoundException(imgBind.textureId, "texture");
			//6:  Verify, for all image bindings, that no two bindings bind to the same image unit.
			if(uniqueBindings.find(imgBind.imageUnit) != uniqueBindings.end())
				throw StyleMultipleBindingsException(imgBind.textureId, "image", (unsigned int)imgBind.imageUnit);
			else
				uniqueBindings.insert(imgBind.imageUnit);
		}
		uniqueBindings.clear();

		//7:  Verify, for each uniform buffer binding, that the referenced uniform buffer binding is real.
		BOOST_FOREACH(const BufferInterfaceBinding &binding, style.uniformBufferBindings)
		{
			if(!resources.HasUniformBufferBinding(binding.bufferId))
				throw ResourceNotFoundException(binding.bufferId, "uniform buffer");
			//8:  Verify, for all uniform buffer bindings, that no two binding resources bind to the same uniform buffer binding index.
			GLuint bindPoint = resources.GetUniformBufferBindingIndex(binding.bufferId);
			if(uniqueBindings.find(bindPoint) != uniqueBindings.end())
				throw StyleMultipleBindingsException(binding.bufferId, "uniform buffer", (unsigned int)bindPoint);
			else
				uniqueBindings.insert(bindPoint);
		}
		uniqueBindings.clear();

		//9:  Verify, for each storage buffer binding, that the referenced storage buffer binding is real.
		BOOST_FOREACH(const BufferInterfaceBinding &binding, style.storageBufferBindings)
		{
			if(!resources.HasStorageBufferBinding(binding.bufferId))
				throw ResourceNotFoundException(binding.bufferId, "storage buffer");
			//10: Verify, for all storage buffer bindings, that no two binding resources bind to the same storage buffer binding index.
			GLuint bindPoint = resources.GetStorageBufferBindingIndex(binding.bufferId);
			if(uniqueBindings.find(bindPoint) != uniqueBindings.end())
				throw StyleMultipleBindingsException(binding.bufferId, "storage buffer", (unsigned int)bindPoint);
			else
				uniqueBindings.insert(bindPoint);
		}
		uniqueBindings.clear();

		//Now that it's verified, set the data into the node.
		node.DefineStyle(styleId, style);
	}

	namespace
	{
		class BindStyleToOpenGL
		{
		public:
			struct BindProgramVisitor : public boost::static_visitor<>
			{
				BindProgramVisitor(const ResourceData &_resources)
					: resources(_resources) {}
				const ResourceData &resources;

				void operator()(const SingleProgramBindingData &binding) const
				{
					GLuint prog = resources.GetProgram(binding.programId);
					gl::UseProgram(prog);
					BOOST_FOREACH(const UniformBindingData &unif, binding.uniformIds)
					{
						resources.ApplyUniform(unif.uniformId,
							resources.GetUniformLocation(prog, unif.uniformId));
					}
				}

				void operator()(const SeparableProgramBindingData &binding) const
				{
					gl::BindProgramPipeline(binding.pipelineObj);

					BOOST_FOREACH(const ProgramMaskData &program, binding.pipeline)
					{
						if(!program.prog.uniformIds.empty())
						{
							GLuint prog = resources.GetProgram(program.prog.programId);
							BOOST_FOREACH(const UniformBindingData &unif, program.prog.uniformIds)
							{
								resources.ApplyUniform(prog, unif.uniformId,
									resources.GetUniformLocation(prog, unif.uniformId));
							}
						}
					}
				}
			};

			struct SetUniformMatrices : public boost::static_visitor<>
			{
				SetUniformMatrices(const ResourceData &_resources,
					const glm::mat4 &_objectToCamera)

					: resources(_resources)
					, objectToCamera(_objectToCamera)
				{}

				const ResourceData &resources;
				const glm::mat4 &objectToCamera;

				glm::mat3 CalcNormModelToCamera() const
				{
					glm::mat3 ret(objectToCamera);
					return glm::inverse(glm::transpose(ret));
				}

				glm::mat3 CalcNormCameraToModel() const
				{
					return glm::inverse(CalcNormModelToCamera());
				}

				//Assumes it's the current program in use.
				void operator()(const SingleProgramBindingData &binding) const
				{
					ProgramMatrices matrices = resources.GetProgramMatrices(binding.programId);

					if(matrices.unifModelToCamera)
					{
						gl::UniformMatrix4fv(matrices.unifModelToCamera.get(), 1, gl::FALSE_,
							glm::value_ptr(objectToCamera));
					}

					if(matrices.unifNormalModelToCamera)
					{
						gl::UniformMatrix3fv(matrices.unifNormalModelToCamera.get(), 1, gl::FALSE_,
							glm::value_ptr(CalcNormModelToCamera()));
					}

					if(matrices.unifNormalCameraToModel)
					{
						gl::UniformMatrix3fv(matrices.unifNormalCameraToModel.get(), 1, gl::FALSE_,
							glm::value_ptr(CalcNormCameraToModel()));
					}
				}

				void operator()(const SeparableProgramBindingData &binding) const
				{
					gl::BindProgramPipeline(binding.pipelineObj);

					BOOST_FOREACH(const ProgramMaskData &program, binding.pipeline)
					{
						GLuint prog = resources.GetProgram(program.prog.programId);
						ProgramMatrices matrices = resources.GetProgramMatrices(program.prog.programId);

						if(matrices.unifModelToCamera)
						{
							gl::ProgramUniformMatrix4fv(prog, matrices.unifModelToCamera.get(), 1,
								gl::FALSE_, glm::value_ptr(objectToCamera));
						}

						if(matrices.unifNormalModelToCamera)
						{
							gl::ProgramUniformMatrix3fv(prog, matrices.unifNormalModelToCamera.get(), 1,
								gl::FALSE_, glm::value_ptr(CalcNormModelToCamera()));
						}

						if(matrices.unifNormalCameraToModel)
						{
							gl::ProgramUniformMatrix3fv(prog, matrices.unifNormalCameraToModel.get(), 1,
								gl::FALSE_, glm::value_ptr(CalcNormCameraToModel()));
						}
					}
				}
			};

			BindStyleToOpenGL(const StyleData &style, const ResourceData &resources)
				: m_style(style)
				, m_resources(resources)
			{
				boost::apply_visitor(BindProgramVisitor(m_resources), m_style.progBinding);

				BOOST_FOREACH(const TextureBindingMap::value_type &texBindingPair, m_style.textureBindings)
				{
					m_resources.BindTexture(texBindingPair.second.textureId, texBindingPair.first);
					m_resources.BindSampler(texBindingPair.second.samplerId, texBindingPair.first);
				}

				BOOST_FOREACH(const ImageBindingMap::value_type &imgBindingPair, m_style.imageBindings)
				{
					const ImageBindingData &imgBinding = imgBindingPair.second;
					m_resources.BindImage(
						imgBinding.textureId,
						imgBindingPair.first,
						imgBinding.mipmapLevel,
						imgBinding.arrayLayer ? imgBinding.arrayLayer.get() : 0,
						imgBinding.access,
						imgBinding.format,
						imgBinding.arrayLayer);
				}

				BOOST_FOREACH(const BufferInterfaceBindingData &uniformBinding, m_style.uniformBufferBindings)
				{
					m_resources.BindUniformBuffer(uniformBinding.bufferId, uniformBinding.bindOffset);
				}

				BOOST_FOREACH(const BufferInterfaceBindingData &storageBinding, m_style.storageBufferBindings)
				{
					m_resources.BindStorageBuffer(storageBinding.bufferId, storageBinding.bindOffset);
				}
			}

			~BindStyleToOpenGL()
			{
				BOOST_FOREACH(const BufferInterfaceBindingData &storageBinding, m_style.storageBufferBindings)
				{
					m_resources.BindStorageBuffer(storageBinding.bufferId, storageBinding.bindOffset);
				}

				BOOST_FOREACH(const BufferInterfaceBindingData &uniformBinding, m_style.uniformBufferBindings)
				{
					m_resources.BindUniformBuffer(uniformBinding.bufferId, uniformBinding.bindOffset);
				}

				BOOST_FOREACH(const ImageBindingMap::value_type &imgBindingPair, m_style.imageBindings)
				{
					gl::BindImageTexture(imgBindingPair.first, 0, 0, gl::FALSE_, 0, gl::READ_ONLY, gl::RGBA8);
				}

				BOOST_FOREACH(const TextureBindingMap::value_type &texBindingPair, m_style.textureBindings)
				{
					m_resources.UnbindTexture(texBindingPair.second.textureId, texBindingPair.first);
					gl::BindSampler(texBindingPair.first, 0);
				}

				gl::BindProgramPipeline(0);
				gl::UseProgram(0);
			}

			void ApplyMatrices(const glm::mat4 &objectToCamera) const
			{
				boost::apply_visitor(SetUniformMatrices(m_resources, objectToCamera),
					m_style.progBinding);
			}

		private:
			const StyleData &m_style;
			const ResourceData &m_resources;
		};

		struct Renderable
		{
			const StyleData *pStyle;
			glm::mat4 nodeToCamera;
			glm::mat4 objectToCamera;
		};

		typedef std::vector<Renderable> RenderList;
		void BuildRenderListRec(RenderList &renderables, const NodeData &currNode,
			glm::mat4 nodeToCamera, int layerIx, const IdString &styleId)
		{
			nodeToCamera *= currNode.GetNodeTM().GetMatrix();

			if(currNode.IsInLayer(layerIx))
			{
				const StyleData *pStyle = currNode.FindStyle(styleId);
				if(pStyle)
				{
					renderables.push_back(Renderable());
					renderables.back().pStyle = pStyle;
					renderables.back().nodeToCamera = nodeToCamera;
					renderables.back().objectToCamera = nodeToCamera * currNode.GetObjectTM().GetMatrix();
				}
			}

			BOOST_FOREACH(const NodeData *pChild, currNode.GetChildRange())
			{
				BuildRenderListRec(renderables, *pChild, nodeToCamera, layerIx, styleId);
			}
		}

		void SortRenderList(RenderList &renderables, NodeRenderingOrder eOrder)
		{
			
		}
	}

	void SceneGraph::Render( const glm::mat4 &worldToCamera, NodeRenderingOrder eOrder,
		int layerIx, boost::string_ref styleId ) const
	{
		//1: Collate all applicable renderables and build transforms.
		RenderList renderList;
		BuildRenderListRec(renderList, m_pData->rootNode, worldToCamera, layerIx, styleId);

		//2: Sort the renderable list.
		SortRenderList(renderList, eOrder);

		//3: Render the renderables.
		BOOST_FOREACH(const Renderable &obj, renderList)
		{
			BindStyleToOpenGL binder(*obj.pStyle, m_pData->resources);
			binder.ApplyMatrices(obj.objectToCamera);

			m_pData->resources.RenderMesh(obj.pStyle->meshResourceId, obj.pStyle->meshVariantString);
		}
	}

	void swap( SceneGraph &lhs, SceneGraph &rhs )
	{
		swap(lhs.m_pData, rhs.m_pData);
	}
}
