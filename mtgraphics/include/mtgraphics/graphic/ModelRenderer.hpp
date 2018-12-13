#pragma once

#include "mtgraphics/graphic/IRenderer.hpp"
#include "mtgraphics/graphic/Model.hpp"
#include "mtgraphics/graphic/ShaderProgram.hpp"
#include "mtgraphics/graphic/Camera.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include <algorithm>

namespace mtgraphics
{
    class ModelRenderer : public IRenderer
    {
    private:
	std::vector<Model*> models;
	ShaderProgram* shaderProgram;

	void loadMeshes(Model* model);

    public:
	ModelRenderer();

	void addModel(Model* model);
	void removeModel(Model* model);

	void render();
	void setShaderProgram(ShaderProgram* shaderProgram);
	void setCamera(Camera* camera);
    };
}
