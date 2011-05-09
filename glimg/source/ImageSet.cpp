

#include "glimg/ImageSet.h"
#include "ImageSetImpl.h"





namespace glimg
{
	namespace
	{
		int ModifySizeForMipmap(int origSize, int mipmapLevel)
		{
			for(int iLoop = 0; iLoop < mipmapLevel; iLoop++)
			{
				origSize = origSize / 2;
			}

			return origSize;
		}
	}

	Image::Image( const detail::ImageSetImpl *pImpl, int arrayIx, int faceIx, int mipmapLevel )
		: m_pImpl(pImpl)
		, m_arrayIx(arrayIx)
		, m_faceIx(faceIx)
		, m_mipmapLevel(mipmapLevel)
	{}

	Image::~Image()
	{}

	int Image::GetDimensions() const
	{
		return m_pImpl->GetDimensions();
	}

	int Image::GetPixelWidth() const
	{
		return ModifySizeForMipmap(m_pImpl->GetWidth(), m_mipmapLevel);
	}

	int Image::GetPixelHeight() const
	{
		return ModifySizeForMipmap(m_pImpl->GetHeight(), m_mipmapLevel);
	}

	int Image::GetPixelDepth() const
	{
		return ModifySizeForMipmap(m_pImpl->GetDepth(), m_mipmapLevel);
	}

	glimg::ImageFormat Image::GetFormat() const
	{
		return m_pImpl->GetImageFormat();
	}


	ImageSet::ImageSet( detail::ImageSetImpl *pImpl )
		: m_pImpl(pImpl)
	{}

	ImageSet::~ImageSet()
	{
		delete m_pImpl;
	}

	int ImageSet::GetDimensions() const
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

	int ImageSet::GetPixelWidth() const
	{
		return m_pImpl->GetWidth();
	}

	int ImageSet::GetPixelHeight() const
	{
		return m_pImpl->GetHeight();
	}

	int ImageSet::GetPixelDepth() const
	{
		return m_pImpl->GetDepth();
	}

	glimg::ImageFormat ImageSet::GetFormat() const
	{
		return m_pImpl->GetImageFormat();
	}

	const Image * ImageSet::GetImage( int ixMipmapLevel, int ixArray, int ixFace ) const
	{
		return new Image(m_pImpl, ixArray, ixFace, ixMipmapLevel);
	}
}

