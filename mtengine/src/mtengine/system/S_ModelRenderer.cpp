#include "mtengine/system/S_ModelRenderer.hpp"

namespace mtengine
{
    S_ModelRenderer::S_ModelRenderer(unsigned int id) :
        System(id),
        modelRenderer(nullptr)
    {

    }

    void S_ModelRenderer::initialize()
    {
        modelRenderer = new mtgraphics::ModelRenderer();
        graphics->addRenderer(modelRenderer);

        // Create shader program.
        mtgraphics::ShaderProgram* shaderProgram = new mtgraphics::ShaderProgram();
        shaderProgram->createProgram();
        shaderProgram->loadShader(GL_VERTEX_SHADER, "/home/gabriel/Documents/projects/game-engine/mtengine/shaders/vertex.glsl");
        shaderProgram->loadShader(GL_FRAGMENT_SHADER, "/home/gabriel/Documents/projects/game-engine/mtengine/shaders/fragment.glsl");
        modelRenderer->setShaderProgram(shaderProgram);

        events->subscribe<S_ModelRenderer, &S_ModelRenderer::onCModelAdded>(this, "component_added");
        events->subscribe<S_ModelRenderer, &S_ModelRenderer::onCModelChanged>(this, "model_modified");
    }

    void S_ModelRenderer::update(float deltaTime)
    {
        
    }

    void S_ModelRenderer::loadModel(mtecs::Entity* entity)
    {
        mtecs::ComponentHandle<C_Model> cModel = entity->getComponent<C_Model>();
        mtgraphics::Model* model = assets->loadAsset<mtgraphics::Model>(cModel->name);

        if (model != nullptr)
        {
            modelRenderer->addModel(model);
        }
    }

    void S_ModelRenderer::onCModelAdded(utility::Message message)
    {
        mtecs::Mask modelMask = registry->getMask<C_Model>();
        if (modelMask == mtecs::Mask(message.getInt("component_mask")))
        {
            mtecs::Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
            loadModel(entity);
        }
    }

    void S_ModelRenderer::onCModelChanged(utility::Message message)
    {
        mtecs::Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
        loadModel(entity);
    }
}
