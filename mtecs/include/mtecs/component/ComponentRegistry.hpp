#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/component/Mask.hpp"

#include <unordered_map>
#include <typeindex>
#include <iostream>
#include <cmath>

namespace mtecs
{
    namespace internal
    {
	class ComponentRegistry
	{
	private:
	    std::unordered_map<std::type_index, Mask> types;
	    uint numRegistered;

	public:
	    ComponentRegistry()
	    {
		numRegistered = 0;
	    }

	    template<class T>
	    Mask getMask()
	    {
		auto it = types.find(typeid(T));
		if (it == types.end())
		{
		    registerType<T>();
		}
         
		return types.at(typeid(T));
	    }

	    template<class T, class U, class ... Rest>
	    Mask getMask()
	    {
		Mask mask = getMask<U, Rest ...>();
		Mask finalMask = getMask<T>();
		finalMask.update(mask);

		return finalMask;
	    }

	    template<class T>
	    void registerType()
	    {
		auto it = types.find(typeid(T));
		if (it == types.end())
		{
		    types[typeid(T)] = Mask(pow(2, numRegistered));
		    numRegistered++;
		}
	    }

	    uint getNumRegistered() const
	    {
		return numRegistered;
	    }
	};	
    }
}
