#ifndef GLSDK_GLGRAPH_SCENE_GRAPH_H
#define GLSDK_GLGRAPH_SCENE_GRAPH_H

/**
\file
\brief Includes the glscene::SceneGraph class for the system.
**/

#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>


namespace glscene
{
	class Resources;
	struct SceneGraphData;

	/**
	\brief The class which represents a scene graph and all of its data.
	
	**/
	class SceneGraph : public boost::noncopyable
	{
	public:
		SceneGraph();
		~SceneGraph();

		Resources GetResources();
		const Resources GetResources() const;

	private:
		boost::scoped_ptr<SceneGraphData> m_pData;
	};
}

#endif //GLSDK_GLGRAPH_SCENE_GRAPH_H
