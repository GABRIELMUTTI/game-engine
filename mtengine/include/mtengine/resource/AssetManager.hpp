#pragma once

#include "mtengine/resource/Asset.hpp"
#include "mtengine/resource/AssetCache.hpp"
#include "mtengine/resource/IAssetLoader.hpp"
#include "mtengine/resource/IResourceConverter.hpp"

#include <typeindex>
#include <iostream>

namespace mtengine
{
    class AssetManager
    {
        private:
            AssetCache assetCache;
            std::map<std::type_index, IAssetLoader*> assetLoaders;

        public:
            template<class T>
            T* loadAsset(const std::string& assetName)
            {
                // Try getting asset from the asset cache.
                Asset<T>* asset = assetCache.get<T>(assetName);

                if (asset != nullptr)
                {
                    return asset->getResource();
                }
                else
                {
                    // If not in cache, load from disk.
                    auto it = assetLoaders.find(typeid(T));
                    if (it != assetLoaders.end())
                    {
                        BaseAsset* asset = it->second->load(assetName);
                        
                        if (asset != nullptr)
                        {
                            assetCache.add(*asset);
                            Asset<T>* tAsset = static_cast<Asset<T>*>(asset);
                            return tAsset->getResource();
                        }
                        else
                        {
                            std::cout << "Error::AssetManager::loadAsset: Error loading asset '" << assetName << "'." << std::endl;
                        }
                    }
                }

                return nullptr;
            }

            template<class T>
            void addResourceLoader(IAssetLoader& assetLoader)
            {
                assetLoaders[typeid(T)] = &assetLoader;
            }
    };
}
