#pragma once

#include "mtengine/serialization/ISerializable.hpp"
    
#include <mtecs/component/Component.hpp>

namespace mtengine
{
    class Component : public mtecs::Component, public serialization::ISerializable
    {
    public:
	Component();
	virtual ~Component() {}
    };
}
