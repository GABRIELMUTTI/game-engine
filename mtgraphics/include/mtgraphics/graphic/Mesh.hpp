#pragma once

#include "mtgraphics/engine/GLInclude.hpp"
#include "mtgraphics/graphic/Vertex.hpp"

#include <vector>

namespace mtgraphics
{
    struct Mesh
    {
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;

        GLuint vbo;
        GLuint vao;
        GLuint ebo;

        const GLchar* file;
    };
}