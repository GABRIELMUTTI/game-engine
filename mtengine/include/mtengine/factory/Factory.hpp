#pragma once

#include "mtengine/identifier/UIDGenerator.hpp"
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
	UIDGenerator& uidGenerator;

	
	template<class T>
	static BaseType* creationFunction(FuncArgs ... args)
	{
	    return new T(args ...);
	}

    public:
	Factory(UIDGenerator& uidGenerator) :
	    uidGenerator(uidGenerator)
	{
		
	}

	template<class T>
	void registerType()
	{
	    registry[uidGenerator.getUID<T>()] = &creationFunction<T>;
	}

	BaseType* create(const UID uid, FuncArgs ... args)
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
