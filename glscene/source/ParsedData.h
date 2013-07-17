#ifndef GLSDK_GLSCENE_PARSED_DATA_H
#define GLSDK_GLSCENE_PARSED_DATA_H

#include "ParserUtils.h"
#include "ResourceData.h"
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/container/stable_vector.hpp>
#include <boost/variant.hpp>
#include <glutil/MousePoles.h>
#include "TransformData.h"
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace glscene { namespace _detail {

	class ParsedIdentifier
	{
	public:
		explicit ParsedIdentifier(boost::string_ref idName)
			: m_id(idName)
			, m_fullName(idName.data(), idName.size())
		{}

		operator IdString() const {return m_id;}
		boost::string_ref ref() const {return m_fullName;}
		const std::string &str() const {return m_fullName;}

		bool operator<(const ParsedIdentifier &rhs) const {return m_id < rhs.m_id;}

		bool operator==(const ParsedIdentifier &rhs) const {return m_id == rhs.m_id;}
		bool operator!=(const ParsedIdentifier &rhs) const {return m_id != rhs.m_id;}

	private:
		IdString m_id;
		std::string m_fullName;
	};

	struct ParsedUniformDef
	{
		FilePosition pos;
		std::string glslUniformName;
		UniformData data;
	};

	struct ParsedSamplerDef
	{
		FilePosition pos;
		SamplerInfo sampler;
	};

	struct ParsedCameraDef
	{
		FilePosition pos;
		glutil::ViewData view;
		glutil::ViewScale scale;
		glutil::MouseButtons actionButton;
		bool bRightKeyboardCtrls;
	};

	struct ParsedBufferDef
	{
		FilePosition pos;
		unsigned int size;
		boost::optional<GLenum> creationUsage;
	};

	struct ParsedShader
	{
		FilePosition pos;
		GLenum shaderType;
		std::string filename;
	};

	struct ParsedProgramDef
	{
		FilePosition pos;
		bool isSeparate;
		std::vector<ParsedShader> shaders;
		ProgramInfo info;
	};

	typedef boost::variant<boost::blank, int, std::string> MeshGenType;

	struct ParsedMeshDef
	{
		FilePosition pos;
		MeshGenType generator;
		std::vector<int> params;
	};

	struct ParsedTextureDef
	{
		FilePosition pos;
		boost::optional<std::string> filename;
	};

	template<typename Def>
	FilePosition GetFilePosition(const Def &def) {return def.pos;}
	FilePosition GetFilePosition(const FilePosition &pos) {return pos;}

	template<typename Key, typename Def>
	FilePosition GetPosFromDef(const std::pair<Key, Def> &pairDef) {return GetFilePosition(pairDef.second);}

	typedef boost::container::flat_map<ParsedIdentifier, ParsedUniformDef> ParsedUniformMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedSamplerDef> ParsedSamplerMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedCameraDef> ParsedCameraMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedBufferDef> ParsedBufferMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedProgramDef> ParsedProgramMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedMeshDef> ParsedMeshMap;
	typedef boost::container::flat_map<ParsedIdentifier, ParsedTextureDef> ParsedTextureMap;

	struct ParsedResources
	{
		ParsedUniformMap uniforms;
		ParsedSamplerMap samplers;
		ParsedCameraMap cameras;
		ParsedBufferMap uniformBuffers;
		ParsedBufferMap storageBuffers;
		ParsedProgramMap programs;
		ParsedMeshMap meshes;
		ParsedTextureMap textures;
	};

	struct ParsedDecomposedTransform
	{
		DecomposedMatrix mat;
		bool hasOrientation;
		bool hasScale;

		ParsedDecomposedTransform() : hasOrientation(false), hasScale(false) {}
	};

	typedef boost::variant<glm::mat4, ParsedDecomposedTransform> ParsedTransform;

	struct ParsedTransformDef
	{
		FilePosition pos;
		ParsedTransform trans;
	};

	inline void ApplyTranslation(ParsedTransform &tm, const glm::vec3 &translation)
	{
		if(tm.which() == 1)
		{
			ParsedDecomposedTransform &decomp = boost::get<ParsedDecomposedTransform>(tm);
			if(!decomp.hasOrientation)
			{
				decomp.mat.translation += translation;
				return;
			}
			
			//Must compose.
			tm = MatrixVisitor()(decomp.mat);
		}

		tm = glm::translate(boost::get<glm::mat4>(tm), translation);
	}

	inline void ApplyOrientation(ParsedTransform &tm, const glm::quat &orient)
	{
		if(tm.which() == 1)
		{
			ParsedDecomposedTransform &decomp = boost::get<ParsedDecomposedTransform>(tm);
			decomp.hasOrientation = true;
			if(!decomp.hasScale)
			{
				decomp.mat.orientation = decomp.mat.orientation * orient;
				return;
			}

			//Must compose.
			tm = MatrixVisitor()(decomp.mat);
		}

		tm = boost::get<glm::mat4>(tm) * glm::mat4_cast(orient);
	}

	inline void ApplyScale(ParsedTransform &tm, const glm::vec3 &scale)
	{
		if(tm.which() == 1)
		{
			ParsedDecomposedTransform &decomp = boost::get<ParsedDecomposedTransform>(tm);
			decomp.hasOrientation = true;
			decomp.hasScale = true;
			decomp.mat.scale *= scale;
			return;
		}

		tm = glm::scale(boost::get<glm::mat4>(tm), scale);
	}

	inline void ApplyMatrix(ParsedTransform &tm, const glm::mat4 &matrix)
	{
		if(tm.which() == 1)
		{
			//Must compose.
			ParsedDecomposedTransform &decomp = boost::get<ParsedDecomposedTransform>(tm);
			tm = MatrixVisitor()(decomp.mat);
		}

		tm = boost::get<glm::mat4>(tm) * matrix;
	}

	typedef boost::container::flat_set<std::string> LayerSet;

	struct ParsedMeshRefDef
	{
		FilePosition pos;
		ParsedIdentifier meshId;
		boost::optional<std::string> variant;

		ParsedMeshRefDef(const ParsedIdentifier &_id) : meshId(_id) {}
	};

	struct ParsedTextureRefDef
	{
		FilePosition pos;
		unsigned int texUnit;
		ParsedIdentifier textureId;
		ParsedIdentifier samplerId;

		ParsedTextureRefDef(const ParsedIdentifier &_textureId, const ParsedIdentifier &_samplerId)
			: textureId(_textureId)
			, samplerId(_samplerId)
		{}
	};

	struct ParsedBufferRefDef
	{
		FilePosition pos;
		unsigned int buffBinding;
		ParsedIdentifier bufferId;
		unsigned int offset;

		ParsedBufferRefDef(const ParsedIdentifier &_bufferId) : bufferId(_bufferId), offset(0) {}
	};

	struct ParsedSingleProgramDef
	{
		FilePosition pos;
		ParsedIdentifier programId;
		std::vector<ParsedIdentifier> uniformReferences;

		ParsedSingleProgramDef(const ParsedIdentifier &_programId) : programId(_programId) {}
	};

	struct ParsedProgramMask
	{
		ParsedSingleProgramDef prog;
		unsigned int stages;

		ParsedProgramMask(const ParsedIdentifier &_programId) : prog(_programId) {}
	};

	struct ParsedPipelineDef
	{
		FilePosition pos;
		std::vector<ParsedProgramMask> progs;
	};

	typedef boost::variant<ParsedPipelineDef, ParsedSingleProgramDef> ParsedProgramVariantDef;

	struct ProgramVariantDefVisit : public boost::static_visitor<FilePosition>
	{
		template<typename T> FilePosition operator()(const T& t) const {return t.pos;}
	};

	FilePosition GetFilePosition(const ParsedProgramVariantDef &def)
	{
		return boost::apply_visitor(ProgramVariantDefVisit(), def);
	}

	struct ParsedStyleData
	{
		boost::optional<ParsedMeshRefDef> mesh;
		boost::optional<ParsedProgramVariantDef> prog;
		std::vector<ParsedTextureRefDef> textures;
		std::vector<ParsedBufferRefDef> uniformBuffers;
		std::vector<ParsedBufferRefDef> storageBuffers;

		bool HasMesh() {return mesh.is_initialized();}
	};

	struct ParsedLocalDef
	{
		FilePosition pos;
		ParsedIdentifier name;
		ParsedStyleData data;

		ParsedLocalDef(const ParsedIdentifier &_name) : name(_name) {}
	};

	struct ParsedStyleDef
	{
		FilePosition pos;
		std::vector<const ParsedLocalDef*> includes;
		ParsedStyleData data;
	};

	typedef boost::container::flat_map<ParsedIdentifier, ParsedStyleDef> ParsedStyleMap;

	class LocalsInScope
	{
	public:
		void AddToScope(const ParsedLocalDef &local)
		{
			m_scope[local.name] = &local;
		}

		const ParsedLocalDef *IncludeLocal(const ParsedIdentifier &name) const
		{
			LocalScope::const_iterator theIt = m_scope.find(name);
			if(theIt == m_scope.end())
				return NULL;
			return theIt->second;
		}

	private:
		typedef boost::container::flat_map<ParsedIdentifier, const ParsedLocalDef *> LocalScope;
		LocalScope m_scope;
	};

	struct ParsedNodeDef
	{
		FilePosition pos;
		boost::optional<ParsedIdentifier> name;
		LayerSet layers;
		std::vector<ParsedNodeDef*> childNodes;
		ParsedNodeDef *pParent;
		ParsedTransformDef nodeTM;
		ParsedTransformDef objectTM;
		ParsedStyleMap styles;
		boost::container::flat_map<ParsedIdentifier, FilePosition> localPositions;

		ParsedNodeDef& operator=(const ParsedNodeDef &other)
		{
			pos = other.pos;
			name = other.name;
			layers = other.layers;
			childNodes = other.childNodes;
			pParent = other.pParent;
			nodeTM = other.nodeTM;
			objectTM = other.objectTM;
			styles = other.styles;
			localPositions = other.localPositions;
			return *this;
		}
	};

	struct InheritedNodeData
	{
		ParsedNodeDef *pParent;
		LayerSet layers;
		LocalsInScope scope;

		InheritedNodeData() : pParent() {}
	};

	struct ParsedSceneGraphDef
	{
		FilePosition pos;
		LayerSet layers;
		std::vector<std::string> layerOrder;
		boost::container::flat_set<ParsedIdentifier> styleChecks;
		boost::container::flat_map<ParsedIdentifier, FilePosition> nodeNamePositions;
		boost::container::stable_vector<ParsedNodeDef> nodes;
		boost::container::stable_vector<ParsedLocalDef> allLocals;
	};
}}

#endif //GLSDK_GLSCENE_PARSED_DATA_H
