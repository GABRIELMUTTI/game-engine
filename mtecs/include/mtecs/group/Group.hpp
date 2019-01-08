#pragma once

#include "mtecs/typedef/Typedef.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/component/ComponentManager.hpp"
#include "mtecs/component/ComponentRegistry.hpp"
#include "mtecs/group/GroupComponentView.hpp"

#include <vector>
#include <algorithm>

namespace mtecs
{
    class Group
    {
	typedef std::vector<Entity*> Entities;

    private:
	Mask mask;
	Entities entities;
	const internal::ComponentManager& componentManager;
	internal::ComponentRegistry& componentRegistry;
	
    public:
	Group(const Mask& mask, const internal::ComponentManager& componentManager, internal::ComponentRegistry& componentRegistry);

	Entity* get(uint index) const;
	void add(Entity* entity);
	void remove(Entity* entity);

	bool entityBelongsToGroup(const Entity& entity) const;
	bool hasComponents(const Mask& componentMask, Mask::Has has) const;

	Mask getMask() const;

	const Entities& getEntities() const;

	template<class ... Components>
	GroupComponentView<Components ...> getEntities(ComponentHandle<Components>& ... handles)
	{
	    return GroupComponentView<Components ...>(entities, handles ..., componentManager, componentRegistry);
	}
    };
}
