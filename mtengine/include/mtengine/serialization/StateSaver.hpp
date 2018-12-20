#pragma once

#include "mtengine/serialization/ISerializer.hpp"

#include <mtecs/world/World.hpp>

#include <string>

namespace mtengine
{
    namespace serialization
    {
	class StateSaver
	{
	private:
	    const mtecs::World* world;

	public:
	    StateSaver(const mtecs::World* world) :
		world(world)
	    {
		
	    }
	    
	    template<class T>
	    void save(const ISerializer<T>& serializer, const std::string& filepath)
	    {
		// Create new file...

		std::string serializedState = serializer.serialize<mtecs::World>(world);

		// Save the file...
	    }
	};
    }
}
