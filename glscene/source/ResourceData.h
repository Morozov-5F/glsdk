#ifndef GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H
#define GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H

#include <string>
#include <glm/glm.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/optional.hpp>
#include <glmesh/Mesh.h>

namespace glscene
{
	typedef std::string IdString;
	typedef boost::variant<float, glm::vec2, glm::vec3, glm::vec4> VectorTypes;
	typedef boost::variant<int, glm::ivec2, glm::ivec3, glm::ivec4> IntVectorTypes;
	typedef boost::variant<unsigned int, glm::uvec2, glm::uvec3, glm::uvec4> UIntVectorTypes;
	typedef boost::variant<glm::mat2, glm::mat3, glm::mat4> MatrixTypes;
	typedef boost::variant<VectorTypes, IntVectorTypes, UIntVectorTypes, MatrixTypes> UniformData;

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
		glmesh::Mesh *pMesh;
		bool owned;
	};

	struct ProgramData
	{
		GLuint program;
		bool owned;
		GLuint unifModelToCameraMatrix;
		boost::optional<GLuint> unifNormalModelToCameraMatrix;
		boost::optional<GLuint> unifNormalCameraToModelMatrix;
	};

	struct SamplerInfo;
	struct ProgramInfo;

	typedef boost::container::flat_map<IdString, UniformValue> UniformMap;
	typedef boost::container::flat_map<IdString, boost::optional<TextureData> > TextureMap;
	typedef boost::container::flat_map<IdString, GLuint> SamplerMap;
	typedef boost::container::flat_map<IdString, MeshData> MeshMap;
	typedef boost::container::flat_map<IdString, ProgramData> ProgramMap;

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
		void DefineUniform(const IdString &resource, const std::string &uniformName, UniformData data);

		void SetUniform(const IdString &resource, UniformData data);

		//Throws ResourceNotFoundException
		GLint GetUniformLocation(GLuint program, const IdString &resource) const;

		//Sets the given uniform into the given program, via glUniform.
		void ApplyUniform(const IdString &resource, GLint uniformLocation) const;
		//Sets the given uniform into the given program, via glProgramUniform.
		void ApplyUniform(GLuint program, const IdString &resource, GLint uniformLocation) const;


		void DefineTexture(const std::string &resource, GLuint textureObj,
			GLenum target, bool claimOwnership);
		void DefineTexture(const std::string &resource);

		void BindTexture(const std::string &resource, GLuint textureUnit) const;
		void BindImage(const std::string &resource, GLuint imageUnit, int mipmapLevel, int imageLayer,
			GLenum access, GLenum format, bool layered) const;

		void DefineSampler(const std::string &resource, const SamplerInfo &sampler);

		void SetSamplerBorderColor(const std::string &resource, const glm::vec4 &color);
		void SetSamplerBorderColorI(const std::string &resource, const glm::ivec4 &color);
		void SetSamplerBorderColorI(const std::string &resource, const glm::uvec4 &color);

		void SetSamplerLODBias(const std::string &resource, float bias);

		void BindSampler(const std::string &resource, GLuint textureUnit) const;

		void DefineMesh(const std::string &resource, glmesh::Mesh *pMesh, bool claimOwnership);
		void DefineMesh(const std::string &resource);

		void RenderMesh(const std::string &resource) const;
		void RenderMesh(const std::string &resource, const std::string &variant) const;

		void DefineProgram(const std::string &resource, GLuint program,
			const ProgramInfo &programInfo, bool claimOwnership);

		GLuint GetProgram(const std::string &resource);


		~ResourceData();

	private:
		UniformMap m_uniformMap;
		TextureMap m_textureMap;
		SamplerMap m_samplerMap;
		MeshMap m_meshMap;
		ProgramMap m_programMap;
	};
}


#endif //GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H
