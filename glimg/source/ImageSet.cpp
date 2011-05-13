

#include "glimg/ImageSet.h"
#include "ImageSetImpl.h"

#define ARRAY_COUNT( array ) (sizeof( array ) / (sizeof( array[0] ) * (sizeof( array ) != sizeof(void*) || sizeof( array[0] ) <= sizeof(void*))))

namespace glimg
{
	namespace
	{
		template<int arrayCount, typename TestType>
		bool IsOneOfThese(TestType testValue, TestType *testArray)
		{
			for(int loop = 0; loop < arrayCount; loop++)
			{
				if(testValue == testArray[loop])
					return true;
			}

			return false;
		}

		BaseDataFormat g_alphaFormats[] = {FMT_COLOR_RGBA, FMT_COLOR_RGBA_sRGB};
		BaseDataFormat g_rgbFormats[] = {FMT_COLOR_RGB, FMT_COLOR_RGB_sRGB};
		Bitdepth g_floatBitdepths[] = {BD_PER_COMP_16, BD_PER_COMP_32, BD_PACKED_32_BIT_101111};
		ComponentOrder g_reversedOrder[] = {ORDER_ARGB, ORDER_ABGR, ORDER_EBGR};
		BaseDataFormat g_colorFormats[] = {FMT_COLOR_RED, FMT_COLOR_RG, FMT_COLOR_RGB,
			FMT_COLOR_RGBX, FMT_COLOR_RGBA, FMT_COLOR_RGB_sRGB, FMT_COLOR_RGBX_sRGB, FMT_COLOR_RGBA_sRGB};

		BaseDataFormat g_twoCompFormats[] = {FMT_COLOR_RG, FMT_DEPTH_X};
		BaseDataFormat g_threeCompFormats[] = {FMT_COLOR_RGB, FMT_COLOR_RGB_sRGB};
		BaseDataFormat g_fourCompFormats[] = {FMT_COLOR_RGBX, FMT_COLOR_RGBA,
			FMT_COLOR_RGBX_sRGB, FMT_COLOR_RGBA_sRGB};

		int ComponentCount(BaseDataFormat eFormat)
		{
			if(IsOneOfThese<ARRAY_COUNT(g_twoCompFormats)>(eFormat, g_twoCompFormats))
				return 2;

			if(IsOneOfThese<ARRAY_COUNT(g_threeCompFormats)>(eFormat, g_threeCompFormats))
				return 3;

			if(IsOneOfThese<ARRAY_COUNT(g_fourCompFormats)>(eFormat, g_fourCompFormats))
				return 4;

			return 1;
		}
	}

	bool ImageFormat::ValidateFormat() const
	{
		//Alignment only matters for uncompressed types.
		if(eType < DT_NUM_UNCOMPRESSED_TYPES)
		{
			int tests[] = {1, 2, 4, 8};

			if(!IsOneOfThese<ARRAY_COUNT(tests)>(lineAlignment, tests))
				return false;

			if(eOrder == ORDER_COMPRESSED)
				return false;

			if(eBitdepth == BD_COMPRESSED)
				return false;
		}
		else
		{
			if(eOrder != ORDER_COMPRESSED)
				return false;

			if(eBitdepth != BD_COMPRESSED)
				return false;

			//Test the compressed formats with the colors.
			if(eType == DT_COMPRESSED_BC2 || eType == DT_COMPRESSED_BC3)
			{
				if(!IsOneOfThese<ARRAY_COUNT(g_alphaFormats)>(eFormat, g_alphaFormats))
					return false;
			}
			else if(eType == DT_COMPRESSED_BC1)
			{
				if( !IsOneOfThese<ARRAY_COUNT(g_rgbFormats)>(eFormat, g_rgbFormats) &&
					!IsOneOfThese<ARRAY_COUNT(g_alphaFormats)>(eFormat, g_alphaFormats))
					return false;				
			}
			if(eType == DT_COMPRESSED_UNSIGNED_BC4 || eType == DT_COMPRESSED_SIGNED_BC4)
			{
				if(eFormat != FMT_COLOR_RED)
					return false;
			}
			if(eType == DT_COMPRESSED_UNSIGNED_BC5 || eType == DT_COMPRESSED_SIGNED_BC5)
			{
				if(eFormat != FMT_COLOR_RG)
					return false;
			}
			if(eType == DT_COMPRESSED_UNSIGNED_BC6H || eType == DT_COMPRESSED_SIGNED_BC6H)
			{
				if(eFormat != FMT_COLOR_RGB)
					return false;
			}
			if(eType == DT_COMPRESSED_BC7)
			{
				if(!IsOneOfThese<ARRAY_COUNT(g_alphaFormats)>(eFormat, g_alphaFormats))
					return false;
			}

			//End of compressed stuff.
			return true;
		}

		{
			//Check for shared float.
			bool bSharedExp = (eType == DT_SHARED_EXP_FLOAT);
			bool bSharedOrder = (eOrder == ORDER_EBGR);
			bool bSharedDepth = (eBitdepth == BD_PACKED_32_BIT_5999);
			if(bSharedExp != bSharedOrder ||
				bSharedOrder != bSharedDepth)
				return false;

			if(bSharedExp && (eFormat != FMT_COLOR_RGB))
				return false;

			//Shared exponent only comes in one form.
			if(bSharedExp)
				return true;
		}

		if(eBitdepth == BD_PER_COMP_4)
		{
			//Must use 4 components.
			BaseDataFormat tests[] = {FMT_COLOR_RGBX, FMT_COLOR_RGBA, FMT_COLOR_RGBX_sRGB,
				FMT_COLOR_RGBA_sRGB};
			if(!IsOneOfThese<ARRAY_COUNT(tests)>(eFormat, tests))
				return false;
		}

		if(eFormat == FMT_DEPTH || eFormat == FMT_DEPTH_X)
		{
			if(eOrder != ORDER_DEPTH_STENCIL)
				return false;

			//Depth can be either 16-bit normalized, 32-bit float, or 24x8 normalized.
			if(eType == DT_NORM_UNSIGNED_INTEGER)
			{
				if(eFormat == FMT_DEPTH)
				{
					if(eBitdepth != BD_PER_COMP_16)
						return false;
				}
				else
				{
					if(eBitdepth != BD_PACKED_32_BIT_248)
						return false;
				}
			}
			else if(eType == DT_FLOAT)
			{
				//Must be float.
				if(eBitdepth != BD_PER_COMP_32)
					return false;
			}
			else
			{
				//Must be either normalized unisgned or float.
				return false;
			}
		}

		if(eBitdepth == BD_PACKED_32_BIT_248)
		{
			if(eFormat != FMT_DEPTH_X)
				return false;
		}

		//Floats must be at least 16-bits per component, or 101111.
		if(eType == DT_FLOAT)
		{
			if(!IsOneOfThese<ARRAY_COUNT(g_floatBitdepths)>(eBitdepth, g_floatBitdepths))
				return false;

		}

		//If 101111, then must be BGR, and must be float.
		if(eBitdepth == BD_PACKED_32_BIT_101111)
		{
			if(!(eType == DT_FLOAT && eOrder == ORDER_BGRA && eFormat == FMT_COLOR_RGB))
				return false;
		}

		//Certain formats must be per-component.
		if(eBitdepth >= BD_NUM_PER_COMPONENT)
		{
			//Only unsigned integers and certain special floats can be packed.
			//The special floats have already been checked, so let them through.
			if(eType != DT_NORM_UNSIGNED_INTEGER && eType != DT_FLOAT)
				return false;

			//Ensure that bitdepth and the format match in terms of component count.
			switch(ComponentCount(eFormat))
			{
			case 1:
				return false;
			case 2:
				if(eFormat != FMT_DEPTH_X)
					return false;
				break;
			case 3:
				if(eBitdepth != BD_PACKED_16_BIT_565)
					return false;
				break;
			case 4:
				if(eBitdepth == BD_PACKED_16_BIT_565)
					return false;
				break;
			}
		}

		//OpenGL cannot full reverse individual per-component values, for certain bitdepths.
		if(IsOneOfThese<ARRAY_COUNT(g_reversedOrder)>(eOrder, g_reversedOrder))
		{
			if(eBitdepth == BD_PER_COMP_16 || eBitdepth == BD_PER_COMP_32)
				return false;
		}

		return true;
	}

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

		Dimensions ModifySizeForMipmap(Dimensions origDim, int mipmapLevel)
		{
			for(int iLoop = 0; iLoop < mipmapLevel; iLoop++)
			{
				origDim.width /= 2;
				origDim.height /= 2;
				origDim.depth /= 2;
			}

			return origDim;
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

	glimg::Dimensions Image::GetDimensions() const
	{
		return ModifySizeForMipmap(m_pImpl->GetDimensions(), m_mipmapLevel);
	}

	glimg::ImageFormat Image::GetFormat() const
	{
		return m_pImpl->GetImageFormat();
	}

	const void * Image::GetImageData() const
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
		return m_pImpl->GetImageFormat();
	}

	Image * ImageSet::GetImage( int ixMipmapLevel, int ixArray, int ixFace ) const
	{
		return new Image(m_pImpl, ixArray, ixFace, ixMipmapLevel);
	}
}

