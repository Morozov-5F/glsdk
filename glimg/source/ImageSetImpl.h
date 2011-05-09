
#include "glimg/ImageSet.h"


namespace glimg
{
	namespace detail
	{
		class ImageSetImpl
		{
		public:
			ImageSetImpl();

			int GetDimensions() const {return m_numDimensions;}
			int GetArrayCount() const {return m_arrayCount;}
			int GetMipmapCount() const {return m_mipmapCount;}
			int GetFaceCount() const {return m_faceCount;}

			int GetWidth() const {return m_width;}
			int GetHeight() const {return m_height;}
			int GetDepth() const {return m_depth;}

			glimg::ImageFormat GetImageFormat() const {return m_format;}

		private:
			int m_numDimensions;
			int m_arrayCount;
			int m_mipmapCount;
			int m_faceCount;

			int m_width;
			int m_height;
			int m_depth;

			glimg::ImageFormat m_format;

		};
	}
}

