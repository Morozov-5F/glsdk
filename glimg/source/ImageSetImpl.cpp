
#include "ImageSetImpl.h"


glimg::detail::ImageSetImpl::ImageSetImpl( MemoryObject *pObject, ImageDimensions dimensions,
										  int arrayCount, int mipmapCount, int faceCount,
										  ImageFormat format, std::vector<MipmapLevel> &swapThisIn )
										  : m_dimensions(dimensions)
										  , m_format(format)
										  , m_pMemory(pObject)
										  , m_arrayCount(arrayCount)
										  , m_mipmapCount(mipmapCount)
										  , m_faceCount(faceCount)
{
	std::swap(m_imageData, swapThisIn);
}

