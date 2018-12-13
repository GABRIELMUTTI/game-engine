#pragma once

#include "mtengine/factory/Factory.hpp"
#include "mtengine/resource/AssetManager.hpp"

#include <mtecs/system/System.hpp>

#include <mtgraphics/engine/Graphics.hpp>

using namespace mtecs;

namespace mtengine
{
    class System : public mtecs::System
    {
        protected:
            mtgraphics::Graphics* graphics;
            AssetManager* assets;

        public:
            System(unsigned int id);
            void setGraphics(mtgraphics::Graphics* graphics);
            void setAssetManager(AssetManager* assetManager);
    };
}
