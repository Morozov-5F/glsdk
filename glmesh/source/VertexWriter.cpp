
#include <string.h>
#include <sstream>
#include <glload/gl_all.hpp>
#include "glmesh/VertexWriter.h"

namespace glmesh
{
	const glm::half _detail::InfoTraits<glm::half>::zero = glm::half(0.0f);
	const glm::half _detail::InfoTraits<glm::half>::one = glm::half(1.0f);
	const GLfloat _detail::InfoTraits<GLfloat>::zero = 0.0f;
	const GLfloat _detail::InfoTraits<GLfloat>::one = 1.0f;
	const GLdouble _detail::InfoTraits<GLdouble>::zero = 0.0;
	const GLdouble _detail::InfoTraits<GLdouble>::one = 1.0;

	MismatchWriterTypeException::MismatchWriterTypeException( int eRequiredType, const std::string &realType )
	{
		std::ostringstream temp;
		temp << "You provided the type \"" << realType << "\", for an attribute of type \"" << eRequiredType
			<< "\"" << std::endl;
		message = temp.str();
	}
}


