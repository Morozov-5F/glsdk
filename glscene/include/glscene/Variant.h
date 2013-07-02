#ifndef GLSDK_GLSCENE_VARIANT_H
#define GLSDK_GLSCENE_VARIANT_H

/**
\file
\brief Includes the data structures used to define node variants, via a call to
SceneGraph::DefineNodeVariant. You must include a [GL Load header](@ref module_glload)
before including this file.
**/

#include <vector>
#include <string>
#include <boost/optional.hpp>
#include <boost/variant.hpp>


namespace glscene
{
	///\addtogroup module_glscene_node
	///@{

	///Binding data for textures, including a sampler.
	struct TextureBinding
	{
		GLuint textureUnit;		///<The texture unit to bind to.
		std::string textureId;	///<The resource name of a texture to bind to that unit.
		std::string samplerId;	///<The resource name of a sampler to bind to that unit.
	};

	/**
	\brief The image binding command.

	This command works pretty much the same way as the OpenGL command
	[glBindImageTexture](http://www.opengl.org/wiki/GLAPI/glBindImageTexture). It takes the same parameters,
	which have the same meaning. The only difference is that the texture object comes from a resource name,
	rather than a number.
	**/
	struct ImageBinding
	{
		GLuint imageUnit;					///<The image unit to bind to.
		std::string textureId;				///<The resource name of a texture to bind to that unit.
		GLint mipmapLevel;					///<The mipmap level of the image being bound.
		boost::optional<GLint> arrayLayer;	///<If set, then binds only the given layer. If not set, then binds the whole array.
		GLenum access;						///<The kind of access that the shader will be using the image for.
		GLenum format;						///<The format that you want to alias with the texture's internal image format.
	};

	///The binding for a uniform or shader storage buffer.
	struct BufferInterfaceBinding
	{
		std::string bufferId;				///<The resource name of the uniform or storage buffer.
		GLuint bindOffset;					///<An additional offset to be applied to the offset already specified by the resource.
	};

	///The data for a single program. Includes the program resource and any uniform resources.
	struct SingleProgramBinding
	{
		std::string programId;					///<The resource name of the program.
		std::vector<std::string> uniformIds;	///<The resource name of any uniform resources used by the program.
	};

	///The data for a separable program, used to build a program pipeline.
	struct ProgramMask
	{
		SingleProgramBinding prog;		///<The data for that program, including uniforms of interest.
		GLuint stages;					///<Stage bitmask, as would be used by [glUseProgramStages](http://www.opengl.org/wiki/GLAPI/glUseProgramStages).
	};

	///A list of all programs used by the pipeline.
	struct SeparableProgramBinding
	{
		std::vector<ProgramMask> pipeline;	///<The list of programs in the pipeline.
	};

	///A program can be either a single program or a separable program.
	typedef boost::variant<SingleProgramBinding, SeparableProgramBinding> ProgramBinding;


	///The data structure representing a full rendering command, with all of the information for rendering.
	struct VariantInfo
	{
		std::string meshResourceId;									///<The resource name of the mesh to render.
		boost::optional<std::string> meshVariantString;				///<The mesh variant string.
		ProgramBinding progBinding;									///<The program to render with.
		std::vector<TextureBinding> textureBindings;				///<The textures to render with.
		std::vector<ImageBinding> imageBindings;					///<The images to render with.
		std::vector<BufferInterfaceBinding> uniformBufferBindings;	///<The uniform buffers to render with.
		std::vector<BufferInterfaceBinding> storageBufferBindings;	///<The storage buffers to render with.
	};

	///@}
}

#endif //GLSDK_GLSCENE_VARIANT_H
