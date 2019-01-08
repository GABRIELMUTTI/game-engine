#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/component/Pool.hpp"
#include "mtecs/component/ComponentPool.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <typeindex>
#include <vector>

namespace mtecs
{
    namespace internal
    {
	class ComponentManager
	{
	private:
	    std::vector<Pool<Component>*> componentPools;
	    uint allocationStep;

	private:
	    template<class T>
	    void createPool(uint index)
	    {
		Pool<Component>* newPool = new ComponentPool<T>(allocationStep);

		if (index >= componentPools.size())
		{
		    componentPools.resize(index + 1, nullptr);
		}
	    
		componentPools[index] = newPool;
	    }

	    void allocateInPools();

	public:
	    ComponentManager(uint allocationStep);

	    template<class T>
	    ComponentHandle<T> getComponent(uint entityId, const Mask& mask) const
	    {
		unsigned int poolIndex = mask.index();
		return ComponentHandle<T>(componentPools[poolIndex], entityId);
	    }

	    template<class T>
	    ComponentHandle<T> addComponent(uint entityId, const Mask& mask)
	    {
		uint index = mask.index();
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

		uint poolCapacity = pool->getCapacity();
		if (entityId >= poolCapacity)
		{
		    pool->allocate((entityId - poolCapacity) + allocationStep);    
		}

		pool->add(entityId);

		return ComponentHandle<T>(componentPools[index], entityId);
	    }

	    template<class T>
	    void removeComponent(uint entityId, const Mask& mask)
	    {
		uint index = mask.index();
		componentPools[index]->remove(entityId);
	    }
	};	
    }
}
