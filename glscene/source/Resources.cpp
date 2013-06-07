
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

	SamplerInfo::SamplerInfo()
		: magFilter(GL_NEAREST)
		, minFilter(GL_NEAREST)
		, maxAniso(1.0f)
		, compareFunc(boost::none)
		, edgeFilterS(GL_CLAMP_TO_EDGE)
		, edgeFilterT(GL_CLAMP_TO_EDGE)
		, edgeFilterR(GL_CLAMP_TO_EDGE)
	{}

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

	void Resources::DefineTextureIncomplete( const std::string &resource )
	{
		m_pData->DefineTextureIncomplete(resource);
	}

	void Resources::DefineSampler( const std::string &resource, const SamplerInfo &data )
	{
		m_pData->DefineSampler(resource, data);
	}

	void Resources::SetSamplerLODBias( const std::string &resource, float bias )
	{
		m_pData->SetSamplerLODBias(resource, bias);
	}

	void Resources::DefineMesh( const std::string &resource, glmesh::Mesh *pMesh, bool claimOwnership )
	{
		m_pData->DefineMesh(resource, pMesh, claimOwnership);
	}

	void Resources::DefineMeshIncomplete( const std::string &resource )
	{
		m_pData->DefineMeshIncomplete(resource);
	}

	void Resources::DefineProgram( const std::string &resource, GLuint program, const ProgramInfo &programInfo,
		bool claimOwnership )
	{
		m_pData->DefineProgram(resource, program, programInfo, claimOwnership);
	}

	void Resources::DefineUniformBufferBinding( const std::string &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_pData->DefineUniformBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void Resources::DefineUniformBufferBinding( const std::string &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_pData->DefineUniformBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void Resources::DefineUniformBufferBindingIncomplete( const std::string &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_pData->DefineUniformBufferBindingIncomplete(resource, bindPoint, size);
	}

	void Resources::DefineStorageBufferBinding( const std::string &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_pData->DefineStorageBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void Resources::DefineStorageBufferBinding( const std::string &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_pData->DefineStorageBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void Resources::DefineStorageBufferBindingIncomplete( const std::string &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_pData->DefineStorageBufferBindingIncomplete(resource, bindPoint, size);
	}

	void Resources::DefineCamera( const std::string &resource, const glutil::ViewData &initialView,
		const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls )
	{
		m_pData->DefineCamera(resource, initialView, viewScale, actionButton, bRightKeyboardCtrls);
	}
}
