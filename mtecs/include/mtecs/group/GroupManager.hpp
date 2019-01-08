#pragma once

#include "mtecs/group/Group.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

namespace mtecs
{
    namespace internal
    {
	class GroupManager
	{
	private:
	    std::vector<Group*> groups;
	    const EntityManager& entityManager;
	    const ComponentManager& componentManager;
	    ComponentRegistry& componentRegistry;

	    void createGroup(const Mask& mask);
	
	public:
	    GroupManager(const EntityManager& entityManager, const ComponentManager& componentManager, ComponentRegistry& componentRegistry);

	    template<class ... Types>
	    Group* getGroup()
	    {
		Mask mask = componentRegistry.getMask<Types ...>();
                
		for (uint i = 0; i < groups.size(); i++)
		{
		    if (groups[i]->getMask() == mask)
		    {
			return groups[i];
		    }
		}

		createGroup(mask);
		return groups[groups.size() - 1];
	    }
	};	
    }
}
