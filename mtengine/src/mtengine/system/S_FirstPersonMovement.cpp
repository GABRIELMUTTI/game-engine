#include "mtengine/system/S_FirstPersonMovement.hpp"

namespace mtengine
{
    S_FirstPersonMovement::S_FirstPersonMovement(unsigned int id) :
        System(id)
    {

    }

    void S_FirstPersonMovement::initialize()
    {
        events->subscribe<S_FirstPersonMovement, &S_FirstPersonMovement::onCCameraAdded>(this, "component_added");
    }
    
    void S_FirstPersonMovement::update(float deltaTime)
    {

    }

    void S_FirstPersonMovement::onCCameraAdded(Message message)
    {
        Mask mask = Mask(message.getUnsignedInt("component_mask"));
        if (mask == registry->getMask<C_Camera>())
        {
            camera = graphics->getCamera();
            events->subscribe<S_FirstPersonMovement, &S_FirstPersonMovement::onForwardCommand>(this, "move_forward");
            events->subscribe<S_FirstPersonMovement, &S_FirstPersonMovement::onBackwardCommand>(this, "move_backward");
            events->subscribe<S_FirstPersonMovement, &S_FirstPersonMovement::onRightwardCommand>(this, "move_rightward");
            events->subscribe<S_FirstPersonMovement, &S_FirstPersonMovement::onLeftwardCommand>(this, "move_leftward");
        }
    }

    void S_FirstPersonMovement::onForwardCommand(Message message)
    {
        Entity* entity = entities->getEntity(0);
	auto cViewMovement = entity->getComponent<C_FirstPersonMovement>();
        auto cTransform = entity->getComponent<C_Transform>();

        cTransform->position += camera->getView() * cViewMovement->speed;
    }

    void S_FirstPersonMovement::onBackwardCommand(Message message)
    {
        Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
        auto cTransform = entity->getComponent<C_Transform>();

        cTransform->position -= camera->getView() * 0.5f;
    }

    void S_FirstPersonMovement::onRightwardCommand(Message message)
    {
        Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
        auto cViewMovement = entity->getComponent<C_FirstPersonMovement>();
        auto cTransform = entity->getComponent<C_Transform>();

        glm::vec3 rightVector = glm::cross(camera->getView(), camera->getUpVector());
        cTransform->position += rightVector * cViewMovement->speed;
    }


    void S_FirstPersonMovement::onLeftwardCommand(Message message)
    {
        Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
        auto cViewMovement = entity->getComponent<C_FirstPersonMovement>();
        auto cTransform = entity->getComponent<C_Transform>();
	
        glm::vec3 rightVector = glm::cross(camera->getView(), camera->getUpVector());
        cTransform->position -= rightVector * cViewMovement->speed;
    }
}
