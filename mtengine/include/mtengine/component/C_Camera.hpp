#pragma once

#include <mtecs/component/Component.hpp>

#include <glm/glm.hpp>

namespace mtengine
{
    struct C_Camera : public mtecs::Component
    {
        unsigned int window;
        unsigned int fov;
        glm::vec3 speed;
        glm::vec3 view;

        C_Camera() :
            window(0),
            fov(90),
            speed(glm::vec3(0.0f, 0.0f, 0.0f)),
            view(glm::vec3(0.0f, 0.0f, 0.0f))
        {
            
        }
    };
}