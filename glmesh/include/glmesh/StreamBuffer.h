
#ifndef STREAM_BUFFER_MESH_H
#define STREAM_BUFFER_MESH_H

/**
\file
\brief Declares the StreamBuffer class. Include an OpenGL header before including this one.
**/

#include <string>
#include <exception>


namespace glmesh
{
	///\addtogroup module_glmesh_exceptions
	///@{

	///Base class for all exceptions thrown by StreamBuffer and StreamBuffer::Map.
	class StreamBufferException : public std::exception
	{
	public:
		virtual ~StreamBufferException() throw() {}

		virtual const char *what() {return message.c_str();}

	protected:
		std::string message;
	};

	///Thrown when the StreamBuffer is mapped and you attempt to call a function that requires the StreamBuffer to not be mapped.
	class StoreAlreadyMappedException : public StreamBufferException
	{
	public:
		StoreAlreadyMappedException()
		{
			message = "The StreamBuffer is already mapped; this operation can only be performed if unmapped.";
		}
	};

	///Thrown when mapping a StreamBuffer and it does not have enough room for the requested map size.
	class NotEnoughStorageForMapException : public StreamBufferException
	{
	public:
		NotEnoughStorageForMapException(size_t requestedSize, size_t bufferSize);
	};

	///Thrown when mapping a StreamBuffer and the current offset + range would exceed the size of the StreamBuffer.
	class NotEnoughRemainingStorageForMapException : public StreamBufferException
	{
	public:
		NotEnoughRemainingStorageForMapException(size_t pos, size_t requestedSize, size_t bufferSize);
	};

	///@}


	///\addtogroup module_glmesh_draw
	///@{

	/**
	\brief A class for streaming vertex data to buffer objects on the GPU.

	This class is specifically used for efficiently streaming vertex data to the GPU. It
	can map some part of the buffer, invalidate the buffer, and so forth. It also stores a convenient
	vertex array object, if VAO's are available.

	The StreamBuffer has the concept of a current position within the buffer. Each time the buffer
	is mapped, the current position is advanced by the space mapped; the assumption being that
	you have written to all of the data requested. The user can ask how much space is left
	in the StreamBuffer.

	StreamBuffer cannot be copied, as performing a deep-copy would not be a good idea.
	**/
	class StreamBuffer
	{
	public:
		/**
		\brief Creates a StreamBuffer with the given size. The size cannot be changed later.

		When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.
		**/
		StreamBuffer(size_t bufferSize);
		~StreamBuffer();

		/**
		\brief Retrieve a communal VAO. If VAO is not defined, returns 0.
		**/
		GLuint GetVao() {return m_vao;}

		/**
		\brief Retrieve the buffer object.
		**/
		GLuint GetBuffer() {return m_bufferObject;}

		/**
		\brief Gets the current position within the buffer object.
		**/
		size_t GetBufferPosition() const {return m_currOffset;}

		/**
		\brief Return how much room there is between the current position and the end of the buffer.
		**/
		size_t GetSpaceRemaining() const;

		/**
		\brief Retrieves the total size of the buffer.
		**/
		size_t GetTotalBufferSize() const {return m_bufferSize;}

		/**
		\brief Causes all data in the buffer to be lost; the current position is reset to 0.

		When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.

		\throw StoreAlreadyMapped Thrown if the StreamBuffer is already mapped.
		**/
		void InvalidateBuffer();

		/**
		\ingroup module_glmesh_draw
		\brief A RAII-style class for mapping a StreamBuffer.
		
		This object is the proper way to update the buffer's storage. It maps the buffer, containing a
		pointer to the buffer's contents that can only be written to. The user must ensure not to write
		outside of the byte range that was mapped.

		When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.
		**/
		class Map
		{
		public:
			/**
			\brief Maps the number of bytes.

			This function will change 

			\param storage The StreamBuffer to map.
			\param numBytes The number of bytes to map. Must be less than the buffer's storage.
			\param invalidateIfNotAvailable If \a numBytes is greater than storage.GetSpaceRemaining(),
			if this parameter is true, then the buffer will be invalidated before mapping. If it is false,
			then an exception is thrown.

			When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.

			\note The mapping of the buffer can cause invalidation, as though by InvalidateBuffer.
			Because of this, the current position can \em change due to this function. So if you
			pass true for \a invalidateIfNotAvailable, then you should make sure to get the offset
			\em after the mapping, but before the unmapping.

			\throw ddd Thrown if \a numBytes is larger than the storage size of the buffer.
			\throw ddd Thrown if \a numBytes is larger than the remaining space and
			\a invalidateIfNotAvailable is false.
			\throw ddd Thrown if \a storage is already currently mapped.
			**/
			Map(StreamBuffer &storage, size_t numBytes, bool invalidateIfNotAvailable = true);

			/**
			\brief Unmaps the buffer, if it has not already been unmapped.
			
			When this function completes, if the Map was not previously Release()'d,
			the binding state of GL_ARRAY_BUFFER will be 0.
			**/
			~Map();

			/**
			\brief Manually unmaps the buffer.

			In OpenGL, unmapping a buffer can cause the buffer's contents to be lost. Destructors in C++
			should never throw exceptions, so to be able to check for this condition, we allow for the
			buffer to be unmapped manually.

			The current position within the buffer will be advanced by the number of bytes mapped.

			When this function completes, if the Map was not previously Release()'d,
			the binding state of GL_ARRAY_BUFFER will be 0.

			\return true if the buffer's contents are fine. False if they are lost, or
			if Release() was called once before
			**/
			bool Release();

			/**
			\brief Retrieve the mapped pointer. Will return NULL if Release() was called.
			**/
			void *GetPtr() {return m_pCurrPtr;}

		private:
			StreamBuffer *m_pData;
			void *m_pCurrPtr;
			size_t m_bytesMapped;

			//No copying.
			Map(const Map&);
			Map& operator=(const Map&);
		};

	private:
		GLuint m_bufferObject;
		const size_t m_bufferSize;

		size_t m_currOffset;
		bool m_isMapped;

		GLuint m_vao;

		StreamBuffer(const StreamBuffer &);
		StreamBuffer &operator=(const StreamBuffer &);
	};
	///@}
}

#endif //STREAM_BUFFER_MESH_H
