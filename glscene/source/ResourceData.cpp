
#include "pch.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <boost/foreach.hpp>
#include <glload/gl_all.hpp>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include "glscene/ResourceRef.h"
#include "ResourceData.h"
#include "glscene/SceneGraph.h"

namespace glscene
{
	ResourceData::ResourceData()
		: m_numIncomplete(0)
	{}

	ResourceData::~ResourceData()
	{
		std::vector<GLuint> objectsToDelete;
		BOOST_FOREACH(TextureMap::value_type &texData, m_textureMap)
		{
			if(texData.second && texData.second->owned)
			{
				if(boost::range::find(objectsToDelete, texData.second->textureObj) == objectsToDelete.end())
					objectsToDelete.push_back(texData.second->textureObj);
			}
		}

		if(!objectsToDelete.empty())
			gl::DeleteTextures(objectsToDelete.size(), &objectsToDelete[0]);
		objectsToDelete.clear();

		BOOST_FOREACH(SamplerMap::value_type &samplerData, m_samplerMap)
		{
			if(boost::range::find(objectsToDelete, samplerData.second) == objectsToDelete.end())
				objectsToDelete.push_back(samplerData.second);
		}

		if(!objectsToDelete.empty())
			gl::DeleteSamplers(objectsToDelete.size(), &objectsToDelete[0]);
		objectsToDelete.clear();

		BOOST_FOREACH(ProgramMap::value_type &programData, m_programMap)
		{
			if(boost::range::find(objectsToDelete, programData.second.program) == objectsToDelete.end())
				objectsToDelete.push_back(programData.second.program);
		}

		if(!objectsToDelete.empty())
			boost::range::for_each(objectsToDelete, gl::DeleteProgram);
		objectsToDelete.clear();

		BOOST_FOREACH(InterfaceBufferMap::value_type &interfaceData, m_uniformBufferMap)
		{
			if(interfaceData.second.bufferObject &&
				boost::range::find(objectsToDelete, interfaceData.second.bufferObject.get()) == objectsToDelete.end())
				objectsToDelete.push_back(interfaceData.second.bufferObject.get());
		}

		BOOST_FOREACH(InterfaceBufferMap::value_type &interfaceData, m_storageBufferMap)
		{
			if(interfaceData.second.bufferObject &&
				boost::range::find(objectsToDelete, interfaceData.second.bufferObject.get()) == objectsToDelete.end())
				objectsToDelete.push_back(interfaceData.second.bufferObject.get());
		}

		if(!objectsToDelete.empty())
			gl::DeleteBuffers(objectsToDelete.size(), &objectsToDelete[0]);
		objectsToDelete.clear();

		BOOST_FOREACH(MeshMap::value_type &meshData, m_meshMap)
		{
			if(meshData.second.owned)
				meshData.second.pMesh->Dispose();
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

			void operator()(const float &data) const {gl::Uniform1f(uniformLoc, data);}
			void operator()(const glm::vec2 &data) const {gl::Uniform2f(uniformLoc, data.x, data.y);}
			void operator()(const glm::vec3 &data) const {gl::Uniform3f(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::vec4 &data) const {gl::Uniform4f(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const int &data) const {gl::Uniform1i(uniformLoc, data);}
			void operator()(const glm::ivec2 &data) const {gl::Uniform2i(uniformLoc, data.x, data.y);}
			void operator()(const glm::ivec3 &data) const {gl::Uniform3i(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::ivec4 &data) const {gl::Uniform4i(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const unsigned int &data) const {gl::Uniform1ui(uniformLoc, data);}
			void operator()(const glm::uvec2 &data) const {gl::Uniform2ui(uniformLoc, data.x, data.y);}
			void operator()(const glm::uvec3 &data) const {gl::Uniform3ui(uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::uvec4 &data) const {gl::Uniform4ui(uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const glm::mat2 &data) const {gl::UniformMatrix2fv(uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
			void operator()(const glm::mat3 &data) const {gl::UniformMatrix3fv(uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
			void operator()(const glm::mat4 &data) const {gl::UniformMatrix4fv(uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
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

			void operator()(const float &data) const {gl::ProgramUniform1f(prog, uniformLoc, data);}
			void operator()(const glm::vec2 &data) const {gl::ProgramUniform2f(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::vec3 &data) const {gl::ProgramUniform3f(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::vec4 &data) const {gl::ProgramUniform4f(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const int &data) const {gl::ProgramUniform1i(prog, uniformLoc, data);}
			void operator()(const glm::ivec2 &data) const {gl::ProgramUniform2i(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::ivec3 &data) const {gl::ProgramUniform3i(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::ivec4 &data) const {gl::ProgramUniform4i(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const unsigned int &data) const {gl::ProgramUniform1ui(prog, uniformLoc, data);}
			void operator()(const glm::uvec2 &data) const {gl::ProgramUniform2ui(prog, uniformLoc, data.x, data.y);}
			void operator()(const glm::uvec3 &data) const {gl::ProgramUniform3ui(prog, uniformLoc, data.x, data.y, data.z);}
			void operator()(const glm::uvec4 &data) const {gl::ProgramUniform4ui(prog, uniformLoc, data.x, data.y, data.z, data.w);}
			void operator()(const glm::mat2 &data) const {gl::ProgramUniformMatrix2fv(prog, uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
			void operator()(const glm::mat3 &data) const {gl::ProgramUniformMatrix3fv(prog, uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
			void operator()(const glm::mat4 &data) const {gl::ProgramUniformMatrix4fv(prog, uniformLoc, 1, gl::FALSE_, glm::value_ptr(data));}
		};


		GLuint CreateSampler(const SamplerInfo &info)
		{
			GLuint sampler;
			gl::GenSamplers(1, &sampler);
			gl::SamplerParameteri(sampler, gl::TEXTURE_MAG_FILTER, info.magFilter);
			gl::SamplerParameteri(sampler, gl::TEXTURE_MIN_FILTER, info.minFilter);
			gl::SamplerParameterf(sampler, gl::TEXTURE_MAX_ANISOTROPY_EXT, info.maxAniso);
			gl::SamplerParameteri(sampler, gl::TEXTURE_WRAP_S, info.edgeFilterS);
			gl::SamplerParameteri(sampler, gl::TEXTURE_WRAP_T, info.edgeFilterT);
			gl::SamplerParameteri(sampler, gl::TEXTURE_WRAP_R, info.edgeFilterR);
			if(info.compareFunc)
			{
				gl::SamplerParameteri(sampler, gl::TEXTURE_COMPARE_MODE, gl::COMPARE_REF_TO_TEXTURE);
				gl::SamplerParameteri(sampler, gl::TEXTURE_COMPARE_FUNC, info.compareFunc.get());
			}
			return sampler;
		}
	}

	void ResourceData::DefineUniform( const IdString &resourceId, const std::string &uniformName, UniformData data )
	{
		if(m_uniformMap.find(resourceId) != m_uniformMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "uniform");

		UniformValue &value = m_uniformMap[resourceId];
		value.uniformName = uniformName;
		value.data = data;
	}

	bool ResourceData::HasUniform( const IdString &resourceId ) const
	{
		return m_uniformMap.find(resourceId) != m_uniformMap.end();
	}

	void ResourceData::SetUniform( const IdString &resourceId, UniformData data )
	{
		UniformMap::iterator theVal = m_uniformMap.find(resourceId);

		if(theVal == m_uniformMap.end())
			throw ResourceNotFoundException(resourceId, "uniform");

		if(!boost::apply_visitor(UniformsAreSameTypeBinaryVisit(), theVal->second.data, data))
		{
			throw UniformResourceTypeMismatchException(resourceId,
				boost::apply_visitor(UniformTypenameVisit(), theVal->second.data),
				boost::apply_visitor(UniformTypenameVisit(), data));
		}

		theVal->second.data = data;
	}

	GLint ResourceData::GetUniformLocation( GLuint program, const IdString &resourceId ) const
	{
		UniformMap::const_iterator theVal = m_uniformMap.find(resourceId);

		if(theVal == m_uniformMap.end())
			throw ResourceNotFoundException(resourceId, "uniform");

		GLint loc = gl::GetUniformLocation(program, theVal->second.uniformName.c_str());
		return loc;
	}

	void ResourceData::ApplyUniform( const IdString &resourceId, GLint uniformLocation ) const
	{
		UniformMap::const_iterator theVal = m_uniformMap.find(resourceId);

		if(theVal == m_uniformMap.end())
			throw ResourceNotFoundException(resourceId, "uniform");

		boost::apply_visitor(UniformApplyBindVisit(uniformLocation), theVal->second.data);
	}

	void ResourceData::ApplyUniform( GLuint program, const IdString &resourceId, GLint uniformLocation ) const
	{
		UniformMap::const_iterator theVal = m_uniformMap.find(resourceId);

		if(theVal == m_uniformMap.end())
			throw ResourceNotFoundException(resourceId, "uniform");

		boost::apply_visitor(UniformApplyDSAVisit(program, uniformLocation), theVal->second.data);
	}

	void ResourceData::DefineTexture( const IdString &resourceId, GLuint textureObj,
		GLenum target, bool claimOwnership )
	{
		TextureMap::iterator test_it = m_textureMap.find(resourceId);
		if(test_it != m_textureMap.end())
		{
			if(test_it->second)
				throw ResourceMultiplyDefinedException(resourceId, "texture");

			//Incomplete becomes complete.
			m_numIncomplete--;
		}

		TextureData value;
		value.owned = claimOwnership;
		value.target = target;
		value.textureObj = textureObj;

		m_textureMap[resourceId] = value;
	}

	void ResourceData::DefineTextureIncomplete( const IdString &resourceId )
	{
		if(m_textureMap.find(resourceId) != m_textureMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "texture");

		m_textureMap[resourceId] = boost::none;
		m_numIncomplete++;
	}

	bool ResourceData::HasTexture( const IdString &resourceId ) const
	{
		return m_textureMap.find(resourceId) != m_textureMap.end();
	}

	bool ResourceData::IsTextureComplete( const IdString &resourceId ) const
	{
		TextureMap::const_iterator theVal = m_textureMap.find(resourceId);
		if(!theVal->second)
			return false;
		return true;
	}

	void ResourceData::BindTexture( const IdString &resourceId, GLuint textureUnit ) const
	{
		TextureMap::const_iterator theVal = m_textureMap.find(resourceId);

		if(theVal == m_textureMap.end())
			throw ResourceNotFoundException(resourceId, "texture");

		if(!theVal->second)
			throw UsingIncompleteResourceException(resourceId, "texture");

		gl::ActiveTexture(gl::TEXTURE0 + textureUnit);
		gl::BindTexture(theVal->second->target, theVal->second->textureObj);
	}

	void ResourceData::UnbindTexture( const IdString &resourceId, GLuint textureUnit ) const
	{
		TextureMap::const_iterator theVal = m_textureMap.find(resourceId);

		if(theVal == m_textureMap.end())
			throw ResourceNotFoundException(resourceId, "texture");

		if(!theVal->second)
			throw UsingIncompleteResourceException(resourceId, "texture");

		gl::ActiveTexture(gl::TEXTURE0 + textureUnit);
		gl::BindTexture(theVal->second->target, 0);
	}

	void ResourceData::BindImage( const IdString &resourceId, GLuint imageUnit,
		int mipmapLevel, int imageLayer, GLenum access, GLenum format, bool layered ) const
	{
		TextureMap::const_iterator theVal = m_textureMap.find(resourceId);

		if(theVal == m_textureMap.end())
			throw ResourceNotFoundException(resourceId, "texture");

		if(!theVal->second)
			throw UsingIncompleteResourceException(resourceId, "texture");

		gl::BindImageTexture(imageUnit, theVal->second->textureObj, mipmapLevel,
			layered ? gl::TRUE_ : gl::FALSE_, imageLayer, access, format);
	}

	void ResourceData::DefineSampler( const IdString &resourceId, const SamplerInfo &data )
	{
		if(m_samplerMap.find(resourceId) != m_samplerMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "sampler");

		m_samplerMap[resourceId] = CreateSampler(data);
	}

	bool ResourceData::HasSampler( const IdString &resourceId ) const
	{
		return m_samplerMap.find(resourceId) != m_samplerMap.end();
	}

	void ResourceData::SetSamplerBorderColor( const IdString &resourceId, const glm::vec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerMap.find(resourceId);

		if(theVal == m_samplerMap.end())
			throw ResourceNotFoundException(resourceId, "sampler");

		gl::SamplerParameterfv(theVal->second, gl::TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerBorderColorI( const IdString &resourceId, const glm::ivec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerMap.find(resourceId);

		if(theVal == m_samplerMap.end())
			throw ResourceNotFoundException(resourceId, "sampler");

		gl::SamplerParameterIiv(theVal->second, gl::TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerBorderColorI( const IdString &resourceId, const glm::uvec4 &color )
	{
		SamplerMap::iterator theVal = m_samplerMap.find(resourceId);

		if(theVal == m_samplerMap.end())
			throw ResourceNotFoundException(resourceId, "sampler");

		gl::SamplerParameterIuiv(theVal->second, gl::TEXTURE_BORDER_COLOR, glm::value_ptr(color));
	}

	void ResourceData::SetSamplerLODBias( const IdString &resourceId, float bias )
	{
		SamplerMap::iterator theVal = m_samplerMap.find(resourceId);

		if(theVal == m_samplerMap.end())
			throw ResourceNotFoundException(resourceId, "sampler");

		gl::SamplerParameterf(theVal->second, gl::TEXTURE_LOD_BIAS, bias);
	}

	void ResourceData::BindSampler( const IdString &resourceId, GLuint textureUnit ) const
	{
		SamplerMap::const_iterator theVal = m_samplerMap.find(resourceId);

		if(theVal == m_samplerMap.end())
			throw ResourceNotFoundException(resourceId, "sampler");

		gl::BindSampler(textureUnit, theVal->second);
	}

	void ResourceData::DefineMesh( const IdString &resourceId, glmesh::Mesh *pMesh, bool claimOwnership )
	{
		MeshMap::iterator test_it = m_meshMap.find(resourceId);
		if(test_it != m_meshMap.end())
		{
			if(test_it->second.pMesh)
				throw ResourceMultiplyDefinedException(resourceId, "mesh");

			//Incomplete becomes complete.
			m_numIncomplete--;
		}

		MeshData &value = m_meshMap[resourceId];
		value.owned = true;
		value.pMesh = new MeshDrawable(pMesh, claimOwnership);
	}

	void ResourceData::DefineMesh( const IdString &resourceId, glscene::Drawable *pMesh, bool claimOwnership )
	{
		MeshMap::iterator test_it = m_meshMap.find(resourceId);
		if(test_it != m_meshMap.end())
		{
			if(test_it->second.pMesh)
				throw ResourceMultiplyDefinedException(resourceId, "mesh");

			//Incomplete becomes complete.
			m_numIncomplete--;
		}

		MeshData &value = m_meshMap[resourceId];
		value.owned = claimOwnership;
		value.pMesh = pMesh;
	}

	void ResourceData::DefineMeshIncomplete( const IdString &resourceId )
	{
		if(m_meshMap.find(resourceId) != m_meshMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "mesh");

		MeshData &value = m_meshMap[resourceId];
		value.owned = false;
		value.pMesh = NULL;

		m_numIncomplete++;
	}

	bool ResourceData::HasMesh( const IdString &resourceId ) const
	{
		return m_meshMap.find(resourceId) != m_meshMap.end();
	}

	bool ResourceData::IsMeshComplete( const IdString &resourceId ) const
	{
		MeshMap::const_iterator theVal = m_meshMap.find(resourceId);
		if(!theVal->second.pMesh)
			return false;
		return true;
	}

	void ResourceData::RenderMesh( const IdString &resourceId, const boost::optional<std::string> &variant ) const
	{
		MeshMap::const_iterator theVal = m_meshMap.find(resourceId);

		if(theVal == m_meshMap.end())
			throw ResourceNotFoundException(resourceId, "mesh");

		if(!theVal->second.pMesh)
			throw UsingIncompleteResourceException(resourceId, "mesh");

		theVal->second.pMesh->Draw(variant);
	}

	void ResourceData::DefineProgram( const IdString &resourceId, GLuint program,
		const ProgramInfo &programInfo, bool claimOwnership )
	{
		if(m_programMap.find(resourceId) != m_programMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "program");

		ProgramData &progData = m_programMap[resourceId];

		progData.program = program;
		progData.owned = claimOwnership;

		//Set the parameters on the program.
		gl::UseProgram(program);
		BOOST_FOREACH(const BindingLocationMap::value_type &binding, programInfo.samplerBindings)
		{
			GLint uniformLoc = gl::GetUniformLocation(program, binding.first.c_str());
			gl::Uniform1i(uniformLoc, binding.second);
		}

		BOOST_FOREACH(const BindingLocationMap::value_type &binding, programInfo.imageBindings)
		{
			GLint uniformLoc = gl::GetUniformLocation(program, binding.first.c_str());
			gl::Uniform1i(uniformLoc, binding.second);
		}

		BOOST_FOREACH(const BindingLocationMap::value_type &binding, programInfo.uniformBlockBindings)
		{
			GLuint blockIndex = gl::GetUniformBlockIndex(program, binding.first.c_str());
			gl::UniformBlockBinding(program, blockIndex, binding.second);
		}

		BOOST_FOREACH(const BindingLocationMap::value_type &binding, programInfo.bufferVariableBindings)
		{
			GLuint blockIndex = gl::GetProgramResourceIndex(program, gl::SHADER_STORAGE_BLOCK, binding.first.c_str());
			gl::ShaderStorageBlockBinding(program, blockIndex, binding.second);
		}
		gl::UseProgram(0);

		if(programInfo.modelToCameraMatrixUniformName)
		{
			progData.matrices.unifModelToCamera = gl::GetUniformLocation(program,
				programInfo.modelToCameraMatrixUniformName->c_str());
		}
		if(programInfo.normalModelToCameraMatrixUniformName)
		{
			progData.matrices.unifNormalModelToCamera = gl::GetUniformLocation(program,
				programInfo.normalModelToCameraMatrixUniformName->c_str());
		}
		if(programInfo.normalCameraToModelMatrixUniformName)
		{
			progData.matrices.unifNormalCameraToModel = gl::GetUniformLocation(program,
				programInfo.normalCameraToModelMatrixUniformName->c_str());
		}
	}

	bool ResourceData::HasProgram( const IdString &resourceId ) const
	{
		return m_programMap.find(resourceId) != m_programMap.end();
	}

	GLuint ResourceData::GetProgram( const IdString &resourceId ) const
	{
		ProgramMap::const_iterator theVal = m_programMap.find(resourceId);

		if(theVal == m_programMap.end())
			throw ResourceNotFoundException(resourceId, "program");

		return theVal->second.program;
	}

	ProgramMatrices ResourceData::GetProgramMatrices( const IdString &resourceId ) const
	{
		ProgramMap::const_iterator theVal = m_programMap.find(resourceId);

		if(theVal == m_programMap.end())
			throw ResourceNotFoundException(resourceId, "program");

		return theVal->second.matrices;
	}

	void ResourceData::DefineUniformBufferBinding( const IdString &resourceId, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		InterfaceBufferMap::iterator test_it = m_uniformBufferMap.find(resourceId);
		if(test_it != m_uniformBufferMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "uniform buffer");

		InterfaceBuffer &binding = m_uniformBufferMap[resourceId];
		binding.bufferObject = bufferObject;
		binding.owned = claimOwnership;
		binding.bindPoint = bindPoint;
		binding.offset = offset;
		binding.size = size;
	}

	void ResourceData::DefineUniformBufferBinding( const IdString &resourceId, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		InterfaceBufferMap::iterator test_it = m_uniformBufferMap.find(resourceId);
		if(test_it == m_uniformBufferMap.end())
			throw ResourceNotFoundException(resourceId, "uniform buffer");

		InterfaceBuffer &binding = test_it->second;
		if(binding.bufferObject)
			throw ResourceMultiplyDefinedException(resourceId, "uniform buffer");

		//Incomplete becomes complete.
		m_numIncomplete--;

		binding.bufferObject = bufferObject;
		binding.owned = claimOwnership;
		binding.offset = offset;
	}

	void ResourceData::DefineUniformBufferBindingIncomplete( const IdString &resourceId, GLuint bindPoint,
		GLsizeiptr size )
	{
		if(m_uniformBufferMap.find(resourceId) != m_uniformBufferMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "uniform buffer");

		InterfaceBuffer &binding = m_uniformBufferMap[resourceId];
		binding.bufferObject = boost::none;
		binding.owned = false;
		binding.bindPoint = bindPoint;
		binding.offset = 0;
		binding.size = size;

		m_numIncomplete++;
	}

	bool ResourceData::HasUniformBufferBinding( const IdString &resourceId ) const
	{
		return m_uniformBufferMap.find(resourceId) != m_uniformBufferMap.end();
	}

	bool ResourceData::IsUniformBufferBindingComplete( const IdString &resourceId ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_uniformBufferMap.find(resourceId);

		if(!theVal->second.bufferObject)
			return false;
		return true;

	}

	void ResourceData::DefineStorageBufferBinding( const IdString &resourceId, GLuint bufferObject,
		GLuint bindPoint, GLintptr offset, GLsizeiptr size, bool claimOwnership )
	{
		InterfaceBufferMap::iterator test_it = m_storageBufferMap.find(resourceId);
		if(test_it != m_storageBufferMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "storage buffer");

		InterfaceBuffer &binding = m_storageBufferMap[resourceId];
		binding.bufferObject = bufferObject;
		binding.owned = claimOwnership;
		binding.bindPoint = bindPoint;
		binding.offset = offset;
		binding.size = size;
	}

	void ResourceData::DefineStorageBufferBinding( const IdString &resourceId, GLuint bufferObject,
		GLintptr offset, bool claimOwnership )
	{
		InterfaceBufferMap::iterator test_it = m_storageBufferMap.find(resourceId);
		if(test_it == m_storageBufferMap.end())
			throw ResourceNotFoundException(resourceId, "storage buffer");

		InterfaceBuffer &binding = test_it->second;
		if(binding.bufferObject)
			throw ResourceMultiplyDefinedException(resourceId, "storage buffer");

		//Incomplete becomes complete.
		m_numIncomplete--;

		binding.bufferObject = bufferObject;
		binding.owned = claimOwnership;
		binding.offset = offset;
	}

	void ResourceData::DefineStorageBufferBindingIncomplete( const IdString &resourceId, GLuint bindPoint,
		GLsizeiptr size )
	{
		if(m_storageBufferMap.find(resourceId) != m_storageBufferMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "storage buffer");

		InterfaceBuffer &binding = m_storageBufferMap[resourceId];
		binding.bufferObject = boost::none;
		binding.owned = false;
		binding.bindPoint = bindPoint;
		binding.offset = 0;
		binding.size = size;

		m_numIncomplete++;
	}

	bool ResourceData::HasStorageBufferBinding( const IdString &resourceId ) const
	{
		return m_storageBufferMap.find(resourceId) != m_storageBufferMap.end();
	}

	bool ResourceData::IsStorageBufferBindingComplete( const IdString &resourceId ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_storageBufferMap.find(resourceId);

		if(!theVal->second.bufferObject)
			return false;
		return true;
	}

	void ResourceData::BindUniformBuffer( const IdString &resourceId, GLintptr offset ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_uniformBufferMap.find(resourceId);

		if(theVal == m_uniformBufferMap.end())
			throw ResourceNotFoundException(resourceId, "uniform buffer");

		const InterfaceBuffer &buf = theVal->second;

		if(!buf.bufferObject)
			throw UsingIncompleteResourceException(resourceId, "uniform buffer");

		gl::BindBufferRange(gl::UNIFORM_BUFFER, buf.bindPoint, buf.bufferObject.get(),
			buf.offset + offset, buf.size);
	}

	void ResourceData::BindStorageBuffer( const IdString &resourceId, GLintptr offset ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_storageBufferMap.find(resourceId);

		if(theVal == m_storageBufferMap.end())
			throw ResourceNotFoundException(resourceId, "storage buffer");

		const InterfaceBuffer &buf = theVal->second;

		if(!buf.bufferObject)
			throw UsingIncompleteResourceException(resourceId, "storage buffer");

		gl::BindBufferRange(gl::SHADER_STORAGE_BUFFER, buf.bindPoint, buf.bufferObject.get(),
			buf.offset + offset, buf.size);
	}

	GLuint ResourceData::GetUniformBufferBindingIndex( const IdString &resourceId ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_uniformBufferMap.find(resourceId);
		const InterfaceBuffer &buf = theVal->second;
		return buf.bindPoint;
	}

	GLuint ResourceData::GetStorageBufferBindingIndex( const IdString &resourceId ) const
	{
		InterfaceBufferMap::const_iterator theVal = m_storageBufferMap.find(resourceId);
		const InterfaceBuffer &buf = theVal->second;
		return buf.bindPoint;
	}

	void ResourceData::DefineCamera( const IdString &resourceId, const glutil::ViewData &initialView,
		const glutil::ViewScale &viewScale, glutil::MouseButtons actionButton, bool bRightKeyboardCtrls )
	{
		if(m_cameraMap.find(resourceId) != m_cameraMap.end())
			throw ResourceMultiplyDefinedException(resourceId, "camera");

		m_cameraMap.emplace(std::make_pair(resourceId,
			glutil::ViewPole(initialView, viewScale, actionButton, bRightKeyboardCtrls)));
	}

	glutil::ViewPole & ResourceData::GetCamera( const IdString &resourceId )
	{
		return const_cast<glutil::ViewPole &>(
			(const_cast<const ResourceData &>(*this)).GetCamera(resourceId));
	}

	const glutil::ViewPole & ResourceData::GetCamera( const IdString &resourceId ) const
	{
		CameraMap::const_iterator theVal = m_cameraMap.find(resourceId);

		if(theVal == m_cameraMap.end())
			throw ResourceNotFoundException(resourceId, "camera");

		return theVal->second;
	}
}

