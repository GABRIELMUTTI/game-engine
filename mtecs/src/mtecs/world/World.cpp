#include "mtecs/world/World.hpp"

namespace mtecs
{
    World::World()
    {
        messageQueue = new MessageQueue();
        componentRegistry = new ComponentRegistry();
        componentManager = new ComponentManager(componentRegistry, 100, messageQueue);
        entityManager = new EntityManager(componentManager, componentRegistry, messageQueue);
        groupManager = new GroupManager(entityManager, componentRegistry, messageQueue);

        messageQueue->subscribe<World, &World::onSystemStateChanged>(this, "system_awake_changed");   
        messageQueue->subscribe<World, &World::onSystemStateChanged>(this, "system_enabled_changed");
    }

    void World::initialize()
    {
	messageQueue->flush();
	for (System* system : newSystems)
	{
	    system->initialize();
	    awakeSystems.push_back(system);
	}

	newSystems.clear();
    }
    
    void World::addSystem(System* system)
    {
        system->setComponentManager(componentManager);
        system->setComponentRegistry(componentRegistry);
        system->setEntityManager(entityManager);
        system->setMessageQueue(messageQueue);
        system->setGroupManager(groupManager);
	
        if (system->isEnabled() && system->isAwake())
        {
            awakeSystems.push_back(system);
        }

	systems.push_back(system);
	newSystems.push_back(system);

	Message message = Message("system_added");
	message.addArgument("system_id", system->getId());

	messageQueue->send(message);
    }

    void World::removeSystem(System* system)
    {
        systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
        awakeSystems.erase(std::remove(awakeSystems.begin(), awakeSystems.end(), system), awakeSystems.end());
    }

    void World::update(float deltaTime)
    {
	for (System* system : newSystems)
	{
	    system->initialize();
	    awakeSystems.push_back(system);
	}

	newSystems.clear();
	
        for (System* system : awakeSystems)
        {
            system->update(deltaTime);
        }

        messageQueue->flush();
    }

    System* World::getSystem(unsigned int index)
    {
        if (index < systems.size())
        {
            return systems[index];
        }

        return nullptr;
    }

    EntityManager* World::getEntityManager()
    {
        return entityManager;
    }

    ComponentManager* World::getComponentManager()
    {
        return componentManager;
    }

    ComponentRegistry* World::getComponentRegistry()
    {
        return componentRegistry;
    }

    GroupManager* World::getGroupManager()
    {
        return groupManager;
    }

    utility::MessageQueue* World::getMessageQueue()
    {
        return messageQueue;
    }

    void World::onSystemStateChanged(Message message)
    {
        uint systemId = message.getUnsignedInt("system_id");
    
        if (systemId < systems.size())
        {
            System* system = systems[systemId];

            if (system->isEnabled() && system->isAwake())
            {
                awakeSystems.push_back(system);
            }
            else
            {
                awakeSystems.erase(std::remove(awakeSystems.begin(), awakeSystems.end(), system), awakeSystems.end());
            }
        }
    }
}
