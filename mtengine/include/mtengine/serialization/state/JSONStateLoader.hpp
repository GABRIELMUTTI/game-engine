#pragma once

#include "mtengine/serialization/state/IStateLoader.hpp"
#include "mtengine/serialization/List.hpp"

#include <mtecs/world/World.hpp>

#include <nlohmann/json.hpp>

#include <fstream>
    
namespace mtengine
{
    namespace serialization
    {
	class JSONStateLoader : public IStateLoader
	{
	private:
	    std::string readFromFile(const std::string& filepath);

	public:
	    JSONStateLoader(mtecs::World* world);
	    
	    Data* load(const std::string& filepath);
	};
    }
}
