
#include <glload/gl_all.hpp>
#include <glload/gll.hpp>
#include "glmesh/DataStore.h"

namespace glmesh
{
	namespace
	{
		bool HasVAO()
		{
			if(glload::IsVersionGEQ(3, 0) || glext_ARB_vertex_array_object)
				return true;

			return false;
		}
	}

	DataStore::DataStore( size_t bufferSize )
		: m_bufferObject(0)
		, m_bufferSize(bufferSize)
		, m_currOffset(0)
		, m_isMapped(false)
		, m_vao(0)
	{
		gl::GenBuffers(1, &m_bufferObject);
		gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_bufferObject);
		gl::BufferData(gl::GL_ARRAY_BUFFER, bufferSize, NULL, gl::GL_STREAM_DRAW);
		gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);

		if(HasVAO())
			gl::GenVertexArrays(1, &m_vao);
	}

	DataStore::~DataStore()
	{
		if(m_vao)
		{
			gl::DeleteVertexArrays(1, &m_vao);
			m_vao = 0;
		}

		gl::DeleteBuffers(1, &m_bufferObject);
		m_bufferObject = 0;
	}

	size_t DataStore::GetSpaceRemaining() const
	{
		return m_bufferSize - m_currOffset;
	}

	void DataStore::InvalidateBuffer()
	{
		gl::BindBuffer(gl::GL_ARRAY_BUFFER, m_bufferObject);
		gl::BufferData(gl::GL_ARRAY_BUFFER, m_bufferSize, NULL, gl::GL_STREAM_DRAW);
		gl::BindBuffer(gl::GL_ARRAY_BUFFER, 0);
	}


	DataStore::Map::Map( DataStore &storage, size_t numBytes, bool invalidateIfNotAvailable )
		: m_pData(&storage)
		, m_pCurrPtr(NULL)
	{
		
	}

	DataStore::Map::~Map()
	{

	}
}
