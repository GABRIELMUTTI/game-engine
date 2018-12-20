#pragma once

#include <string>

namespace mtengine
{
    namespace serialization
    {
	template<class Derived>
	class ISerializer
	{
	public:
	    template<typename T>
	    std::string serialize(const T& obj)
	    {
		return static_cast<Derived*>(this)->serialize(obj);
	    }

	    template<typename T>
	    void deserialize(T& obj, const std::string& serializedState)
	    {
		return static_cast<Derived*>(this)->deserialize(obj, serializedState);
	    }
	};
    }
}

