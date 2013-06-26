#ifndef GLSDK_GLSCENE_VARIANT_H
#define GLSDK_GLSCENE_VARIANT_H

/**
\file
\brief Includes the . You must include a [GL Load header](@ref module_glload)
before including this file.
**/

#include <vector>
#include <string>
#include <boost/optional.hpp>
#include <boost/variant.hpp>


namespace glscene
{
	struct TextureBinding
	{
		GLuint textureUnit;
		std::string textureId;
		std::string samplerId;
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
		GLuint imageUnit;
		std::string textureId;
		GLint mipmapLevel;
		boost::optional<GLint> arrayLayer; ///<If set, then binds only that layer. If not set, then binds the whole array.
		GLenum access;
		GLenum format;
	};

	struct BufferInterfaceBinding
	{
		std::string bufferId;
		GLuint bindOffset;
	};

	struct SingleProgramBinding
	{
		std::string programId;
		std::vector<std::string> uniformIds;
	};

	struct ProgramMask
	{
		SingleProgramBinding prog;
		GLuint stages;			///<Stage bitmask, as would be used by [glUseProgramStages](http://www.opengl.org/wiki/GLAPI/glUseProgramStages).
	};

	struct SeparableProgramBinding
	{
		std::vector<ProgramMask> pipeline;
	};

	typedef boost::variant<SingleProgramBinding, SeparableProgramBinding> ProgramBinding;


	struct VariantInfo
	{
		std::string meshResourceId;
		ProgramBinding binding;
		std::vector<TextureBinding> textureBindings;
		std::vector<ImageBinding> imageBindings;
		std::vector<BufferInterfaceBinding> uniformBufferBindings;
		std::vector<BufferInterfaceBinding> storageBufferBindings;
	};
}

#endif //GLSDK_GLSCENE_VARIANT_H
