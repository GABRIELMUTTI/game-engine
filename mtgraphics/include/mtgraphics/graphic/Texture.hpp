#pragma once

#include "mtgraphics/engine/GLInclude.hpp"

namespace mtgraphics
{
    class Texture
    {
    private:
	GLuint id;

    public:
	Texture(const GLchar* );

	void load(const GLchar* filepath);
	void use();
    };
}
