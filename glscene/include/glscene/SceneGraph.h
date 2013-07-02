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
#include <boost/optional.hpp>
#include <boost/ref.hpp>
#include "glscene/NodeRef.h"


namespace glscene
{
	class ResourceRef;
	struct SceneGraphData;
	struct VariantInfo;

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

	///Thrown when adding a node with a name that already matches an existing node.
	class NodeNameAlreadyExistsException : public SceneGraphException
	{
	public:
		explicit NodeNameAlreadyExistsException(const std::string &nodeName)
			: SceneGraphException(GetErrorName(nodeName)) {}

	private:
		static std::string GetErrorName(const std::string &nodeName);
	};

	///Thrown when attempting to delete the root node.
	class CannotDeleteRootNodeException : public SceneGraphException
	{
	public:
		explicit CannotDeleteRootNodeException()
			: SceneGraphException("You cannot delete the root NodeRef.") {}
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

		///Retrieves the current root node.
		NodeData &GetRootNode();

		///Finds the given node by its name.
		NodeData *FindNode(const boost::string_ref &name);

		///Creates a new node that is the child of the given one.
		NodeData &CreateChildNode(NodeData &parent, boost::optional<boost::string_ref> name = boost::none);

		/**
		\brief Deletes the node and all of its child nodes.

		\throws CannotDeleteRootNodeException If \a nodeToDelete is the root node.
		**/
		void DeleteNodeRecursive(NodeData &nodeToDelete);

		/**
		\brief Deletes only the given node, making all of it's child nodes children of its direct parent.
		
		\throws CannotDeleteRootNodeException If \a nodeToDelete is the root node.
		**/
		void DeleteNodeOnly(NodeData &nodeToDelete);

		/**
		\brief Retrieves the index for the given layer name.

		\throws UndefinedLayerException If \a layer is not the name of one of the layers.
		**/
		int GetLayerIndex(const std::string &layer) const;

		///Retrieves the Resources stored in the scene graph.
		ResourceRef GetResources();

		/**
		\brief Sets a named rendering variant into a node.

		If this function succeeds, the following OpenGL state will be changed:

		- If you provide a VariantInfo that uses separable programs, the current program pipeline will be reset
		to 0 by a call to `glBindProgramPipeline(0)`.

		\throws VariantAlreadyExistsException If \a variantId has already been defined.
		\throws ResourceNotFoundException If any identifiers in the \a variant refer to resources that don't exist.
		**/
		void DefineNodeVariant(NodeData &node, const boost::string_ref variantId,
			const VariantInfo &variant);

	private:
		boost::scoped_ptr<SceneGraphData> m_pData;

		friend void swap(SceneGraph &lhs, SceneGraph &rhs);
	};

	///Makes SceneGraph swappable via an ADL-style `swap` call.
	void swap(SceneGraph &lhs, SceneGraph &rhs);

	///@}

}

#endif //GLSDK_GLSCENE_SCENE_GRAPH_H
