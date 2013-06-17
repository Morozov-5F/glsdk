
#ifndef GLSDK_GLSCENE_NODE_H
#define GLSDK_GLSCENE_NODE_H

/**
\file
\brief Includes the glscene::Node and glscene::Transform classes for the system.
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

	///\addtogroup module_glscene_exceptions
	///@{

	///Base class for all Node-based exceptions.
	class NodeException : public std::runtime_error
	{
	public:
		explicit NodeException(const std::string &desc) : std::runtime_error(desc) {}

	private:
	};

	///Thrown by any `Transform::*Decomp` function if the transform is not decomposed.
	class TransformNotDecomposedException : public NodeException
	{
	public:
		explicit TransformNotDecomposedException()
			: NodeException("The transform is not decomposed.") {}

	private:
	};

	///Thrown by Node::MakeChildOfNode if the current node and the parent are the same node.
	class CannotMakeParentOfSelfException : public NodeException
	{
	public:
		explicit CannotMakeParentOfSelfException()
			: NodeException("A Node cannot be made the parent of itself.") {}

	private:
	};

	///Thrown by Node::MakeChildOfNode if trying to reparent the root node.
	class CannotChangeTheRootParentException : public NodeException
	{
	public:
		explicit CannotChangeTheRootParentException()
			: NodeException("The root Node's parent cannot be changed.") {}

	private:
	};
	///@}

	///\addtogroup module_glscene_node
	///@{

	/**
	\brief Represents one of the transforms on the node.

	This object has reference semantics. Copies can be made, but you cannot copy-assign
	an existing object; you must copy-construct them.
	
	Transforms on a node can exist in one of two states: composed or decomposed. In the composed form,
	the transform is just a matrix. In the decomposed form, it is represented as a
	translation/orientation/scale. The orientation is stored as a quaternion. The decomposed rotations
	are apply such that scale comes first, then orientation, then translation.

	The decomposed form makes it easy to modify, for example, the rotation without having it
	affect or be affected by the existing translation. A translation can be applied without affecting the
	existing scale. And so forth. Right-multiplication vs. left-multiplication can achieve some of these
	effects, but that is not enough for some of these changes.

	Any function that ends in `Decomp` will only work if IsDecomposed returns `true`. If it is `false`,
	the function will throw TransformNotDecomposedException.

	When creating a node, the transforms on that node will be decomposed. You can call SetDecomposed to
	make the transform decomposed, but this requires resetting the translation/orientation/scale all at once.

	Calling any function that ends on `Compose` or the Compose function itself, will convert the transform
	to the composed form. Note that GetMatrix does *not* compose a decomposed matrix.

	No functions in SceneGraph, Node, or any other scene graph class will do anything to change the
	composed/decomposed status of the transform. Only your actions can cause a matrix to become decomposed.
	**/
	class Transform
	{
	public:
		///Returns `true` if the transform is decomposed.
		bool IsDecomposed() const;

		///Sets the translation of a decomposed transform, or throws TransformNotDecomposedException
		void SetTranslationDecomp(const glm::vec3 &translation);
		///Adds vector to the the translation of a decomposed transform, or throws TransformNotDecomposedException
		void OffsetTranslationDecomp(const glm::vec3 &translation);

		///Sets the orientation of a decomposed transform, or throws TransformNotDecomposedException
		void SetOrientDecomp(const glm::quat &orientation);
		///Right-multiplies the quaternion to the orientation of a decomposed transform, or throws TransformNotDecomposedException
		void RightMultiplyOrientDecomp(const glm::quat &orientation);
		///Left-multiplies the quaternion to the orientation of a decomposed transform, or throws TransformNotDecomposedException
		void LeftMultiplyOrientDecomp(const glm::quat &orientation);

		///Sets the scale of a decomposed transform, or throws TransformNotDecomposedException
		void SetScaleDecomp(const glm::vec3 &scale);

		///Gets the translation of a decomposed transform, or throws TransformNotDecomposedException
		glm::vec3 GetTranslationDecomp() const;
		///Gets the orientation of a decomposed transform, or throws TransformNotDecomposedException
		glm::quat GetOrientDecomp() const;
		///Gets the scale of a decomposed transform, or throws TransformNotDecomposedException
		glm::vec3 GetScaleDecomp() const;

		///Sets the 3 decomposed values of the transform. The transform will be decomposed following this.
		void SetDecomposed(const glm::vec3 &translation,
			const glm::quat &orientation = glm::quat(),
			const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f));

		///Retrieves the matrix representing this transform.
		glm::mat4 GetMatrix() const;

		///Causes the transform to become composed.
		void Compose();

		///Computes and stores current * \a rhs. Causes the transform to become composed.
		void RightMultiplyCompose(const glm::mat4 &rhs);
		///Computes and stores \a lhs * current. Causes the transform to become composed.
		void LeftMultiplyCompose(const glm::mat4 &lhs);

		///Sets the current matrix to the given. Causes the transform to become composed.
		void SetMatrixCompose(const glm::mat4 &matrix);

	private:
		boost::reference_wrapper<TransformData> m_data;

		Transform(TransformData &data) : m_data(data) {}

		friend class Node;
	};

	///@}

	/**
	\brief Represents a reference to a node in the scene graph.
	
	**/
	class Node
	{
	public:
		///Gets the Node's [node transform](@ref module_glscene_core_transforms).
		Transform GetNodeTM();
		///Gets the Node's [object transform](@ref module_glscene_core_transforms).
		Transform GetObjectTM();


		/**
		\brief Puts the node into the given layer by index.

		If \a layerIx is out of bounds, this will not throw. It will just ignore the call.
		**/
		void AddToLayer(int layerIx);

		/**
		\brief Removes the node from the given layer by index.
		
		If you remove the node from a layer it is not in, or if \a layerIx is out of bounds,
		this will not throw. It will simply ignore the call.
		**/
		void RemoveFromLayer(int layerIx);

		/**
		\brief Tests whether the node is in the given layer by index.

		If \a layerIx is out of bounds, this will not throw. It will return `false`.
		**/
		bool IsInLayer(int layerIx) const;

		/**
		\brief Retrieves the identifier string given for the node's name at construction time.
		
		If the Node has no name, this will return an empty string.
		**/
		boost::string_ref GetName() const;

		/**
		\brief Retrieves the parent node, if the node is not the root.
		**/
		boost::optional<Node> GetParent();

		/**
		\brief Makes the given node the parent of this one.

		\throws CannotMakeParentOfSelfException If `*this` is the root node. The root node's parentage cannot be changed.
		\throws CannotMakeParentOfSelfException If `*this` and \a newParent are the same node.
		
		**/
		void MakeChildOfNode(Node newParent);

	private:
		boost::reference_wrapper<NodeData> m_data;

		Node(NodeData &data) : m_data(data) {}

		friend class SceneGraph;
	};
}


#endif //GLSDK_GLSCENE_NODE_H
