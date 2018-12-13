#pragma once

#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/Mask.hpp"

#include <set>
#include <typeindex>

namespace mtecs
{
    class Entity
    {
    private:
	unsigned int id;
	std::string name;
	ComponentManager* componentManager;
	ComponentRegistry* componentRegistry;
	Mask mask;

    public:
	Entity(unsigned int id, const std::string& name, ComponentManager* componentManager, ComponentRegistry* componentRegistry);

	unsigned int getId();
	std::string getName();
	bool hasComponents(const Mask& componentMask);

	template<class T>
	ComponentHandle<T> addComponent(const Mask& componentMask)
	{
	    mask.update(componentMask);
	    ComponentHandle<T> handle = componentManager->addComponent<T>(id, componentMask);

	    return handle;
	}

	template<class T>
	ComponentHandle<T> addComponent()
	{
	    Mask componentMask = componentRegistry->getMask<T>();
	    mask.update(componentMask);

	    ComponentHandle<T> handle = componentManager->addComponent<T>(id, componentMask);
	    return handle;
	}


	template<class T>
	ComponentHandle<T> getComponent()
	{
	    Mask componentMask = componentRegistry->getMask<T>();
	    return componentManager->getComponent<T>(id, componentMask);
	}


	template<class T>
	ComponentHandle<T> getComponent(const Mask& componentMask)
	{
	    return componentManager->getComponent<T>(id, componentMask);
	}

	template<class T>
	void removeComponent(const Mask& componentMask)
	{
	    mask.remove(componentMask);
	    componentManager->removeComponent<T>(id, componentMask);
	}
    };
}
