

#include <glload/gl_all.h>
#include "glscene/SceneGraph.h"
#include "glscene/Resources.h"
#include "ResourceData.h"


namespace glscene
{
	std::string NodeRequestedUnknownResourceException::GetErrorName(
		const std::string &resource, const std::string &resourceType )
	{
		return std::string("The resource '") + resource + "' of type '" + resourceType +
			"' was defined but not provided.";
	}

	struct SceneGraphData
	{
		ResourceData resources;
	};


	SceneGraph::SceneGraph()
		: m_pData(new SceneGraphData)
	{
	}

	SceneGraph::~SceneGraph()
	{}

	Resources SceneGraph::GetResources()
	{
		return Resources(&m_pData->resources);
	}

	const Resources SceneGraph::GetResources() const
	{
		return Resources(&m_pData->resources);
	}
}
