
#ifndef GLIMG_IMAGE_CREATOR_H
#define GLIMG_IMAGE_CREATOR_H

#include <string>
#include <vector>
#include <exception>
#include "ImageSet.h"
#include "ImageCreatorExceptions.h"

namespace glimg
{
	///\addtogroup module_glimg_creation
	///@{
	///A useful typedef for automatic memory management of image data.
	typedef std::vector<unsigned char> ImageBuffer;

	///Do not use. Not mature enough yet.
	class ImageCreator
	{
	public:
		/**
		\brief Creates an ImageCreator factory for making ImageSet objects.

		\param format The ImageFormat for the ImageSet to be created.
		\param dimensions The dimensionality of the base layer of the image.
		\param mipmapCount The number of mipmaps in the image.
		\param arrayCount The number of arrays of the image.
		\param faceCount The number of faces of the image.
		**/
		ImageCreator(ImageFormat format, Dimensions dimensions, int mipmapCount, int arrayCount, int faceCount);

		/**
		\brief Sets the data for a single image.

		\param pixelData The pixel data for the mipmap. It is expected to be formatted exactly as specified
		by the ImageFormat given to this ImageCreator at creation time.
		\param isTopLeft True if the orientation of the given image data is top-left. False if it is bottom-left
		\param mipmapLevel The mipmap layer to set the image on.
		\param arrayIx The array index to set the image on.
		\param faceIx The face index to set the image on.
		
		\todo Implement image flipping.
		**/
		void SetImageData(const void *pixelData, bool isTopLeft, int mipmapLevel, int arrayIx, int faceIx);

		/**
		\brief Sets the data for an entire mipmap layer.
		
		Each mipmap layer contains a number of array images and faces. This function will specify all
		of this data in one shot. The order is defined as follows:

		<pre>
for_each(array)
  +X face
  -X face
  +Y face
  -Y face
  +Z face
  -Z face
		</pre>

		If \a faceCount was 1, then there will only be one face instead of the 6. If \a arrayCount was 1
		then there will only be one set of faces. And if they were both 1, then there is only one image.

		\param pixelData The pixel data for the mipmap. It is expected to be formatted exactly as specified
		by the ImageFormat given to this ImageCreator at creation time. It must contain all of the pixel data
		in the order as above.
		\param isTopLeft True if the orientation of the given image data is top-left. False if it is bottom-left
		\param mipmapLevel The mipmap layer to set to.

		\todo Implement image flipping.
		**/
		///
		void SetFullMipmapLevel(const void *pixelData, bool isTopLeft, int mipmapLevel);

		/**
		\brief Creates an ImageSet from the stored data. The ImageCreator object is now dead.

		Do not use the ImageCreator object after calling this. Deleting it is fine, but the data
		has been \em transferred to the ImageSet, and no longer resides in the ImageCreator.

		This object is a copyable object, so if you want to make multiple ImageSet objects from the same ImageCreator,
		just copy the object before creating it. The copy will replicate the data.
		**/
		ImageSet *CreateImage();

	private:
		const ImageFormat m_format;
		const Dimensions m_dimensions;
		const int m_mipmapCount;
		const int m_arrayCount;
		const int m_faceCount;

		//Indexed by mipmap.
		std::vector<ImageBuffer> m_imageData;
		std::vector<size_t> m_imageSizes;
	};

	///@}
}


#endif //GLIMG_IMAGE_CREATOR_H
