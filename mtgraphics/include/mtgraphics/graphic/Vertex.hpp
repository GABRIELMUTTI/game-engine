#pragma once

#include "glm/glm.hpp"

namespace mtgraphics
{
    struct Vertex
    {
        Vertex()
        {}
        
        Vertex(glm::vec3 position, glm::vec3 normal, glm::vec2 uv) :
            position(position),
            normal(normal),
            uv(uv)
        {}

        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 uv;
    };
}