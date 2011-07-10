

#include "glimg/ImageSet.h"
#include "ImageSetImpl.h"

namespace glimg
{
	SingleImage::SingleImage( const detail::ImageSetImpl *pImpl, int arrayIx, int faceIx, int mipmapLevel )
		: m_pImpl(pImpl)
		, m_arrayIx(arrayIx)
		, m_faceIx(faceIx)
		, m_mipmapLevel(mipmapLevel)
	{}

	SingleImage::~SingleImage()
	{}

	glimg::Dimensions SingleImage::GetDimensions() const
	{
		return m_pImpl->GetDimensions(m_mipmapLevel);
	}

	glimg::ImageFormat SingleImage::GetFormat() const
	{
		return m_pImpl->GetFormat();
	}

	const void * SingleImage::GetImageData() const
	{
		const detail::MipmapLevel &mipmapData = m_pImpl->GetMipmapLevel(m_mipmapLevel);

		if(mipmapData.bFullLayer)
		{
			return m_pImpl->OffsetPointerForImage(m_mipmapLevel, m_arrayIx, m_faceIx);
		}
		else
		{
			int dataIx = m_pImpl->GetArrayCount() * m_arrayIx + m_faceIx;
			return mipmapData.individualDataList[dataIx].pPixelData;
		}
	}

///////////////////////////////////////////////////////////
	ImageSet::ImageSet( detail::ImageSetImpl *pImpl )
		: m_pImpl(pImpl)
	{}

	ImageSet::~ImageSet()
	{
		delete m_pImpl;
	}

	glimg::Dimensions ImageSet::GetDimensions() const
	{
		return m_pImpl->GetDimensions();
	}

	int ImageSet::GetArrayCount() const
	{
		return m_pImpl->GetArrayCount();
	}

	int ImageSet::GetMipmapCount() const
	{
		return m_pImpl->GetMipmapCount();
	}

	int ImageSet::GetFaceCount() const
	{
		return m_pImpl->GetFaceCount();
	}

	glimg::ImageFormat ImageSet::GetFormat() const
	{
		return m_pImpl->GetFormat();
	}

	SingleImage * ImageSet::GetImage( int ixMipmapLevel, int ixArray, int ixFace ) const
	{
		return new SingleImage(m_pImpl, ixArray, ixFace, ixMipmapLevel);
	}
}

