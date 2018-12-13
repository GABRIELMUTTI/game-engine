#include "mtecs/entity/Entity.hpp"

namespace mtecs
{
    Entity::Entity(unsigned int id, const std::string& name, ComponentManager* componentManager, ComponentRegistry* componentRegistry) :
        id(id),
        name(name),
        componentManager(componentManager),
        componentRegistry(componentRegistry)
    {

    }

    unsigned int Entity::getId()
    {
	return id;
    }

    std::string Entity::getName()
    {
        return name;
    }

    bool Entity::hasComponents(const Mask& componentMask)
    {
        return mask.has(componentMask);
    }
}
