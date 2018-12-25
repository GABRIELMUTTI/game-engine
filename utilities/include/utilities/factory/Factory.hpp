#pragma once

#include <unordered_map>
#include <string>

namespace utility
{
    template<class TBase, typename TId, class ... FuncArgs>
    class Factory
    {
        typedef TBase*(*CreateFunc)(FuncArgs ...);
        
    private:
	std::unordered_map<TId, CreateFunc> registry;
	
	template<class T>
	static TBase* creationFunction(FuncArgs ... args)
	{
	    return new T(args ...);
	}

    public:
	Factory()
	{
		
	}

	template<class T>
	void registerType(TId uid)
	{
	    registry[uid] = &creationFunction<T>;
	}

	TBase* create(TId uid, FuncArgs ... args)
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
