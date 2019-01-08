#pragma once

#include "mtecs/entity/Entity.hpp"
#include "mtecs/group/GroupComponentIterator.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

#include <vector>
#include <tuple>

namespace mtecs
{
    template<class ... Components>
    class GroupComponentView
    {
        typedef std::vector<Entity*> Entities;
    
    private:
	const Entities& entities;
	const std::vector<Mask> masks;
	std::tuple<ComponentHandle<Components>& ...> handles;
	const internal::ComponentManager& componentManager;
	internal::ComponentRegistry& componentRegistry;

	template<class TFirst, class TSecond, class ... Rest>
	void getMasks(std::vector<Mask>& masks)
	{
	    getMasks<TFirst>(masks);
	    getMasks<TSecond, Rest ...>(masks);
	}

	template<class Type>
	void getMasks(std::vector<Mask>& masks)
	{
	    masks.push_back(componentRegistry.getMask<Type>());
	}
	
    public:
	GroupComponentView(const Entities& entities, ComponentHandle<Components>& ... handles, const internal::ComponentManager& componentManager, internal::ComponentRegistry& componentRegistry) :
	    entities(entities),
	    masks(masks),
	    handles(handles ...),
	    componentManager(componentManager),
	    componentRegistry(componentRegistry)
	{

	    getMasks<Components ...>(masks);
	}

	GroupComponentIterator<Entities, Components ...> begin()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.begin(), handles, masks, componentManager);
	}     

	GroupComponentIterator<Entities, Components ...> end()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.end(), handles, masks, componentManager);
	}      
    };
}
