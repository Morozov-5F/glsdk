
#include "glscene/Transform.h"
#include "TransformData.h"

namespace glscene
{
	void Transform::SetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.SetTranslationDecomp(translation);
	}

	void Transform::OffsetTranslationDecomp( const glm::vec3 &translation )
	{
		m_data.OffsetTranslationDecomp(translation);
	}

	void Transform::SetOrientDecomp( const glm::quat &orientation )
	{
		m_data.SetOrientDecomp(orientation);
	}

	void Transform::RightMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.RightMultiplyOrientDecomp(orientation);
	}

	void Transform::LeftMultiplyOrientDecomp( const glm::quat &orientation )
	{
		m_data.LeftMultiplyOrientDecomp(orientation);
	}

	void Transform::SetScaleDecomp( const glm::vec3 &scale )
	{
		m_data.SetScaleDecomp(scale);
	}

	glm::vec3 Transform::GetTranslationDecomp() const
	{
		return m_data.GetTranslationDecomp();
	}

	glm::quat Transform::GetOrientDecomp() const
	{
		return m_data.GetOrientDecomp();
	}

	glm::vec3 Transform::GetScaleDecomp() const
	{
		return m_data.GetScaleDecomp();
	}

	void Transform::SetDecomposed( const glm::vec3 &translation,
		const glm::quat &orientation, const glm::vec3 &scale )
	{
		DecomposedMatrix mat;
		mat.translation = translation;
		mat.orientation = orientation;
		mat.scale = scale;
		m_data.SetDecomposed(mat);
	}

	glm::mat4 Transform::GetMatrix() const
	{
		return m_data.GetMatrix();
	}

	void Transform::Compose()
	{
		m_data.Compose();
	}

	void Transform::RightMultiplyCompose( const glm::mat4 &rhs )
	{
		m_data.RightMultiplyCompose(rhs);
	}

	void Transform::LeftMultiplyCompose( const glm::mat4 &lhs )
	{
		m_data.LeftMultiplyCompose(lhs);
	}

	void Transform::SetMatrixCompose( const glm::mat4 &matrix )
	{
		m_data.SetMatrixCompose(matrix);
	}

	bool Transform::IsDecomposed() const
	{
		return m_data.IsDecomposed();
	}
}

