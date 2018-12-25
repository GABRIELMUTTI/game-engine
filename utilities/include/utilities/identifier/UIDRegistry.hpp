#pragma once

#include "UID.hpp"

#include <unordered_map>
#include <typeindex>

namespace utility
{
    class UIDGenerator
    {
    private:
	std::unordered_map<std::type_index, UID> uids;
	unsigned int numRegistered;
	
    public:
	UIDGenerator() :
	    numRegistered(0)
	{
	    
	}

	template<class T>
	void registerType()
	{
	    auto it = uids.find(typeid(T));
	    if (it != uids.end())
	    {
		uids[typeid(T)] = UID(numRegistered);
		numRegistered++;
	    }
	}

	template<class T>
	UID getUID()
	{
	    return uids[typeid(T)];
	}
    };
}
