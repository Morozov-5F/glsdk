
#ifndef IMAGE_SET_H
#define IMAGE_SET_H

namespace glimg
{
	/**
	\brief Describes the basic type of the pixel data.

	The pixel data type of an image represents the basic type of data stored in the image.
	This can be floating-point, normalized unsigned integer, and the like.

	Compressed formats do not have pixel bitdepths or component ordering.
	**/
	enum BaseDataType
	{
		DT_NORM_UNSIGNED_INTEGER,			///<Image data are unsigned integers that is mapped to floats on the range [0, 1].
		DT_NORM_SIGNED_INTEGER,				///<Image data are signed integers that is mapped to floats on the range [-1, 1].
		DT_UNSIGNED_INTEGRAL,				///<Image data are unsigned integers.
		DT_SIGNED_INTEGRAL,					///<Image data are signed integers.
		DT_FLOAT,							///<Image data are individual floating-point numbers.
		DT_SHARED_EXP_FLOAT,				///<Image data are floats, but each pixel uses the same exponent.
		DT_NUM_UNCOMPRESSED_TYPES,

		DT_COMPRESSED_BC1 = DT_NUM_UNCOMPRESSED_TYPES,	///<Image data is compressed with DXT1/BC1 compression. Unsigned normalized integers.
		DT_COMPRESSED_BC2,					///<Image data is compressed with DXT3/BC2 compression. Unsigned normalized integers.
		DT_COMPRESSED_BC3,					///<Image data is compressed with DXT5/BC3 compression. Unsigned normalized integers.
		DT_COMPRESSED_UNSIGNED_BC4,			///<Image is compressed with BC4 compression, with unsigned normalized integers.
		DT_COMPRESSED_SIGNED_BC4,			///<Image is compressed with BC4 compression, with signed normalized integers.
		DT_COMPRESSED_UNSIGNED_BC5,			///<Image is compressed with BC5 compression, with unsigned normalized integers.
		DT_COMPRESSED_SIGNED_BC5,			///<Image is compressed with BC5 compression, with signed normalized integers.
		DT_COMPRESSED_UNSIGNED_BC6H,		///<Image is compressed with BC6H compression, with unsigned floats [0, +inf).
		DT_COMPRESSED_SIGNED_BC6H,			///<Image is compressed with BC6H compression, with floats.
		DT_COMPRESSED_BC7,					///<Image data is compressed with BC7 compression. Unsigned normalized integers.

		DT_NUM_TYPES,
	};

	/**
	\brief Describes the meaning of the pixel data stored in the image.

	The base data format of an image represents what kind of data is stored in each pixel. If it is
	color data, it also describes which color components are stored. The order of these components in
	the image data is not reflected here.
	**/
	enum BaseDataFormat
	{
		FMT_COLOR_RED,					///<Image contains 1 color component, namely red.
		FMT_COLOR_RG,					///<Image contains 2 color components, red and green.
		FMT_COLOR_RGB,					///<Image contains 3 color components, red, green, and blue.
		FMT_COLOR_RGBX,					///<Image contains 3 color components, red, green, and blue. There is a fourth component, which should be discarded.
		FMT_COLOR_RGBA,					///<Image contains 4 color components, red, green, blue, and alpha.
		FMT_COLOR_RGB_sRGB,				///<Image contains 3 color components, which are in the sRGB colorspace.
		FMT_COLOR_RGBX_sRGB,			///<Image contains 3 color components, which are in the sRGB colorspace. There is a fourth component, which should be discarded.
		FMT_COLOR_RGBA_sRGB,			///<Image contains 4 color components; the RGB components are in the sRGB colorspace.

		FMT_DEPTH,						///<Image contains a single depth component.
		FMT_DEPTH_X,					///<Image contains a depth value (unsigned normalized integer) and a second component, who's value is discarded/irrelevant.

		FMT_NUM_FORMATS,
	};

	/**
	\brief Specifies the ordering of the component data in the image.

	This enumeration specifies the ordering of the components in the image's values. Values that are
	missing from the BaseDataFormat are ignored.
	**/
	enum ComponentOrder
	{
		ORDER_RGBA,
		ORDER_BGRA,
		ORDER_ARGB,
		ORDER_ABGR,
		ORDER_EBGR,				///<For DT_SHARED_EXP_FLOAT types. The E is the exponent, and it comes first.

		ORDER_DEPTH_STENCIL,	///<Ordering for depth and depth-stencil image formats.

		ORDER_COMPRESSED,		///<The order is built into the compressed data format.

		ORDER_NUM_ORDERS,
	};

	/**
	\brief Specifies the bitdepth for each component of each value.

	Each component of each pixel has a particular bitdepth. The bitdepths specified here
	are either per-component or specify the size of an entire pixel. The PER_COMP
	enumerators specify the size of each component.

	So if PER_COMP_16 is used with a RGB format, then each pixel takes up 48 bits.
	This could be using unsigned integers (shorts) or floats (half-floats).

	The PACKED enumerators are for formats where each component does not have
	the same bitdepth. The number after PACKED specifies the overall bitdepth
	of the pixel. PACKED_16_BIT means that the pixel takes up 16 bits.
	The numbers after represent the bitdepth of the individual components, in the oder
	specified by the ComponentOrder enumerator.
	**/
	enum Bitdepth
	{
		BD_COMPRESSED,					///<Used for compressed data types. They do not have a bitdepth.

		BD_PER_COMP_4,					///<Each component takes up 4 bits.
		BD_PER_COMP_8,					///<Each component takes up 8 bits.
		BD_PER_COMP_16,					///<Each component takes up 16 bits.
		BD_PER_COMP_32,					///<Each component takes up 32 bits.

		BD_PACKED_16_BIT_565,			///<The first and third components take up 5 bits, while the second takes up 6.
		BD_PACKED_16_BIT_5551,			///<The first three components take up 5 bits, and the last takes up 1.
		BD_PACKED_16_BIT_1555,			///<The first component takes up 1 bit, the last three take up 5.

		BD_PACKED_32_BIT_1010102,		///<The first three components take up 10 bits, and the last takes up 2.
		BD_PACKED_32_BIT_2101010,		///<The first component takes up 2 bits, and the last three takes up 10 bits.
		BD_PACKED_32_BIT_5999,			///<The first component takes up 5 bits, and the next three take up 9. Used for DT_SHARED_EXP_FLOAT types. 
		BD_PACKED_32_BIT_101111,		///<The first component takes up 10 bits, and the next two take up 11 bits.
		BD_PACKED_32_BIT_248,			///<The first component takes up 24 bits; the second takes up 8 bits.

		BD_NUM_BITDEPTH,
	};

	struct ImageFormat
	{
		BaseDataType eType;
		BaseDataFormat eFormat;
		ComponentOrder eOrder;
		Bitdepth eBitdepth;
	};

	/**
	\brief Represents a single image of a certain dimensionality.
	**/
	class Image
	{
	public:
		int GetDimensions() const;
		int GetPixelWidth() const;
		int GetPixelHeight() const;
		int GetPixelDepth() const;

		ImageFormat GetFormat() const;

		const void *GetImageData() const;

	private:
	};

	/**
	\brief Represents a set of images that can be stored in a texture object.

	This class represents the full range of possible image layouts with regard to texture objects. All
	images in the ImageSet use the same format.
	**/
	class ImageSet
	{
	public:
		/**
		\brief Returns the number of dimensions that the images in this image set have.
		
		This function will return the number of dimensions that the images in the image set contains.
		This is a number on the range [1, 3].
		**/
		int GetDimensions() const;

		/**
		\brief Returns the number of array images this image set has.

		This function will return the number of array images in the image set. The minimum is 1.
		**/
		int GetArrayCount() const;

		/**
		\brief Returns the number of mipmap levels the image set contains.

		This function will return the number of mipmap levels in the image set. The minimum is 1.
		
		**/
		int GetMipmapCount() const;

		/**
		\brief Returns the number of faces in the image set.

		This function will return the number of faces in the image set. This will be 1 for regular
		images, and 6 for cubemaps and cubemap arrays.
		**/
		int GetFaceCount() const;

		/**
		\brief Returns the width in pixels of the largest mipmap layer.
		
		**/
		int GetPixelWidth() const;

		/**
		\brief Returns the height in pixels of the largest mipmap layer.
		
		**/
		int GetPixelHeight() const;

		/**
		\brief Returns the depth in pixels of the largest mipmap layer.
		
		**/
		int GetPixelDepth() const;

		/**
		\brief Retrieves the image format that describes all images in this ImageSet.
		
		**/
		ImageFormat GetFormat() const;

		/**
		\brief Retrieves the image at the given array index, face index, and mipmap level.
		
		\return A pointer to the image. DO NOT DELETE THIS POINTER. Also, do not use it after this object is destroyed.
		**/
		const Image *GetImage(int ixMipmapLevel, int ixArray = 0, int ixFace = 0) const;

		/**
		\brief Retrieves a pointer to the full array data for a mipmap level.
		
		\return A pointer to the image data. DO NOT DELETE THIS POINTER. Also, do not use this pointer after this object is destroyed.
		**/
		const void *GetImageArray(int ixMipmapLevel) const;

	private:
	};
}


#endif //IMAGE_SET_H
