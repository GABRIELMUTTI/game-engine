#pragma once

#include "mtgraphics/graphic/Mesh.hpp"
#include "mtgraphics/graphic/Transform.hpp"
#include "mtgraphics/graphic/Texture.hpp"

#include <vector>

namespace mtgraphics
{
    struct Model
    {
        GLuint id;
        Transform transform;
        std::vector<Mesh> meshes;
        std::vector<Texture> textures;
    
        Model()
        {}

        Model(GLuint id, Transform transform, std::vector<Mesh> meshes, std::vector<Texture> textures) :
            id(id),
            transform(transform),
            meshes(meshes),
            textures(textures)
        {}
    
        bool operator==(const Model& other)
        {
            return id == other.id;
        }
    };
}