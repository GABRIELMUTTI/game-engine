#pragma once

#include "mtengine/factory/IRegister.hpp"
#include "mtengine/factory/Factory.hpp"
#include "mtengine/system/System.hpp"
#include "mtengine/factory/SystemRegister.hpp"
#include "mtengine/factory/ComponentRegister.hpp"
#include "mtengine/loader/ModelLoader.hpp"
#include "mtengine/resource/AssetManager.hpp"
#include "mtengine/identifier/UIDGenerator.hpp"

#include <mtecs/world/World.hpp>
#include <mtecs/component/Component.hpp>

#include <mtgraphics/engine/Graphics.hpp>
#include <mtgraphics/graphic/Window.hpp>
#include <mtgraphics/input/Input.hpp>
#include <mtgraphics/graphic/Model.hpp>

#include <vector>

namespace mtengine
{
    class Engine
    {
    private:
	UIDGenerator componentUIDs;
	UIDGenerator systemUIDs;
	
	IRegister componentRegister;
	IRegister systemRegister;

	Factory<mtecs::Component> componentFactory;
	Factory<System, int> systemFactory;

	mtgraphics::Graphics graphics;
	mtecs::World world;
	AssetManager assetManager;

	void onSystemAdded(Message message);
	
    public:
	Engine();

	void initialize();
	void update();
	    
	mtgraphics::Graphics* getGraphics();
	mtecs::World* getWorld();
	AssetManager* getAssetManager();

	void setComponentRegister(IRegister<mtecs::Component>* componentRegister);
	void setSystemRegister(IRegister<System, int>* systemRegister);
    };
}


