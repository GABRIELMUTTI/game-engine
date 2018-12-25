#pragma once

#include "mtengine/identifier/UID.hpp"

#include <unordered_map>
#include <string>

namespace mtengine
{
    template<class BaseType, class ... FuncArgs>
    class Factory
    {
        typedef BaseType*(*CreateFunc)(FuncArgs ...);
        
    private:
	std::unordered_map<UID, CreateFunc> registry;
	
	template<class T>
	static BaseType* creationFunction(FuncArgs ... args)
	{
	    return new T(args ...);
	}

    public:
	Factory()
	{
		
	}

	template<class T>
	void registerType(UID uid)
	{
	    registry[uid] = &creationFunction<T>;
	}

	BaseType* create(UID uid, FuncArgs ... args)
	{
	    auto it = registry.find(uid);
	    if (it != registry.end())
	    {
		return it->second(args ...);
	    }

	    return nullptr;
	}
    };
}
