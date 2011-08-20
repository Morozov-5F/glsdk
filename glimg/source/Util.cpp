
#include "ImageSetImpl.h"
#include "Util.h"

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

		PixelComponents g_twoCompFormats[] = {FMT_COLOR_RG, FMT_DEPTH_X};
		PixelComponents g_threeCompFormats[] = {FMT_COLOR_RGB, FMT_COLOR_RGB_sRGB};
		PixelComponents g_fourCompFormats[] = {FMT_COLOR_RGBX, FMT_COLOR_RGBA,
			FMT_COLOR_RGBX_sRGB, FMT_COLOR_RGBA_sRGB};
	}

	int ComponentCount(PixelComponents eFormat)
	{
		if(IsOneOfThese<ARRAY_COUNT(g_twoCompFormats)>(eFormat, g_twoCompFormats))
			return 2;

		if(IsOneOfThese<ARRAY_COUNT(g_threeCompFormats)>(eFormat, g_threeCompFormats))
			return 3;

		if(IsOneOfThese<ARRAY_COUNT(g_fourCompFormats)>(eFormat, g_fourCompFormats))
			return 4;

		return 1;
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

	size_t CalcBytesPerPixel( const ValidFormat &fmt )
	{
		size_t bytesPerPixel = 0;
		switch(fmt.Depth())
		{
		case BD_COMPRESSED:			return 0;
		case BD_PER_COMP_8:					bytesPerPixel = 1;		break;
		case BD_PER_COMP_16:				bytesPerPixel = 2;		break;
		case BD_PER_COMP_32:				bytesPerPixel = 4;		break;
		case BD_PACKED_16_BIT_565:			bytesPerPixel = 2;		break;
		case BD_PACKED_16_BIT_5551:			bytesPerPixel = 2;		break;
		case BD_PACKED_16_BIT_4444:			bytesPerPixel = 2;		break;
		case BD_PACKED_32_BIT_8888:			bytesPerPixel = 4;		break;
		case BD_PACKED_32_BIT_1010102:		bytesPerPixel = 4;		break;
		case BD_PACKED_32_BIT_248:			bytesPerPixel = 4;		break;
		case BD_PACKED_16_BIT_565_REV:		bytesPerPixel = 2;		break;
		case BD_PACKED_16_BIT_1555_REV:		bytesPerPixel = 2;		break;
		case BD_PACKED_16_BIT_4444_REV:		bytesPerPixel = 2;		break;
		case BD_PACKED_32_BIT_8888_REV:		bytesPerPixel = 4;		break;
		case BD_PACKED_32_BIT_2101010_REV:	bytesPerPixel = 4;		break;
		case BD_PACKED_32_BIT_101111_REV:	bytesPerPixel = 4;		break;
		case BD_PACKED_32_BIT_5999_REV:		bytesPerPixel = 4;		break;
		}

		if(fmt.Depth() < BD_NUM_PER_COMPONENT)
			bytesPerPixel *= ComponentCount(fmt.Components());

		return bytesPerPixel;
	}
}