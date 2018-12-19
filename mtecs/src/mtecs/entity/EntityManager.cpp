#include "mtecs/entity/EntityManager.hpp"

namespace mtecs
{
    EntityManager::EntityManager(ComponentManager* componentManager,
				 ComponentRegistry* componentRegistry, 
                                 utility::MessageQueue* messageQueue) :
	componentRegistry(componentRegistry),
	componentManager(componentManager),
	messageQueue(messageQueue),
        Entities(entities)
    {

    }


    Entity* EntityManager::createEntity(const std::string& name)
    {
        int entityId;

        if (freeFragmentedIndexes.empty())
        {
            entityId = entities.size();
        }
        else
        {
            entityId = freeFragmentedIndexes.back();
            freeFragmentedIndexes.pop_back();
        }

        Entity* entity = new Entity(entityId, name, componentManager, componentRegistry);
        entities.push_back(entity);

        Message message = Message("entity_created");
        message.addArgument("entity_id", entityId);
        messageQueue->send(message);

        return entity;
    }

    void EntityManager::destroyEntity(Entity* entity)
    {
        uint entityId = entity->getId();

        if (entityId + 1 == entities.size())
        {
            entities.erase(entities.begin() + entityId);
        }
        else
        {
            entities[entityId] = nullptr;
            freeFragmentedIndexes.push_back(entityId);
            std::sort(freeFragmentedIndexes.rbegin(), freeFragmentedIndexes.rend());
        }

        Message message = Message("entity_destroyed");
        message.addArgument("entity_id", entityId);
    }

    Entity* EntityManager::getEntity(int entityId)
    {
        return entities[entityId];
    }
}
