#include "mtecs/component/ComponentManager.hpp"

namespace mtecs
{
    namespace internal
    {
	ComponentManager::ComponentManager(uint allocationStep) :
	    allocationStep(allocationStep)
	{

	}

	void ComponentManager::allocateInPools()
	{
	    for (Pool<Component>* pool : componentPools)
	    {
		pool->allocate(allocationStep);
	    }
	}	
    }
}
