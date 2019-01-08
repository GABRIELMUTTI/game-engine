#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/EntityManager.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/group/GroupManager.hpp"
#include "mtecs/system/SystemManager.hpp"
#include "mtecs/api/ISetter.hpp"
#include "mtecs/system/ISystem.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <string>

namespace mtecs
{
    namespace internal
    {
	class Behaviour
	{
	private:
	    EntityManager& entityManager;
	    ComponentManager& componentManager;
	    ComponentRegistry& componentRegistry;
	    GroupManager& groupManager;
	    SystemManager& systemManager;
	    ISetter<ISystem>& behaviourSetter;
	
	public:
	    Behaviour(EntityManager& entityManager, ComponentManager& componentManager, ComponentRegistry& componentRegistry, GroupManager& groupManager, SystemManager& systemManager, ISetter<ISystem>& behaviourSetter) :
		entityManager(entityManager),
		componentManager(componentManager),
		componentRegistry(componentRegistry),
		groupManager(groupManager),
		systemManager(systemManager),
		behaviourSetter(behaviourSetter)
	    {
	    
	    }

	    // Entity API:
	    inline Entity* createEntity(const std::string& name)
	    {
		return entityManager.createEntity(name);
	    }
	
	    inline Entity* getEntity(uint entityId)
	    {
		return entityManager.getEntity(entityId);
	    }
	
	    inline void destroyEntity(Entity* entity)
	    {
		entityManager.destroyEntity(entity->getId());
	    }
	
	    inline void destroyEntity(uint entityId)
	    {
		entityManager.destroyEntity(entityId);
	    }

	    // Component API:
	    template<class T>
	    inline ComponentHandle<T> addComponent(Entity* entity)
	    {
		return componentManager.addComponent<T>(entity->getId(), componentRegistry.getMask<T>());
	    }

	    template<class T>
	    inline void removeComponent(Entity* entity)
	    {
		componentManager.removeComponent<T>(entity->getId(), componentRegistry.getMask<T>());
	    }
	
	    template<class T>
	    inline ComponentHandle<T> getComponent(Entity* entity)
	    {
		return componentManager.getComponent<T>(entity->getId(), componentRegistry.getMask<T>());
	    }

	    // System API:
	    template<class T>
	    inline T* addSystem()
	    {
		T* system = systemManager.addSystem<T>();
		behaviourSetter.set(*system);

		return system;
	    }

	    template<class T>
	    inline T* getSystem(uint systemId)
	    {
		return systemManager.getSystem<T>(systemId);
	    }

	    inline void removeSystem(uint systemId)
	    {
		systemManager.removeSystem(systemId);
	    }

	    // Group API:
	    template<class ... TComponents>
	    inline Group* getGroup()
	    {
		return groupManager.getGroup<TComponents ...>();
	    }
	};	
    }
}
