
#ifndef GLSDK_MESH_VERTEX_WRITER_H
#define GLSDK_MESH_VERTEX_WRITER_H

/**
\file
\brief Declares the VertexWriter class and its helper types. Include an OpenGL header before including this one.
**/


#include <vector>
#include <string>
#include <exception>
#include <glm/glm.hpp>
#include <glm/gtc/half_float.hpp>
#include "VertexFormat.h"

namespace glmesh
{
	///\addtogroup module_glmesh_exceptions
	///@{

	///Base class for all VertexWriter specific exceptions.
	class VertexWriterException : public std::exception
	{
	public:
		virtual ~VertexWriterException() throw() {}

		virtual const char *what() const throw() {return message.c_str();}

	protected:
		std::string message;
	};

	///Thrown when the type the VertexWriter::Attrib functions are used with does not match the type of the attribute as defined by the VertexFormat.
	class MismatchWriterTypeException : public VertexWriterException
	{
	public:
		MismatchWriterTypeException(int eRequiredType, const std::string &realType);
	};

	///@}

	///\addtogroup module_glmesh_draw
	///@{

	/**
	\brief Base class, using CRTP, that provides a framework for writing vertex attributes to arbitrary locations.

	Vertex attribute writing, such as done in glmesh::Draw, has a lot of boilerplate code that can be shared
	among many different destinations. glmesh::Draw writes to a StreamBuffer. Other writers could write
	to some form of std::vector. And so forth.

	This provides a standard interface for all of them, as well as a solid codebase. To use this, derive from
	VertexWriter using the CRTP:

	\code
	class Derived : public VertexWriter<Derived> ...
	\endcode

	Your Derived class needs to provide two methods accessible to VertexWriter. You may make this VertexWriter
	instantiation a friend of your Derived class, to keep these hidden. It must provide:

	\code
	const VertexFormat &GetVertexFormat() const;
	void WriteAttribute(const void *pData, size_t bytesPerComponent, size_t currAttrib);
	\endcode

	GetVertexFormat just gets a VertexFormat instance, which represents the format of the data used for this
	writer. It should not change from call to call.

	WriteAttribute will be called to write an attribute's data. The \a pData argument is a pointer to a buffer 
	that is \a bytesPerComponent * 4 in size. You should copy a number of components worth of data, based
	on the VertexFormat and the \a currAttrib index. \a currAttrib is the current vertex attribute
	for the data being written.

	This class provides GetCurrAttrib as a protected member function. This returns the current attribute
	index.
	**/
	template<typename Sink>
	class VertexWriter
	{
	public:
		///Creates a VertexWriter class instance.
		VertexWriter() : m_currAttrib(0) {}

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

		If you get an unresolved external error for some form of VertexWriter::Attrib, it is because you are
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

		\throw MismatchWriterTypeException If the type you are using does not exactly match the type
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
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, y, BaseType(0), BaseType(1)));
		}

		template<typename BaseType>
		void Attrib(const glm::detail::tvec2<BaseType> &val)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(val, BaseType(0), BaseType(1)));
		}

		template<typename BaseType>
		void Attrib(BaseType x, BaseType y, BaseType z)
		{
			Attrib<BaseType>(glm::detail::tvec4<BaseType>(x, y, z, BaseType(1)));
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

	protected:
		///Retrieves the current vertex attribute index, to be used with VertexFormat::GetAttribDesc.
		size_t GetCurrAttrib() const {return m_currAttrib;}

	private:
		template<typename BaseType> void VerifyType();
		void IncrementCurrAttrib()
		{
			++m_currAttrib;
			if(Owner()->GetVertexFormat().GetNumAttribs() == m_currAttrib)
				m_currAttrib = 0;
		}

		Sink *Owner() {return static_cast<Sink*>(this);}
		const Sink *Owner() const {return static_cast<const Sink*>(this);}

		size_t m_currAttrib;


		template<>
		inline void VerifyType<glm::half>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_HALF_FLOAT)
				throw MismatchWriterTypeException(eType, "half");
		}

		template<>
		inline void VerifyType<GLfloat>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_SINGLE_FLOAT)
				throw MismatchWriterTypeException(eType, "float");
		}

		template<>
		inline void VerifyType<GLdouble>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_DOUBLE_FLOAT)
				throw MismatchWriterTypeException(eType, "double");
		}

		template<>
		inline void VerifyType<GLbyte>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_SIGN_BYTE)
				throw MismatchWriterTypeException(eType, "signed byte");
		}

		template<>
		inline void VerifyType<GLubyte>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_UNSIGN_BYTE)
				throw MismatchWriterTypeException(eType, "unsigned byte");
		}

		template<>
		inline void VerifyType<GLshort>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_SIGN_SHORT)
				throw MismatchWriterTypeException(eType, "signed short");
		}

		template<>
		inline void VerifyType<GLushort>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_UNSIGN_SHORT)
				throw MismatchWriterTypeException(eType, "unsigned short");
		}

		template<>
		inline void VerifyType<GLint>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_SIGN_INT)
				throw MismatchWriterTypeException(eType, "signed int");
		}

		template<>
		inline void VerifyType<GLuint>()
		{
			const VertexFormat &fmt = Owner()->GetVertexFormat();
			VertexDataType eType = fmt.GetAttribDesc(m_currAttrib).GetVertexDataType();
			if(eType != VDT_UNSIGN_INT)
				throw MismatchWriterTypeException(eType, "unsigned int");
		}

		template<>
		inline void Attrib<glm::half>(const glm::detail::tvec4<glm::half> &val)
		{
			VerifyType<glm::half>();
			glm::half theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(glm::half), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLfloat>(const glm::detail::tvec4<GLfloat> &val)
		{
			VerifyType<GLfloat>();
			GLfloat theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLfloat), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLdouble>(const glm::detail::tvec4<GLdouble> &val)
		{
			VerifyType<GLdouble>();
			GLdouble theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLdouble), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLbyte>(const glm::detail::tvec4<GLbyte> &val)
		{
			VerifyType<GLbyte>();
			GLbyte theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLbyte), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLubyte>(const glm::detail::tvec4<GLubyte> &val)
		{
			VerifyType<GLubyte>();
			GLubyte theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLubyte), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLshort>(const glm::detail::tvec4<GLshort> &val)
		{
			VerifyType<GLshort>();
			GLshort theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLshort), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLushort>(const glm::detail::tvec4<GLushort> &val)
		{
			VerifyType<GLushort>();
			GLushort theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLushort), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLint>(const glm::detail::tvec4<GLint> &val)
		{
			VerifyType<GLint>();
			GLint theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLint), m_currAttrib);
			IncrementCurrAttrib();
		}

		template<>
		inline void Attrib<GLuint>(const glm::detail::tvec4<GLuint> &val)
		{
			VerifyType<GLuint>();
			GLuint theData[4];
			theData[0] = val[0];
			theData[1] = val[1];
			theData[2] = val[2];
			theData[3] = val[3];
			Owner()->WriteAttribute(theData, sizeof(GLuint), m_currAttrib);
			IncrementCurrAttrib();
		}
	};

	///@}
}



#endif //GLSDK_MESH_VERTEX_WRITER_H
