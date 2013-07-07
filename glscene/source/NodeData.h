
#ifndef GLSDK_GLSCENE_NODE_DATA_H
#define GLSDK_GLSCENE_NODE_DATA_H

#include "TransformData.h"
#include "glscene/NodeRef.h"
#include "IdString.h"
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <boost/optional.hpp>
#include <boost/range.hpp>

namespace glscene
{
	class NodeData;
	class ResourceData;

	struct TextureBindingData
	{
		TextureBindingData(boost::string_ref _textureId, boost::string_ref _samplerId)
			: textureId(_textureId), samplerId(_samplerId) {}

		IdString textureId;
		IdString samplerId;
	};

	struct ImageBindingData
	{
		ImageBindingData(boost::string_ref _textureId)
			: textureId(_textureId) {}

		IdString textureId;
		GLint mipmapLevel;
		boost::optional<GLint> arrayLayer; ///<If set, then binds only that layer. If not set, then binds the whole array.
		GLenum access;
		GLenum format;
	};

	struct BufferInterfaceBindingData
	{
		BufferInterfaceBindingData(boost::string_ref _bufferId)
			: bufferId(_bufferId) {}

		GLuint bindPoint;
		IdString bufferId;
		GLintptr bindOffset;
	};

	struct UniformBindingData
	{
		UniformBindingData(boost::string_ref _uniformId)
			: uniformId(_uniformId) {}

		IdString uniformId;
	};

	struct SingleProgramBindingData
	{
		SingleProgramBindingData(boost::string_ref _programId)
			: programId(_programId) {}

		IdString programId;
		std::vector<UniformBindingData> uniformIds;
	};

	struct ProgramMaskData
	{
		ProgramMaskData(const SingleProgramBindingData &_prog, GLuint _stages)
			: prog(_prog), stages(_stages) {}

		SingleProgramBindingData prog;
		GLuint stages;			///<Stage bitmask, as would be used by [glUseProgramStages](http://www.opengl.org/wiki/GLAPI/glUseProgramStages).
	};

	struct SeparableProgramBindingData
	{
		std::vector<ProgramMaskData> pipeline;
		GLuint pipelineObj;
	};

	typedef boost::variant<SeparableProgramBindingData, SingleProgramBindingData> ProgramBindingData;
	typedef boost::container::flat_map<GLuint, TextureBindingData> TextureBindingMap;
	typedef boost::container::flat_map<GLuint, ImageBindingData> ImageBindingMap;

	struct StyleData
	{
		StyleData(boost::string_ref meshId) : meshResourceId(meshId) {}

		IdString meshResourceId;
		boost::optional<std::string> meshVariantString;
		ProgramBindingData progBinding;
		TextureBindingMap textureBindings;
		ImageBindingMap imageBindings;
		std::vector<BufferInterfaceBindingData> uniformBufferBindings;
		std::vector<BufferInterfaceBindingData> storageBufferBindings;
	};

	typedef boost::container::flat_map<IdString, StyleData> StyleMap;
	typedef std::vector<NodeData*> NodeChildren;

	class NodeData
	{
	public:
		NodeData(const boost::optional<IdString> &name, NodeData *pParent, int numLayers);
		~NodeData();

		TransformData &GetNodeTM() {return m_nodeTM;}
		const TransformData &GetNodeTM() const {return m_nodeTM;}
		TransformData &GetObjectTM() {return m_objTM;}
		const TransformData &GetObjectTM() const {return m_objTM;}

		void AddToLayer(int layerIx);
		void RemoveFromLayer(int layerIx);
		bool IsInLayer(int layerIx) const;

		NodeData *FindByName(const IdString &name);
		void MakeChildOfNode(NodeData &newParent);

		boost::string_ref GetName() const
		{
			return m_name ? boost::string_ref(m_name.get()) : boost::string_ref();
		}

		const boost::optional<IdString> &GetNameId() const {return m_name;}

		NodeData &CreateChildNode(const boost::optional<IdString> &name);

		//Beware: will crash if parent is NULL.
		void ReparentChildrenToParent();

		NodeData *GetParent() {return m_pParent;}
		const NodeData *GetParent() const {return m_pParent;}

		void DefineStyle(const boost::string_ref &styleName, const StyleInfo &style);

		const StyleData *FindStyle(const IdString &styleId) const;

		boost::iterator_range<NodeChildren::const_iterator> GetChildRange() const
		{
			return boost::iterator_range<NodeChildren::const_iterator>(
				m_children.begin(), m_children.end());
		}

	private:
		boost::optional<IdString> m_name;
		NodeData *m_pParent;
		NodeChildren m_children;
		TransformData m_nodeTM;
		TransformData m_objTM;
		boost::dynamic_bitset<> m_layers;
		StyleMap m_styles;

		//Creates root node.
		NodeData(int numLayers);

		void RemoveFromParent();

		friend struct SceneGraphData;
	};
}


#endif //GLSDK_GLSCENE_NODE_DATA_H
