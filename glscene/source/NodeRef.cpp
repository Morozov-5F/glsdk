
#include "pch.h"

#include "glscene/NodeRef.h"
#include <glload/gl_all.hpp>
#include "NodeData.h"
#include <boost/lexical_cast.hpp>

namespace glscene
{
	std::string StyleMultiplyDefinedException::GetErrorName( const std::string &styleName )
	{
		return "The style '" + styleName + "' is already defined on this node.";
	}

	std::string StyleMultipleBindingsException::GetErrorString( const std::string &resourceId,
		const std::string &resourceType, unsigned int bindingIndex )
	{
		return "A style tried to set the resource '" + resourceId + "' of type '"
			+ resourceType + "' to the same binding index " + boost::lexical_cast<std::string>(bindingIndex)
			+ " as another resource on the same style.";
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


	TransformData &GetNodeTM(NodeData &data)
	{
		return data.GetNodeTM();
	}

	const TransformData &GetNodeTM(const NodeData &data)
	{
		return data.GetNodeTM();
	}

	TransformData &GetObjectTM(NodeData &data)
	{
		return data.GetObjectTM();
	}

	const TransformData &GetObjectTM(const NodeData &data)
	{
		return data.GetObjectTM();
	}

	void AddToLayer( NodeData &data, int layerIx )
	{
		data.AddToLayer(layerIx);
	}

	void RemoveFromLayer( NodeData &data, int layerIx )
	{
		data.RemoveFromLayer(layerIx);
	}

	bool IsInLayer( const NodeData &data, int layerIx )
	{
		return data.IsInLayer(layerIx);
	}

	boost::string_ref GetName(const NodeData &data)
	{
		return data.GetName();
	}

	NodeData *GetParent(NodeData &data)
	{
		return data.GetParent();
	}

	const NodeData *GetParent( const NodeData &data )
	{
		return data.GetParent();
	}

	void MakeChildOfNode(NodeData &data, NodeData &newParent)
	{
		if(&data == &newParent)
			throw CannotMakeParentOfSelfException();

		data.MakeChildOfNode(newParent);
	}
}
