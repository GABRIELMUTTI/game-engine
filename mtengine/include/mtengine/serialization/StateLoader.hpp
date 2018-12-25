#pragma once

#include "mtengine/serialization/ISerializer.hpp"

#include <mtecs/world/World.hpp>

#include <string>

namespace mtengine
{
    namespace serialization
    {
	class StateLoader
	{
	private:
	    mtecs::World& world;

	public:
	    StateLoader(mtecs::World& world) :
		world(world)
	    {
		
	    }
	    
	    template<class T>
	    void load(const ISerializer<T>& serializer, const std::string& filepath)
	    {
		// Read file...

		std::string serializedState;
		serializer.deserialize<mtecs::World>(world, serializedState);
	    }
	};
    }
}
