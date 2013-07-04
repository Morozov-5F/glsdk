#ifndef GLSDK_INTERNAL_GLSCENE_TRANSFORM_DATA_H
#define GLSDK_INTERNAL_GLSCENE_TRANSFORM_DATA_H

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <boost/variant.hpp>
#include <boost/variant/static_visitor.hpp>

namespace glscene
{
	struct DecomposedMatrix
	{
		glm::vec3 translation;
		glm::quat orientation;
		glm::vec3 scale;

		operator glm::mat4 () const
		{
			glm::mat4 ret(1.0f);
			ret = glm::translate(ret, translation);
			ret = ret * glm::mat4_cast(orientation);
			ret = glm::scale(ret, scale);
			return ret;
		}

		static DecomposedMatrix CreateDefault()
		{
			DecomposedMatrix ret =
			{
				glm::vec3(0.0f, 0.0f, 0.0f),
				glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
				glm::vec3(1.0f, 1.0f, 1.0f),
			};

			return ret;
		}
	};

	typedef boost::variant<glm::mat4, DecomposedMatrix> ComposableMatrix;

	struct MatrixVisitor : public boost::static_visitor<glm::mat4>
	{
		template<typename T>
			glm::mat4 operator()(const T &mat) const {return mat;}
	};

	class TransformData
	{
	public:
		TransformData(const ComposableMatrix &mat) : m_matrix(mat) {}
		TransformData() : m_matrix(DecomposedMatrix::CreateDefault()) {}

		bool IsDecomposed() const
		{
			return boost::get<const DecomposedMatrix*>(m_matrix) != NULL;
		}

		void SetTranslationDecomp(const glm::vec3 &translation)
		{
			GetDecomposed().translation = translation;
		}

		void OffsetTranslationDecomp(const glm::vec3 &translation)
		{
			GetDecomposed().translation += translation;
		}

		void SetOrientDecomp(const glm::quat &orientation)
		{
			GetDecomposed().orientation = glm::normalize(orientation);
		}

		void RightMultiplyOrientDecomp(const glm::quat &orientation)
		{
			DecomposedMatrix &mat = GetDecomposed();
			mat.orientation = mat.orientation * orientation;
			mat.orientation = glm::normalize(mat.orientation);
		}

		void LeftMultiplyOrientDecomp(const glm::quat &orientation)
		{
			DecomposedMatrix &mat = GetDecomposed();
			mat.orientation = orientation * mat.orientation;
			mat.orientation = glm::normalize(mat.orientation);
		}

		void SetScaleDecomp(const glm::vec3 &scale)
		{
			GetDecomposed().scale = scale;
		}

		glm::vec3 GetTranslationDecomp() const {return GetDecomposed().translation;}
		glm::quat GetOrientDecomp() const {return GetDecomposed().orientation;}
		glm::vec3 GetScaleDecomp() const {return GetDecomposed().scale;}

		void SetDecomposed(const DecomposedMatrix &decomp)
		{
			m_matrix = decomp;
			glm::mat4 test = GetMatrix();
		}


		glm::mat4 GetMatrix() const
		{
			return boost::apply_visitor(MatrixVisitor(), m_matrix);
		}

		void Compose()
		{
			m_matrix = GetMatrix();
		}

		void RightMultiplyCompose(const glm::mat4 &rhs)
		{
			glm::mat4 mat = GetMatrix();
			m_matrix = mat * rhs;
		}

		void LeftMultiplyCompose(const glm::mat4 &lhs)
		{
			glm::mat4 mat = GetMatrix();
			m_matrix = lhs * mat;
		}

		void SetMatrixCompose(const glm::mat4 &matrix)
		{
			m_matrix = matrix;
		}

	private:
		ComposableMatrix m_matrix;

		DecomposedMatrix &GetDecomposed()
		{
			const DecomposedMatrix &ret = (const_cast<const TransformData&>(*this)).GetDecomposed();
			return const_cast<DecomposedMatrix &>(ret);
		}

		const DecomposedMatrix &GetDecomposed() const
		{
			const DecomposedMatrix *pRet = boost::get<const DecomposedMatrix*>(m_matrix);
			if(!pRet)
				throw;
			return *pRet;
		}
	};
}

#endif //GLSDK_INTERNAL_GLSCENE_TRANSFORM_DATA_H
