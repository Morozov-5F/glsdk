
#ifndef GLSDK_MESH_QUADRICS_H
#define GLSDK_MESH_QUADRICS_H

/**
\file
\brief Defines mesh generators for various quadrics and curved surfaces.
**/

#include "GenDescriptors.h"

namespace glmesh
{
	class Mesh;

	namespace gen
	{
		///\addtogroup module_glmesh_mesh_generator
		///@{

		/**
		\brief Creates a sphere of radius 1 at the origin.
		
		**/
		Mesh *UnitSphere(int numHorizSlices, int numVertSlices);

		///@}
	}
}



#endif //GLSDK_MESH_QUADRICS_H
