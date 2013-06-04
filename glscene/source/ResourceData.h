#ifndef GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H
#define GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H

#include <string>
#include <glm/glm.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/variant.hpp>
#include <boost/variant/static_visitor.hpp>
#include <boost/optional.hpp>

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

	typedef boost::container::flat_map<IdString, UniformValue> UniformMap;
	typedef boost::container::flat_map<IdString, boost::optional<TextureData> > TextureMap;

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

		~ResourceData();

	private:
		UniformMap m_uniformData;
		TextureMap m_textureData;
	};
}


#endif //GLSDK_INTERNAL_GLGRAPH_RESOURCE_DATA_H
