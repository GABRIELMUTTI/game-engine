#include "mtengine/engine/Engine.hpp"

namespace mtengine
{
    Engine::Engine() :
        componentRegister(nullptr),
        systemRegister(nullptr),
	componentFactory(Factory<mtecs::Component>(componentUIDs))
	system(Factory<mtecs::Component>(systemUIDs))
    {

    }

    void Engine::initialize()
    {
	// Register components.
	
	
        // Register library's types.
        ComponentRegister* libraryComponentRegister = new ComponentRegister(componentUIDs);
        libraryComponentRegister->registerTypes(componentFactory);

        SystemRegister* librarySystemRegister = new SystemRegister(systemUIDs);
        librarySystemRegister->registerTypes(systemFactory);

        // Register user types.
        if (componentRegister != nullptr)
        {
            componentRegister->registerTypes(&componentFactory);
        }

        if (systemRegister != nullptr)
        {
            systemRegister->registerTypes(&systemFactory);
        }
        
        // Initialize asset manager.
        ModelLoader* modelLoader = new ModelLoader();
        assetManager.addResourceLoader<mtgraphics::Model>(*modelLoader);
    	
        // Initialize window.
        mtgraphics::Window* window = new mtgraphics::Window(0, 800, 600, "mtgraphics::Window");
        window->makeWindowContextCurrent();
        graphics.addWindow(window);

	// Subscribe to "system_added" event.
	utility::MessageQueue* messageQueue = world.getMessageQueue();
	messageQueue->subscribe<Engine, &Engine::onSystemAdded>(this, "system_added");
	
	

        // Initialize world;        
        world.addSystem(systemFactory.create("S_Input", 0));
        world.addSystem(systemFactory.create("S_ModelRenderer", 1));

	world.initialize();
    }

    void Engine::update()
    {
        world.update(1.0f);
        graphics.render();
    }
    
    void Engine::onSystemAdded(Message message)
    {
	unsigned int systemId = message.getUnsignedInt("system_id");
	System* system = static_cast<System*>(world.getSystem(systemId));

	system->setGraphics(&graphics);
	system->setAssetManager(&assetManager);
    }
    
    mtgraphics::Graphics* Engine::getGraphics()
    {
        return &graphics;
    }

    mtecs::World* Engine::getWorld()
    {
        return &world;
    }

    AssetManager* Engine::getAssetManager()
    {
        return &assetManager;
    }

    void Engine::setComponentRegister(IRegister<mtecs::Component>* componentRegister)
    {
        this->componentRegister = componentRegister;
    }

    void Engine::setSystemRegister(IRegister<System, int>* systemRegister)
    {
        this->systemRegister = systemRegister;
    }
}
