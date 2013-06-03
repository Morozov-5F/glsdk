
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glload/gl_all.h>
#include "ResourceData.h"
#include "glscene/Resources.h"

namespace glscene
{
	namespace
	{
		struct UniformsAreSameTypeBinaryVisit : public boost::static_visitor<bool>
		{
			bool operator()(const VectorTypes &data1, const VectorTypes &data2) const
			{
				return boost::apply_visitor(*this, data1, data2);
			}

			bool operator()(const IntVectorTypes &data1, const IntVectorTypes &data2) const
			{
				return boost::apply_visitor(*this, data1, data2);
			}

			bool operator()(const UIntVectorTypes &data1, const UIntVectorTypes &data2) const
			{
				return boost::apply_visitor(*this, data1, data2);
			}

			bool operator()(const MatrixTypes &data1, const MatrixTypes &data2) const
			{
				return boost::apply_visitor(*this, data1, data2);
			}

			template<typename T>
			bool operator()(const T&, const T&) const {return true;}

			template<typename T, typename U>
			bool operator()(const T&, const U&) const {return false;}
		};

		struct UniformTypenameVisit : public boost::static_visitor<std::string>
		{
			std::string operator()(const VectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			std::string operator()(const IntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			std::string operator()(const UIntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			std::string operator()(const MatrixTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			std::string operator()(const float &) const {return "float";}
			std::string operator()(const glm::vec2 &) const {return "vec2";}
			std::string operator()(const glm::vec3 &) const {return "vec3";}
			std::string operator()(const glm::vec4 &) const {return "vec4";}
			std::string operator()(const int &) const {return "signed int";}
			std::string operator()(const glm::ivec2 &) const {return "ivec2";}
			std::string operator()(const glm::ivec3 &) const {return "ivec3";}
			std::string operator()(const glm::ivec4 &) const {return "ivec4";}
			std::string operator()(const unsigned int &) const {return "unsigned int";}
			std::string operator()(const glm::uvec2 &) const {return "uvec2";}
			std::string operator()(const glm::uvec3 &) const {return "uvec3";}
			std::string operator()(const glm::uvec4 &) const {return "uvec4";}
			std::string operator()(const glm::mat2 &) const {return "mat2";}
			std::string operator()(const glm::mat3 &) const {return "mat3";}
			std::string operator()(const glm::mat4 &) const {return "mat4";}
		};

		struct UniformApplyBindVisit : public boost::static_visitor<>
		{
			GLint uniformLoc;

			UniformApplyBindVisit(GLint loc) : uniformLoc(loc) {}

			void operator()(const VectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const IntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const UIntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const MatrixTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const float &data) const {glUniform1f(uniformLoc, data);}
			void operator()(const glm::vec2 &data) const {glUniform2f(uniformLoc, data.x, data.y);}
			void operator()(const glm::vec3 &data) const {glUniform3f(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::vec4 &data) const {glUniform4f(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const int &data) const {glUniform1i(uniformLoc, data);}
			void operator()(const glm::ivec2 &data) const {glUniform2i(uniformLoc, data.x, data.y);}
			void operator()(const glm::ivec3 &data) const {glUniform3i(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::ivec4 &data) const {glUniform4i(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const unsigned int &data) const {glUniform1ui(uniformLoc, data);}
			void operator()(const glm::uvec2 &data) const {glUniform2ui(uniformLoc, data.x, data.y);}
			void operator()(const glm::uvec3 &data) const {glUniform3ui(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::uvec4 &data) const {glUniform4ui(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const glm::mat2 &data) const {glUniformMatrix2fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
			void operator()(const glm::mat3 &data) const {glUniformMatrix3fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
			void operator()(const glm::mat4 &data) const {glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
		};

		struct UniformApplyDSAVisit : public boost::static_visitor<>
		{
			GLuint prog;
			GLint uniformLoc;

			UniformApplyDSAVisit(GLuint _prog, GLint loc) : prog(_prog), uniformLoc(loc) {}

			void operator()(const VectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const IntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const UIntVectorTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const MatrixTypes &data1) const
			{
				return boost::apply_visitor(*this, data1);
			}

			void operator()(const float &data) const {glProgramUniform1f(prog, uniformLoc, data);}
			void operator()(const glm::vec2 &data) const {glProgramUniform2f(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::vec3 &data) const {glProgramUniform3f(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::vec4 &data) const {glProgramUniform4f(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const int &data) const {glProgramUniform1i(prog, uniformLoc, data);}
			void operator()(const glm::ivec2 &data) const {glProgramUniform2i(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::ivec3 &data) const {glProgramUniform3i(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::ivec4 &data) const {glProgramUniform4i(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const unsigned int &data) const {glProgramUniform1ui(prog, uniformLoc, data);}
			void operator()(const glm::uvec2 &data) const {glProgramUniform2ui(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::uvec3 &data) const {glProgramUniform3ui(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::uvec4 &data) const {glProgramUniform4ui(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const glm::mat2 &data) const {glProgramUniformMatrix2fv(prog, uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
			void operator()(const glm::mat3 &data) const {glProgramUniformMatrix3fv(prog, uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
			void operator()(const glm::mat4 &data) const {glProgramUniformMatrix4fv(prog, uniformLoc, 1, GL_FALSE, glm::value_ptr(data));}
		};

	}

	void ResourceData::DefineUniform( const IdString &resource, const std::string &uniformName, UniformData data )
	{
		if(m_uniformData.find(resource) != m_uniformData.end())
			throw ResourceMultiplyDefinedException(resource, "uniform");

		UniformValue &value = m_uniformData[resource];
		value.uniformName = uniformName;
		value.data = data;
	}

	void ResourceData::SetUniform( const IdString &resource, UniformData data )
	{
		UniformMap::iterator theVal = m_uniformData.find(resource);

		if(theVal == m_uniformData.end())
			throw ResourceNotFoundException(resource, "uniform");

		if(!boost::apply_visitor(UniformsAreSameTypeBinaryVisit(), theVal->second.data, data))
		{
			throw UniformResourceTypeMismatchException(resource,
				boost::apply_visitor(UniformTypenameVisit(), theVal->second.data),
				boost::apply_visitor(UniformTypenameVisit(), data));
		}

		theVal->second.data = data;
	}

	GLint ResourceData::GetUniformLocation( GLuint program, const IdString &resource ) const
	{
		UniformMap::iterator theVal = m_uniformData.find(resource);

		if(theVal == m_uniformData.end())
			throw ResourceNotFoundException(resource, "uniform");

		GLint loc = glGetUniformLocation(program, theVal->second.uniformName.c_str());
		return loc;
	}

	void ResourceData::ApplyUniform( const IdString &resource, GLint uniformLocation ) const
	{
		UniformMap::const_iterator theVal = m_uniformData.find(resource);

		if(theVal == m_uniformData.end())
			throw ResourceNotFoundException(resource, "uniform");

		boost::apply_visitor(UniformApplyBindVisit(uniformLocation), theVal->second.data);
	}

	void ResourceData::ApplyUniform( GLuint program, const IdString &resource, GLint uniformLocation ) const
	{
		UniformMap::const_iterator theVal = m_uniformData.find(resource);

		if(theVal == m_uniformData.end())
			throw ResourceNotFoundException(resource, "uniform");

		boost::apply_visitor(UniformApplyDSAVisit(program, uniformLocation), theVal->second.data);
	}

	void ResourceData::DefineTexture( const std::string &resource, GLuint textureObj,
		GLenum target, bool claimOwnership )
	{
		if(m_textureData.find(resource) != m_textureData.end())
			throw ResourceMultiplyDefinedException(resource, "texture");

		TextureData &value = m_textureData[resource];
		value.owned = claimOwnership;
		value.target = target;
		value.textureObj = textureObj;
	}
}

