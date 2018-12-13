#pragma once

#include "mtengine/resource/IAssetLoader.hpp"
#include "mtengine/resource/Asset.hpp"
#include "mtengine/resource/BaseAsset.hpp"

#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include <mtgraphics/graphic/Mesh.hpp>
#include <mtgraphics/graphic/Model.hpp>

#include <iostream>


namespace mtengine
{
    class ModelLoader : public IAssetLoader
    {
    private:
	void processNode(mtgraphics::Model* model, aiNode* node, const aiScene* scene);
	mtgraphics::Mesh convertMesh(const aiScene* scene, aiMesh* mesh);

    public:
	ModelLoader();

	BaseAsset* load(const std::string& filepath);

    };
}
