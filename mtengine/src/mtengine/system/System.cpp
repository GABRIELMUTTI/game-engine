#include "mtengine/system/System.hpp"

namespace mtengine
{
    System::System(unsigned int id) :
        mtecs::System(id)
    {

    }
  
    void System::setGraphics(mtgraphics::Graphics* graphics)
    {
        this->graphics = graphics;
    }

    void System::setAssetManager(AssetManager* assetManager)
    {
        this->assets = assetManager;
    }
}
