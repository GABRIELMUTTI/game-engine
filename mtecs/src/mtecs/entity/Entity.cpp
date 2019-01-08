#include "mtecs/entity/Entity.hpp"

namespace mtecs
{
    Entity::Entity(uint id, const std::string& name) :
	id(id),
	name(name)
    {
	
    }

    uint Entity::getId() const
    {
	return id;
    }

    std::string Entity::getName() const
    {
	return name;
    }

    Mask Entity::getMask() const
    {
	return mask;
    }

    bool Entity::hasComponents(const Mask& componentMask) const
    {
	return mask.has(componentMask);
    }

    void Entity::setMask(const Mask& mask)
    {
	this->mask.update(mask);
    }
}
