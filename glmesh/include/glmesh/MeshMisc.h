
#ifndef GLSDK_MESH_MISCELLANEOUS_H
#define GLSDK_MESH_MISCELLANEOUS_H

/**
\file
\brief Defines miscellaneous mesh generators.
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
		\brief A mesh of a full-screen quad. Useful for post-processing effects.

		This is a quad that covers the screen. Your vertex shader should pass the positions without
		transformation. The positions are already in clip-space.

		This mesh has only the position attribute. The position's Z is always 0, and the W is 1.
		**/
		Mesh *FullScreenQuad();

		/**
		\brief A mesh ground plane. Can be double-sided and arbitrarily tessellated.
		
		This creates a square, on the range [-1, 1] in the XY plane (faces in the +Z direction).
		The quad can be tessellated arbitrarily, via parameters.

		Avaliable attributes:
		\li normals
		\li texture coordinates: The lower-left corner of the texture is in the -X/-Y part of the square.

		\param numXVerts Number of vertices along the X axis. Must be 2 or greater.
		\param numYVerts Number of vertices along the Y axis. Must be 2 or greater.
		\param bDoubleSided Whether the ground is double-sided or not. If not, then CCW will point in the positive-Y.
		**/
		Mesh *GroundPlane(int numXVerts, int numYVerts, bool bDoubleSided = true);
		///@}
	}
}



#endif //GLSDK_MESH_MISCELLANEOUS_H
