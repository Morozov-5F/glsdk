
#include "pch.h"
#include <boost/foreach.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/assert.hpp>
#include "NodeData.h"


namespace glscene
{
	NodeData::NodeData( const boost::optional<IdString> &name, NodeData *pParent, int numLayers )
		: m_name(name)
		, m_pParent(pParent)
		, m_layers(numLayers)
	{
		BOOST_ASSERT(m_pParent);
		m_pParent->m_children.push_back(this);
	}

	NodeData::NodeData( int numLayers )
		: m_pParent(NULL)
		, m_layers(numLayers)
	{}

	NodeData::~NodeData()
	{
		//Remove from parent's list.
		if(m_pParent)
			RemoveFromParent();

		BOOST_FOREACH(NodeData *pChild, m_children)
		{
			//Stop his destructor from removing himself from my list while I'm iterating over it.
			pChild->m_pParent = NULL;
			delete pChild;
		}
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

	void NodeData::RemoveFromParent()
	{
		if(m_pParent)
		{
			m_pParent->m_children.erase(
				boost::range::remove(m_pParent->m_children, this), m_pParent->m_children.end());
		}
	}

	NodeData * NodeData::FindByName( const IdString &name )
	{
		if(m_name && m_name.get() == name)
			return this;

		BOOST_FOREACH(NodeData *pChild, m_children)
		{
			NodeData *pRet = pChild->FindByName(name);
			if(pRet)
				return pRet;
		}

		return NULL;
	}

	void NodeData::MakeChildOfNode( NodeData &newParent )
	{
		if(!m_pParent)
			throw CannotChangeTheRootParentException();

		//Already the parent. No-op.
		if(m_pParent == &newParent)
			return;

		//First, remove ourself from the nodes in our parent list.
		NodeData &currParent = *m_pParent;
		currParent.m_children.erase(
			boost::range::remove(currParent.m_children, this), currParent.m_children.end());

		//Now, add ourselves to the new parent's list.
		newParent.m_children.push_back(this);

		//Change our parent.
		m_pParent = &newParent;
	}

	NodeData & NodeData::CreateChildNode( const boost::optional<IdString> &name )
	{
		//Child will automatically add itself.
		NodeData *pRet = new NodeData(name, this, (int)m_layers.size());
		return *pRet;
	}

	void NodeData::ReparentChildrenToParent()
	{
		while(!m_children.empty())
			m_children.front()->MakeChildOfNode(*m_pParent);
	}
}
