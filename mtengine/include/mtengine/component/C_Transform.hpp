#pragma once

#include <mtecs/component/Component.hpp>

#include <glm/glm.hpp>
#include <MetaStuff/include/Meta.h>


namespace mtengine
{
    struct C_Transform : public mtecs::Component
    {
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;

        C_Transform() :
            position(glm::vec3(0.0f, 0.0f, 0.0f)),
            rotation(glm::vec3(0.0f, 0.0f, 0.0f)),
            scale(glm::vec3(1.0f, 1.0f, 1.0f))
        {}

        C_Transform(const glm::vec3 position, const glm::vec3 rotation, const glm::vec3 scale) :
            position(position),
            rotation(rotation),
            scale(scale)
        {}
    };
}


namespace meta
{
    using mtengine::C_Transform;
     
    template<>
    inline auto registerMembers<C_Transform>()
    {
	return members(member("position", &C_Transform::position),
		       member("rotation", &C_Transform::rotation),
		       member("scale", &C_Transform::scale));
    }
}
    
    
