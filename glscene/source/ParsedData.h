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

	typedef boost::container::flat_map<IdString, ParsedUniformDef> ParsedUniformMap;
	typedef boost::container::flat_map<IdString, ParsedSamplerDef> ParsedSamplerMap;
	typedef boost::container::flat_map<IdString, ParsedCameraDef> ParsedCameraMap;
	typedef boost::container::flat_map<IdString, ParsedBufferDef> ParsedBufferMap;
	typedef boost::container::flat_map<IdString, ParsedProgramDef> ParsedProgramMap;
	typedef boost::container::flat_map<IdString, ParsedMeshDef> ParsedMeshMap;
	typedef boost::container::flat_map<IdString, ParsedTextureDef> ParsedTextureMap;

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
		IdString meshId;
		boost::optional<std::string> variant;

		ParsedMeshRefDef(const IdString &_id) : meshId(_id) {}
	};

	struct ParsedTextureRefDef
	{
		FilePosition pos;
		unsigned int texUnit;
		IdString textureId;
		IdString samplerId;

		ParsedTextureRefDef(const IdString &_textureId, const IdString &_samplerId)
			: textureId(_textureId)
			, samplerId(_samplerId)
		{}
	};

	struct ParsedBufferRefDef
	{
		FilePosition pos;
		unsigned int buffBinding;
		IdString bufferId;
		unsigned int offset;

		ParsedBufferRefDef(const IdString &_bufferId) : bufferId(_bufferId), offset(0) {}
	};

	struct ParsedStyleData
	{
		boost::optional<ParsedMeshRefDef> mesh;
		std::vector<ParsedTextureRefDef> textures;
		std::vector<ParsedBufferRefDef> uniformBuffers;
		std::vector<ParsedBufferRefDef> storageBuffers;
	};

	struct ParsedLocalDef
	{
		FilePosition pos;
		IdString name;
		ParsedStyleData data;

		ParsedLocalDef(const IdString &_name) : name(_name) {}
	};

	struct ParsedStyleDef
	{
		FilePosition pos;
		std::vector<const ParsedLocalDef*> includes;
		ParsedStyleData data;
	};

	typedef boost::container::flat_map<IdString, ParsedStyleDef> ParsedStyleMap;

	class LocalsInScope
	{
	public:
		void AddToScope(const ParsedLocalDef &local)
		{
			m_scope[local.name] = &local;
		}

		const ParsedLocalDef *IncludeLocal(const IdString &name) const
		{
			LocalScope::const_iterator theIt = m_scope.find(name);
			if(theIt == m_scope.end())
				return NULL;
			return theIt->second;
		}

	private:
		typedef boost::container::flat_map<IdString, const ParsedLocalDef *> LocalScope;
		LocalScope m_scope;
	};

	struct ParsedNodeDef
	{
		FilePosition pos;
		boost::optional<IdString> name;
		LayerSet layers;
		std::vector<ParsedNodeDef*> childNodes;
		ParsedNodeDef *pParent;
		ParsedTransformDef nodeTM;
		ParsedTransformDef objectTM;
		ParsedStyleMap styles;
		boost::container::flat_map<IdString, FilePosition> localPositions;

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
		boost::container::flat_set<IdString> styleChecks;
		boost::container::flat_map<IdString, FilePosition> nodeNamePositions;
		boost::container::stable_vector<ParsedNodeDef> nodes;
		boost::container::stable_vector<ParsedLocalDef> allLocals;
	};
}}

#endif //GLSDK_GLSCENE_PARSED_DATA_H
