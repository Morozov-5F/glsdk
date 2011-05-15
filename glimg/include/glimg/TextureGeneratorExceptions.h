#ifndef GLIMG_TEXTURE_GENERATOR_EXCEPTIONS_H
#define GLIMG_TEXTURE_GENERATOR_EXCEPTIONS_H

#include <exception>
#include <string>

namespace glimg
{
	class TextureGenerationException : public std::exception
	{
	public:

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;
	};

	class ImageFormatUnsupportedException : public TextureGenerationException
	{
	public:
		ImageFormatUnsupportedException()
		{
			message = "The image format is not supported by this OpenGL implementation.";
		}
	};

	class CannotForceRenderTargetException : public TextureGenerationException
	{
	public:
		CannotForceRenderTargetException()
		{
			message = "The image format cannot be forced to be a renderable format without compromizing the data.";
		}
	};

	class ImageFormatUnexpectedException : public TextureGenerationException
	{
	public:
		ImageFormatUnexpectedException()
		{
			message = "This image format is not supported by glimg.\nNo idea how we got here.";
		}

		explicit ImageFormatUnexpectedException(const std::string &msg)
		{
			message = "This image format is not supported by glimg.\n";
			message += msg;
		}
	};

}



#endif //GLIMG_TEXTURE_GENERATOR_EXCEPTIONS_H
