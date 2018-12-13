#pragma once

#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/system/System.hpp"
#include "mtecs/group/GroupManager.hpp"

#include <utilities/eventqueue/message/MessageQueue.hpp>
#include <utilities/property/StructureProperty.hpp>

#include <vector>
#include <algorithm>

namespace mtecs
{
    class World
    {
    private:
	std::vector<System*> systems;
	std::vector<System*> awakeSystems;
	std::vector<System*> newSystems;
      
	ComponentManager* componentManager;
	EntityManager* entityManager;
	ComponentRegistry* componentRegistry;
	GroupManager* groupManager;
	utility::MessageQueue* messageQueue;
      
	void onSystemStateChanged(Message message);
      
    public:
	World();

	void initialize();

	void addSystem(System* system);
	void removeSystem(System* system);
	void update(float deltaTime);
	  
	System* getSystem(unsigned int index);
	  
	EntityManager* getEntityManager();
	ComponentManager* getComponentManager();
	ComponentRegistry* getComponentRegistry();
	GroupManager* getGroupManager();
	utility::MessageQueue* getMessageQueue();
    };
}
