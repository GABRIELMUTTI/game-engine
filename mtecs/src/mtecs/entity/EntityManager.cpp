#include "mtecs/entity/EntityManager.hpp"

namespace mtecs
{
    namespace internal
    {
	EntityManager::EntityManager() :
	    Entities(entities)
	{

	}

	Entity* EntityManager::createEntity(const std::string& name)
	{
	    int entityId;

	    if (freeFragmentedIndexes.empty())
	    {
		entityId = entities.size();
	    }
	    else
	    {
		entityId = freeFragmentedIndexes.back();
		freeFragmentedIndexes.pop_back();
	    }

	    Entity* entity = new Entity(entityId, name);
	    entities.push_back(entity);

	    return entity;
	}

	void EntityManager::destroyEntity(uint entityId)
	{
	    if (entityId + 1 == entities.size())
	    {
		entities.erase(entities.begin() + entityId);
	    }
	    else
	    {
		entities[entityId] = nullptr;
		freeFragmentedIndexes.push_back(entityId);
		std::sort(freeFragmentedIndexes.rbegin(), freeFragmentedIndexes.rend());
	    }
	}

	Entity* EntityManager::getEntity(uint entityId)
	{
	    return entities[entityId];
	}	
    }
}
