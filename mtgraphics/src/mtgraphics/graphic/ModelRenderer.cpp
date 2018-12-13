#include "mtgraphics/graphic/ModelRenderer.hpp"

namespace mtgraphics
{
    ModelRenderer::ModelRenderer()
    {
        camera = nullptr;
    }

    void ModelRenderer::addModel(Model* model)
    {
        loadMeshes(model);
        models.push_back(model);
    }

    void ModelRenderer::removeModel(Model* model)
    {
        models.erase(std::remove(models.begin(), models.end(), model), models.end());
    }
    
    void ModelRenderer::render()
    {
        if (camera == nullptr)
        {
            return;
        }

        shaderProgram->use();
        glm::mat4 modelMatrix;

        shaderProgram->setMat4("view", camera->getViewMatrix());
        shaderProgram->setMat4("projection", camera->getProjectionMatrix());

        for (int i = 0; i < models.size(); i++)
        {
            Model* model = models[i];
            glBindVertexArray(model->meshes[0].vao);

            modelMatrix = glm::mat4(1.0f);

            // Translate.
            modelMatrix = glm::translate(modelMatrix, model->transform.translation);

            // Rotate.
            modelMatrix = glm::rotate(modelMatrix, model->transform.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
            modelMatrix = glm::rotate(modelMatrix, model->transform.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
            modelMatrix = glm::rotate(modelMatrix, model->transform.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

            // Scale.
            modelMatrix = glm::scale(modelMatrix, model->transform.scale);

            shaderProgram->setMat4("model", modelMatrix);

            glDrawElements(GL_TRIANGLES, model->meshes[0].indices.size(), GL_UNSIGNED_INT, &model->meshes[0].indices[0]);
        }
    }

    void ModelRenderer::loadMeshes(Model* model)
    {
        for (int i = 0; i < model->meshes.size(); i++)
        {
            Mesh* mesh = &(model->meshes[0]);
            GLuint vao, vbo, ebo;

            // Generate buffers.
            glGenVertexArrays(1, &vao);
            glGenBuffers(1, &vbo);
            glGenBuffers(1, &ebo);

            // Bind buffers.
            glBindVertexArray(vao);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
            std::cout << mesh->vertices.size() << std::endl;
            // Send data to buffers.
            glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * sizeof(Vertex), &mesh->vertices[0], GL_STATIC_DRAW);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->indices.size() * sizeof(GLuint) * 3, &mesh->indices[0], GL_STATIC_DRAW);

            // Set attribute pointers.
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

            // Enable attribute pointers.
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glEnableVertexAttribArray(2);

            // Unbind buffers.
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindVertexArray(0);

            mesh->vao = vao;
            mesh->vbo= vbo;
            mesh->ebo = ebo;
        }
    }

    void ModelRenderer::setShaderProgram(ShaderProgram* shaderProgram)
    {
        this->shaderProgram = shaderProgram;
    }

    void ModelRenderer::setCamera(Camera* camera)
    {
        this->camera = camera;
    }
}


