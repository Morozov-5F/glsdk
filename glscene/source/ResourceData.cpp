
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <boost/foreach.hpp>
#include <glload/gl_all.h>
#include "ResourceData.h"
#include "glscene/Resources.h"
#include "glscene/SceneGraph.h"

namespace glscene
{
	ResourceData::~ResourceData()
	{
		BOOST_FOREACH(TextureMap::value_type &texData, m_textureData)
		{
			if(texData.second && texData.second->owned)
				glDeleteTextures(1, &texData.second->textureObj);
		}

		BOOST_FOREACH(SamplerMap::value_type &samplerData, m_samplerData)
		{
			glDeleteSamplers(1, &samplerData.second);
		}
	}

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


		GLuint CreateSampler(const SamplerInfo &info)
		{
			GLuint sampler;
			glGenSamplers(1, &sampler);
			glSamplerParameteri(sampler, GL_TEXTURE_MAG_FILTER, info.magFilter);
			glSamplerParameteri(sampler, GL_TEXTURE_MIN_FILTER, info.minFilter);
			glSamplerParameterf(sampler, GL_TEXTURE_MAX_ANISOTROPY_EXT, info.maxAniso);
			glSamplerParameteri(sampler, GL_TEXTURE_WRAP_S, info.edgeFilterS);
			glSamplerParameteri(sampler, GL_TEXTURE_WRAP_T, info.edgeFilterT);
			glSamplerParameteri(sampler, GL_TEXTURE_WRAP_R, info.edgeFilterR);
			if(info.compareFunc)
			{
				glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
				glSamplerParameteri(sampler, GL_TEXTURE_COMPARE_FUNC, info.compareFunc.get());
			}
			return sampler;
		}
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
		UniformMap::const_iterator theVal = m_uniformData.find(resource);

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
		TextureMap::iterator test_it = m_textureData.find(resource);
		if(test_it != m_textureData.end())
		{
			if(test_it->second)
				throw ResourceMultiplyDefinedException(resource, "texture");
		}

		TextureData value;
		value.owned = claimOwnership;
		value.target = target;
		value.textureObj = textureObj;

		m_textureData[resource] = value;
	}

	void ResourceData::DefineTexture( const std::string &resource )
	{
		if(m_textureData.find(resource) != m_textureData.end())
			throw ResourceMultiplyDefinedException(resource, "texture");

		m_textureData[resource] = boost::none;
	}

	void ResourceData::BindTexture( const std::string &resource, GLuint textureUnit ) const
	{
		TextureMap::const_iterator theVal = m_textureData.find(resource);

		if(theVal == m_textureData.end())
			throw ResourceNotFoundException(resource, "texture");

		if(!theVal->second)
			throw NodeRequestedUnknownResourceException(resource, "texture");

		glActiveTexture(GL_TEXTURE0 + textureUnit);
		glBindTexture(theVal->second->target, theVal->second->textureObj);
	}

	void ResourceData::BindImage( const std::string &resource, GLuint imageUnit,
		int mipmapLevel, int imageLayer, GLenum access, GLenum format, bool layered ) const
	{
		TextureMap::const_iterator theVal = m_textureData.find(resource);

		if(theVal == m_textureData.end())
			throw ResourceNotFoundException(resource, "texture");

		if(!theVal->second)
			throw NodeRequestedUnknownResourceException(resource, "texture");

		glBindImageTexture(imageUnit, theVal->second->textureObj, mipmapLevel,
			layered ? GL_TRUE : GL_FALSE, imageLayer, access, format);
	}

	void ResourceData::DefineSampler( const std::string &resource, const SamplerInfo &data )
	{
		if(m_samplerData.find(resource) != m_samplerData.end())
			throw ResourceMultiplyDefinedException(resource, "sampler");

		m_samplerData[resource] = CreateSampler(data);
	}

	void ResourceData::SetSamplerBorderColor( const std::string &resource, const glm::vec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerData.find(resource);

		if(theVal == m_samplerData.end())
			throw ResourceNotFoundException(resource, "sampler");

		glSamplerParameterfv(theVal->second, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerBorderColorI( const std::string &resource, const glm::ivec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerData.find(resource);

		if(theVal == m_samplerData.end())
			throw ResourceNotFoundException(resource, "sampler");

		glSamplerParameterIiv(theVal->second, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerBorderColorI( const std::string &resource, const glm::uvec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerData.find(resource);

		if(theVal == m_samplerData.end())
			throw ResourceNotFoundException(resource, "sampler");

		glSamplerParameterIuiv(theVal->second, GL_TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerLODBias( const std::string &resource, float bias )
	{
		SamplerMap::iterator theVal = m_samplerData.find(resource);

		if(theVal == m_samplerData.end())
			throw ResourceNotFoundException(resource, "sampler");

		glSamplerParameterf(theVal->second, GL_TEXTURE_LOD_BIAS, bias);
	}

	void ResourceData::BindSampler( const std::string &resource, GLuint textureUnit ) const
	{
		SamplerMap::const_iterator theVal = m_samplerData.find(resource);

		if(theVal == m_samplerData.end())
			throw ResourceNotFoundException(resource, "sampler");

		glBindSampler(textureUnit, theVal->second);
	}
}

