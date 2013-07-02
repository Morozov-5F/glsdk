
#ifndef GLSDK_GLSCENE_NODE_H
#define GLSDK_GLSCENE_NODE_H

/**
\file
\brief Includes the NodeData and associated classes.
**/

#include <string>
#include <stdexcept>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <boost/utility/string_ref.hpp>
#include <boost/optional.hpp>
#include <boost/ref.hpp>

namespace glscene
{
	class NodeData;
	class TransformData;
	struct StyleInfo;

	///\addtogroup module_glscene_exceptions
	///@{

	///Base class for all NodeData and TransformData classes.
	class NodeException : public std::runtime_error
	{
	public:
		explicit NodeException(const std::string &desc) : std::runtime_error(desc) {}

	private:
	};

	///Thrown by any `*Decomp` function if the TransformData object is not decomposed.
	class TransformNotDecomposedException : public NodeException
	{
	public:
		explicit TransformNotDecomposedException()
			: NodeException("The transform is not decomposed.") {}

	private:
	};

	///Thrown by glscene::MakeChildOfNode if the current node and the parent are the same node.
	class CannotMakeParentOfSelfException : public NodeException
	{
	public:
		explicit CannotMakeParentOfSelfException()
			: NodeException("A NodeRef cannot be made the parent of itself.") {}

	private:
	};

	///Thrown by glscene::MakeChildOfNode if trying to reparent the root node.
	class CannotChangeTheRootParentException : public NodeException
	{
	public:
		CannotChangeTheRootParentException()
			: NodeException("The root NodeRef's parent cannot be changed.") {}

	private:
	};

	///Thrown by SceneGraph::DefineNodeStyle if some bindings overlap in the style. That is, if you try to bind two different textures to the same unit.
	class StyleMultipleBindingsException : public NodeException
	{
	public:
		StyleMultipleBindingsException(const std::string &resourceId, const std::string &resourceType,
			unsigned int bindingIndex)
			: NodeException(GetErrorString(resourceId, resourceType, bindingIndex)) {}

	private:
		static std::string GetErrorString(const std::string &resourceId, const std::string &resourceType,
			unsigned int bindingIndex);
	};

	///Thrown by glscene::DefineNodeStyle if the given style name already exists.
	class StyleMultiplyDefinedException : public NodeException
	{
	public:
		explicit StyleMultiplyDefinedException(const std::string &styleName)
			: NodeException(GetErrorName(styleName)) {}

	private:
		static std::string GetErrorName(const std::string &styleName);
	};
	///@}

	///\addtogroup module_glscene_node
	///@{

	/**
	\class glscene::TransformData
	\brief One of the transforms on the node.

	This is an opaque type; values of this type are only returned by reference (or `const&`),
	so you may not manually construct them or copy them to other instances. You can only reference
	a transform within a node.
	
	Transforms on a node can exist in one of two states: composed or decomposed. In the composed form,
	the transform is just a matrix. In the decomposed form, it is represented as a
	translation/orientation/scale. The orientation is stored as a quaternion. The decomposed rotations
	are apply such that scale comes first, then orientation, then translation.

	The decomposed form makes it easy to modify, for example, the rotation without having it
	affect or be affected by the existing translation. A translation can be applied without affecting the
	existing scale. And so forth. Right-multiplication vs. left-multiplication can achieve some of these
	effects, but that is not enough for some of these changes.

	Any function that ends in `Decomp` will only work if glscene::IsDecomposed returns `true`. If it is `false`,
	the function will throw TransformNotDecomposedException.

	When creating a node, the transforms on that node will be decomposed. You can call glscene::SetDecomposed to
	make the transform decomposed, but this will reset all of the translation/orientation/scale in one call.

	Calling any function that ends on `Compose` or the glscene::Compose function itself, will convert the transform
	to the composed form. Note that glscene::GetMatrix does *not* compose a decomposed matrix.

	No functions in SceneGraph or any other scene graph class will do anything to change the
	composed/decomposed status of the TransformData. Only your actions can cause a matrix to become decomposed.
	**/

	/**
	\name TransformData Operations

	TransformData objects are operated on by these glscene functions. This global interface is
	used to preserve const-correctness, which can't be done with C++ value objects
	(without having two distinct object types).

	Remember that C++ provides argument dependent lookup. You can call these functions
	with just `IsDecomposed(data)` without the `glscene` namespace qualifier.
	**/
	///@{

	///Returns `true` if the transform is decomposed.
	bool IsDecomposed(const TransformData &data);

	///Sets the translation of a decomposed transform, or throws TransformNotDecomposedException
	void SetTranslationDecomp(TransformData &data, const glm::vec3 &translation);
	///Adds vector to the the translation of a decomposed transform, or throws TransformNotDecomposedException
	void OffsetTranslationDecomp(TransformData &data, const glm::vec3 &translation);

	///Sets the orientation of a decomposed transform, or throws TransformNotDecomposedException
	void SetOrientDecomp(TransformData &data, const glm::quat &orientation);
	///Right-multiplies the quaternion to the orientation of a decomposed transform, or throws TransformNotDecomposedException
	void RightMultiplyOrientDecomp(TransformData &data, const glm::quat &orientation);
	///Left-multiplies the quaternion to the orientation of a decomposed transform, or throws TransformNotDecomposedException
	void LeftMultiplyOrientDecomp(TransformData &data, const glm::quat &orientation);

	///Sets the scale of a decomposed transform, or throws TransformNotDecomposedException
	void SetScaleDecomp(TransformData &data, const glm::vec3 &scale);

	///Gets the translation of a decomposed transform, or throws TransformNotDecomposedException
	glm::vec3 GetTranslationDecomp(const TransformData &data);
	///Gets the orientation of a decomposed transform, or throws TransformNotDecomposedException
	glm::quat GetOrientDecomp(const TransformData &data);
	///Gets the scale of a decomposed transform, or throws TransformNotDecomposedException
	glm::vec3 GetScaleDecomp(const TransformData &data);

	///Sets the 3 decomposed values of the transform. The transform will be decomposed following this.
	void SetDecomposed(TransformData &data, const glm::vec3 &translation,
		const glm::quat &orientation = glm::quat(),
		const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f));

	///Retrieves the matrix representing this transform.
	glm::mat4 GetMatrix(const TransformData &data);

	///Causes the transform to become composed.
	void Compose(TransformData &data);

	///Computes and stores current * \a rhs. Causes the transform to become composed.
	void RightMultiplyCompose(TransformData &data, const glm::mat4 &rhs);
	///Computes and stores \a lhs * current. Causes the transform to become composed.
	void LeftMultiplyCompose(TransformData &data, const glm::mat4 &lhs);

	///Sets the current matrix to the given. Causes the transform to become composed.
	void SetMatrixCompose(TransformData &data, const glm::mat4 &matrix);
	///@}

	/**
	\class glscene::NodeData
	\brief A node in the scene graph.

	NodeData is an opaque type; values of this type are only returned by reference or pointer,
	so you may not manually construct them or copy them to other instances. You can only reference
	a node within the SceneGraph.

	Nodes have a [pair of transforms](\ref module_glscene_node_transforms) that determine the position of the
	object and any child nodes. Nodes can also have a number of styles set on them, defined by the
	SceneGraph::DefineNodeStyle function. Styles represent the visual element of a node, and each style has a name.

	Nodes can also be members of layers in the SceneGraph. When the scene graph is rendered, if a node is not
	part of the layer being rendered, the node is not drawn.

	Because these are opaque types, the interface to accessing or modifying much of the information
	for NodeData objects is part of a number of [free functions in this namespace](#ref module_glscene_node).
	C++'s argument dependent lookup allows you to use these without namespace qualifiers.
	**/

	/**
	\name NodeData Operations

	NodeData objects are manipulated by these glscene functions. This global interface is
	used to preserve const-correctness, which can't be done with C++ value objects
	(without having two distinct object types).

	Remember that C++ provides argument dependent lookup. You can call these functions
	with just `AddToLayer(data)` without the `glscene` namespace qualifier.
	**/
	///@{
	///Gets the NodeRef's [node transform](@ref module_glscene_node_transforms).
	TransformData &GetNodeTM(NodeData &data);
	///Gets the NodeRef's [node transform](@ref module_glscene_node_transforms).
	const TransformData &GetNodeTM(const NodeData &data);

	///Gets the NodeRef's [object transform](@ref module_glscene_node_transforms).
	TransformData &GetObjectTM(NodeData &data);
	///Gets the NodeRef's [object transform](@ref module_glscene_node_transforms).
	const TransformData &GetObjectTM(const NodeData &data);

	/**
	\brief Puts the node into the given layer by index.

	If \a layerIx is out of bounds, this will not throw. It will just ignore the call.
	**/
	void AddToLayer(NodeData &data, int layerIx);

	/**
	\brief Removes the node from the given layer by index.
	
	If you remove the node from a layer it is not in, or if \a layerIx is out of bounds,
	this will not throw. It will simply ignore the call.
	**/
	void RemoveFromLayer(NodeData &data, int layerIx);

	/**
	\brief Tests whether the node is in the given layer by index.

	If \a layerIx is out of bounds, this will not throw. It will return `false`.
	**/
	bool IsInLayer(const NodeData &data, int layerIx);

	/**
	\brief Retrieves the identifier string given for the node's name at construction time.
	
	If the NodeData has no name, this will return an empty string.
	**/
	boost::string_ref GetName(const NodeData &data);

	/**
	\brief Retrieves the parent node; returns NULL if it is the root.
	**/
	NodeData *GetParent(NodeData &data);

	/**
	\brief Retrieves the parent node; returns NULL if it is the root.
	**/
	const NodeData *GetParent(const NodeData &data);

	/**
	\brief Makes the given node the parent of this one.

	\throws CannotChangeTheRootParentException If \a data is the root node. The root node's parentage cannot be changed.
	\throws CannotMakeParentOfSelfException If `\a data and \a newParent are the same node.
	**/
	void MakeChildOfNode(NodeData &data, NodeData &newParent);
	///@}

	///@}
}


#endif //GLSDK_GLSCENE_NODE_H
