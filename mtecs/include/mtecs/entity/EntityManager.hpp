#pragma once

#include "mtecs/component/ComponentRegistry.hpp"

#include "mtecs/entity/Entity.hpp"

#include <utilities/delegate/Event.hpp>
#include <utilities/eventqueue/message/MessageQueue.hpp>
#include <utilities/property/EventProperty.hpp>
#include <utilities/property/StructureProperty.hpp>


#include <vector>
#include <string>

namespace mtecs
{
    class EntityManager
    {
    private:
	std::vector<Entity*> entities;
	std::vector<unsigned int> freeFragmentedIndexes;

	ComponentRegistry* componentRegistry;
	ComponentManager* componentManager;

	utility::MessageQueue* messageQueue;

    public:
	utility::StructureProperty<std::vector<Entity*>> Entities;

	EntityManager(ComponentManager* componentManager, ComponentRegistry* componentRegistry, 
		      utility::MessageQueue* messageQueue);
            
	Entity* createEntity(const std::string& name);
	void destroyEntity(Entity* entity);

	Entity* getEntity(int entityId);


    };
}
