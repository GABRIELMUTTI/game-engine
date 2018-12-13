#pragma once

#include "mtecs/group/Group.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

#include <utilities/eventqueue/message/MessageQueue.hpp>

using utility::MessageQueue;
using utility::Message;

namespace mtecs
{
    class GroupManager
    {
    private:
	std::vector<Group*> groups;
	EntityManager* entityManager;
	MessageQueue* messageQueue;
	ComponentRegistry* componentRegistry;

	void onComponentAdded(Message message);
	void onComponentRemoved(Message message);

	void createGroup(const Mask& mask);

    public:
	GroupManager(EntityManager* entityManager, ComponentRegistry* componentRegistry, MessageQueue* messageQueue);

	template<class ... Types>
	Group* getGroup()
	{
	    Mask mask = componentRegistry->getMask<Types ...>();
                
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
