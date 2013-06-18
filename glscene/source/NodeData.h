
#ifndef GLSDK_GLSCENE_NODE_DATA_H
#define GLSDK_GLSCENE_NODE_DATA_H

#include "TransformData.h"
#include "glscene/Node.h"
#include "IdString.h"
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <boost/optional.hpp>

namespace glscene
{
	class NodeData;

	typedef std::vector<NodeData*> NodeChildren;

	class NodeData
	{
	public:
		NodeData(const boost::optional<IdString> &name, NodeData *pParent, int numLayers);
		~NodeData();

		TransformData GetNodeTM();
		TransformData GetObjectTM();

		void AddToLayer(int layerIx);
		void RemoveFromLayer(int layerIx);
		bool IsInLayer(int layerIx) const;

		NodeData *FindByName(const IdString &name);
		void MakeChildOfNode(NodeData &newParent);

		boost::string_ref GetName()
		{
			return m_name ? boost::string_ref(m_name.get()) : boost::string_ref();
		}

		const boost::optional<IdString> &GetNameId() const {return m_name;}

		NodeData &CreateChildNode(const boost::optional<IdString> &name);

		//Beware: will crash if parent is NULL.
		void ReparentChildrenToParent();

		NodeData *GetParent() {return m_pParent;}

	private:
		boost::optional<IdString> m_name;
		NodeData *m_pParent;
		NodeChildren m_children;
		TransformData m_nodeTM;
		TransformData m_objTM;
		boost::dynamic_bitset<> m_layers;

		//Creates root node.
		NodeData(int numLayers);

		void RemoveFromParent();

		friend struct SceneGraphData;
	};
}


#endif //GLSDK_GLSCENE_NODE_DATA_H
