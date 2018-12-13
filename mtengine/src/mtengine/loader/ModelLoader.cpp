#include "mtengine/loader/ModelLoader.hpp"

namespace mtengine
{
    ModelLoader::ModelLoader()
    {

    }

    BaseAsset* ModelLoader::load(const std::string& filepath)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(filepath, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenSmoothNormals);

        if (scene == nullptr || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mRootNode == nullptr)
        {
            std::cout << "Error::Assimp:: " << importer.GetErrorString() << std::endl;
            return nullptr;
        }

        mtgraphics::Model* model = new mtgraphics::Model();
        processNode(model, scene->mRootNode, scene);


        return new Asset<mtgraphics::Model>(filepath, model);
    }

    void ModelLoader::processNode(mtgraphics::Model* model, aiNode* node, const aiScene* scene)
    {
        for (int i = 0; i < node->mNumMeshes; i++)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            model->meshes.push_back(convertMesh(scene, mesh));
        }

        for (int i = 0; i < node->mNumChildren; i++)
        {
            processNode(model, node->mChildren[i], scene);
        }
    }

    mtgraphics::Mesh ModelLoader::convertMesh(const aiScene* scene, aiMesh* mesh)
    {
        mtgraphics::Mesh convertedMesh;

        // Convert vertices.
        for (int i = 0; i < mesh->mNumVertices; i++)
        {
            mtgraphics::Vertex vertex = mtgraphics::Vertex();
            vertex.position.x = mesh->mVertices[i].x;
            vertex.position.y = mesh->mVertices[i].y;
            vertex.position.z = mesh->mVertices[i].z;

            if (mesh->HasNormals())
            {
                vertex.normal.x = mesh->mNormals[i].x;
                vertex.normal.y = mesh->mNormals[i].y;
                vertex.normal.z = mesh->mNormals[i].z;
            }

            convertedMesh.vertices.push_back(vertex);
        }

        // Convert faces/indices.
        for (int i = 0; i < mesh->mNumFaces; i++)
        {
            for (int j = 0; j < mesh->mFaces[i].mNumIndices; j++)
            {
                convertedMesh.indices.push_back(mesh->mFaces[i].mIndices[j]);
            }
        }

        return convertedMesh;
    }
}
