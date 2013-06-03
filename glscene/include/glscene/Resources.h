#ifndef GLSDK_GLGRAPH_RESOURCES_H
#define GLSDK_GLGRAPH_RESOURCES_H

/**
\file
\brief Includes the glscene::Resources class. You must include an OpenGL header
before including this file.

**/

#include <string>
#include <stdexcept>
#include <boost/scoped_ptr.hpp>
#include <boost/utility/string_ref.hpp>
#include <glm/glm.hpp>

namespace glmesh
{
	class Mesh;
}

namespace glscene
{
	class ResourceData;
	///\addtogroup module_glscene_exceptions
	///@{

	///Base class for all resource exceptions.
	class ResourceException : public std::runtime_error
	{
	public:
		explicit ResourceException(const std::string &desc) : std::runtime_error(desc) {}

	private:
	};

	///Thrown by any `Resources::Define*` function if the given resource name has already been used for a resource of that type.
	class ResourceMultiplyDefinedException : public ResourceException
	{
	public:
		explicit ResourceMultiplyDefinedException(const std::string &resource, const std::string &resourceType)
			: ResourceException(GetErrorName(resource, resourceType)) {}

		static std::string GetErrorName(const std::string &resource, const std::string &resourceType);
	};

	///Thrown by any Resources access functions if the given resource name has not been defined for that resource type.
	class ResourceNotFoundException : public ResourceException
	{
	public:
		explicit ResourceNotFoundException(const std::string &resource, const std::string &resourceType)
			: ResourceException(GetErrorName(resource, resourceType)) {}

		static std::string GetErrorName(const std::string &resource, const std::string &resourceType);
	};

	///Thrown by any `Resources::SetUniform` function if the given data doesn't match the type of the input.
	class UniformResourceTypeMismatchException : public ResourceException
	{
	public:
		explicit UniformResourceTypeMismatchException(const std::string &resource,
			const std::string &uniformType, const std::string &givenType)
			: ResourceException(GetErrorName(resource, uniformType, givenType)) {}

		static std::string GetErrorName(const std::string &resource,
			const std::string &uniformType, const std::string &givenType);
	};

	///@}

	///\addtogroup module_glscene_resources
	///@{

	/**
	\brief Used to modify a sampler resource.
	
	**/
	class SamplerResource
	{
	public:

	private:
	};

	/**
	\brief This class represents all of the named resources for a scene graph.
	
	This object uses reference semantics. Every copy of it will refer to the resources from the same
	SceneGraph.

	**/
	class Resources
	{
	public:
		/**
		\name Creates a named uniform with the given type.

		\throws ResourceMultiplyDefinedException If \a resource refers to a uniform resource that has already
		been defined.
		
		\param resource The resource name for the uniform.
		\param uniformName The name of the uniform in GLSL.
		\param data The value to set the uniform to.
		**/
		///@{
		void DefineUniform(const std::string &resource, const std::string &uniformName, float data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::vec2 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::vec3 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::vec4 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, int data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::ivec2 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::ivec3 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::ivec4 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, unsigned int data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::uvec2 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::uvec3 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::uvec4 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::mat2 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::mat3 data);
		void DefineUniform(const std::string &resource, const std::string &uniformName, glm::mat4 data);
		///@}

		/**
		\name Sets the value of an existing uniform.

		\throws ResourceNotFoundException If \a resource is not a uniform resource.
		\throws UniformResourceTypeMismatchException If \a data is not the same type as the original uniform definition.

		\param resource The resource name for the uniform.
		\param data The value to set into the uniform.
		**/
		///@{
		void SetUniform(const std::string &resource, float data);
		void SetUniform(const std::string &resource, glm::vec2 data);
		void SetUniform(const std::string &resource, glm::vec3 data);
		void SetUniform(const std::string &resource, glm::vec4 data);
		void SetUniform(const std::string &resource, int data);
		void SetUniform(const std::string &resource, glm::ivec2 data);
		void SetUniform(const std::string &resource, glm::ivec3 data);
		void SetUniform(const std::string &resource, glm::ivec4 data);
		void SetUniform(const std::string &resource, unsigned int data);
		void SetUniform(const std::string &resource, glm::uvec2 data);
		void SetUniform(const std::string &resource, glm::uvec3 data);
		void SetUniform(const std::string &resource, glm::uvec4 data);
		void SetUniform(const std::string &resource, glm::mat2 data);
		void SetUniform(const std::string &resource, glm::mat3 data);
		void SetUniform(const std::string &resource, glm::mat4 data);
		///@}

		/**
		\brief Creates a named texture resource, which may claim ownership of the texture.
		
		\throws ResourceMultiplyDefinedException If \a resource refers to a texture resource that has already
		been defined.

		**/
		void DefineTexture(const std::string &resource, GLuint textureObj,
			GLenum target, bool claimOwnership = true);

	private:
		ResourceData *m_pData;

		Resources(ResourceData *pData) : m_pData(pData) {}

		friend class SceneGraph;
	};
	///@}
}


#endif //GLSDK_GLGRAPH_RESOURCES_H
