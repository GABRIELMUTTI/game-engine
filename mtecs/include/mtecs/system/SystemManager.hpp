#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/system/ISystem.hpp"

#include <utilities/identifier/UIDRegistry.hpp>
#include <utilities/factory/Factory.hpp>

#include <vector>
#include <algorithm>

namespace mtecs
{
    namespace internal
    {
	class SystemManager
	{
	private:
	    std::vector<ISystem*> systems;
	    std::vector<ISystem*> newSystems;

	    utility::UIDRegistry systemUIDRegistry;
	    utility::Factory<ISystem, uint, uint> systemFactory;

	public:
	    SystemManager();

	    void initialize();
	    void update(float deltaTime);

	    template<class T>
	    T* getSystem(uint systemId) const
	    {
		if (systemId >= systems.size()) { return nullptr; }
		return static_cast<T*>(systems[systemId]);
	    }

	    template<class T>
	    void addSystem()
	    {
		ISystem* newSystem = new T(systems.size());

		systems.push_back(newSystem);
		newSystems.push_back(newSystem);
	    }

	    void addSystem(uint systemTypeId);
	    void removeSystem(uint systemId);
	};	
    }
}
