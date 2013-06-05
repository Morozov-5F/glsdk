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
#include <boost/optional.hpp>
#include <boost/container/flat_map.hpp>
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

	private:
		static std::string GetErrorName(const std::string &resource, const std::string &resourceType);
	};

	///Thrown by any Resources access functions if the given resource name has not been defined for that resource type.
	class ResourceNotFoundException : public ResourceException
	{
	public:
		explicit ResourceNotFoundException(const std::string &resource, const std::string &resourceType)
			: ResourceException(GetErrorName(resource, resourceType)) {}

	private:
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
	\brief Used to define a sampler resource.
	
	**/
	struct SamplerInfo
	{
	public:
		GLenum magFilter;
		GLenum minFilter;
		float maxAniso;
		boost::optional<GLenum> compareFunc;

		GLenum edgeFilterS;
		GLenum edgeFilterT;
		GLenum edgeFilterR;

		SamplerInfo();
	};

	///Mapping between GLSL variable names and binding indices.
	typedef boost::container::flat_map<std::string, GLint> BindingLocationMap;

	/**
	\brief Used to define data for a program.
	
	**/
	struct ProgramInfo
	{
	public:
		BindingLocationMap samplerBindings;			///<Binding locations for [sampler types](http://www.opengl.org/wiki/Sampler_%28GLSL%29).
		BindingLocationMap imageBindings;			///<Binding locations for [image types](http://www.opengl.org/wiki/Image_Load_Store).
		BindingLocationMap uniformBlockBindings;	///<Binding locations for [uniform blocks](http://www.opengl.org/wiki/Uniform_Buffer_Object).
		BindingLocationMap bufferVariableBindings;	///<Binding locations for [buffer variables](http://www.opengl.org/wiki/Shader_Storage_Buffer_Object).

		std::string modelToCameraMatrixUniformName;
		boost::optional<std::string> normalModelToCameraMatrixUniformName;
		boost::optional<std::string> normalCameraToModelMatrixUniformName;
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
		been defined with texture data. If it was defined with void DefineTexture(const std::string &), then it
		can be redefined with an actual texture.

		\param resource The resource name for the texture.
		\param textureObj The texture object to be stored.
		\param target The target the texture is associated with.
		\param claimOwnership Set to `true` if you want the scene graph to delete the texture.
		**/
		void DefineTexture(const std::string &resource, GLuint textureObj,
			GLenum target, bool claimOwnership = true);

		/**
		\brief Creates a named texture, which will be filled in with actual data later.
		
		\throws ResourceMultiplyDefinedException If \a resource refers to a texture resource that has already
		been defined.

		\param resource The resource name for the texture.
		**/
		void DefineTexture(const std::string &resource);

		/**
		\brief Creates a named sampler resource.
		
		\throws ResourceMultiplyDefinedException If \a resource refers to a sampler resource that has already
		been defined.

		\param resource The resource name for the sampler.
		\param data The information about the sampler parameters. These parameters are immutable.
		**/
		void DefineSampler(const std::string &resource, const SamplerInfo &data);

		/**
		\brief Sets a floating-point border color for a sampler.

		\throws ResourceNotFoundException If \a resource is not a sampler resource.

		\param resource The resource name for the sampler.
		\param color The color to set the border color to.
		**/
		void SetSamplerBorderColor(const std::string &resource, const glm::vec4 &color);

		/**
		\brief Sets an integer border color for a sampler.

		\throws ResourceNotFoundException If \a resource is not a sampler resource.

		\param resource The resource name for the sampler.
		\param color The color to set the border color to.
		**/
		void SetSamplerBorderColorI(const std::string &resource, const glm::ivec4 &color);

		/**
		\brief Sets an integer border color for a sampler.

		\throws ResourceNotFoundException If \a resource is not a sampler resource.

		\param resource The resource name for the sampler.
		\param color The color to set the border color to.
		**/
		void SetSamplerBorderColorI(const std::string &resource, const glm::uvec4 &color);

		/**
		\brief Sets the LOD bias for a sampler
		
		\throws ResourceNotFoundException If \a resource is not a sampler resource.

		\param resource The resource name for the sampler.
		\param bias The LOD bias for the sampler.
		**/
		void SetSamplerLODBias(const std::string &resource, float bias);

		/**
		\brief Creates a named mesh, which may claim ownership of the mesh.
		
		\throws ResourceMultiplyDefinedException If \a resource refers to a mesh resource that has already
		been defined with mesh data. If it was defined with void DefineMesh(const std::string &), then it
		can be redefined with an actual mesh.

		\param resource The resource name for the mesh.
		\param pMesh The mesh object to be stored.
		\param claimOwnership Set to `true` if you want the scene graph to delete the mesh.
		**/
		void DefineMesh(const std::string &resource, glmesh::Mesh *pMesh, bool claimOwnership = true);

		/**
		\brief Creates a named mesh, which will be filled in with actual data later.
		
		\throws ResourceMultiplyDefinedException If \a resource refers to a mesh resource that has already
		been defined.

		\param resource The resource name for the mesh.
		**/
		void DefineMesh(const std::string &resource);

		/**
		\brief 
		

		This function will modify the following OpenGL state:

		* sets the current program (as defined by glUseProgram) to 0. It will not modify the current program.
		**/
		void DefineProgram(const std::string &resource, GLuint program, const ProgramInfo &programInfo,
			bool claimOwnership = true);


	private:
		ResourceData *m_pData;

		Resources(ResourceData *pData) : m_pData(pData) {}

		friend class SceneGraph;
	};
	///@}
}


#endif //GLSDK_GLGRAPH_RESOURCES_H
