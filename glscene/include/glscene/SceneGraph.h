#ifndef GLSDK_GLSCENE_SCENE_GRAPH_H
#define GLSDK_GLSCENE_SCENE_GRAPH_H

/**
\file
\brief Includes the glscene::SceneGraph class for the system.
**/

#include <stdexcept>
#include <string>
#include <boost/noncopyable.hpp>
#include <boost/scoped_ptr.hpp>
#include <glutil/array_ref.h>
#include <boost/utility/string_ref.hpp>


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

	///Thrown if the array of layer names passed to the constructor is empty.
	class EmptyLayerListException : public SceneGraphException
	{
	public:
		explicit EmptyLayerListException()
			: SceneGraphException("Empty list of layers to SceneGraph constructor.") {}
	};

	///Thrown if you request a layer by string name that was not defined.
	class UndefinedLayerException : public SceneGraphException
	{
	public:
		explicit UndefinedLayerException(const std::string &layerName)
			: SceneGraphException(GetErrorName(layerName)) {}

	private:
		static std::string GetErrorName(const std::string &layerName);
	};


	///Thrown whenever a resource that was incomplete is used by a node during rendering.
	class UsingIncompleteResourceException : public SceneGraphException
	{
	public:
		explicit UsingIncompleteResourceException(const std::string &resource, const std::string &resourceType)
			: SceneGraphException(GetErrorName(resource, resourceType)) {}

	private:
		static std::string GetErrorName(const std::string &resource, const std::string &resourceType);
	};

	///@}

	///\addtogroup module_glscene_core
	///@{

	/**
	\brief The class which represents a scene graph and all of its data.

	This class is [swappable](http://en.cppreference.com/w/cpp/concept/Swappable) but not copyable.

	**/
	class SceneGraph : public boost::noncopyable
	{
	public:
		/**
		\brief Constructs a scene graph with the given list of layers.
		
		\throws EmptyLayerListException If \a layerNames is empty. You must provide at least one layer.
		**/
		SceneGraph(refs::array_ref<const char*> layerNames);

		/// \copydoc SceneGraph::SceneGraph(refs::array_ref<const char*>)
		SceneGraph(refs::array_ref<std::string> layerNames);
		~SceneGraph();

		/**
		\brief Retrieves the index for the given layer name.

		\throws UndefinedLayerException If \a layer is not the name of one of the layers.
		**/
		int GetLayerIndex(const std::string &layer) const;

		Resources GetResources();
		const Resources GetResources() const;

	private:
		boost::scoped_ptr<SceneGraphData> m_pData;

		friend void swap(SceneGraph &lhs, SceneGraph &rhs);
	};

	///Makes SceneGraph swappable via an ADL-style `swap` call.
	void swap(SceneGraph &lhs, SceneGraph &rhs);

	///@}

}

#endif //GLSDK_GLSCENE_SCENE_GRAPH_H
