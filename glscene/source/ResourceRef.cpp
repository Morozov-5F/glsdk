
#include "pch.h"
#include <glload/gl_all.hpp>
#include "glscene/ResourceRef.h"
#include "ResourceData.h"

namespace glscene
{
	std::string ResourceMultiplyDefinedException::GetErrorName(
		const std::string &resourceId, const std::string &resourceType )
	{
		return std::string("The resourceId '") + resourceId + "' is already in use in the '" + resourceType + "' system.";
	}

	std::string ResourceNotFoundException::GetErrorName( const std::string &resourceId,
		const std::string &resourceType )
	{
		return std::string("The resourceId '") + resourceId + "' of type '" + resourceType + "' was not found.";
	}

	std::string UniformResourceTypeMismatchException::GetErrorName( const std::string &resourceId,
		const std::string &uniformType, const std::string &givenType )
	{
		return std::string("Attempting to set the uniform resourceId '") + resourceId +
			"', which is of type '" + uniformType + "', with a type of " + givenType + ".";
	}

	SamplerInfo::SamplerInfo()
		: magFilter(gl::NEAREST)
		, minFilter(gl::NEAREST)
		, maxAniso(1.0f)
		, compareFunc(boost::none)
		, edgeFilterS(gl::CLAMP_TO_EDGE)
		, edgeFilterT(gl::CLAMP_TO_EDGE)
		, edgeFilterR(gl::CLAMP_TO_EDGE)
	{}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, float data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::vec2 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::vec3 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::vec4 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, VectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, int data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec2 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec3 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec4 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, IntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, unsigned int data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec2 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec3 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec4 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, UIntVectorTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::mat2 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, MatrixTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::mat3 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, MatrixTypes(data));
	}

	void ResourceRef::DefineUniform( const boost::string_ref &resourceId, const std::string &uniformName, glm::mat4 data )
	{
		m_data.get().DefineUniform(resourceId, uniformName, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, float data )
	{
		m_data.get().SetUniform(resourceId, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::vec2 data )
	{
		m_data.get().SetUniform(resourceId, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::vec3 data )
	{
		m_data.get().SetUniform(resourceId, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::vec4 data )
	{
		m_data.get().SetUniform(resourceId, VectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, int data )
	{
		m_data.get().SetUniform(resourceId, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::ivec2 data )
	{
		m_data.get().SetUniform(resourceId, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::ivec3 data )
	{
		m_data.get().SetUniform(resourceId, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::ivec4 data )
	{
		m_data.get().SetUniform(resourceId, IntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, unsigned int data )
	{
		m_data.get().SetUniform(resourceId, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::uvec2 data )
	{
		m_data.get().SetUniform(resourceId, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::uvec3 data )
	{
		m_data.get().SetUniform(resourceId, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::uvec4 data )
	{
		m_data.get().SetUniform(resourceId, UIntVectorTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::mat2 data )
	{
		m_data.get().SetUniform(resourceId, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::mat3 data )
	{
		m_data.get().SetUniform(resourceId, MatrixTypes(data));
	}

	void ResourceRef::SetUniform( const boost::string_ref &resourceId, glm::mat4 data )
	{
		m_data.get().SetUniform(resourceId, MatrixTypes(data));
	}

	void ResourceRef::DefineTexture( const boost::string_ref &resourceId, GLuint textureObj, GLenum target,
		bool claimOwnership )
	{
		m_data.get().DefineTexture(resourceId, textureObj, target, claimOwnership);
	}

	void ResourceRef::DefineTextureIncomplete( const boost::string_ref &resourceId )
	{
		m_data.get().DefineTextureIncomplete(resourceId);
	}

	void ResourceRef::DefineSampler( const boost::string_ref &resourceId, const SamplerInfo &data )
	{
		m_data.get().DefineSampler(resourceId, data);
	}

	void ResourceRef::SetSamplerLODBias( const boost::string_ref &resourceId, float bias )
	{
		m_data.get().SetSamplerLODBias(resourceId, bias);
	}

	void ResourceRef::DefineMesh( const boost::string_ref &resourceId, glmesh::Mesh *pMesh, bool claimOwnership )
	{
		m_data.get().DefineMesh(resourceId, pMesh, claimOwnership);
	}

	void ResourceRef::DefineMesh( const boost::string_ref &resourceId, glscene::Drawable *pMesh, bool claimOwnership /*= true*/ )
	{
		m_data.get().DefineMesh(resourceId, pMesh, claimOwnership);
	}

	void ResourceRef::DefineMeshIncomplete( const boost::string_ref &resourceId )
	{
		m_data.get().DefineMeshIncomplete(resourceId);
	}

	void ResourceRef::DefineProgram( const boost::string_ref &resourceId, GLuint program, const ProgramInfo &programInfo,
		bool claimOwnership )
	{
		m_data.get().DefineProgram(resourceId, program, programInfo, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
		GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.get().DefineUniformBufferBinding(resourceId, bufferObject, offset, size, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.get().DefineUniformBufferBinding(resourceId, bufferObject, offset, claimOwnership);
	}

	void ResourceRef::DefineUniformBufferBindingIncomplete( const boost::string_ref &resourceId,
		GLsizeiptr size )
	{
		m_data.get().DefineUniformBufferBindingIncomplete(resourceId, size);
	}

	void ResourceRef::DefineStorageBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
		GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		m_data.get().DefineStorageBufferBinding(resourceId, bufferObject, offset, size, claimOwnership);
	}

	void ResourceRef::DefineStorageBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		m_data.get().DefineStorageBufferBinding(resourceId, bufferObject, offset, claimOwnership);
	}

	void ResourceRef::DefineStorageBufferBindingIncomplete( const boost::string_ref &resourceId,
		GLsizeiptr size )
	{
		m_data.get().DefineStorageBufferBindingIncomplete(resourceId, size);
	}

	void ResourceRef::DefineCamera( const boost::string_ref &resourceId, const glutil::ViewData &initialView,
		const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls )
	{
		m_data.get().DefineCamera(resourceId, initialView, viewScale, actionButton, bRightKeyboardCtrls);
	}

	glutil::ViewPole & ResourceRef::GetCamera( const boost::string_ref &resourceId )
	{
		return m_data.get().GetCamera(resourceId);
	}
}
