
#include <assert.h>
#include <glload/gl_all.h>
#include <glload/gll.h>
#include "glimg/TextureGeneratorExceptions.h"
#include "glimg/TextureGenerator.h"


namespace glimg
{
	namespace
	{
		void ThrowIfS3TCNotSupported();
		void ThrowIfLATCNotSupported();
		void ThrowIfRGTCNotSupported();
		void ThrowIfBPTCNotSupported();
		void ThrowIfSRGBNotSupported();
		void ThrowIfEXT_SRGBNotSupported();
		void ThrowIfSharedExpNotSupported();
		void ThrowIfFloatNotSupported();
		void ThrowIfEXT_FloatNotSupported();
		void ThrowIfHalfFloatNotSupported();
		void ThrowIfSignedNormNotSupported();
		void ThrowIfPackedFloatNotSupported();
		void ThrowIfIntegralNotSupported();
		void ThrowIfEXT_IntegralNotSupported();
		void ThrowIfSnormNotSupported();
		void ThrowIfEXT_SnormNotSupported();
		void ThrowIfRGNotSupported();
		void ThrowIfForceRendertarget(unsigned int forceConvertBits);
		void ThrowIfDepthNotSupported();
		void ThrowIfDepthStencilNotSupported();

		bool IsSRGBFormat(const ImageFormat &format, unsigned int forceConvertBits);
		bool FormatHasAlpha(const ImageFormat &format, unsigned int forceConvertBits);
		bool UseLAInsteadOfRG(unsigned int forceConvertBits);
		BaseDataType GetDataType(const ImageFormat &format, unsigned int forceConvertBits);

		int ComponentCount(const ImageFormat &format, unsigned int forceConvertBits);
		int PerComponentSize(const ImageFormat &format, unsigned int forceConvertBits);

		//Ordered by BaseDataFormat*2. The first is 16-bit, the second is 32-bit.
		GLenum g_floatFormats[] =
		{
			GL_R16F,
			GL_R32F,
			GL_RG16F,
			GL_RG32F,
			GL_RGB16F,
			GL_RGB32F,
			GL_RGB16F,
			GL_RGB32F,
			GL_RGBA16F,
			GL_RGBA32F,
			0,			//sRGB
			0,			//sRGB
			0,			//sRGB
			0,			//sRGB
			0,			//sRGB
			0,			//sRGB
			0,			//16-bit float depth buffer. 
			GL_DEPTH_COMPONENT32F,
			0,			//UNorm+stencil.
		};

		//Ordered by number of components * size (8, 16, 32=>0, 1, 2).
		GLenum g_signIntegralFormats[] =
		{
			GL_R8I,			GL_R16I,			GL_R32I,
			GL_RG8I,		GL_RG16I,			GL_RG32I,
			GL_RGB8I,		GL_RGB16I,			GL_RGB32I,
			GL_RGBA8I,		GL_RGBA16I,			GL_RGBA32I,
		};

		//Ordered by number of components * size (8, 16, 32=>0, 1, 2).
		GLenum g_unsignIntegralFormats[] =
		{
			GL_R8UI,		GL_R16UI,			GL_R32UI,
			GL_RG8UI,		GL_RG16UI,			GL_RG32UI,
			GL_RGB8UI,		GL_RGB16UI,			GL_RGB32UI,
			GL_RGBA8UI,		GL_RGBA16UI,		GL_RGBA32UI,
		};

		//Ordered by number of components * size (8, 16=>0, 1, 2).
		GLenum g_signedNormFormats[] =
		{
			GL_R8_SNORM,		GL_R16_SNORM,
			GL_RG8_SNORM,		GL_RG16_SNORM,
			GL_RGB8_SNORM,		GL_RGB16_SNORM,
			GL_RGBA8_SNORM,		GL_RGBA16_SNORM,
		};

		GLenum ThrowInvalidFormatIfZero(GLenum input);

		unsigned int GetStandardOpenGLFormat( const ImageFormat &format, unsigned int forceConvertBits )
		{
			BaseDataType eType = GetDataType(format, forceConvertBits);

			switch(eType)
			{
			case DT_NORM_UNSIGNED_INTEGER:
				//Only 16-bit for non Depth_x.
				if(format.eFormat == FMT_DEPTH)
				{
					ThrowIfDepthNotSupported();
					return GL_DEPTH_COMPONENT16;
				}

				//Only 24x8 for this.
				if(format.eFormat == FMT_DEPTH_X)
				{
					ThrowIfDepthStencilNotSupported();
					return GL_DEPTH24_STENCIL8;
				}

				//Color formats.
				switch(format.eBitdepth)
				{
				case BD_PER_COMP_8:
					{
						GLenum components[] = {GL_R8, GL_RG8, GL_RGB8, GL_RGBA8};
						int numComponents = ComponentCount(format, forceConvertBits);

						return components[numComponents - 1];
					}
				case BD_PER_COMP_16:
					{
						GLenum components[] = {GL_R16, GL_RG16, GL_RGB16, GL_RGBA16};
						int numComponents = ComponentCount(format, forceConvertBits);

						return components[numComponents - 1];
					}

				case BD_PACKED_16_BIT_565:
				case BD_PACKED_16_BIT_565_REV:
					return GL_RGB8;

				case BD_PACKED_16_BIT_5551:
				case BD_PACKED_16_BIT_1555_REV:
					return GL_RGB5_A1;

				case BD_PACKED_16_BIT_4444:
				case BD_PACKED_16_BIT_4444_REV:
					return GL_RGBA4;

				case BD_PACKED_32_BIT_8888:
				case BD_PACKED_32_BIT_8888_REV:
					return GL_RGBA8;

				case BD_PACKED_32_BIT_1010102:
				case BD_PACKED_32_BIT_2101010_REV:
					return GL_RGB10_A2;
				}

				throw ImageFormatUnexpectedException("Unisgned normalize integer doesn't match accepted bitdepths.");

			case DT_NORM_SIGNED_INTEGER:
				ThrowIfSignedNormNotSupported();
				ThrowIfForceRendertarget(forceConvertBits);
				{
					int numComponents = ComponentCount(format, forceConvertBits);
					int compSize = PerComponentSize(format, forceConvertBits);
					compSize /= 16; //map to 0, 1.

					int index = ((numComponents - 1) * 3) + compSize;

					return g_signedNormFormats[index];
				}

			case DT_UNSIGNED_INTEGRAL:
			case DT_SIGNED_INTEGRAL:
				ThrowIfIntegralNotSupported();
				{
					int numComponents = ComponentCount(format, forceConvertBits);
					int compSize = PerComponentSize(format, forceConvertBits);
					compSize /= 16; //map to 0, 1, 2.

					int index = ((numComponents - 1) * 3) + compSize;

					if(eType == DT_SIGNED_INTEGRAL)
						return g_signIntegralFormats[index];
					else
						return g_unsignIntegralFormats[index];
				}

			case DT_FLOAT:
				ThrowIfFloatNotSupported();
				if(format.eBitdepth < BD_NUM_PER_COMPONENT)
				{
					int offset = 0;
					if(format.eBitdepth == BD_PER_COMP_32)
						offset = 1;
					else
						ThrowIfHalfFloatNotSupported();

					return ThrowInvalidFormatIfZero(g_floatFormats[(2 * format.eFormat) + offset]);
				}
				else
				{
					//Only one packed format.
					ThrowIfPackedFloatNotSupported();
					return GL_R11F_G11F_B10F;
				}

			case DT_SHARED_EXP_FLOAT:
				ThrowIfSharedExpNotSupported();
				ThrowIfForceRendertarget(forceConvertBits);
				return GL_RGB9_E5;

			case DT_COMPRESSED_BC1:
				ThrowIfS3TCNotSupported();
				if(IsSRGBFormat(format, forceConvertBits))
				{
					ThrowIfEXT_SRGBNotSupported();
					if(forceConvertBits & FORCE_BC1_ALPHA_TEXTURE)
						return GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT;
					else
						return GL_COMPRESSED_SRGB_S3TC_DXT1_EXT;
				}
				else
				{
					if(forceConvertBits & FORCE_BC1_ALPHA_TEXTURE)
						return GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
					else
						return GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
				}

			case DT_COMPRESSED_BC2:
				ThrowIfS3TCNotSupported();
				if(IsSRGBFormat(format, forceConvertBits))
				{
					ThrowIfEXT_SRGBNotSupported();
					return GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT;
				}
				else
					return GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;

			case DT_COMPRESSED_BC3:
				ThrowIfS3TCNotSupported();
				if(IsSRGBFormat(format, forceConvertBits))
				{
					ThrowIfEXT_SRGBNotSupported();
					return GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT;
				}
				else
					return GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;

			case DT_COMPRESSED_UNSIGNED_BC4:
				return GL_COMPRESSED_RED_RGTC1;
			case DT_COMPRESSED_SIGNED_BC4:
				return GL_COMPRESSED_SIGNED_RED_RGTC1;

			case DT_COMPRESSED_UNSIGNED_BC5:
				return GL_COMPRESSED_RG_RGTC2;
			case DT_COMPRESSED_SIGNED_BC5:
				return GL_COMPRESSED_SIGNED_RG_RGTC2;

			case DT_COMPRESSED_UNSIGNED_BC6H:
				ThrowIfBPTCNotSupported();
				return GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB;

			case DT_COMPRESSED_SIGNED_BC6H:
				ThrowIfBPTCNotSupported();
				return GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB;

			case DT_COMPRESSED_BC7:
				ThrowIfBPTCNotSupported();
				if(IsSRGBFormat(format, forceConvertBits))
					return GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB;
				else
					return GL_COMPRESSED_RGBA_BPTC_UNORM_ARB;
			}

			throw ImageFormatUnexpectedException("???");
		}
	}

#define LARG_COMPRESSED_CONV(oldFormat, newFormat)\
	case oldFormat:\
		if(bConvertToLA)\
		{\
			ThrowIfLATCNotSupported();\
			internalFormat = newFormat;\
		}\
		else\
			ThrowIfRGTCNotSupported();\
		break;


#define LARG_INTEGRAL_CONV(oldFormat, newFormat)\
	case oldFormat:\
	if(bConvertToLA)\
		{\
			ThrowIfEXT_IntegralNotSupported();\
			internalFormat = newFormat;\
		}\
		else\
			ThrowIfRGNotSupported();\
		break;

#define LARG_FLOAT_CONV(oldFormat, newFormat)\
	case oldFormat:\
	if(bConvertToLA)\
		{\
			ThrowIfEXT_FloatNotSupported();\
			internalFormat = newFormat;\
		}\
		else\
			ThrowIfRGNotSupported();\
		break;

#define LARG_SNORM_CONV(oldFormat, newFormat)\
	case oldFormat:\
		if(bConvertToLA)\
		{\
			ThrowIfEXT_SnormNotSupported();\
			internalFormat = newFormat;\
		}\
		else\
			ThrowIfRGNotSupported();\
		break;

#define LARG_NORM_CONV(oldFormat, newFormat)\
	case oldFormat:\
		if(bConvertToLA)\
		{\
			internalFormat = newFormat;\
		}\
		else\
			ThrowIfRGNotSupported();\
		break;


#define ONE_COMP_RG(size, suffix) GL_R ## size ## suffix
#define TWO_COMP_RG(size, suffix) GL_RG ## size ## suffix
#define ONE_COMP_LA(size, suffix) GL_LUMINANCE ## size ## suffix ## _EXT
#define TWO_COMP_LA(size, suffix) GL_LUMINANCE_ALPHA ## size ## suffix ## _EXT
#define ONE_SNORM_LA(size, suffix) GL_LUMINANCE ## size ## suffix
#define TWO_SNORM_LA(size, suffix) GL_LUMINANCE ## size ## _ALPHA ## size ## suffix

	unsigned int GetInternalFormat( const ImageFormat &format, unsigned int forceConvertBits )
	{
		{
			const std::string & msg = format.ValidateFormatText();
			if(!msg.empty())
				throw ImageFormatUnexpectedException(msg);
		}

		unsigned int internalFormat = GetStandardOpenGLFormat(format, forceConvertBits);

		bool bConvertToLA = UseLAInsteadOfRG(forceConvertBits);

		//Convert any R or RG formats to L or LA formats.
		switch(internalFormat)
		{
			LARG_COMPRESSED_CONV(GL_COMPRESSED_RED_RGTC1, GL_COMPRESSED_LUMINANCE_LATC1_EXT);
			LARG_COMPRESSED_CONV(GL_COMPRESSED_SIGNED_RED_RGTC1, GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT);
			LARG_COMPRESSED_CONV(GL_COMPRESSED_RG_RGTC2, GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT);
			LARG_COMPRESSED_CONV(GL_COMPRESSED_SIGNED_RG_RGTC2, GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT);

			LARG_INTEGRAL_CONV(ONE_COMP_RG(8, I), ONE_COMP_LA(8, I));
			LARG_INTEGRAL_CONV(ONE_COMP_RG(16, I), ONE_COMP_LA(16, I));
			LARG_INTEGRAL_CONV(ONE_COMP_RG(32, I), ONE_COMP_LA(32, I));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(8, I), TWO_COMP_LA(8, I));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(16, I), TWO_COMP_LA(16, I));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(32, I), TWO_COMP_LA(32, I));

			LARG_INTEGRAL_CONV(ONE_COMP_RG(8, UI), ONE_COMP_LA(8, UI));
			LARG_INTEGRAL_CONV(ONE_COMP_RG(16, UI), ONE_COMP_LA(16, UI));
			LARG_INTEGRAL_CONV(ONE_COMP_RG(32, UI), ONE_COMP_LA(32, UI));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(8, UI), TWO_COMP_LA(8, UI));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(16, UI), TWO_COMP_LA(16, UI));
			LARG_INTEGRAL_CONV(TWO_COMP_RG(32, UI), TWO_COMP_LA(32, UI));

			LARG_SNORM_CONV(ONE_COMP_RG(8, _SNORM), ONE_SNORM_LA(8, _SNORM));
			LARG_SNORM_CONV(ONE_COMP_RG(16, _SNORM), ONE_SNORM_LA(16, _SNORM));
			LARG_SNORM_CONV(TWO_COMP_RG(8, _SNORM), TWO_SNORM_LA(8, _SNORM));
			LARG_SNORM_CONV(TWO_COMP_RG(16, _SNORM), TWO_SNORM_LA(16, _SNORM));

			LARG_NORM_CONV(GL_R8, GL_LUMINANCE8);
			LARG_NORM_CONV(GL_R16, GL_LUMINANCE16);
			LARG_NORM_CONV(GL_RG8, GL_LUMINANCE8_ALPHA8);
			LARG_NORM_CONV(GL_RG16, GL_LUMINANCE16_ALPHA16);
		}

		return internalFormat;
	}
}
