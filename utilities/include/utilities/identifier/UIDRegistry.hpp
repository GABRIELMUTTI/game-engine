#pragma once

#include <unordered_map>
#include <typeindex>

namespace utility
{
    class UIDRegistry
    {
	typedef unsigned int uint;
	
    private:
	std::unordered_map<std::type_index, uint> uids;
	unsigned int numRegistered;
	
    public:
	UIDRegistry() :
	    numRegistered(0)
	{
	    
	}

	template<class T>
	void registerType()
	{
	    auto it = uids.find(typeid(T));
	    if (it != uids.end())
	    {
		uids[typeid(T)] = numRegistered;
		numRegistered++;
	    }
	}

	template<class T>
	uint getUID()
	{
	    return uids[typeid(T)];
	}
    };
}
