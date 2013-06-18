
#include <glload/gl_all.h>
#include "glscene/ResourceRef.h"
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

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, float data )
	{
		m_data.get().DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec2 data )
	{
		m_data.get().DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec3 data )
	{
		m_data.get().DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec4 data )
	{
		m_data.get().DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, int data )
	{
		m_data.get().DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec2 data )
	{
		m_data.get().DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec3 data )
	{
		m_data.get().DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec4 data )
	{
		m_data.get().DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, unsigned int data )
	{
		m_data.get().DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec2 data )
	{
		m_data.get().DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec3 data )
	{
		m_data.get().DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec4 data )
	{
		m_data.get().DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat2 data )
	{
		m_data.get().DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat3 data )
	{
		m_data.get().DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat4 data )
	{
		m_data.get().DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, float data )
	{
		m_data.get().SetUniform(resource, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::vec2 data )
	{
		m_data.get().SetUniform(resource, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::vec3 data )
	{
		m_data.get().SetUniform(resource, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::vec4 data )
	{
		m_data.get().SetUniform(resource, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, int data )
	{
		m_data.get().SetUniform(resource, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::ivec2 data )
	{
		m_data.get().SetUniform(resource, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::ivec3 data )
	{
		m_data.get().SetUniform(resource, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::ivec4 data )
	{
		m_data.get().SetUniform(resource, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, unsigned int data )
	{
		m_data.get().SetUniform(resource, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::uvec2 data )
	{
		m_data.get().SetUniform(resource, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::uvec3 data )
	{
		m_data.get().SetUniform(resource, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::uvec4 data )
	{
		m_data.get().SetUniform(resource, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::mat2 data )
	{
		m_data.get().SetUniform(resource, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::mat3 data )
	{
		m_data.get().SetUniform(resource, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resource, glm::mat4 data )
	{
		m_data.get().SetUniform(resource, MatrixTypes(data));
	}

	void ResourceRef::DefineTexture( const boost::string_ref &resource, GLuint textureObj, GLenum target,
		bool claimOwnership )
	{
		m_data.get().DefineTexture(resource, textureObj, target, claimOwnership);
	}

	void ResourceRef::DefineTextureIncomplete( const boost::string_ref &resource )
	{
		m_data.get().DefineTextureIncomplete(resource);
	}

	void ResourceRef::DefineSampler( const boost::string_ref &resource, const SamplerInfo &data )
	{
		m_data.get().DefineSampler(resource, data);
	}

	void ResourceRef::SetSamplerLODBias( const boost::string_ref &resource, float bias )
	{
		m_data.get().SetSamplerLODBias(resource, bias);
	}

	void ResourceRef::DefineMesh( const boost::string_ref &resource, glmesh::Mesh *pMesh, bool claimOwnership )
	{
		m_data.get().DefineMesh(resource, pMesh, claimOwnership);
	}

	void ResourceRef::DefineMesh( const boost::string_ref &resource, glscene::Drawable *pMesh, bool claimOwnership /*= true*/ )
	{
		m_data.get().DefineMesh(resource, pMesh, claimOwnership);
	}

	void ResourceRef::DefineMeshIncomplete( const boost::string_ref &resource )
	{
		m_data.get().DefineMeshIncomplete(resource);
	}

	void ResourceRef::DefineProgram( const boost::string_ref &resource, GLuint program, const ProgramInfo &programInfo,
		bool claimOwnership )
	{
		m_data.get().DefineProgram(resource, program, programInfo, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.get().DefineUniformBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.get().DefineUniformBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBindingIncomplete( const boost::string_ref &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_data.get().DefineUniformBufferBindingIncomplete(resource, bindPoint, size);
	}

	void ResourceRef::DefineStorageBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.get().DefineStorageBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void ResourceRef::DefineStorageBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.get().DefineStorageBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void ResourceRef::DefineStorageBufferBindingIncomplete( const boost::string_ref &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_data.get().DefineStorageBufferBindingIncomplete(resource, bindPoint, size);
	}

	void ResourceRef::DefineCamera( const boost::string_ref &resource, const glutil::ViewData &initialView,
		const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls )
	{
		m_data.get().DefineCamera(resource, initialView, viewScale, actionButton, bRightKeyboardCtrls);
	}
}
