
#ifndef FONT_UTIL_H
#define FONT_UTIL_H

/**
\file
\brief Contains the \ref module_glutil_font "basic font rendering system" classes and functions.
**/

#include <glm/glm.hpp>

namespace glutil
{
	///\addtogroup module_glutil_font
	///@{

	namespace detail
	{
		class FontImpl;
	}

	class Font;

	enum FontSizes
	{
		FONT_SIZE_SMALL,
		FONT_SIZE_MEDIUM,
		FONT_SIZE_LARGE,
		FONT_SIZE_GIANT,
	};

	Font *CreateFont(FontSizes eSize);

	//Deletion of this object must happen while OpenGL is still active.
	class Font
	{
	public:
		~Font();

		GLuint GetTexture() const;

	private:
		detail::FontImpl *m_pImpl;

		explicit Font(detail::FontImpl *pImpl);

		friend Font *CreateFont(FontSizes eSize);

		//Prevent copying
		Font(const Font &);
		Font &operator=(const Font &);
	};

	///@}
}

#endif //FONT_UTIL_H
