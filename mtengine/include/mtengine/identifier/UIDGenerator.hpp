#pragma once

#include "mtengine/identifier/UID.hpp"

#include <unordered_map>
#include <typeindex>

namespace mtengine
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
	    uids[typeid(T)] = UID(numRegistered);
	    numRegistered++;
	}

	template<class T>
	UID getUID()
	{
	    return uids[typeid(T)];
	}
    };
}
