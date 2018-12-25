#pragma once

#include "mtecs/component/Component.hpp"
#include "mtecs/component/Pool.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/component/ComponentPool.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <utilities/eventqueue/message/MessageQueue.hpp>

#include <typeindex>
#include <vector>

using utility::MessageQueue;
using utility::Message;

namespace mtecs
{
    class ComponentManager
    {
    private:
	std::vector<Pool<Component>*> componentPools;
	ComponentRegistry* componentRegistry;
	unsigned int allocationStep;
            
	MessageQueue* messageQueue;

    private:
	template<class T>
	void createPool(int index)
	{
	    Pool<Component>* newPool = new ComponentPool<T>(allocationStep);

	    if (index >= componentPools.size())
	    {
		componentPools.resize(index + 1, nullptr);
	    }
	    
	    componentPools[index] = newPool;
	}

	void allocateInPools();

	void sendComponentAddedMessage(unsigned int entityId, const Mask& mask);
	void sendComponentRemovedMessage(unsigned int entityId, const Mask& mask);

    public:
	ComponentManager(ComponentRegistry* componentRegistry, unsigned int allocationStep, MessageQueue* messageQueue);

	template<class T>
	ComponentHandle<T> getComponent(unsigned int entityId, const Mask& mask)
	{
	    unsigned int poolIndex = mask.index();
	    return ComponentHandle<T>(componentPools[poolIndex], entityId);
	}

	template<class T>
	ComponentHandle<T> addComponent(unsigned int entityId, Mask& mask)
	{
	    unsigned int index = mask.index();
	    Pool<Component>* pool;

	    // Fetch pool;
	    if (index + 1 <= componentPools.size())
	    {
		pool = componentPools[index];
	    }
	    else // Create new pool.
	    {
		createPool<T>(index);
		pool = componentPools[index];
	    }

	    if (pool == nullptr)
	    {
		createPool<T>(index);
		pool = componentPools[index];
	    }

	    unsigned int poolCapacity = pool->getCapacity();
	    if (entityId >= poolCapacity)
	    {
		pool->allocate((entityId - poolCapacity) + allocationStep);    
	    }

	    pool->add(entityId);
                
	    sendComponentAddedMessage(entityId, mask);

	    return ComponentHandle<T>(componentPools[index], entityId);
	}

	template<class T>
	void removeComponent(unsigned int entityId, Mask& mask)
	{
	    unsigned int index = mask.index();
	    componentPools[index]->remove(entityId);

	    sendComponentRemovedMessage(entityId, mask);
	}
    };
}
