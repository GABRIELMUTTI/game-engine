#include "mtecs/system/SystemManager.hpp"

namespace mtecs
{
    namespace internal
    {
	SystemManager::SystemManager()
	{
	
	}
    
	void SystemManager::initialize()
	{
	    for (ISystem* newSystem : newSystems)
	    {
		newSystem->initialize();
	    }

	    newSystems.clear();
	}

	void SystemManager::removeSystem(uint systemId)
	{
	    if (systemId >= systems.size()) { return; }
	
	    ISystem* system = systems[systemId];
	    systems.erase(std::remove(systems.begin(), systems.end(), system), systems.end());
	}

	void SystemManager::update(float deltaTime)
	{
	    for (ISystem* newSystem : newSystems)
	    {
		newSystem->initialize();
	    }
	
	    for (ISystem* system : systems)
	    {
		system->update(deltaTime);
	    }
	}
    
	void SystemManager::addSystem(uint systemTypeId)
	{
	    ISystem* newSystem = systemFactory.create(systemTypeId, systems.size());

	    systems.push_back(newSystem);
	    newSystems.push_back(newSystem);
	}	
    }
}
