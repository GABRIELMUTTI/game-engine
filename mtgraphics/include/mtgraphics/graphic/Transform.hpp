#pragma once

#include <glm/vec3.hpp>

namespace mtgraphics
{
    struct Transform
    {
        Transform()
        {
            translation = glm::vec3(0.0f, 0.0f, 0.0f);
            rotation = glm::vec3(0.0f, 0.0f, 0.0f);
            scale = glm::vec3(1.0f, 1.0f, 1.0f);
        }

        Transform(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale) :
            translation(translation),
            rotation(rotation),
            scale(scale) {}

        glm::vec3 translation;
        glm::vec3 rotation;
        glm::vec3 scale;
    };
}