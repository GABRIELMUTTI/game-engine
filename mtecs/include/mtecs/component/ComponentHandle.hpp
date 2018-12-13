#pragma once

#include "mtecs/component/Component.hpp"
#include "mtecs/component/Pool.hpp"

namespace mtecs
{
    template<class T>
    class ComponentHandle
    {
    private:
	
	unsigned int index;
	const Pool<Component>* componentPool;
	
    public:
	ComponentHandle() :
	    componentPool(nullptr),
	    index(0)
	{
	      
	}
	
	ComponentHandle(const Pool<Component>* componentPool, unsigned int index) :
	    componentPool(componentPool),
	    index(index)
	{

	}

	bool isValid()
	{
	    return componentPool != nullptr;
	}
            
	T* operator -> ()
	{ 
	    return static_cast<T*>(componentPool->get(index));
	}

	T operator * ()
	{ 
	    return *static_cast<T*>(componentPool->get(index)); 
	}

	bool operator == (const ComponentHandle<T>& other)
	{
	    return componentPool == other.componentPool && index == other.index;
	}

	bool operator != (const ComponentHandle<T>& other)
	{
	    return componentPool != other.componentPool || index != other.index;
	}
    };
}
