#pragma once

#include "mtecs/system/ISystem.hpp"
#include "mtecs/api/Behaviour.hpp"

namespace mtecs
{
    class System : public internal::ISystem
    {
    private:
	internal::Behaviour* behaviour;
	
    public:
	void setBehaviour(internal::Behaviour& behaviour)
	{
	    this->behaviour = &behaviour;
	}
	
	// Entity API:
	inline Entity* createEntity(const std::string& name)
	{
	    return behaviour->createEntity(name);
	}
	
	inline Entity* getEntity(uint entityId)
	{
	    return behaviour->getEntity(entityId);
	}
	
	inline void destroyEntity(Entity* entity)
	{
	    behaviour->destroyEntity(entity);
	}
	
	// Component API:
	template<class T>
	inline ComponentHandle<T> addComponent(Entity* entity)
	{
	    return behaviour->addComponent<T>(entity);
	}

	template<class T>
	inline void removeComponent(Entity* entity)
	{
	    behaviour->removeComponent<T>(entity);
	}
	
	template<class T>
	inline ComponentHandle<T> getComponent(Entity* entity)
	{
	    return behaviour->getComponent<T>(entity);
	}

	// System API:
	template<class T>
	inline T* addSystem()
	{
	    return behaviour->addSystem<T>();
	}

	template<class T>
	inline T* getSystem(uint systemId)
	{
	    return behaviour->getSystem<T>();
	}

	inline void removeSystem(uint systemId)
	{
	    behaviour->removeSystem(systemId);
	}

	// Group API:
	template<class ... TComponents>
	inline Group* getGroup()
	{
	    return behaviour->getGroup<TComponents ...>();
	}
    };
}
