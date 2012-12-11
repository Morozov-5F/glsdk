
#ifndef GLSDK_MESH_DRAW_WITH_BOOST_H
#define GLSDK_MESH_DRAW_WITH_BOOST_H

#include "Draw.h"
#include "VertexFormat.h"
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/adapted/boost_tuple.hpp>
#include <boost/fusion/include/boost_tuple.hpp>

namespace glmesh
{
	namespace _detail
	{
		template<typename AttribType>
		struct AttribTypeTraits
		{
			typedef AttribType value_type;
		};

		template<typename T>
		struct AttribTypeTraits<glm::detail::tvec1<T> >
		{
			typedef T value_type;
		};

		template<typename T>
		struct AttribTypeTraits<glm::detail::tvec2<T> >
		{
			typedef T value_type;
		};

		template<typename T>
		struct AttribTypeTraits<glm::detail::tvec3<T> >
		{
			typedef T value_type;
		};

		template<typename T>
		struct AttribTypeTraits<glm::detail::tvec4<T> >
		{
			typedef T value_type;
		};


		struct WriteAttrib
		{
			WriteAttrib(Draw &drawable) : m_drawable(drawable) {}

			template<typename AttribType>
			void operator()(const AttribType &attribute) const
			{
				m_drawable.Attrib<typename AttribTypeTraits<AttribType>::value_type>(attribute);
			}

		private:
			mutable Draw &m_drawable;
		};
	}

	template<typename VertexSequence>
	void Attrib(Draw &drawable, const VertexSequence &vertexData)
	{
		boost::fusion::for_each(vertexData, _detail::WriteAttrib(drawable));
	}
}



#endif //GLSDK_MESH_DRAW_WITH_BOOST_H
