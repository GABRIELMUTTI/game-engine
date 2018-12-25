#include "mtecs/system/System.hpp"

namespace mtecs
{
    System::System(unsigned int id) :
        id(id),
        enabled(true),
	awake(true)
    {

    }

    unsigned int System::getId()
    {
	return id;
    }
    
    Mask System::getMask()
    {
        return mask;
    }

    void System::setEnabled(bool state)
    {
        enabled = state;

        Message message = Message("system_enabled_modified");
        message.addArgument("system_id", id);
        events->send(message);
    }

    void System::setAwake(bool state)
    {
        awake = state;

        Message message = Message("system_awake_modified");
        message.addArgument("system_id", id);
        events->send(message);
    }

    bool System::isEnabled()
    {
        return enabled;
    }

    bool System::isAwake()
    {
        return awake;
    }
    
    void System::setComponentManager(ComponentManager* componentManager)
    {
        components = componentManager;
    }

    void System::setEntityManager(EntityManager* entityManager)
    {
        entities = entityManager;
    }

    void System::setComponentRegistry(ComponentRegistry* componentRegistry)
    {
        registry = componentRegistry;
    }

    void System::setMessageQueue(utility::MessageQueue* messageQueue)
    {
        events = messageQueue;
    }

    void System::setGroupManager(GroupManager* groupManager)
    {
        groups = groupManager;
    }
}
