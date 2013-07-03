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
#include <glm/glm.hpp>


namespace glscene
{
	class ResourceRef;
	struct SceneGraphData;
	struct StyleInfo;

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
	\brief Defines the order by which nodes are rendered.
	
	**/
	enum NodeRenderingOrder
	{
		ORDER_ARBITRARY,		///<The nodes will be rendered without any specific order.
//		ORDER_FRONT_TO_BACK,	///<The nodes will be sorted front-to-back, based on the node transform's camera-space position. "Front" means larger Z values.
//		ORDER_BACK_TO_FRONT,	///<The nodes will be sorted back-to-front, based on the node transform's camera-space position. "Front" means larger Z values.
	};

	/**
	\brief The class which represents a scene graph and all of its data.

	The foundation of the Scene Graph system is this class. This object represents all of the
	[nodes in the scene](\ref module_glscene_node) and the [resources](\ref module_glscene_resources)
	being used by those nodes.

	SceneGraph objects are created with a number of layers. Each NodeData that is created can be assigned
	to one or more of these layers. When rendering a layer, only nodes within that layer are considered. This
	makes it possible to assign each node to a different visibility set. For example, all nodes that cast
	shadows can be assigned to a layer, thus allowing one to separate what causes shadows from what gets drawn.
	They are also useful for blended rendering vs. non-blended rendering.

	This class is not copyable. But it is [swappable](http://en.cppreference.com/w/cpp/concept/Swappable).
	Destroying this object will destroy all of the owned resources and nodes that use it. So be careful not
	to allow any ResourceRef, NodeData&, or any other objects that refer to data within the SceneGraph
	to outlive the SceneGraph that created them.

	SceneGraph objects are not unique. They are not singletons or anything of the like. You can freely create
	(and destroy) as many of these as you see fit. You can render with multiple SceneGraphs to your heart's content.
	Just make sure that any resources you share between them aren't owned by both of them.

	That being said, due to the layer paradigm, rendering with multiple scene graphs is probably not
	particularly useful. You can just use different layers of nodes; it would probably be much easier to work with.
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

		///Retrieves the ResourceRef stored in the scene graph.
		ResourceRef GetResources();


		/**
		\name NodeData Accessors and Modifiers
		
		The SceneGraph class owns all of the NodeData objects it manages. Therefore, all NodeData creation and
		destruction goes through the SceneGraph class.
		**/
		///@{
		///Retrieves the root node.
		NodeData &GetRootNode();

		///Finds the given node by its name. Returns NULL if no node with the given name is found.
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
		\brief Sets a named rendering style into a node.

		If this function succeeds, the following OpenGL state will be changed:

		- If you provide a StyleInfo that uses separable programs, the current program pipeline will be reset
		to 0 by a call to `glBindProgramPipeline(0)`.

		\param node The node to set the style on.
		\param styleId Identifier string for the style to add.
		\param style The style to set into the node.

		\throws StyleMultiplyDefinedException If \a styleId has already been defined.
		\throws StyleMultipleBindingsException If one of the binding points is used by multiple resources.
		For example, two textures trying to bind to the same texture unit.
		\throws ResourceNotFoundException If any identifiers in the \a style refer to resources that don't exist.
		**/
		void DefineNodeStyle(NodeData &node, const boost::string_ref styleId,
			const StyleInfo &style);
		///@}

		/**
		\brief Renders all nodes in given layer of the scene, using the specific style specified.

		\param worldToCamera A matrix to be left-multiplied with all transformation matrices before being passed
		on to the program(s) being used. Usually represents the world-to-camera transform.
		\param eOrder The order used for node rendering operations. Nodes are ordered based on the camera-space
		position of their [node transform, not their object transform](\ref module_glscene_node_transforms).
		\param layerIx Specifies the layer of nodes to render. Only nodes that are part of the given layer
		will be rendered. Transforms from nodes that are not part of the layer will still be computed.
		\param styleId Specifies the style that will be rendered. Nodes with a style matching this name will
		that style rendered.
		**/
		void Render(const glm::mat4 &worldToCamera, NodeRenderingOrder eOrder,
			int layerIx, boost::string_ref styleId) const;

	private:
		boost::scoped_ptr<SceneGraphData> m_pData;

		friend void swap(SceneGraph &lhs, SceneGraph &rhs);
	};

	///Makes SceneGraph swappable via an ADL-style `swap` call.
	void swap(SceneGraph &lhs, SceneGraph &rhs);

	///@}

}

#endif //GLSDK_GLSCENE_SCENE_GRAPH_H
