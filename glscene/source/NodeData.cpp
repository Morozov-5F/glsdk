
#include "NodeData.h"


namespace glscene
{
	NodeData::NodeData( NodeData *pParent, int numLayers )
		: m_pParent(pParent)
		, m_layers(numLayers)
	{
	}

	glscene::TransformData NodeData::GetNodeTM()
	{
		return m_nodeTM;
	}

	glscene::TransformData NodeData::GetObjectTM()
	{
		return m_objTM;
	}

	void NodeData::AddToLayer( int layerIx )
	{
		if(layerIx < (int)m_layers.size())
			m_layers.set(layerIx);
	}

	void NodeData::RemoveFromLayer( int layerIx )
	{
		if(layerIx < (int)m_layers.size())
			m_layers.reset(layerIx);
	}

	bool NodeData::IsInLayer( int layerIx ) const
	{
		if(layerIx < (int)m_layers.size())
			return m_layers.test(layerIx);
		return false;
	}
}
