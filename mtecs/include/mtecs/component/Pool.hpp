#pragma once

namespace mtecs
{
    template<class T>
    class Pool
    {
    public:
	virtual T* get(unsigned int index) const = 0;
	virtual void add(unsigned int index) = 0;
	virtual void remove(unsigned int index) = 0;
	virtual void allocate(unsigned int amount) = 0;
	virtual void deallocate(unsigned int amount) = 0;
	virtual void swap(unsigned int indexA, unsigned int indexB) = 0;
            
	virtual unsigned int getCapacity() const = 0;
	virtual unsigned int getCount() const = 0;
    };
}
