

#include "glscene/Node.h"
#include "NodeData.h"

namespace glscene
{
	void Transform::SetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.get().SetTranslationDecomp(translation);
	}

	void Transform::OffsetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.get().OffsetTranslationDecomp(translation);
	}

	void Transform::SetOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().SetOrientDecomp(orientation);
	}

	void Transform::RightMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().RightMultiplyOrientDecomp(orientation);
	}

	void Transform::LeftMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().LeftMultiplyOrientDecomp(orientation);
	}

	void Transform::SetScaleDecomp( const glm::vec3 &scale )
	{
		m_data.get().SetScaleDecomp(scale);
	}

	glm::vec3 Transform::GetTranslationDecomp() const
	{
		return m_data.get().GetTranslationDecomp();
	}

	glm::quat Transform::GetOrientDecomp() const
	{
		return m_data.get().GetOrientDecomp();
	}

	glm::vec3 Transform::GetScaleDecomp() const
	{
		return m_data.get().GetScaleDecomp();
	}

	void Transform::SetDecomposed( const glm::vec3 &translation,
		const glm::quat &orientation, const glm::vec3 &scale )
	{
		DecomposedMatrix mat;
		mat.translation = translation;
		mat.orientation = orientation;
		mat.scale = scale;
		m_data.get().SetDecomposed(mat);
	}

	glm::mat4 Transform::GetMatrix() const
	{
		return m_data.get().GetMatrix();
	}

	void Transform::Compose()
	{
		m_data.get().Compose();
	}

	void Transform::RightMultiplyCompose( const glm::mat4 &rhs )
	{
		m_data.get().RightMultiplyCompose(rhs);
	}

	void Transform::LeftMultiplyCompose( const glm::mat4 &lhs )
	{
		m_data.get().LeftMultiplyCompose(lhs);
	}

	void Transform::SetMatrixCompose( const glm::mat4 &matrix )
	{
		m_data.get().SetMatrixCompose(matrix);
	}

	bool Transform::IsDecomposed() const
	{
		return m_data.get().IsDecomposed();
	}

	Transform Node::GetNodeTM()
	{
		return m_data.get().GetNodeTM();
	}

	boost::string_ref Node::GetName() const
	{
		return m_data.get().GetName();
	}

	boost::optional<Node> Node::GetParent()
	{
		NodeData *pNode = m_data.get().GetParent();
		return pNode ? boost::optional<Node>(Node(*pNode)) : boost::none;
	}

	void Node::MakeChildOfNode( Node newParent )
	{
		if(m_data.get_pointer() == newParent.m_data.get_pointer())
			throw CannotMakeParentOfSelfException();

		m_data.get().MakeChildOfNode(newParent.m_data.get());
	}
}
