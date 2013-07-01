

#include "pch.h"

#include <vector>
#include <string>
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>
#include <glload/gl_all.h>
#include "glscene/SceneGraph.h"
#include "glscene/ResourceRef.h"
#include "glscene/Variant.h"
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

	void SceneGraph::DefineNodeVariant( NodeData &node, const boost::string_ref variantId,
		const VariantInfo &variant )
	{
		const ResourceData &resources = m_pData->resources;

		//First, verify the variant data against the resources.
		//1:  Verify that the mesh is a real mesh.
		if(!resources.HasMesh(variant.meshResourceId))
			throw ResourceNotFoundException(variant.meshResourceId, "mesh");

		//2:  Verify, for each program:
		//2a:   that the program is a real program.
		//2b:   that the uniforms are real uniforms.
		boost::apply_visitor(VerifyProgramData(resources), variant.progBinding);

		boost::container::flat_set<GLuint> uniqueBindings;

		//3:  Verify, for each texture binding:
		BOOST_FOREACH(const TextureBinding &texBind, variant.textureBindings)
		{
			//3a:   that the referenced texture is real.
			if(!resources.HasMesh(texBind.textureId))
				throw ResourceNotFoundException(texBind.textureId, "texture");
			//3b:   that the referenced sampler is real.
			if(!resources.HasMesh(texBind.samplerId))
				throw ResourceNotFoundException(texBind.samplerId, "sampler");
			//4:  Verify, for all texture bindings, that no two bindings bind to the same texture unit.
			if(uniqueBindings.find(texBind.textureUnit) != uniqueBindings.end())
				throw VariantMultipleBindingsException(texBind.textureId, "texture", (unsigned int)texBind.textureUnit);
			else
				uniqueBindings.insert(texBind.textureUnit);
		}
		uniqueBindings.clear();

		//5:  Verify, for each image binding, that the referenced texture is real.
		BOOST_FOREACH(const ImageBinding &imgBind, variant.imageBindings)
		{
			if(!resources.HasTexture(imgBind.textureId))
				throw ResourceNotFoundException(imgBind.textureId, "texture");
			//6:  Verify, for all image bindings, that no two bindings bind to the same image unit.
			if(uniqueBindings.find(imgBind.imageUnit) != uniqueBindings.end())
				throw VariantMultipleBindingsException(imgBind.textureId, "image", (unsigned int)imgBind.imageUnit);
			else
				uniqueBindings.insert(imgBind.imageUnit);
		}
		uniqueBindings.clear();

		//7:  Verify, for each uniform buffer binding, that the referenced uniform buffer binding is real.
		BOOST_FOREACH(const BufferInterfaceBinding &binding, variant.uniformBufferBindings)
		{
			if(!resources.HasUniformBufferBinding(binding.bufferId))
				throw ResourceNotFoundException(binding.bufferId, "uniform buffer");
			//8:  Verify, for all uniform buffer bindings, that no two binding resources bind to the same uniform buffer binding index.
			GLuint bindPoint = resources.GetUniformBufferBindingIndex(binding.bufferId);
			if(uniqueBindings.find(bindPoint) != uniqueBindings.end())
				throw VariantMultipleBindingsException(binding.bufferId, "uniform buffer", (unsigned int)bindPoint);
			else
				uniqueBindings.insert(bindPoint);
		}
		uniqueBindings.clear();

		//9:  Verify, for each storage buffer binding, that the referenced storage buffer binding is real.
		BOOST_FOREACH(const BufferInterfaceBinding &binding, variant.storageBufferBindings)
		{
			if(!resources.HasStorageBufferBinding(binding.bufferId))
				throw ResourceNotFoundException(binding.bufferId, "storage buffer");
			//10: Verify, for all storage buffer bindings, that no two binding resources bind to the same storage buffer binding index.
			GLuint bindPoint = resources.GetStorageBufferBindingIndex(binding.bufferId);
			if(uniqueBindings.find(bindPoint) != uniqueBindings.end())
				throw VariantMultipleBindingsException(binding.bufferId, "storage buffer", (unsigned int)bindPoint);
			else
				uniqueBindings.insert(bindPoint);
		}
		uniqueBindings.clear();

		//Now that it's verified, set the data into the node.
		node.DefineVariant(variantId, variant);
	}

	void swap( SceneGraph &lhs, SceneGraph &rhs )
	{
		swap(lhs.m_pData, rhs.m_pData);
	}
}
