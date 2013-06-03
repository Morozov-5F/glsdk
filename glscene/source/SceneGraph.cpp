

#include <glload/gl_all.h>
#include "glscene/SceneGraph.h"
#include "glscene/Resources.h"
#include "ResourceData.h"


namespace glscene
{
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
