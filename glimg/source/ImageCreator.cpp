
#include <assert.h>
#include <algorithm>
#include "glimg/ImageSet.h"
#include "glimg/ImageCreator.h"
#include "ImageSetImpl.h"
#include "Util.h"

namespace glimg
{
	ImageCreator::ImageCreator( ImageFormat format, Dimensions dimensions,
		int mipmapCount, int arrayCount, int faceCount )
		: m_format(format)
		, m_dimensions(dimensions)
		, m_mipmapCount(mipmapCount)
		, m_arrayCount(arrayCount)
		, m_faceCount(faceCount)
		, m_imageData(mipmapCount)
		, m_imageSizes(mipmapCount)
	{
		assert(m_faceCount == 6 || m_faceCount == 1);
		if(m_dimensions.numDimensions == 3)
			assert(m_arrayCount == 1);

		//Allocate the memory for our data.
		int bpp = CalcBytesPerPixel(m_format);
		for(int level = 0; level < mipmapCount; ++level)
		{
			Dimensions mipmapDims = ModifySizeForMipmap(m_dimensions, level);
			size_t imageSize = CalcImageByteSize(m_format, mipmapDims);
			m_imageData[level].resize(imageSize * m_faceCount * m_arrayCount);
			m_imageSizes[level] = imageSize;
		}
	}

	void ImageCreator::SetImageData( const void *pixelData, bool isTopLeft,
		int mipmapLevel, int arrayIx, int faceIx )
	{
		//Check inputs.
		if((arrayIx < 0) || (m_arrayCount <= arrayIx))
			throw ArrayOutOfBoundsException();

		if((mipmapLevel < 0) || (m_mipmapCount <= mipmapLevel))
			throw MipmapLayerOutOfBoundsException();

		if((faceIx < 0) || (m_faceCount <= faceIx))
			throw FaceIndexOutOfBoundsException();

		size_t imageOffset = arrayIx * faceIx * m_imageSizes[mipmapLevel];

		unsigned char *pMipmapData = &m_imageData[mipmapLevel][0];
		memcpy(pMipmapData + imageOffset, pixelData, m_imageSizes[mipmapLevel]);
	}

	void ImageCreator::SetFullMipmapLevel( const void *pixelData, bool isTopLeft, int mipmapLevel )
	{
		//Check inputs.
		if((mipmapLevel < 0) || (m_mipmapCount <= mipmapLevel))
			throw MipmapLayerOutOfBoundsException();

		unsigned char *pMipmapData = &m_imageData[mipmapLevel][0];
		memcpy(pMipmapData, pixelData, m_imageSizes[mipmapLevel] * m_arrayCount * m_faceCount);
	}

	ImageSet * ImageCreator::CreateImage()
	{
		detail::ImageSetImpl *pImageData = new detail::ImageSetImpl(m_format, m_dimensions,
			m_mipmapCount, m_arrayCount, m_faceCount, m_imageData, m_imageSizes);

		ImageSet *pImageSet = new ImageSet(pImageData);

		return pImageSet;
	}
}
