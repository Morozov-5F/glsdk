
#ifndef GLIMG_IMAGE_CREATOR_EXCEPTIONS_H
#define GLIMG_IMAGE_CREATOR_EXCEPTIONS_H

#include <string>
#include <exception>

namespace glimg
{
	///\addtogroup module_glimg_exceptions
	///@{

	class ImageCreationException : public std::exception
	{
	public:
	    virtual ~ImageCreationException() throw() {}

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;
	};

	class BadFaceCountException : public ImageCreationException
	{
	public:
		BadFaceCountException()
		{
			message = "Must pass 1 or 6 as the face count.";
		}
	};

	class CubemapsMustBe2DException : public ImageCreationException
	{
	public:
		CubemapsMustBe2DException()
		{
			message = "Textures with a face count of 6 MUST be 2D textures.";
		}
	};

	class No3DTextureArrayException : public ImageCreationException
	{
	public:
		No3DTextureArrayException()
		{
			message = "Images cannot be 3D arrays.";
		}
	};

	class NoImagesSpecifiedException : public ImageCreationException
	{
	public:
		NoImagesSpecifiedException()
		{
			message = "Mipmap and array count must be >= 1.";
		}
	};

	class ArrayOutOfBoundsException : public ImageCreationException
	{
	public:
		ArrayOutOfBoundsException()
		{
			message = "Attempted to add an image to an array index that doesn't exist.";
		}
	};

	class MipmapLayerOutOfBoundsException : public ImageCreationException
	{
	public:
		MipmapLayerOutOfBoundsException()
		{
			message = "Attempted to add an image to a mipmap layer that doesn't exist.";
		}
	};

	class FaceIndexOutOfBoundsException : public ImageCreationException
	{
	public:
		FaceIndexOutOfBoundsException()
		{
			message = "Attempted to add an image to a face index that doesn't exist.";
		}
	};

	class ImageSetAlreadyCreatedException : public ImageCreationException
	{
	public:
		ImageSetAlreadyCreatedException()
		{
			message = "Attempted to use an ImageCreator that has already been used to create an ImageSet.";
		}
	};
	///@}
}


#endif //GLIMG_IMAGE_CREATOR_EXCEPTIONS_H
