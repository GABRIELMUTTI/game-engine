#pragma once

#include "mtecs/entity/Entity.hpp"
#include "mtecs/group/GroupComponentIterator.hpp"
#include "mtecs/component/ComponentHandle.hpp"

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

    public:
	GroupComponentView(const Entities& entities, const std::vector<Mask>& masks, ComponentHandle<Components>& ... handles) :
	    entities(entities),
	    masks(masks),
	    handles(handles ...)
	{

	}

	GroupComponentIterator<Entities, Components ...> begin()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.begin(), handles, masks);
	}     

	GroupComponentIterator<Entities, Components ...> end()
	{
	    return GroupComponentIterator<Entities, Components ...>(entities.end(), handles, masks);
	}      
    };
}
