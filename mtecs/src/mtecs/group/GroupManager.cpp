#include "mtecs/group/GroupManager.hpp"

namespace mtecs
{
    GroupManager::GroupManager(EntityManager* entityManager, ComponentRegistry* componentRegistry, 
                               MessageQueue* messageQueue) :
        entityManager(entityManager),
        messageQueue(messageQueue),
	componentRegistry(componentRegistry)
    {
        messageQueue->subscribe<GroupManager, &GroupManager::onComponentAdded>(this, "component_added");
        messageQueue->subscribe<GroupManager, &GroupManager::onComponentRemoved>(this, "component_removed");
    }

    void GroupManager::createGroup(const Mask& mask)
    {
        Group* group = new Group(mask, componentRegistry);

        for (Entity* entity : entityManager->Entities)
        {
            if (entity->hasComponents(mask))
            {
                group->add(entity);
            }
        }

        groups.push_back(group);
    }

    void GroupManager::onComponentAdded(Message message)
    {
        unsigned int entityId = message.getUnsignedInt("entity_id");
        Mask componentMask = Mask(message.getInt("component_mask"));

        for (Group* group : groups)
        {
            if (group->hasComponents(componentMask, Mask::Has::All))
            {
                group->add(entityManager->getEntity(entityId));
            }
        }
    }

    void GroupManager::onComponentRemoved(Message message)
    {
        unsigned int entityId = message.getUnsignedInt("entity_id");
        Mask componentMask = Mask(message.getInt("component_mask"));

        for (Group* group : groups)
        {
            if (!group->hasComponents(componentMask, Mask::Has::All))
            {
                group->remove(entityManager->getEntity(entityId));
            }
        }
    }
}
