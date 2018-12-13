#pragma once

#include <unordered_map>
#include <string>

namespace mtengine
{
    template<class BaseType, class ... FuncArgs>
    class Factory
    {
        typedef BaseType*(*CreateFunc)(FuncArgs ...);
        
    private:
	std::unordered_map<std::string, CreateFunc> registry;

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
	void registerType(const std::string& name)
	{
	    registry[name] = &creationFunction<T>;
	}

	BaseType* create(const std::string& name, FuncArgs ... args)
	{
	    auto it = registry.find(name);
	    if (it != registry.end())
	    {
		return it->second(args ...);
	    }

	    return nullptr;
	}
    };
}
