
#include "pch.h"

#include "glscene/NodeRef.h"
#include "NodeData.h"

namespace glscene
{
	TransformData & NodeRef::GetNodeTMRef()
	{
		return m_data.get().GetNodeTM();
	}

	const TransformData & NodeRef::GetNodeTMRef() const
	{
		return m_data.get().GetNodeTM();
	}

	TransformData & NodeRef::GetObjectTMRef()
	{
		return m_data.get().GetObjectTM();
	}

	const TransformData & NodeRef::GetObjectTMRef() const
	{
		return m_data.get().GetObjectTM();
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

	bool IsDecomposed( const TransformData &data )
	{
		return data.IsDecomposed();
	}

	void SetTranslationDecomp( TransformData &data, const glm::vec3 &translation )
	{
		data.SetTranslationDecomp(translation);
	}

	void OffsetTranslationDecomp( TransformData &data, const glm::vec3 &translation )
	{
		data.OffsetTranslationDecomp(translation);
	}

	void SetOrientDecomp( TransformData &data, const glm::quat &orientation )
	{
		data.SetOrientDecomp(orientation);
	}

	void RightMultiplyOrientDecomp( TransformData &data, const glm::quat &orientation )
	{
		data.RightMultiplyOrientDecomp(orientation);
	}

	void LeftMultiplyOrientDecomp( TransformData &data, const glm::quat &orientation )
	{
		data.LeftMultiplyOrientDecomp(orientation);
	}

	void SetScaleDecomp( TransformData &data, const glm::vec3 &scale )
	{
		data.SetScaleDecomp(scale);
	}

	glm::vec3 GetTranslationDecomp( const TransformData &data )
	{
		return data.GetTranslationDecomp();
	}

	glm::quat GetOrientDecomp( const TransformData &data )
	{
		return data.GetOrientDecomp();
	}

	glm::vec3 GetScaleDecomp( const TransformData &data )
	{
		return data.GetScaleDecomp();
	}

	void SetDecomposed( TransformData &data, const glm::vec3 &translation, const glm::quat &orientation /*= glm::quat()*/, const glm::vec3 &scale /*= glm::vec3(1.0f, 1.0f, 1.0f)*/ )
	{
		DecomposedMatrix mat;
		mat.translation = translation;
		mat.orientation = orientation;
		mat.scale = scale;
		data.SetDecomposed(mat);
	}

	glm::mat4 GetMatrix( const TransformData &data )
	{
		return data.GetMatrix();
	}

	void Compose( TransformData &data )
	{
		data.Compose();
	}

	void RightMultiplyCompose( TransformData &data, const glm::mat4 &rhs )
	{
		data.RightMultiplyCompose(rhs);
	}

	void LeftMultiplyCompose( TransformData &data, const glm::mat4 &lhs )
	{
		data.LeftMultiplyCompose(lhs);
	}

	void SetMatrixCompose( TransformData &data, const glm::mat4 &matrix )
	{
		data.SetMatrixCompose(matrix);
	}
}
