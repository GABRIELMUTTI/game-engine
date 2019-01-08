#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/Entity.hpp"

#include <utilities/property/StructureProperty.hpp>

#include <vector>
#include <string>
#include <algorithm>

namespace mtecs
{
    namespace internal
    {
	class EntityManager
	{
	private:
	    std::vector<Entity*> entities;
	    std::vector<uint> freeFragmentedIndexes;

	public:
	    const utility::StructureProperty<std::vector<Entity*>> Entities;

	    EntityManager();
            
	    Entity* createEntity(const std::string& name);
	    void destroyEntity(uint entityId);
	    Entity* getEntity(uint entityId);
	};		
    }
}
