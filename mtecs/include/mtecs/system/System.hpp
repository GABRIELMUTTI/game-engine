#pragma once

#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/group/GroupManager.hpp"
#include "mtecs/group/Group.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <utilities/eventqueue/message/MessageQueue.hpp>

namespace mtecs
{
    class System
    {
    private:
	unsigned int id;
	Mask mask;
	bool enabled;
	bool awake;

    protected:
	ComponentManager* components;
	EntityManager* entities;
	ComponentRegistry* registry;
	GroupManager* groups;

	utility::MessageQueue* events;
            
    public:
	System(unsigned int id);

	virtual void initialize() = 0;
	virtual void update(float deltaTime) = 0;

	Mask getMask();
	unsigned int getId();
	
	bool isEnabled();
	bool isAwake();

	void setEnabled(bool state);
	void setAwake(bool state);

	void setComponentManager(ComponentManager* componentManager);
	void setEntityManager(EntityManager* entityManager);
	void setComponentRegistry(ComponentRegistry* componentRegistry);
	void setMessageQueue(utility::MessageQueue* messageQueue);
	void setGroupManager(GroupManager* groupManager);

    };
}
