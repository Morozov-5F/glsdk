
#ifndef GLSDK_MESH_GENERATOR_DESCRIPTORS_H
#define GLSDK_MESH_GENERATOR_DESCRIPTORS_H

/**
\file
\brief Describes the mesh generator flags.

**/

namespace glmesh
{
	/**
	\brief Contains all of the mesh generator functions and helper types.
	\ingroup module_glmesh_mesh_generator
	**/
	namespace gen
	{
		///\addtogroup module_glmesh_mesh_generator
		///@{

		/**
		\brief Flags that specify which attributes to generate.

		**/
		enum AttributeFlags
		{
			MSH_COLOR					= 0x0001,	///<The mesh will be generated with per-vertex colors, if possible.
			MSH_NORMAL					= 0x0002,	///<The mesh will be generated with per-normals colors, if possible.
			MSH_TANGENT_SPACE_BASIS		= 0x0006,	///<The mesh will be generated with a tangent-space basis (normal/tangent/binormal), if possible. Obviously includes the normal.
			MSH_TEXTURE_COORD			= 0x0008,	///<The mesh will be generated with a set of 2D texture coordinates, if possible.
		};

		///@}
	}
}




#endif //GLSDK_MESH_GENERATOR_DESCRIPTORS_H
