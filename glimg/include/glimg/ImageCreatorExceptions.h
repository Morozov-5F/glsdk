
#ifndef GLIMG_IMAGE_CREATOR_EXCEPTIONS_H
#define GLIMG_IMAGE_CREATOR_EXCEPTIONS_H

namespace glimg
{
	class ImageCreationException : public std::exception
	{
	public:

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;
	};

	class InvalidImageFormatException : public ImageCreationException
	{
	public:
		InvalidImageFormatException()
		{
			message = "ImageCreator was given an invalid image format.";
		}
	};

	class MissingImageException : public ImageCreationException
	{
	public:
		MissingImageException()
		{
			message = "ImageCreator is missing one or more images.";
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

	class ImageAlreadySpecifiedException : public ImageCreationException
	{
	public:
		ImageAlreadySpecifiedException()
		{
			message = "Attempted to add an image that already has been added.";
		}
	};

	class ImageSetAlreadyCreatedException : public ImageCreationException
	{
	public:
		ImageSetAlreadyCreatedException()
		{
			message = "Attempted to add an image to an ImageCreator that has already been used to create an image set.";
		}
	};
}


#endif //GLIMG_IMAGE_CREATOR_EXCEPTIONS_H
