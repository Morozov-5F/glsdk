
#include <glload/gl_all.h>
#include "glscene/Resources.h"
#include "ResourceData.h"

namespace glscene
{
	std::string ResourceMultiplyDefinedException::GetErrorName(
		const std::string &resource, const std::string &resourceType )
	{
		return std::string("The resource '") + resource + "' is already in use in the '" + resourceType + "' system.";
	}

	std::string ResourceNotFoundException::GetErrorName( const std::string &resource,
		const std::string &resourceType )
	{
		return std::string("The resource '") + resource + "' of type '" + resourceType + "' was not found.";
	}

	std::string UniformResourceTypeMismatchException::GetErrorName( const std::string &resource,
		const std::string &uniformType, const std::string &givenType )
	{
		return std::string("Attempting to set the uniform resource '") + resource +
			"', which is of type '" + uniformType + "', with a type of " + givenType + ".";
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, float data )
	{
		m_pData->DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::vec2 data )
	{
		m_pData->DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::vec3 data )
	{
		m_pData->DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::vec4 data )
	{
		m_pData->DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, int data )
	{
		m_pData->DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::ivec2 data )
	{
		m_pData->DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::ivec3 data )
	{
		m_pData->DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::ivec4 data )
	{
		m_pData->DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, unsigned int data )
	{
		m_pData->DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::uvec2 data )
	{
		m_pData->DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::uvec3 data )
	{
		m_pData->DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::uvec4 data )
	{
		m_pData->DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::mat2 data )
	{
		m_pData->DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::mat3 data )
	{
		m_pData->DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::DefineUniform( const std::string &resource, const std::string &uniformName, glm::mat4 data )
	{
		m_pData->DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, float data )
	{
		m_pData->SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::vec2 data )
	{
		m_pData->SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::vec3 data )
	{
		m_pData->SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::vec4 data )
	{
		m_pData->SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, int data )
	{
		m_pData->SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::ivec2 data )
	{
		m_pData->SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::ivec3 data )
	{
		m_pData->SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::ivec4 data )
	{
		m_pData->SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, unsigned int data )
	{
		m_pData->SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::uvec2 data )
	{
		m_pData->SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::uvec3 data )
	{
		m_pData->SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::uvec4 data )
	{
		m_pData->SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::mat2 data )
	{
		m_pData->SetUniform(resource, MatrixTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::mat3 data )
	{
		m_pData->SetUniform(resource, MatrixTypes(data));
	}

	void Resources::SetUniform( const std::string &resource, glm::mat4 data )
	{
		m_pData->SetUniform(resource, MatrixTypes(data));
	}

	void Resources::DefineTexture( const std::string &resource, GLuint textureObj, GLenum target,
		bool claimOwnership )
	{
		m_pData->DefineTexture(resource, textureObj, target, claimOwnership);
	}
}
