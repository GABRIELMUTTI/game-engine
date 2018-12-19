#include "mtecs/component/ComponentManager.hpp"

namespace mtecs
{
    ComponentManager::ComponentManager(ComponentRegistry* componentRegistry, unsigned int allocationStep, MessageQueue* messageQueue) : 
        messageQueue(messageQueue)                                  
    {
        this->componentRegistry = componentRegistry;
        this->allocationStep = allocationStep;
    }

    void ComponentManager::sendComponentAddedMessage(unsigned int entityId, const Mask& mask)
    {
        Message message = Message("component_added");
        message.addArgument("entity_id", entityId);
        message.addArgument("component_mask", mask.getMask());

        messageQueue->send(message);
    }

    void ComponentManager::sendComponentRemovedMessage(unsigned int entityId, const Mask& mask)
    {
        Message message = Message("component_removed");
        message.addArgument("entity_id", entityId);
        message.addArgument("component_mask", mask.getMask());

        messageQueue->send(message);
    }

    void ComponentManager::allocateInPools()
    {
        for (Pool<Component>* pool : componentPools)
        {
            pool->allocate(allocationStep);
        }
    }
}
