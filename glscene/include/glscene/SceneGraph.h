#ifndef GLSDK_GLGRAPH_SCENE_GRAPH_H
#define GLSDK_GLGRAPH_SCENE_GRAPH_H

/**
\file
\brief Includes the glscene::SceneGraph class for the system.
**/

#include <stdexcept>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>


namespace glscene
{
	class Resources;
	struct SceneGraphData;

	///\addtogroup module_glscene_exceptions
	///@{

	///Base class for scene graph exceptions.
	class SceneGraphException : public std::runtime_error
	{
	public:
		explicit SceneGraphException(const std::string &desc) : std::runtime_error(desc) {}

	private:
	};

	class NodeRequestedUnknownResourceException : public SceneGraphException
	{
	public:
		explicit NodeRequestedUnknownResourceException(const std::string &resource, const std::string &resourceType)
			: SceneGraphException(GetErrorName(resource, resourceType)) {}


	private:
		static std::string GetErrorName(const std::string &resource, const std::string &resourceType);
	};

	///@}

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
