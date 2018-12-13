#pragma once

#include "mtengine/resource/BaseAsset.hpp"

namespace mtengine
{
    class IAssetLoader
    {
        public:
            virtual BaseAsset* load(const std::string& filepath) = 0;
    };
}
