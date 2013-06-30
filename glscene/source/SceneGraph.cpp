

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

	void swap( SceneGraph &lhs, SceneGraph &rhs )
	{
		swap(lhs.m_pData, rhs.m_pData);
	}
}
