#include "testgame/factory/SystemRegister.hpp"
#include "testgame/system/PrintSystem.hpp"

#include <mtengine/engine/Engine.hpp>
#include <mtengine/component/C_Model.hpp>
#include <mtengine/resource/AssetManager.hpp>
#include <mtengine/component/C_FirstPersonMovement.hpp>
#include <mtengine/system/S_FirstPersonMovement.hpp>

#include <iostream>

using namespace testgame;
using namespace mtengine;
using namespace mtecs;
using namespace mtgraphics;
using namespace utility;

mtengine::Engine engine;
mtgraphics::Graphics* graphics;
MessageQueue* events;
ComponentRegistry* registry;
World* world;
EntityManager* em;

mtengine::KeyInput forwardKey = mtengine::KeyInput(0, GLFW_KEY_W, 0, GLFW_PRESS, 0);
mtengine::KeyInput backwardKey = mtengine::KeyInput(0, GLFW_KEY_S, 0, GLFW_PRESS, 0);
mtengine::KeyInput rightwardKey = mtengine::KeyInput(0, GLFW_KEY_D, 0, GLFW_PRESS, 0);
mtengine::KeyInput leftwardKey = mtengine::KeyInput(0, GLFW_KEY_A, 0, GLFW_PRESS, 0);

void sendInputMappingModifiedMessage(const mtengine::KeyInput setting, const std::string& contextName, const std::string& eventName)
{
    Message message = Message("input_mapping_modified");
    message.addArgument("new_mapping", setting.toString());
    message.addArgument("new_event", eventName);
    message.addArgument("input_type", std::string("key_input"));
    message.addArgument("context_name", contextName);
    events->send(message);
    
}

void initializePlayer()
{
    Entity* entity = em->createEntity("player");
    auto cInput = entity->addComponent<C_Input>();
    auto cTransform = entity->addComponent<C_Transform>();
    cTransform->position = glm::vec3(0.0f, 0.0f, -5.0f);
    
    cInput->context = std::string("playing");
    cInput->keyInputMapping[forwardKey].push_back("move_forward");
    cInput->keyInputMapping[backwardKey].push_back("move_backward");
    cInput->keyInputMapping[rightwardKey].push_back("move_rightward");
    cInput->keyInputMapping[leftwardKey].push_back("move_leftward");

    sendInputMappingModifiedMessage(forwardKey, cInput->context, std::string("move_forward"));
    sendInputMappingModifiedMessage(backwardKey, cInput->context, std::string("move_backward"));
    sendInputMappingModifiedMessage(rightwardKey, cInput->context, std::string("move_rightward"));
    sendInputMappingModifiedMessage(leftwardKey, cInput->context, std::string("move_leftward"));

    auto cMovement = entity->addComponent<C_FirstPersonMovement>();
    cMovement->speed = 0.5f;
  
    auto cCamera = entity->addComponent<C_Camera>();
    cCamera->fov = 90.0f;
    cCamera->window = 0;
}


int main()
{
    graphics = engine.getGraphics();
    events = engine.getWorld()->getMessageQueue();
    registry = engine.getWorld()->getComponentRegistry();
    world = engine.getWorld();
    em = world->getEntityManager();

    engine.initialize();

 
    world->addSystem(new S_FirstPersonCamera(2));
 
    world->addSystem(new S_FirstPersonMovement(3));

    initializePlayer();
    
    Entity* entity = em->createEntity("bunny");
    auto cModel = entity->addComponent<C_Model>();
    std::string aStr = "/home/gabriel/Documents/projects/game-engine/mtengine/data/bunny.obj";
    cModel->name = "/home/gabriel/Documents/projects/game-engine/mtengine/data/bunny.obj";

    utility::Message message = utility::Message("model_modified");
    message.addArgument("entity_id", entity->getId());
    events->send(message);
    
    mtgraphics::Window* window = graphics->getWindow(0);
    graphics->setBufferMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    std::cout << "CTransform mask: " << registry->getMask<C_Transform>().getMask() << std::endl;
    std::cout << "CCamera mask: " << registry->getMask<C_Camera>().getMask() << std::endl;
    std::cout << "CFirstPersonMovement mask: " << registry->getMask<C_FirstPersonMovement>().getMask() << std::endl;

    
    /*
    while(!window->shouldClose())
    {
        engine.update();
    }
    */
    
   return 0;
}
   
