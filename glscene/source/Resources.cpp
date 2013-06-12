
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

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, float data )
	{
		m_data.DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec2 data )
	{
		m_data.DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec3 data )
	{
		m_data.DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::vec4 data )
	{
		m_data.DefineUniform(resource, uniformName, VectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, int data )
	{
		m_data.DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec2 data )
	{
		m_data.DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec3 data )
	{
		m_data.DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::ivec4 data )
	{
		m_data.DefineUniform(resource, uniformName, IntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, unsigned int data )
	{
		m_data.DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec2 data )
	{
		m_data.DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec3 data )
	{
		m_data.DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::uvec4 data )
	{
		m_data.DefineUniform(resource, uniformName, UIntVectorTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat2 data )
	{
		m_data.DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat3 data )
	{
		m_data.DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::DefineUniform( const boost::string_ref &resource, const std::string &uniformName, glm::mat4 data )
	{
		m_data.DefineUniform(resource, uniformName, MatrixTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, float data )
	{
		m_data.SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::vec2 data )
	{
		m_data.SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::vec3 data )
	{
		m_data.SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::vec4 data )
	{
		m_data.SetUniform(resource, VectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, int data )
	{
		m_data.SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::ivec2 data )
	{
		m_data.SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::ivec3 data )
	{
		m_data.SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::ivec4 data )
	{
		m_data.SetUniform(resource, IntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, unsigned int data )
	{
		m_data.SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::uvec2 data )
	{
		m_data.SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::uvec3 data )
	{
		m_data.SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::uvec4 data )
	{
		m_data.SetUniform(resource, UIntVectorTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::mat2 data )
	{
		m_data.SetUniform(resource, MatrixTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::mat3 data )
	{
		m_data.SetUniform(resource, MatrixTypes(data));
	}

	void Resources::SetUniform( const boost::string_ref &resource, glm::mat4 data )
	{
		m_data.SetUniform(resource, MatrixTypes(data));
	}

	void Resources::DefineTexture( const boost::string_ref &resource, GLuint textureObj, GLenum target,
		bool claimOwnership )
	{
		m_data.DefineTexture(resource, textureObj, target, claimOwnership);
	}

	void Resources::DefineTextureIncomplete( const boost::string_ref &resource )
	{
		m_data.DefineTextureIncomplete(resource);
	}

	void Resources::DefineSampler( const boost::string_ref &resource, const SamplerInfo &data )
	{
		m_data.DefineSampler(resource, data);
	}

	void Resources::SetSamplerLODBias( const boost::string_ref &resource, float bias )
	{
		m_data.SetSamplerLODBias(resource, bias);
	}

	void Resources::DefineMesh( const boost::string_ref &resource, glmesh::Mesh *pMesh, bool claimOwnership )
	{
		//Manager will delete, but MeshDrawable will decide to delete the mesh itself.
		m_data.DefineMesh(resource, new MeshDrawable(pMesh, claimOwnership), true);
	}

	void Resources::DefineMesh( const boost::string_ref &resource, glscene::Drawable *pMesh, bool claimOwnership /*= true*/ )
	{
		m_data.DefineMesh(resource, pMesh, claimOwnership);
	}

	void Resources::DefineMeshIncomplete( const boost::string_ref &resource )
	{
		m_data.DefineMeshIncomplete(resource);
	}

	void Resources::DefineProgram( const boost::string_ref &resource, GLuint program, const ProgramInfo &programInfo,
		bool claimOwnership )
	{
		m_data.DefineProgram(resource, program, programInfo, claimOwnership);
	}

	void Resources::DefineUniformBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.DefineUniformBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void Resources::DefineUniformBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.DefineUniformBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void Resources::DefineUniformBufferBindingIncomplete( const boost::string_ref &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_data.DefineUniformBufferBindingIncomplete(resource, bindPoint, size);
	}

	void Resources::DefineStorageBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.DefineStorageBufferBinding(resource, bufferObject, bindPoint, offset, size, claimOwnership);
	}

	void Resources::DefineStorageBufferBinding( const boost::string_ref &resource, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.DefineStorageBufferBinding(resource, bufferObject, offset, claimOwnership);
	}

	void Resources::DefineStorageBufferBindingIncomplete( const boost::string_ref &resource, GLuint bindPoint,
		GLsizeiptr size )
	{
		m_data.DefineStorageBufferBindingIncomplete(resource, bindPoint, size);
	}

	void Resources::DefineCamera( const boost::string_ref &resource, const glutil::ViewData &initialView,
		const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls )
	{
		m_data.DefineCamera(resource, initialView, viewScale, actionButton, bRightKeyboardCtrls);
	}
}
