
#ifndef GLSDK_MESH_GENERATOR_COMMON_H
#define GLSDK_MESH_GENERATOR_COMMON_H

#include <glutil/array_ref.h>
#include <glm/glm.hpp>

namespace glmesh
{
	namespace gen
	{
		typedef glm::detail::tvec4<GLubyte> Color;
		typedef refs::array_ref<Color> ColorArray;
	}
}


#endif //GLSDK_MESH_GENERATOR_COMMON_H
