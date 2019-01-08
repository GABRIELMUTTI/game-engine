#pragma once

#include "mtecs/world/World.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/entity/Entity.hpp"

#include <string>

#define ERR_NULL_ENTITY -1
#define ERR_WRONG_NAME -2
#define ERR_WRONG_ID -3

#define TST_CREATION 1
#define TST_DESTRUCTION 2

namespace mtecs
{
    namespace test
    {
	class EntityTest
	{
	    typedef unsigned int uint;
	    
	private:
	    World world;
	    
	    
	    int testCreation(uint correctId)
	    {
		std::string entityName = "testEntity";
		
		Entity* entity = world.createEntity(entityName);

		if (entity == nullptr) { return ERR_NULL_ENTITY; }
		
		if (entity->getName() != entityName) { return ERR_WRONG_NAME;}

		if (entity->getId() != correctId) { return ERR_WRONG_ID; }

		return 0;
	    }

	    int testDestruction()
	    {
		Entity* entity = world.getEntity(0);
		world.destroyEntity(entity);

		return 0;
	    }

	    
	public:
	    int test()
	    {
		if (testCreation(0) != 0) { return TST_CREATION; }
		if (testCreation(1) != 0) { return TST_CREATION; }
		if (testDestruction() != 0) { return TST_DESTRUCTION; }

		return 0;
	    }
	};
    }
}



