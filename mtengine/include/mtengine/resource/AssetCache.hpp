#pragma once

#include "mtengine/resource/BaseAsset.hpp"
#include "mtengine/resource/Asset.hpp"

#include <map>

namespace mtengine
{
    class AssetCache
    {
        private:
            std::map<std::string, BaseAsset*> assets;

        public:
            template<class T>
            Asset<T>* get(const std::string& assetName)
            {
                auto it = assets.find(assetName);
                if (it != assets.end())
                {
                    return static_cast<Asset<T>*>(it->second);
                }

                return nullptr;
            }

            void add(BaseAsset& asset)
            {
                assets[asset.getFilepath()] = &asset;
            }

            void remove(BaseAsset& asset)
            {
                auto it = assets.find(asset.getFilepath());
                if (it != assets.end())
                {
                    assets.erase(it);
                }
            }
    };
}
