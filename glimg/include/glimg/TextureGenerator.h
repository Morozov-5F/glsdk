#ifndef GLIMG_TEXTURE_GENERATOR_H
#define GLIMG_TEXTURE_GENERATOR_H

#include "ImageSet.h"


namespace glimg
{
	enum ForcedConvertBits
	{
		FORCE_SRGB_COLORSPACE		= 0x0001,	///<When possible, will force the format to use the sRGB colorspace.
		FORCE_BC1_ALPHA_TEXTURE		= 0x0002,	///<When used with a BC1 texture, will force the texture to have an alpha.
		FORCE_ARRAY_TEXTURE			= 0x0004,	///<The texture will be an array texture even if the depth is one. Ignored for formats that can't be arrays.
		FORCE_RG_TO_LA				= 0x0008,	///<Red and RG textures will become luminance and luminance/alpha textures in all cases.
		FORCE_REQUIRED_FORMATS		= 0x0010,	///<Will only get image formats that are required to exist by OpenGL.
		FORCE_INTEGRAL_FORMAT		= 0x0020,	///<Integer textures are considered integral.
		FORCE_SIGNED_FORMAT			= 0x0040,	///<Unsigned integer textures are considered signed integers.
		FORCE_COLOR_RENDERABLE		= 0x0080,	///<Will force the use of formats that are required to be valid render targets. This will add components if necessary, but it will throw if conversion would require fundamentally changing the basic format (from signed to unsigned, etc).
	};

	unsigned int GetInternalFormat(const ImageFormat &format, unsigned int forceConvertBits);
}



#endif //GLIMG_TEXTURE_GENERATOR_H
