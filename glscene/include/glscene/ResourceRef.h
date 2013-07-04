#ifndef GLSDK_GLSCENE_RESOURCE_REF_H
#define GLSDK_GLSCENE_RESOURCE_REF_H

/**
\file
\brief Includes the glscene::ResourceRef class. You must include a [GL Load header](@ref module_glload)
before including this file.
**/

#include <string>
#include <stdexcept>
#include <boost/scoped_ptr.hpp>
#include <boost/utility/string_ref.hpp>
#include <boost/optional.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/ref.hpp>
#include <glm/glm.hpp>
#include <glutil/MousePoles.h>

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

	///Thrown by any `ResourceRef::Define*` function if the given resource name has already been used for a resource of that type.
	class ResourceMultiplyDefinedException : public ResourceException
	{
	public:
		explicit ResourceMultiplyDefinedException(const std::string &resourceId, const std::string &resourceType)
			: ResourceException(GetErrorName(resourceId, resourceType)) {}

	private:
		static std::string GetErrorName(const std::string &resourceId, const std::string &resourceType);
	};

	///Thrown by any ResourceRef access functions if the given resource name has not been defined for that resource type.
	class ResourceNotFoundException : public ResourceException
	{
	public:
		explicit ResourceNotFoundException(const std::string &resourceId, const std::string &resourceType)
			: ResourceException(GetErrorName(resourceId, resourceType)) {}

	private:
		static std::string GetErrorName(const std::string &resourceId, const std::string &resourceType);
	};

	///Thrown by any `ResourceRef::SetUniform` function if the given data doesn't match the type of the input.
	class UniformResourceTypeMismatchException : public ResourceException
	{
	public:
		explicit UniformResourceTypeMismatchException(const std::string &resourceId,
			const std::string &uniformType, const std::string &givenType)
			: ResourceException(GetErrorName(resourceId, uniformType, givenType)) {}

	private:
		static std::string GetErrorName(const std::string &resourceId,
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
		GLenum magFilter;		///<The `GL_TEXTURE_MAG_FILTER` parameter. Defaults to `GL_NEAREST`.
		GLenum minFilter;		///<The `GL_TEXTURE_MIN_FILTER` parameter. Defaults to `GL_NEAREST`.
		float maxAniso;			///<The maximum anisotropy. Defaults to 1.0f.
		boost::optional<GLenum> compareFunc;	///<The `GL_TEXTURE_COMPARE_FUNC` parameter. If not present, then there is no depth comparison.

		GLenum edgeFilterS;		///<The `GL_TEXTURE_WRAP_S` parameter. Defaults to `GL_CLAMP_TO_EDGE`.
		GLenum edgeFilterT;		///<The `GL_TEXTURE_WRAP_T` parameter. Defaults to `GL_CLAMP_TO_EDGE`.
		GLenum edgeFilterR;		///<The `GL_TEXTURE_WRAP_R` parameter. Defaults to `GL_CLAMP_TO_EDGE`.

		SamplerInfo();			///<Creates a default sampler-info.
	};

	/**
	\brief Base class for user-provided drawable objects.

	This class provides a hook for the user to define their own meshes and provide them as resources. A
	Drawable only needs to be able to render the mesh.

	The Drawable you provide will be destroyed only if you told the ResourceRef object to claim ownership of it.
	This destruction will be managed by calling the Dispose function; `delete` will not be called directly.
	This allows you to manage the memory for Drawable objects in your own way, such as by pool allocators
	and the like.
	**/
	class Drawable
	{
	public:
		/**
		\brief Performs rendering.

		This function will be called after all state setup has been done. All textures have been bound,
		all buffers and the like that are part of the scene graph have been bound to the
		context. This class simply needs to set
		[vertex specification](http://www.opengl.org/wiki/Vertex_Specification) state (perhaps with a VAO bind)
		and issue some number of rendering commands.
		
		While this cannot be enforced, this class is expected to:

		- Restrict its OpenGL state modifications to *only*
		[vertex specification](http://www.opengl.org/wiki/Vertex_Specification) and
		[vertex rendering](http://www.opengl.org/wiki/Vertex_Rendering) state. No uniform setting and such.
		- Make no assumptions about the current contents of vertex specification or rendering state. For example,
		if you need attribute X, you enable that attribute.
		- Reset this state upon being finished. If you used primitive restarting in your rendering, turn it off.

		\note Do not attempt to modify anything within the scene graph system when this function is called. So
		if you have access to a non `const` ResourceRef object, a NodeRef, or whatever, do not call non `const`
		functions on it.

		\param param An arbitrary string passed by the system. For glmesh::Mesh objects, it's the mesh variant
		name.
		**/
		virtual void Draw(const boost::optional<std::string> &param) const = 0;

		virtual ~Drawable() {}

	private:
		/**
		\brief Destroys this object. 
		
		Override this function only if your Drawable-derived class has special memory management needs
		that prevent `delete` from being called on them.
		**/
		virtual void Dispose() {delete this;}

		friend class ResourceData;
	};

	///Mapping between GLSL variable names and binding indices.
	typedef boost::container::flat_map<std::string, GLint> BindingLocationMap;

	/**
	\brief Used to define bindings and uniform data for a program.
	
	**/
	struct ProgramInfo
	{
	public:
		BindingLocationMap samplerBindings;			///<Binding locations for [sampler types](http://www.opengl.org/wiki/Sampler_%28GLSL%29).
		BindingLocationMap imageBindings;			///<Binding locations for [image types](http://www.opengl.org/wiki/Image_Load_Store).
		BindingLocationMap uniformBlockBindings;	///<Binding locations for [uniform blocks](http://www.opengl.org/wiki/Uniform_Buffer_Object).
		BindingLocationMap bufferVariableBindings;	///<Binding locations for [buffer variables](http://www.opengl.org/wiki/Shader_Storage_Buffer_Object).

		boost::optional<std::string> modelToCameraMatrixUniformName;			///<The name of the shader's `mat4` model-to-camera transformation matrix uniform.
		boost::optional<std::string> normalModelToCameraMatrixUniformName;		///<The name of the shader's `mat3` model-to-camera transformation matrix uniform.
		boost::optional<std::string> normalCameraToModelMatrixUniformName;		///<The name of the shader's `mat3` camera-to-model transformation matrix uniform.
	};

	/**
	\brief This class represents all of the named resources for a scene graph.
	
	This object uses reference semantics. Every copy of it will refer to the resources from the same
	SceneGraph.

	Some resources have "ownership" semantics: the scene graph takes ownership of some OpenGL object. This mean
	that the SceneGraph will destroy the OpenGL object. Resource types that claim ownership of objects only do
	so conditionally; they will provide a \a claimOwnership parameter. If you don't want them to own the object,
	then pass `false` to this parameter and the scene graph will not destroy the object.

	Certain resources can be provided without giving the OpenGL object immediately. This allows for multi-stage
	loading of resources. For example, a texture resource can be named without providing an actual texture yet.
	This allows a file format to specify a resource, which SceneGraph nodes can reference. The reason to do this
	is to be able to create a texture manually, instead of from a file. SceneGraph nodes in the file can 
	reference the incomplete resource, then after loading, the user can fill in the missing information.

	All incomplete resources being used must be fulled specified before rendering. All of the incomplete resource
	definition functions are of the form `Define*Incomplete`. To fully specify the missing data, use the
	`Define*` version with the name previously used with `Define*Incomplete`.

	With the exception of a single call to complete incomplete resources, named resources can only be defined
	once. If you attempt to define a resource with the same name again, the call will throw a
	ResourceMultiplyDefinedException exception.

	Most resources have data that is fixed at definition time. Some resources however allow the user to modify their
	contents later. Specifically, the modifiable resources are sampler resources and uniform resources. Camera
	resources are technically modifiable, but only by accessing the camera object directly through the
	SceneGraph's API.
	**/
	class ResourceRef
	{
	public:
		/**
		\name Creates a named uniform with the given type.
		
		\param resourceId The resource name for the uniform.
		\param uniformName The name of the uniform in GLSL.
		\param data The value to set the uniform to.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a uniform resource that has already
		been defined.
		**/
		///@{
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, float data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::vec2 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::vec3 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::vec4 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, int data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec2 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec3 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::ivec4 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, unsigned int data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec2 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec3 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::uvec4 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::mat2 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::mat3 data);
		void DefineUniform(const boost::string_ref &resourceId, const std::string &uniformName, glm::mat4 data);
		///@}

		/**
		\name Sets the value of an existing uniform.

		\param resourceId The resource name for the uniform.
		\param data The value to set into the uniform.

		\throws ResourceNotFoundException If \a resourceId is not a uniform resource.
		\throws UniformResourceTypeMismatchException If \a data is not the same type as the original uniform definition.
		**/
		///@{
		void SetUniform(const boost::string_ref &resourceId, float data);
		void SetUniform(const boost::string_ref &resourceId, glm::vec2 data);
		void SetUniform(const boost::string_ref &resourceId, glm::vec3 data);
		void SetUniform(const boost::string_ref &resourceId, glm::vec4 data);
		void SetUniform(const boost::string_ref &resourceId, int data);
		void SetUniform(const boost::string_ref &resourceId, glm::ivec2 data);
		void SetUniform(const boost::string_ref &resourceId, glm::ivec3 data);
		void SetUniform(const boost::string_ref &resourceId, glm::ivec4 data);
		void SetUniform(const boost::string_ref &resourceId, unsigned int data);
		void SetUniform(const boost::string_ref &resourceId, glm::uvec2 data);
		void SetUniform(const boost::string_ref &resourceId, glm::uvec3 data);
		void SetUniform(const boost::string_ref &resourceId, glm::uvec4 data);
		void SetUniform(const boost::string_ref &resourceId, glm::mat2 data);
		void SetUniform(const boost::string_ref &resourceId, glm::mat3 data);
		void SetUniform(const boost::string_ref &resourceId, glm::mat4 data);
		///@}

		/**
		\brief Creates a named texture resource, which may claim ownership of the texture.

		\param resourceId The resource name for the texture.
		\param textureObj The texture object to be stored.
		\param target The target the texture is associated with.
		\param claimOwnership Set to `true` if you want the scene graph to delete the texture.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a texture resource that has already
		been defined with texture data. If it was defined with DefineTextureIncomplete, then this exception
		will not be thrown.
		**/
		void DefineTexture(const boost::string_ref &resourceId, GLuint textureObj,
			GLenum target, bool claimOwnership = true);

		/**
		\brief Creates an incomplete named texture resource.

		\param resourceId The resource name for the texture.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a texture resource that has already
		been defined.
		**/
		void DefineTextureIncomplete(const boost::string_ref &resourceId);

		/**
		\brief Creates a named sampler resource.
		
		\throws ResourceMultiplyDefinedException If \a resourceId refers to a sampler resource that has already
		been defined.

		\param resourceId The resource name for the sampler.
		\param data The information about the sampler parameters. These parameters are immutable.
		**/
		void DefineSampler(const boost::string_ref &resourceId, const SamplerInfo &data);

		/**
		\brief Sets a floating-point border color for a sampler.

		\param resourceId The resource name for the sampler.
		\param color The color to set the border color to.

		\throws ResourceNotFoundException If \a resourceId is not a sampler resource.
		**/
		void SetSamplerBorderColor(const boost::string_ref &resourceId, const glm::vec4 &color);

		/**
		\brief Sets an integer border color for a sampler.

		\param resourceId The resource name for the sampler.
		\param color The color to set the border color to.

		\throws ResourceNotFoundException If \a resourceId is not a sampler resource.
		**/
		void SetSamplerBorderColorI(const boost::string_ref &resourceId, const glm::ivec4 &color);

		/**
		\brief Sets an integer border color for a sampler.

		\param resourceId The resource name for the sampler.
		\param color The color to set the border color to.

		\throws ResourceNotFoundException If \a resourceId is not a sampler resource.
		**/
		void SetSamplerBorderColorI(const boost::string_ref &resourceId, const glm::uvec4 &color);

		/**
		\brief Sets the LOD bias for a sampler

		\param resourceId The resource name for the sampler.
		\param bias The LOD bias for the sampler.

		\throws ResourceNotFoundException If \a resourceId is not a sampler resource.
		**/
		void SetSamplerLODBias(const boost::string_ref &resourceId, float bias);

		/**
		\brief Creates a named mesh, which may claim ownership of the mesh.
		
		\param resourceId The resource name for the mesh.
		\param pMesh The mesh object to be stored.
		\param claimOwnership Set to `true` if you want the scene graph to delete the mesh.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a mesh resource that has already
		been defined with mesh data. If it was previously defined with DefineMeshIncomplete, then this exception
		will not be thrown.
		**/
		void DefineMesh(const boost::string_ref &resourceId, glmesh::Mesh *pMesh, bool claimOwnership = true);

		/**
		\brief Creates a named, user-defined mesh, which may claim ownership of the mesh.
		
		\param resourceId The resource name for the mesh.
		\param pMesh The mesh object to be stored.
		\param claimOwnership Set to `true` if you want the scene graph to delete the mesh.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a mesh resource that has already
		been defined with mesh data. If it was previously defined with DefineMeshIncomplete, then this exception
		will not be thrown.
		**/
		void DefineMesh(const boost::string_ref &resourceId, glscene::Drawable *pMesh, bool claimOwnership = true);

		/**
		\brief Creates a named mesh, which will be filled in with actual data later.
		
		\throws ResourceMultiplyDefinedException If \a resourceId refers to a mesh resource that has already
		been defined.

		\param resourceId The resource name for the mesh.
		**/
		void DefineMeshIncomplete(const boost::string_ref &resourceId);

		/**
		\brief Creates a named program object resource.

		Program resources are OpenGL program objects, but they are more than that. They can also set various
		important state on a program, such as sampler/image unit locations, buffer binding points, and the like.
		
		Because the scene graph computes the full transform for a node, the scene graph needs a way to communicate
		this transform to the node. As such, programs can specify a number of uniform matrices that the
		scene graph will fill in when rendering a mesh with this program.

		The program object can be separable.

		This function will modify the following OpenGL state:

		- sets the current program (as defined by glUseProgram) to 0. It will not modify the current program, but
		it may modify the given program's state.

		\param resourceId The resource name for the program.
		\param program The fully linked (possibly separable) program to store in the resource.
		\param programInfo Information about \a program.
		\param claimOwnership Set to `true` if you want the scene graph to delete the program.
		**/
		void DefineProgram(const boost::string_ref &resourceId, GLuint program, const ProgramInfo &programInfo,
			bool claimOwnership = true);

		/**
		\brief Creates a named uniform buffer binding resource.

		A [uniform buffer binding][1] is a region of a buffer object that needs to be bound to a location in the
		context. It effectively encapsulates a [glBindBufferRange(GL_UNIFORM_BUFFER)][2]
		call.

		\param resourceId The resource name of the uniform buffer binding.
		\param bufferObject The OpenGL buffer object.
		\param bindPoint The index to bind to. Must be less than `GL_MAX_UNIFORM_BUFFER_BINDINGS`.
		\param offset The offset from the start of the buffer for the bind call. The offset must be
		a multiple of `GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT`
		\param size The size of the range to bind.
		\param claimOwnership Set to `true` if you want the scene graph to delete the buffer.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a uniform buffer resource that has
		already been defined. This will still be thrown if you used DefineUniformBufferBindingIncomplete
		to partially define the resource. In that case, you must use the other overload of this function.

		[1]: http://www.opengl.org/wiki/Uniform_Buffer_Object
		[2]: http://www.opengl.org/wiki/GLAPI/glBindBufferRange
		**/
		void DefineUniformBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
			GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership );

		/**
		\brief Completes the creation of a named uniform buffer that was started with DefineUniformBufferBindingIncomplete.

		This call defines the buffer object and offset for a uniform buffer resource that was 
		incompletely defined with DefineUniformBufferBindingIncomplete. The bind point and range size
		will remain the same; only the buffer object and the starting offset can be modified with this function.

		\param resourceId The resource name of the uniform buffer binding.
		\param bufferObject The OpenGL buffer object.
		\param offset The offset from the start of the buffer for the bind call. The offset must be
		a multiple of `GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT`
		\param claimOwnership Set to `true` if you want the scene graph to delete the buffer.

		\throws ResourceNotFoundException If \a resourceId does not refer to an existing uniform buffer
		resource.
		\throws ResourceMultiplyDefinedException If \a resourceId refers to an existing uniform buffer
		resource that was not incompletely defined by a call to DefineUniformBufferBindingIncomplete, or
		if the resource was previously defined by a call to this function.
		**/
		void DefineUniformBufferBinding(const boost::string_ref &resourceId, GLuint bufferObject,
			GLintptr offset, bool claimOwnership);

		/**
		\brief Incompletely creates a named uniform buffer binding resource.

		This call defines the bind-point and byte size for a uniform buffer binding resource. The rest of the
		data can be filled in with a call to DefineUniformBufferBinding(const std::string &, GLuint,
		GLintptr, bool).

		\param resourceId The resource name of the uniform buffer binding.
		\param bindPoint The index to bind to. Must be less than `GL_MAX_UNIFORM_BUFFER_BINDINGS`.
		\param size The size of the range to bind.
		
		\throws ResourceMultiplyDefinedException If \a resourceId refers to a uniform buffer resource that has
		already been defined.
		**/
		void DefineUniformBufferBindingIncomplete(const boost::string_ref &resourceId, GLuint bindPoint,
			GLsizeiptr size);


		/**
		\brief Creates a named storage buffer binding resource.

		A [storage buffer binding][1] is a region of a buffer object that needs to be bound to a location in the
		context. It effectively encapsulates a [glBindBufferRange(`GL_SHADER_STORAGE_BUFFER`)][2]
		call.

		\param resourceId The resource name of the storage buffer binding.
		\param bufferObject The OpenGL buffer object.
		\param bindPoint The index to bind to. Must be less than `GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS`.
		\param offset The offset from the start of the buffer for the bind call. The offset must be
		a multiple of `GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT`
		\param size The size of the range to bind.
		\param claimOwnership Set to `true` if you want the scene graph to delete the buffer.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a storage buffer resource that has
		already been defined. This will still be thrown if you used DefineUniformBufferBindingIncomplete
		to partially define the resource. In that case, you must use the other overload of this function.

		[1]: http://www.opengl.org/wiki/Shader_Storage_Uniform_Buffer_Object
		[2]: http://www.opengl.org/wiki/GLAPI/glBindBufferRange
		**/
		void DefineStorageBufferBinding( const boost::string_ref &resourceId, GLuint bufferObject,
			GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership );

		/**
		\brief Completes the creation of a named storage buffer that was started with DefineStorageBufferBindingIncomplete.

		This call defines the buffer object and offset for a storage buffer resource that was 
		incompletely defined with DefineUniformBufferBindingIncomplete. The bind point and range size
		will remain the same; only the buffer object and the starting offset can be modified with this function.

		\param resourceId The resource name of the storage buffer binding.
		\param bufferObject The OpenGL buffer object.
		\param offset The offset from the start of the buffer for the bind call. The offset must be
		a multiple of `GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT`
		\param claimOwnership Set to `true` if you want the scene graph to delete the buffer.

		\throws ResourceNotFoundException If \a resourceId does not refer to an existing storage buffer
		resource.
		\throws ResourceMultiplyDefinedException If \a resourceId refers to an existing storage buffer
		resource that was not incompletely defined by a call to DefineStorageBufferBindingIncomplete, or
		if the resource was previously defined by a call to this function.
		**/
		void DefineStorageBufferBinding(const boost::string_ref &resourceId, GLuint bufferObject,
			GLintptr offset, bool claimOwnership);

		/**
		\brief Incompletely creates a named storage buffer binding resource.

		This call defines the bind-point and byte size for a storage buffer binding resource. The rest of the
		data can be filled in with a call to DefineStorageBufferBinding(const std::string &, GLuint,
		GLintptr, bool).

		\param resourceId The resource name of the storage buffer binding.
		\param bindPoint The index to bind to. Must be less than `GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS`.
		\param size The size of the range to bind.
		
		\throws ResourceMultiplyDefinedException If \a resourceId refers to a storage buffer resource that has
		already been defined.
		**/
		void DefineStorageBufferBindingIncomplete(const boost::string_ref &resourceId, GLuint bindPoint,
			GLsizeiptr size);


		/**
		\brief Creates a named camera resource.

		This call creates a glutil::ViewPole camera resource, given the various information needed by the
		glutil::ViewPole class. Named cameras can be directly accessed by the user through the SceneGraph
		class.

		\param resourceId The resource name of the camera.
		\param initialView The starting state of the view.
		\param viewScale The viewport definition to use.
		\param actionButton The mouse button to listen for. All other mouse buttons are ignored.
		\param bRightKeyboardCtrls If true, then it uses IJKLUO instead of WASDQE keys.

		\throws ResourceMultiplyDefinedException If \a resourceId refers to a camera resource that has
		already been defined.
		**/
		void DefineCamera(const boost::string_ref &resourceId, const glutil::ViewData &initialView,
			const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls);

		/**
		\brief Retrieves the named camera resource.
		\throws ResourceNotFoundException If \a resourceId is not a previously defined camera resource.
		**/
		glutil::ViewPole &GetCamera(const boost::string_ref &resourceId);

	private:
		boost::reference_wrapper<ResourceData> m_data;

		ResourceRef(ResourceData &data) : m_data(data) {}

		friend class SceneGraph;
	};
	///@}
}


#endif //GLSDK_GLSCENE_RESOURCE_REF_H
