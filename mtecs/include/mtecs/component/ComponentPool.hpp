#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Pool.hpp"
#include "mtecs/component/Component.hpp"

#include <vector>

namespace mtecs
{
    namespace internal
    {
	template<class T>
	class ComponentPool : public Pool<Component>
	{    
	private:
	    T* array;
	    uint capacity;
	    uint count;
	    uint allocationStep;

	    bool isIndexValid(uint index) const
	    {
		return index < capacity && index >= 0;
	    }

	public:
	    ComponentPool(const uint allocationStep) :
		allocationStep(allocationStep),
		array(nullptr),
		capacity(0),
		count(0)
	    {
		allocate(allocationStep);
	    }

            
	    void add(uint index)
	    {
		count++;
	    }

            
	    void remove(uint index)
	    {
		count--;
	    }

            
	    Component* get(uint index) const
	    {
		return static_cast<Component*>(&array[index]);
	    }

	    void allocate(uint amount)
	    {
		uint newCapacity = capacity + amount;
		T* newArray = new T[newCapacity];

		if (array != nullptr)
		{
		    for (int i = 0; i < capacity; i++)
		    {
			newArray[i] = array[i];
		    }
		}

		delete[] array;
		array = newArray;
		capacity = newCapacity;
	    }

            
	    void deallocate(uint amount)
	    {
		int newCapacity = capacity - amount;

		if (newCapacity > 0)
		{
		    T* newArray = new T[newCapacity];

		    if (array != nullptr)
		    {
			for (int i = 0; i < newCapacity; i++)
			{
			    newArray[i] = array[i];
			}
		    }
                    
		    delete[] array;
		    array = newArray;
		}
		else
		{
		    capacity = 0;
		    delete[] array;
		    array = nullptr;
		}
	    }

            
	    void swap(uint indexA, uint indexB)
	    {
		if (isIndexValid(indexA) && isIndexValid(indexB))
		{
		    T tmp = array[indexB];
		    array[indexB] = array[indexA];
		    array[indexA] = tmp;
		}
	    }

            
	    uint getCount() const
	    {
		return count;
	    }

            
	    uint getCapacity() const
	    {
		return capacity;
	    }
	};	
    }
}
