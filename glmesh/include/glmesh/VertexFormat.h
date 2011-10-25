
#ifndef VERTEX_FORMAT_MESH_H
#define VERTEX_FORMAT_MESH_H

/**
\file
\brief Declares the VertexFormat class and its helper types. Include an OpenGL header before including this one.

**/

#include <vector>

namespace glmesh
{
	///\addtogroup module_glmesh_draw
	///@{

	/**
	\brief The C data type that you will be providing the vertex attribute data in.
	**/
	enum VertexDataType
	{
		VDT_HALF,
		VDT_FLOAT,

		VDT_SIGN_BYTE,
		VDT_UNSIGN_BYTE,
		VDT_SIGN_SHORT,
		VDT_UNSIGN_SHORT,
		VDT_SIGN_INT,
		VDT_UNSIGN_INT,
	};

	/**
	\brief The expected interpretation of the attribute data by GLSL.

	This type must match its corresponding VertexDataType or an error will result. For example, floating-point
	VDTs cannot use normalized float or integer ADTs.
	**/
	enum AttribDataType
	{
		ADT_FLOAT,			
		ADT_NORM_FLOAT,
		ADT_INTEGER,
	};


	/**
	\brief A basic description of the storage for a single vertex attribute.
	
	\note A valid OpenGL context must be active to create one of these objects.
	**/
	class AttribDesc
	{
	public:
		/**
		\brief Creates a valid AttribDesc

		\throw ddd If \a attribIndex is outside the allowed range of OpenGL.
		\throw ddd If \a vertType and \a attribType do not match.
		\throw ddd If \a numComponents is not on the range [1, 4].
		
		**/
		AttribDesc(unsigned int attribIndex, unsigned int numComponents,
			VertexDataType vertType, AttribDataType attribType);

	private:
		unsigned int m_attribIndex;
		unsigned int m_numComponents;
		VertexDataType m_vertType;
		AttribDataType m_attribType;
	};

	/**
	\brief Describes the layout for a sequence of vertex attributes, to be used for rendering.
	**/
	class VertexFormat
	{
	public:
		/**
		\brief Creates a VertexFormat from a sequence of AttribDesc objects.
		
		\throw ddd If any of the \a attribs refer to the same attribute index as any of the others.
		**/
		VertexFormat(const std::vector<AttribDesc> &attribs);

		///Retrieves the size of an entire vertex, including any padding.
		size_t GetVertexByteSize() const;

		///Gets the number of vertex attributes.
		int GetNumAttribs() const;

		///Gets the AttribDesc, given an index between 0 and GetNumAttribs.
		AttribDesc GetAttribDesc(int attribIx) const;

		///Gets the byte offset for a particular attribute, given an index between 0 and GetNumAttribs.
		size_t GetAttribByteOffset(int attribIx) const;

		/**
		\ingroup module_glmesh_draw
		\brief RAII-style class for binding a VertexFormat to the OpenGL context. The destructor unbinds it.

		This class assumes that a valid VAO is bound, as well as that all vertex data comes from a buffer
		object which has also been bound to GL_ARRAY_BUFFER.
		**/
		class Enable
		{
		public:
			///Binds the vertex format to the OpenGL context, given a byte offset to the first vertex.
			Enable(const VertexFormat &fmt, size_t baseOffset);

			///Unbinds the vertex format from the OpenGL context.
			~Enable();

		private:
			const VertexFormat &m_fmt;

			//No copying.
			Enable(const Enable &);
			Enable &operator=(const Enable &);
		};

	private:
		std::vector<AttribDesc> m_attribs;

	};

	///@}
}


#endif //VERTEX_FORMAT_MESH_H
