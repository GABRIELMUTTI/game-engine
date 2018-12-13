#pragma once

#include <mtecs/world/World.hpp>

namespace mtengine
{
    class MtecsStateRestorer
    {
    private:
	mtcs::World* world;
    public:
	MtecsStateRestorer(mtecs::World* world);

	void restore(serialization::Data* data);
    };
}
