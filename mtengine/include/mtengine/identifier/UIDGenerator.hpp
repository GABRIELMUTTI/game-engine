#pragma once

#include <unordered_map>
#include <typeindex>

namespace mtengine
{
    class UIDGenerator
    {
    private:
	std::unordered_map<std::type_index, unsigned int> uids;
	unsigned int numRegistered;
	
    public:
	UIDGenerator() :
	    numRegistered(0)
	{
	    
	}

	template<class T>
	void registerType()
	{
	    uids[typeid(T)] = numRegistered;
	    numRegistered++;
	}

	template<class T>
	unsigned int getUID()
	{
	    return uids[typeid(T)];
	}
	
    };
}
