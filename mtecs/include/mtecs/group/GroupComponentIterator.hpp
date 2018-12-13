#pragma once

#include "mtecs/component/Mask.hpp"
#include "mtecs/entity/Entity.hpp"
#include "mtecs/component/ComponentHandle.hpp"

#include <tuple>
#include <vector>

namespace mtecs
{
    template<class Container, class ... Components>
    class GroupComponentIterator
    {
        typedef typename Container::const_iterator Iterator;

    private:
	Iterator containerIterator;
	std::tuple<ComponentHandle<Components>& ...> handles;
	std::vector<Mask> masks;
	unsigned int currentIndex;

	template<unsigned int N, class TFirst, class TSecond, class ... Rest>
	void setComponents(Entity* entity)
	{
	    setComponents<N, TFirst>(entity);
	    setComponents<N + 1, TSecond, Rest ...>(entity);
	}

	template<unsigned int N, class TComponent>
	void setComponents(Entity* entity)
	{
	    std::get<N, ComponentHandle<Components>& ...>(handles) = entity->getComponent<TComponent>(masks[N]);
           
	}

    public:
	GroupComponentIterator(Iterator containerIterator, std::tuple<ComponentHandle<Components>& ...> handles, const std::vector<Mask>& masks) :
	    containerIterator(containerIterator),
	    handles(handles),
	    masks(masks)
	{
 
	}

	bool operator == (const GroupComponentIterator& other) const { return containerIterator == other.containerIterator; }
	bool operator != (const GroupComponentIterator& other) const { return containerIterator != other.containerIterator; }
	Entity* operator * () { setComponents<0, Components ...>(*containerIterator); return *containerIterator; }
	void operator ++ () { containerIterator++; }
    };
}
