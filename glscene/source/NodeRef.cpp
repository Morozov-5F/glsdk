
#include "pch.h"

#include "glscene/NodeRef.h"
#include "NodeData.h"

namespace glscene
{
	void TransformRef::SetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.get().SetTranslationDecomp(translation);
	}

	void TransformRef::OffsetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.get().OffsetTranslationDecomp(translation);
	}

	void TransformRef::SetOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().SetOrientDecomp(orientation);
	}

	void TransformRef::RightMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().RightMultiplyOrientDecomp(orientation);
	}

	void TransformRef::LeftMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.get().LeftMultiplyOrientDecomp(orientation);
	}

	void TransformRef::SetScaleDecomp( const glm::vec3 &scale )
	{
		m_data.get().SetScaleDecomp(scale);
	}

	glm::vec3 TransformRef::GetTranslationDecomp() const
	{
		return m_data.get().GetTranslationDecomp();
	}

	glm::quat TransformRef::GetOrientDecomp() const
	{
		return m_data.get().GetOrientDecomp();
	}

	glm::vec3 TransformRef::GetScaleDecomp() const
	{
		return m_data.get().GetScaleDecomp();
	}

	void TransformRef::SetDecomposed( const glm::vec3 &translation,
		const glm::quat &orientation, const glm::vec3 &scale )
	{
		DecomposedMatrix mat;
		mat.translation = translation;
		mat.orientation = orientation;
		mat.scale = scale;
		m_data.get().SetDecomposed(mat);
	}

	glm::mat4 TransformRef::GetMatrix() const
	{
		return m_data.get().GetMatrix();
	}

	void TransformRef::Compose()
	{
		m_data.get().Compose();
	}

	void TransformRef::RightMultiplyCompose( const glm::mat4 &rhs )
	{
		m_data.get().RightMultiplyCompose(rhs);
	}

	void TransformRef::LeftMultiplyCompose( const glm::mat4 &lhs )
	{
		m_data.get().LeftMultiplyCompose(lhs);
	}

	void TransformRef::SetMatrixCompose( const glm::mat4 &matrix )
	{
		m_data.get().SetMatrixCompose(matrix);
	}

	bool TransformRef::IsDecomposed() const
	{
		return m_data.get().IsDecomposed();
	}

	TransformRef NodeRef::GetNodeTM()
	{
		return TransformRef(m_data.get().GetNodeTM());
	}

	boost::string_ref NodeRef::GetName() const
	{
		return m_data.get().GetName();
	}

	boost::optional<NodeRef> NodeRef::GetParent()
	{
		NodeData *pNode = m_data.get().GetParent();
		return pNode ? boost::optional<NodeRef>(NodeRef(*pNode)) : boost::none;
	}

	void NodeRef::MakeChildOfNode( NodeRef newParent )
	{
		if(m_data.get_pointer() == newParent.m_data.get_pointer())
			throw CannotMakeParentOfSelfException();

		m_data.get().MakeChildOfNode(newParent.m_data.get());
	}
}
