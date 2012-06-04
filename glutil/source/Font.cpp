
#include <vector>
#include <glload/gl_all.hpp>
#include <glload/gll.hpp>
#include "glutil/Font.h"
#include "ftData.h"


namespace glutil
{
	namespace detail
	{
		GLenum CalcInternalFormat()
		{
			return gl::GL_R8;
		}

		GLenum CalcFormat()
		{
			return gl::GL_RED;
		}

		class FontImpl
		{
		public:
			FontImpl(const TypefaceMetrics &metrics, const Glyph *glyphs, const unsigned char* imageData)
				: m_metrics(metrics)
				, m_glyphs(glyphs)
				, m_texture(0)
			{
				gl::GenTextures(1, &m_texture);

				gl::PixelStorei(gl::GL_UNPACK_SWAP_BYTES, gl::GL_FALSE);
				gl::PixelStorei(gl::GL_UNPACK_LSB_FIRST, gl::GL_FALSE);
				gl::PixelStorei(gl::GL_UNPACK_ROW_LENGTH, 0);
				gl::PixelStorei(gl::GL_UNPACK_SKIP_ROWS, 0);
				gl::PixelStorei(gl::GL_UNPACK_SKIP_PIXELS, 0);
				gl::PixelStorei(gl::GL_UNPACK_IMAGE_HEIGHT, 0);
				gl::PixelStorei(gl::GL_UNPACK_SKIP_IMAGES, 0);
				gl::PixelStorei(gl::GL_UNPACK_ALIGNMENT, 1);

/*
				if(glext_EXT_direct_state_access)
				{
					if(glext_ARB_texture_storage)
					{
						gl::TextureStorage2DEXT(m_texture, gl::GL_TEXTURE_2D, 1, CalcInternalFormat(),
							m_metrics.imageWidth, m_metrics.imageHeight);
					}
					else
					{
						gl::TextureImage2DEXT(m_texture, gl::GL_TEXTURE_2D, 0, CalcInternalFormat(),
							m_metrics.imageWidth, m_metrics.imageHeight, 0, CalcFormat(),
							gl::GL_UNSIGNED_BYTE, NULL);
						gl::TextureParameteriEXT(m_texture, gl::GL_TEXTURE_2D,
							gl::GL_TEXTURE_BASE_LEVEL, 0);
						gl::TextureParameteriEXT(m_texture, gl::GL_TEXTURE_2D,
							gl::GL_TEXTURE_MAX_LEVEL, 0);
					}

					gl::TextureSubImage2DEXT(m_texture, gl::GL_TEXTURE_2D, 0, 0, 0,
						m_metrics.imageWidth, m_metrics.imageHeight, CalcFormat(),
						gl::GL_UNSIGNED_BYTE, imageData);
				}
				else
*/
				{
					gl::BindTexture(gl::GL_TEXTURE_2D, m_texture);

					if(glext_ARB_texture_storage)
					{
						gl::TexStorage2D(gl::GL_TEXTURE_2D, 1, CalcInternalFormat(),
							m_metrics.imageWidth, m_metrics.imageHeight);
					}
					else
					{
						gl::TexImage2D(gl::GL_TEXTURE_2D, 0, CalcInternalFormat(),
							m_metrics.imageWidth, m_metrics.imageHeight, 0, CalcFormat(),
							gl::GL_UNSIGNED_BYTE, NULL);
						gl::TexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_BASE_LEVEL, 0);
						gl::TexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAX_LEVEL, 0);
					}

					gl::TexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MAG_FILTER, gl::GL_NEAREST);
					gl::TexParameteri(gl::GL_TEXTURE_2D, gl::GL_TEXTURE_MIN_FILTER, gl::GL_NEAREST);

					gl::TexSubImage2D(gl::GL_TEXTURE_2D, 0, 0, 0,
						m_metrics.imageWidth, m_metrics.imageHeight, CalcFormat(),
						gl::GL_UNSIGNED_BYTE, imageData);

					gl::BindTexture(gl::GL_TEXTURE_2D, 0);
				}
			}

			~FontImpl()
			{
				gl::DeleteTextures(1, &m_texture);
				m_texture = 0;
			}

		
			GLuint GetTexture() const {return m_texture;}
		private:
			TypefaceMetrics m_metrics;
			const Glyph *m_glyphs;
			GLuint m_texture;
		};
	}

	Font *CreateFont( FontSizes eSize )
	{
		detail::FontImpl *pImpl = NULL;
		switch(eSize)
		{
		case FONT_SIZE_SMALL:
			pImpl = new detail::FontImpl(detail::small_Typeface, detail::small_Glyphs, detail::small_Image);
			break;
		case FONT_SIZE_MEDIUM:
			pImpl = new detail::FontImpl(detail::medium_Typeface, detail::medium_Glyphs, detail::medium_Image);
			break;
		case FONT_SIZE_LARGE:
			pImpl = new detail::FontImpl(detail::large_Typeface, detail::large_Glyphs, detail::large_Image);
			break;
		case FONT_SIZE_GIANT:
			pImpl = new detail::FontImpl(detail::giant_Typeface, detail::giant_Glyphs, detail::giant_Image);
			break;
		}

		return new Font(pImpl);
	}

	Font::Font( detail::FontImpl *pImpl )
		: m_pImpl(pImpl)
	{}

	Font::~Font()
	{
		delete m_pImpl;
	}

	GLuint Font::GetTexture() const
	{
		return m_pImpl->GetTexture();
	}
}

