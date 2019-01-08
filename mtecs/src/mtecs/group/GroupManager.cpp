#include "mtecs/group/GroupManager.hpp"

namespace mtecs
{
    namespace internal
    {
	GroupManager::GroupManager(const EntityManager& entityManager, const ComponentManager& componentManager, ComponentRegistry& componentRegistry) :
	    entityManager(entityManager),
	    componentManager(componentManager),
	    componentRegistry(componentRegistry)
	{

	}

	void GroupManager::createGroup(const Mask& mask)
	{
	    Group* group = new Group(mask, componentManager, componentRegistry);

	    for (Entity* entity : entityManager.Entities)
	    {
		if (entity->hasComponents(mask))
		{
		    group->add(entity);
		}
	    }

	    groups.push_back(group);
	}	
    }
}
