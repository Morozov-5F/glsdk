
#ifndef GLSDK_GLSCENE_NODE_DATA_H
#define GLSDK_GLSCENE_NODE_DATA_H

#include "TransformData.h"
#include "glscene/Node.h"
#include <vector>
#include <boost/dynamic_bitset.hpp>

namespace glscene
{
	class NodeData;

	typedef std::vector<boost::reference_wrapper<NodeData> > NodeChildren;

	class NodeData
	{
	public:
		NodeData(NodeData *pParent, int numLayers);

		TransformData GetNodeTM();
		TransformData GetObjectTM();

		void AddToLayer(int layerIx);
		void RemoveFromLayer(int layerIx);
		bool IsInLayer(int layerIx) const;


	private:
		NodeData *m_pParent;
		NodeChildren m_children;
		TransformData m_nodeTM;
		TransformData m_objTM;
		boost::dynamic_bitset<> m_layers;
	};
}


#endif //GLSDK_GLSCENE_NODE_DATA_H
