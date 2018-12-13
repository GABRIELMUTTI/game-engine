#include "mtgraphics/graphic/IRenderer.hpp"

namespace mtgraphics
{
    void IRenderer::setCamera(Camera* camera)
    {
        this->camera = camera;
    }

    void IRenderer::setShaderProgram(ShaderProgram* shaderProgram)
    {
        this->shaderProgram = shaderProgram;
    }
}