
#ifndef DRAW_MESH_H
#define DRAW_MESH_H

/**
\file
\brief Declares the Draw class and its helper types. Include an OpenGL header before including this one.
**/

#include <vector>
#include <string>
#include <exception>
#include <glm/glm.hpp>
#include <glm/gtc/half_float.hpp>
#include "VertexFormat.h"
#include "StreamBuffer.h"

namespace glmesh
{
	///\addtogroup module_glmesh_exceptions
	///@{

	///Base class for all Draw specific exceptions.
	class DrawException : public std::exception
	{
	public:
		virtual ~DrawException() throw() {}

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;
	};

	///Thrown when the type the Draw::Attrib functions are used with does not match the type of the attribute as defined by the VertexFormat.
	class MismatchDrawTypeException : public DrawException
	{
	public:
		MismatchDrawTypeException(int eRequiredType, const std::string &realType);
	};

	///Thrown when drawing with Draw and you did not provide as many vertices as promised.
	class TooFewVerticesSentException : public DrawException
	{
	public:
		TooFewVerticesSentException(int numProvided, size_t numStated);
	};

	///Thrown when calling Attrib and you are writing more vertices than you promised.
	class TooManyVerticesSentException : public DrawException
	{
	public:
		TooManyVerticesSentException()
		{
			message = "You provided more attribute data than you said you would.";
		}
	};

	///Thrown when creating a Draw with a primitive type that the current OpenGL implementation does not support.
	class PrimitiveTypeUnsupportedException : public DrawException
	{
	public:
		PrimitiveTypeUnsupportedException(const std::string &primTypename)
		{
			message = "The primitive type \"" + primTypename + "\" is not supported by OpenGL.";
		}
	};

	///Thrown when the primitive type and vertex count cannot be used together.
	class VertexCountPrimMismatchException : public DrawException
	{
	public:
		VertexCountPrimMismatchException(const std::string &primName, const std::string &primReqs,
			size_t vertexCount);
	};

	///@}

	///\addtogroup module_glmesh_draw
	///@{

	/**
	\brief RAII-style class for immediate-mode type rendering through a VertexFormat and StreamBuffer.

	\note This class cannot be copied.
	**/
	class Draw
	{
	public:
		/**
		\brief Creates a non-copyable object for drawing.

		\param primType The OpenGL primitive type to render.
		\param vertexCount The number of vertices you will provide. This must work with \a primType
		or an exception is thrown.
		\param fmt The format of the attributes in each vertex.
		\param buffer The streaming buffer that will be used to store the vertex data.

		\throw PrimitiveTypeUnsupportedException If \a primType is not supported on the OpenGL implementation.
		\throw VertexCountPrimMismatchException If \a vertexCount does not match \a primType's requirements.
		\throw StreamBuffer::Map Anything that this class throws, except for NotEnoughRemainingStorageForMapException.

		In the event of any exceptions, nothing is mapped and the StreamBuffer is not touched.
		**/
		Draw(GLenum primType, size_t vertexCount, const VertexFormat &fmt, StreamBuffer &buffer);

		/**
		\brief Draws, if the object has not been drawn previously with a call to Render().
		
		Unlike Render, this does not throw exceptions, since throwing exceptions in a destructor is bad.
		By letting this fall off the stack without an explicit render, you are effectively saying
		that you don't care to error check.

		Therefore, if not enough vertices have been provided, then nothing will be rendered.
		**/
		~Draw();

		/**
		\brief Draws the vertex data provided, if the object has not previously been drawn.

		You can only call this after calling the Attrib functions enough times to provide a full set
		of attribute data for all vertices, as specified by \a vertexCount in the constructor.

		\return true if the vertex data was rendered. False if Render has already been called or if the
		unmapping of the buffer failed. In both cases, nothing is rendered.

		\throw TooFewVerticesSentException If you have not provided all of the vertices promised by the vertex count.
		**/
		bool Render();

		/**
		\name Attribute Setting Functions
		
		The Attrib functions set the value of the current attribute.

		The Attrib series of functions are all templates based on certain types that the Draw class
		accepts.
		
		If you attempt to use the wrong type for the current attribute, an exception will be thrown. The
		types must match \em exactly; there is no narrowing or expansion of shorts into bytes or ints.
		Nor is there conversion from signed to unsigned types.

		Though the types must match, the number of components do not have to exactly match. Per
		OpenGL standard conventions, if you provide more components for an attribute than a vertex format
		allows, the extras will be ignored. If you provide fewer, then rest will be filled in with zeros,
		except for fourth (if applicable), which will be 1.

		If you get an unresolved external error for some form of Draw::Attrib, it is because you are
		not using the correct type. The valid types are, in the order defined in VertexDataType:

		\li \c glm::thalf
		\li \c GLfloat
		\li \c GLdouble
		\li \c GLbyte
		\li \c GLubyte
		\li \c GLshort
		\li \c GLushort
		\li \c GLint
		\li \c GLuint

		There are vector versions of these functions. They will work with glm's vector types, but
		only for certain ones. The 3 floating-point types (glm::hvec, glm::vec, glm::dvec) will work.
		And if you specifically use glm::detail::vec#<type>, then you can use vector types directly.
		Otherwise, you should probably stick to the overloads that take a number of scalar values.

		\throw TooManyVerticesSentException If more vertices have been sent than were originally specified.
		\throw MismatchDrawTypeException If the type you are using does not exactly match the type
		specified by the VertexFormat for this attribute.
		**/

		///@{

		template<typename BaseType>
		void Attrib(BaseType x)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, BaseType(0), BaseType(0), BaseType(1)));
		}

		template<typename BaseType>
		void Attrib(BaseType x, BaseType y)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, y, BaseType(0), BaseType(1)))
		}

		template<typename BaseType>
		void Attrib(const glm::detail::tvec2<BaseType> &val)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(val, BaseType(0), BaseType(1)));
		}

		template<typename BaseType>
		void Attrib(BaseType x, BaseType y, BaseType z)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, y, z, BaseType(1)))
		}

		template<typename BaseType>
		void Attrib(const glm::detail::tvec3<BaseType> &val)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(val, BaseType(1)));
		}

		template<typename BaseType>
		void Attrib(BaseType x, BaseType y, BaseType z, BaseType w)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, y, z, w));
		}

		template<typename BaseType>
		void Attrib(const glm::detail::tvec4<BaseType> &val);

		///@}

		template<>
		void Attrib<GLfloat>(const glm::detail::tvec4<GLfloat> &val)
		{
			VerifyType<GLfloat>();
			GLfloat theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			ProcessAttrib(theData, sizeof(GLfloat));
		}


	private:
		GLenum m_primType;
		size_t m_vertexCount;
		const VertexFormat &m_fmt;
		StreamBuffer::Map m_map;
		StreamBuffer &m_buffer;

		const size_t m_bufferOffset;
		size_t m_currAttrib;
		int m_verticesRemaining;
		std::vector<GLubyte> m_tempBuffer;
		

		//No copying.
		Draw(const Draw &);
		Draw& operator=(const Draw&);

		void ProcessAttrib(const void *pData, size_t bytesPerComponent);
		void *GetPtrForAttrib();
		void *GetOutputPtrForVertex();

		template<typename BaseType>
		void VerifyType();

		template<>
		void VerifyType<GLfloat>()
		{
			VertexDataType eType = m_fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_SINGLE_FLOAT)
				throw MismatchDrawTypeException(eType, "float");
		}

		int InternalRender();
	};
	

	///@}
}
#endif //DRAW_MESH_H
