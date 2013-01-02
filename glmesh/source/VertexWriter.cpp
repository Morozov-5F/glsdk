
#include <string.h>
#include <sstream>
#include <glload/gl_all.hpp>
#include "glmesh/VertexWriter.h"

namespace glmesh
{


	MismatchWriterTypeException::MismatchWriterTypeException( int eRequiredType, const std::string &realType )
	{
		std::ostringstream temp;
		temp << "You provided the type \"" << realType << "\", for an attribute of type \"" << eRequiredType
			<< "\"" << std::endl;
		message = temp.str();
	}
}


