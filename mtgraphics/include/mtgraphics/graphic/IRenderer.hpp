#pragma once

#include "mtgraphics/graphic/Camera.hpp"
#include "mtgraphics/graphic/ShaderProgram.hpp"

namespace mtgraphics
{
    class IRenderer
    {
    protected:
	Camera* camera;
	ShaderProgram* shaderProgram;

    public:
	virtual void render() = 0;

	void setCamera(Camera* camera);
	void setShaderProgram(ShaderProgram* shaderProgram);
    };
}
