

#include <vector>
#include <string>
#include <boost/container/flat_map.hpp>
#include <glload/gl_all.h>
#include "glscene/SceneGraph.h"
#include "glscene/Resources.h"
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

	std::string UndefinedLayerException::GetErrorName( const std::string &layerName )
	{
		return "The layer '" + layerName + "' was not defined.";
	}

	typedef boost::container::flat_map<std::string, size_t> LayerMap;

	struct SceneGraphData
	{
		ResourceData resources;
		LayerMap layerMap;
		NodeData rootNode;

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

	Node SceneGraph::GetRootNode()
	{
		return Node(m_pData->rootNode);
	}

	glscene::Node SceneGraph::CreateChildNode( Node parent, boost::optional<boost::string_ref> name )
	{
		boost::optional<IdString> nameId;
		if(name)
			nameId = IdString(name.get());

		return parent.m_data.get().CreateChildNode(nameId);
	}

	Resources SceneGraph::GetResources()
	{
		return Resources(m_pData->resources);
	}

	int SceneGraph::GetLayerIndex( const std::string &layer ) const
	{
		LayerMap::const_iterator found = m_pData->layerMap.find(layer);
		if(found == m_pData->layerMap.end())
			throw UndefinedLayerException(layer);

		return (int)found->second;
	}

	boost::optional<Node> SceneGraph::FindNode( const boost::string_ref &name )
	{
		NodeData *pData = m_pData->rootNode.FindByName(name);
		if(!pData)
			return boost::none;

		return Node(*pData);
	}

	void swap( SceneGraph &lhs, SceneGraph &rhs )
	{
		swap(lhs.m_pData, rhs.m_pData);
	}
}
