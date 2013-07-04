#ifndef GLSDK_INTERNAL_GLSCENE_RESOURCE_DATA_H
#define GLSDK_INTERNAL_GLSCENE_RESOURCE_DATA_H

#include <string>
#include <glm/glm.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/optional.hpp>
#include <glmesh/Mesh.h>
#include <glutil/MousePoles.h>
#include "glscene/ResourceRef.h"
#include "IdString.h"

namespace glscene
{
	typedef boost::variant<float, glm::vec2, glm::vec3, glm::vec4> VectorTypes;
	typedef boost::variant<int, glm::ivec2, glm::ivec3, glm::ivec4> IntVectorTypes;
	typedef boost::variant<unsigned int, glm::uvec2, glm::uvec3, glm::uvec4> UIntVectorTypes;
	typedef boost::variant<glm::mat2, glm::mat3, glm::mat4> MatrixTypes;
	typedef boost::variant<VectorTypes, IntVectorTypes, UIntVectorTypes, MatrixTypes> UniformData;

	class MeshDrawable : public Drawable
	{
	public:
		MeshDrawable(glmesh::Mesh *_pMesh, bool _owned) : pMesh(_pMesh), owned(_owned) {}

		virtual void Draw(const boost::optional<std::string> &param) const
		{
			if(!param)
				pMesh->Render();
			else
				pMesh->Render(param.get());
		}

		virtual ~MeshDrawable()
		{
			if(owned)
				delete pMesh;
		}

	private:
		glmesh::Mesh *pMesh;
		bool owned;
	};

	struct UniformValue
	{
		std::string uniformName;
		UniformData data;
	};

	struct TextureData
	{
		GLuint textureObj;
		GLenum target;
		bool owned;
	};

	struct MeshData
	{
		glscene::Drawable *pMesh;
		bool owned;
	};

	struct ProgramMatrices
	{
		boost::optional<GLuint> unifModelToCamera;
		boost::optional<GLuint> unifNormalModelToCamera;
		boost::optional<GLuint> unifNormalCameraToModel;
	};

	struct ProgramData
	{
		GLuint program;
		bool owned;
		ProgramMatrices matrices;
	};

	struct InterfaceBuffer
	{
		boost::optional<GLuint> bufferObject;
		bool owned;
		GLuint bindPoint;
		GLintptr offset;
		GLsizeiptr size;
	};

	struct SamplerInfo;
	struct ProgramInfo;

	typedef boost::container::flat_map<IdString, UniformValue> UniformMap;
	typedef boost::container::flat_map<IdString, boost::optional<TextureData> > TextureMap;
	typedef boost::container::flat_map<IdString, GLuint> SamplerMap;
	typedef boost::container::flat_map<IdString, MeshData> MeshMap;
	typedef boost::container::flat_map<IdString, ProgramData> ProgramMap;
	typedef boost::container::flat_map<IdString, InterfaceBuffer> InterfaceBufferMap;
	typedef boost::container::flat_map<IdString, glutil::ViewPole> CameraMap;

	template<typename Derived, typename ResultType>
	struct static_uniform_visitor : public boost::static_visitor<ResultType>
	{
		ResultType operator()(const VectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(const IntVectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(const UIntVectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(const MatrixTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(VectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(IntVectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(UIntVectorTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}

		ResultType operator()(MatrixTypes &data) const
		{
			return boost::apply_visitor(*static_cast<const Derived *>(this), data);
		}
	};

	class ResourceData
	{
	public:
		bool AreAnyIncomplete() const {return m_numIncomplete != 0;}

		void DefineUniform(const IdString &resourceId, const std::string &uniformName, UniformData data);
		bool HasUniform(const IdString &resourceId) const;
		void SetUniform(const IdString &resourceId, UniformData data);

		//Throws ResourceNotFoundException
		GLint GetUniformLocation(GLuint program, const IdString &resourceId) const;

		//Sets the given uniform into the given program, via glUniform.
		void ApplyUniform(const IdString &resourceId, GLint uniformLocation) const;
		//Sets the given uniform into the given program, via glProgramUniform.
		void ApplyUniform(GLuint program, const IdString &resourceId, GLint uniformLocation) const;


		void DefineTexture(const IdString &resourceId, GLuint textureObj,
			GLenum target, bool claimOwnership);
		void DefineTextureIncomplete(const IdString &resourceId);
		bool HasTexture(const IdString &resourceId) const;
		//Will crash on a texture not found.
		bool IsTextureComplete(const IdString &resourceId) const;

		void BindTexture(const IdString &resourceId, GLuint textureUnit) const;
		void UnbindTexture(const IdString &resourceId, GLuint textureUnit) const;
		void BindImage(const IdString &resourceId, GLuint imageUnit, int mipmapLevel, int imageLayer,
			GLenum access, GLenum format, bool layered) const;

		void DefineSampler(const IdString &resourceId, const SamplerInfo &sampler);
		bool HasSampler(const IdString &resourceId) const;

		void SetSamplerBorderColor(const IdString &resourceId, const glm::vec4 &color);
		void SetSamplerBorderColorI(const IdString &resourceId, const glm::ivec4 &color);
		void SetSamplerBorderColorI(const IdString &resourceId, const glm::uvec4 &color);

		void SetSamplerLODBias(const IdString &resourceId, float bias);

		void BindSampler(const IdString &resourceId, GLuint textureUnit) const;

		void DefineMesh(const IdString &resourceId, glmesh::Mesh *pMesh, bool claimOwnership);
		void DefineMesh(const IdString &resourceId, glscene::Drawable *pMesh, bool claimOwnership);
		void DefineMeshIncomplete(const IdString &resourceId);
		bool HasMesh(const IdString &resourceId) const;
		//Will crash on a texture not found.
		bool IsMeshComplete(const IdString &resourceId) const;

		void RenderMesh(const IdString &resourceId, const boost::optional<std::string> &variant) const;

		void DefineProgram(const IdString &resourceId, GLuint program,
			const ProgramInfo &programInfo, bool claimOwnership);
		bool HasProgram(const IdString &resourceId) const;

		GLuint GetProgram(const IdString &resourceId) const;
		ProgramMatrices GetProgramMatrices(const IdString &resourceId) const;

		void DefineUniformBufferBinding(const IdString &resourceId, GLuint bufferObject, GLuint bindPoint,
			GLintptr offset, GLsizeiptr size, bool claimOwnership);
		void DefineUniformBufferBinding(const IdString &resourceId, GLuint bufferObject,
			GLintptr offset, bool claimOwnership);
		void DefineUniformBufferBindingIncomplete(const IdString &resourceId, GLuint bindPoint,
			GLsizeiptr size);
		bool HasUniformBufferBinding(const IdString &resourceId) const;
		//Will crash on a texture not found.
		bool IsUniformBufferBindingComplete(const IdString &resourceId) const;

		void DefineStorageBufferBinding(const IdString &resourceId, GLuint bufferObject, GLuint bindPoint,
			GLintptr offset, GLsizeiptr size, bool claimOwnership);
		void DefineStorageBufferBinding(const IdString &resourceId, GLuint bufferObject,
			GLintptr offset, bool claimOwnership);
		void DefineStorageBufferBindingIncomplete(const IdString &resourceId, GLuint bindPoint,
			GLsizeiptr size);
		bool HasStorageBufferBinding(const IdString &resourceId) const;
		//Will crash on a texture not found.
		bool IsStorageBufferBindingComplete(const IdString &resourceId) const;

		void BindUniformBuffer(const IdString &resourceId, GLintptr offset = 0) const;
		void BindStorageBuffer(const IdString &resourceId, GLintptr offset = 0) const;

		GLuint GetUniformBufferBindingIndex(const IdString &resourceId) const;
		GLuint GetStorageBufferBindingIndex(const IdString &resourceId) const;

		void DefineCamera(const IdString &resourceId, const glutil::ViewData &initialView,
			const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls);

		glutil::ViewPole &GetCamera(const IdString &resourceId);
		const glutil::ViewPole &GetCamera(const IdString &resourceId) const;

		ResourceData();
		~ResourceData();

	private:
		UniformMap m_uniformMap;
		TextureMap m_textureMap;
		SamplerMap m_samplerMap;
		MeshMap m_meshMap;
		ProgramMap m_programMap;
		InterfaceBufferMap m_uniformBufferMap;
		InterfaceBufferMap m_storageBufferMap;
		CameraMap m_cameraMap;

		int m_numIncomplete;
	};
}


#endif //GLSDK_INTERNAL_GLSCENE_RESOURCE_DATA_H
