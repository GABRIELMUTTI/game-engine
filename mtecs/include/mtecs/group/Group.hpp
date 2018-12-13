#pragma once

#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/Mask.hpp"
#include "mtecs/group/GroupComponentIterator.hpp"
#include "mtecs/group/GroupComponentView.hpp"
#include "mtecs/component/ComponentHandle.hpp"
#include "mtecs/component/ComponentRegistry.hpp"

namespace mtecs
{
    class Group
    {
        typedef std::vector<Entity*> Entities;

    private:
	Mask mask;
	std::vector<Entity*> entities;
	mtecs::ComponentRegistry* componentRegistry;

	template<class TFirst, class TSecond, class ... Rest>
	void getMasks(std::vector<Mask>& masks)
	{
	    getMasks<TFirst>(masks);
	    getMasks<TSecond, Rest ...>(masks);
	}

	template<class Type>
	void getMasks(std::vector<Mask>& masks)
	{
	    masks.push_back(componentRegistry->getMask<Type>());
	}

    public:
	Group(const Mask& mask, ComponentRegistry* componentRegistry);

	Entity* get(unsigned int index);
	void add(Entity* entity);
	void remove(Entity* entity);

	bool entityBelongsToGroup(Entity* entity);
	bool hasComponents(const Mask& componentMask, Mask::Has has);

	Mask getMask();

	const Entities& getEntities();

	template<class ... Components>
	GroupComponentView<Components ...> getEntities(ComponentHandle<Components>& ... handles)
	{
	    std::vector<Mask> masks;
	    getMasks<Components ...>(masks);
                
	    return GroupComponentView<Components ...>(entities, masks, handles ...);
	}
    };
}
