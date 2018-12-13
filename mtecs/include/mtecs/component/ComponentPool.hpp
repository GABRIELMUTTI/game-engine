#pragma once

#include "mtecs/component/Pool.hpp"
#include "mtecs/component/Component.hpp"

#include <vector>

namespace mtecs
{
    template<class T>
    class ComponentPool : public Pool<Component>
    {    
    private:
	T* array;
	unsigned int capacity;
	unsigned int count;
	unsigned int allocationStep;

	bool isIndexValid(unsigned int index)
	{
	    return index < capacity && index >= 0;
	}

    public:
	ComponentPool(const unsigned int allocationStep) :
	    allocationStep(allocationStep),
	    array(nullptr),
	    capacity(0),
	    count(0)
	{
	    allocate(allocationStep);
	}

            
	void add(unsigned int index)
	{
	    count++;
	}

            
	void remove(unsigned int index)
	{
	    count--;
	}

            
	Component* get(unsigned int index) const
	{
	    return static_cast<Component*>(&array[index]);
	}

	void allocate(unsigned int amount)
	{
	    unsigned int newCapacity = capacity + amount;
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

            
	void deallocate(unsigned int amount)
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

            
	void swap(unsigned int indexA, unsigned int indexB)
	{
	    if (isIndexValid(indexA) && isIndexValid(indexB))
	    {
		T tmp = array[indexB];
		array[indexB] = array[indexA];
		array[indexA] = tmp;
	    }
	}

            
	unsigned int getCount() const
	{
	    return count;
	}

            
	unsigned int getCapacity() const
	{
	    return capacity;
	}
    };
}
