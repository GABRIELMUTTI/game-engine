#pragma once

#include <mtecs/component/Component.hpp>

namespace mtengine
{
    class C_FirstPersonMovement : public mtecs::Component
    {
        public:
            float speed;

            C_FirstPersonMovement() :
                speed(0.0f)
            {

            }
    };
}
