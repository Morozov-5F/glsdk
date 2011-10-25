
#ifndef DATA_STORE_MESH_H
#define DATA_STORE_MESH_H

/**
\file
\brief Declares the DataStore class. Include an OpenGL header before including this one.
**/


namespace glmesh
{

	///\addtogroup module_glmesh_draw
	///@{

	/**
	\brief A class for streaming vertex data to buffer objects on the GPU.

	This class is specifically used for efficiently streaming vertex data to the GPU. It
	can map some part of the buffer, invalidate the buffer, and so forth. It also stores a convenient
	vertex array object, if VAO's are available.

	The DataStore has the concept of a current position within the buffer. Each time the buffer
	is mapped, the current position is advanced by the space mapped; the assumption being that
	you have written to all of the data requested. The user can ask how much space is left
	in the DataStore.

	DataStore cannot be copied, as performing a deep-copy would not be a good idea.
	**/
	class DataStore
	{
	public:
		/**
		\brief Creates a DataStore with the given size. The size cannot be changed later.

		When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.
		**/
		DataStore(size_t bufferSize);
		~DataStore();

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

		\throw ddd Thrown if the DataStore is already mapped.
		**/
		void InvalidateBuffer();

		/**
		\ingroup module_glmesh_draw
		\brief A RAII-style class for mapping a DataStore.
		
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

			\param storage The DataStore to map.
			\param numBytes The number of bytes to map. Must be less than the buffer's storage.
			\param invalidateIfNotAvailable If \a numBytes is greater than storage.GetSpaceRemaining(),
			if this parameter is true, then the buffer will be invalidated before mapping. If it is false,
			then an exception is thrown.

			When this function completes, the binding state of GL_ARRAY_BUFFER will be 0.

			\throw ddd Thrown if \a numBytes is larger than the storage size of the buffer.
			\throw ddd Thrown if \a numBytes is larger than the remaining space and
			\a invalidateIfNotAvailable is false.
			\throw ddd Thrown if \a storage is already currently mapped.
			**/
			Map(DataStore &storage, size_t numBytes, bool invalidateIfNotAvailable = true);

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

			When this function completes, if the Map was not previously Release()'d,
			the binding state of GL_ARRAY_BUFFER will be 0.

			\return true if the buffer's contents are fine. False if they are lost, or
			if Release() was called once before
			**/
			bool Release();

			/**
			\brief Retrieve the mapped pointer. Will return NULL if Release() was called.
			**/
			void *GetPtr();

		private:
			DataStore *m_pData;
			void *m_pCurrPtr;
		};

	private:
		GLuint m_bufferObject;
		const size_t m_bufferSize;

		size_t m_currOffset;
		bool m_isMapped;

		GLuint m_vao;

		DataStore(const DataStore &);
		DataStore &operator=(const DataStore &);
	};
	///@}
}

#endif //DATA_STORE_MESH_H
