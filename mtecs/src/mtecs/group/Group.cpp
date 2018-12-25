#include "mtecs/group/Group.hpp"

namespace mtecs
{
    Group::Group(const Mask& mask, ComponentRegistry* componentRegistry) :
        mask(mask),
	componentRegistry(componentRegistry)
    {

    }

    Entity* Group::get(unsigned int index)
    {
        return entities[index];
    }

    void Group::add(Entity* entity)
    {
        entities.push_back(entity);
    }

    void Group::remove(Entity* entity)
    {
        entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
    }

    bool Group::entityBelongsToGroup(Entity* entity)
    {
        return entity->hasComponents(mask);
    }

    bool Group::hasComponents(const Mask& componentMask, Mask::Has has)
    {
        return mask.has(componentMask, has);
    }

    Mask Group::getMask()
    {
        return mask;
    }

    const std::vector<Entity*>& Group::getEntities()
    {
        return entities;
    }
}
