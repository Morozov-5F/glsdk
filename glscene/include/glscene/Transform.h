#ifndef GLSDK_INTERNAL_GLSCENE_TRANSFORM_H
#define GLSDK_INTERNAL_GLSCENE_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <stdexcept>


namespace glscene
{
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
		TransformData &m_data;

		Transform(TransformData &data) : m_data(data) {}
	};

	///@}
}


#endif //GLSDK_INTERNAL_GLSCENE_TRANSFORM_H
