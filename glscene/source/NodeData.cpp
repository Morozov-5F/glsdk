
#include "pch.h"
#include <boost/foreach.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/assert.hpp>
#include <glload/gl_all.hpp>
#include "glscene/Style.h"
#include "NodeData.h"
#include "ResourceData.h"


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

	namespace
	{
		struct DeletePipelineVisitor : public boost::static_visitor<>
		{
			void operator()(const SeparableProgramBindingData &sepData) const
			{
				gl::DeleteProgramPipelines(1, &sepData.pipelineObj);
			}

			void operator()(const SingleProgramBindingData &) const {}
		};
	}

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

		BOOST_FOREACH(const StyleList::value_type &stylePair, m_styles)
		{
			boost::apply_visitor(DeletePipelineVisitor(), stylePair.second.progBinding);
		}
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

	namespace
	{
		struct ProgDataExtraction : public boost::static_visitor<ProgramBindingData>
		{
			SingleProgramBindingData operator()(const SingleProgramBinding &binding) const
			{
				SingleProgramBindingData data(binding.programId);
				data.uniformIds.reserve(binding.uniformIds.size());
				BOOST_FOREACH(const std::string &uniformId, binding.uniformIds)
				{
					data.uniformIds.push_back(UniformBindingData(uniformId));
				}

				return data;
			}

			SeparableProgramBindingData operator()(const SeparableProgramBinding &binding) const
			{
				SeparableProgramBindingData data;
				data.pipeline.reserve(binding.pipeline.size());
				gl::GenProgramPipelines(1, &data.pipelineObj);
				gl::BindProgramPipeline(data.pipelineObj);
				BOOST_FOREACH(const ProgramMask &prog, binding.pipeline)
				{
					data.pipeline.push_back(ProgramMaskData((*this)(prog.prog), prog.stages));

				}
				gl::BindProgramPipeline(0);
				return data;
			}
		};
	}

	void NodeData::DefineStyle( const boost::string_ref &styleName, const StyleInfo &style )
	{
		if(m_styles.find(styleName) != m_styles.end())
			throw StyleMultiplyDefinedException(std::string(styleName.begin(), styleName.end()));

		m_styles.emplace(styleName, StyleData(style.meshResourceId));
		StyleData &data = m_styles.find(styleName)->second;
		data.meshVariantString = style.meshVariantString;

		data.progBinding = boost::apply_visitor(ProgDataExtraction(), style.progBinding);

		data.textureBindings.reserve(style.textureBindings.size());
		BOOST_FOREACH(const TextureBinding &texBinding, style.textureBindings)
		{
			TextureBindingData newBinding(texBinding.textureId, texBinding.samplerId);
			data.textureBindings.emplace(texBinding.textureUnit, newBinding);
		}

		data.imageBindings.reserve(style.imageBindings.size());
		BOOST_FOREACH(const ImageBinding &imgBinding, style.imageBindings)
		{
			ImageBindingData newBinding(imgBinding.textureId);
			newBinding.mipmapLevel = imgBinding.mipmapLevel;
			newBinding.arrayLayer = imgBinding.arrayLayer;
			newBinding.access = imgBinding.access;
			newBinding.format = imgBinding.format;
			data.imageBindings.emplace(imgBinding.imageUnit, newBinding);
		}

		data.uniformBufferBindings.reserve(style.uniformBufferBindings.size());
		BOOST_FOREACH(const BufferInterfaceBinding &bufBinding, style.uniformBufferBindings)
		{
			BufferInterfaceBindingData newBinding(bufBinding.bufferId);
			newBinding.bindOffset = bufBinding.bindOffset;
			data.uniformBufferBindings.push_back(newBinding);
		}

		data.storageBufferBindings.reserve(style.storageBufferBindings.size());
		BOOST_FOREACH(const BufferInterfaceBinding &bufBinding, style.storageBufferBindings)
		{
			BufferInterfaceBindingData newBinding(bufBinding.bufferId);
			newBinding.bindOffset = bufBinding.bindOffset;
			data.storageBufferBindings.push_back(newBinding);
		}
	}
}
