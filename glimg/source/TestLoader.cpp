
#include <vector>
#include "glimg/ImageSet.h"
#include "ImageSetImpl.h"
#include "glimg/TestLoader.h"
#include "glimg/ImageCreator.h"

namespace
{
	typedef std::vector<unsigned char> PixelArray;

	class TestData : public glimg::MemoryObject
	{
	public:
		virtual ~TestData() {}

		std::vector<PixelArray> pixelDataArray;
	};
}

glimg::ImageSet *glimg::loaders::TestImage()
{
	TestData *pMemory = new TestData;
	pMemory->pixelDataArray.resize(1);

	PixelArray &pixelData = pMemory->pixelDataArray[0];
	pixelData.resize(16*16*4, 255);

	//Fill in the data.

	//Make an image creator and create the image.
	ImageDimensions dims;
	dims.numDimensions = 2;
	dims.depth = 0;
	dims.width = 16;
	dims.height = 16;

	ImageFormat fmt;
	fmt.eType = DT_NORM_UNSIGNED_INTEGER;
	fmt.eFormat = FMT_COLOR_RGBA;
	fmt.eOrder = ORDER_RGBA;
	fmt.eBitdepth = BD_PER_COMP_8;

	ImageCreator imgCreator(pMemory, dims, 1, 1, 1, fmt);

	imgCreator.AddImage(&pixelData[0], 0);

	return imgCreator.CreateImage();
}

