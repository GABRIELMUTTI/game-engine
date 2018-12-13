#include "mtengine/system/S_FirstPersonCamera.hpp"

namespace mtengine
{
    S_FirstPersonCamera::S_FirstPersonCamera(unsigned int id) :
        System(id),
        pitch(0.0f),
        yaw(0.0f),
        roll(0.0f)
    {
        
    }

    void S_FirstPersonCamera::onCCameraAdded(utility::Message message)
    {
        mtecs::Mask componentMask = mtecs::Mask(message.getInt("component_mask"));

        if (componentMask == registry->getMask<C_Camera>())
        {
            mtecs::Entity* entity = entities->getEntity(message.getUnsignedInt("entity_id"));
            mtecs::ComponentHandle<C_Camera> cCamera = entity->getComponent<C_Camera>();

	    auto cTransform = entity->getComponent<C_Transform>();
	    
            mtgraphics::Window* cameraWindow = graphics->getWindow(cCamera->window);
            camera = new mtgraphics::Camera(cameraWindow->getWidth(), cameraWindow->getHeight(), 45);
            camera->transform = mtgraphics::Transform(cTransform->position, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
            graphics->setCamera(camera);
        }
    }

    void S_FirstPersonCamera::onPointerMoved(utility::Message message)
    {
        mtgraphics::Input* windowInput = graphics->getWindow(0)->getInput();

        glm::vec2 cursorDelta = windowInput->getDeltaCursor();

        yaw += cursorDelta.x;
        pitch += cursorDelta.y;

        if (pitch >= 90.0f)
        {
            pitch = 90.0f;
        }
        else if (pitch <= -90.0f)
        {
            pitch = -90.0f;
        }

        glm::vec3 cameraView = glm::vec3();
        cameraView.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        cameraView.y = sin(glm::radians(pitch));
        cameraView.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

        camera->setView(cameraView);        
    }

    void S_FirstPersonCamera::initialize()
    {   
        events->subscribe<S_FirstPersonCamera, &S_FirstPersonCamera::onCCameraAdded>(this, "component_added");
        events->subscribe<S_FirstPersonCamera, &S_FirstPersonCamera::onPointerMoved>(this, "on_pointer_moved");

        group = groups->getGroup<C_Transform, C_Camera>(); 
    }

    void S_FirstPersonCamera::update(float deltaTime)
    {
        if (camera != nullptr)
        {
            ComponentHandle<C_Transform> cTransform;
            for (Entity* entity : group->getEntities<C_Transform>(cTransform))
	    {	    
		camera->transform.translation = cTransform->position;
		camera->updateViewMatrix();
            }
        }
    }
}
