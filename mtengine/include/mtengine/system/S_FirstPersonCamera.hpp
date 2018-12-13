#pragma once

#include "mtengine/system/System.hpp"
#include "mtengine/component/C_Camera.hpp"
#include "mtengine/component/C_Transform.hpp"
#include "mtengine/component/C_Input.hpp"

#include <mtgraphics/graphic/Camera.hpp>


namespace mtengine
{
    class S_FirstPersonCamera : public System
    {
        private:
            mtgraphics::Camera* camera;
            mtecs::Group* group;
            mtecs::Mask cTransformMask;

            float pitch;
            float yaw;
            float roll;

        private:
            void onCCameraAdded(utility::Message message);
            void onPointerMoved(utility::Message message);

        public:

            S_FirstPersonCamera(unsigned int id);

            void update(float deltaTime);
            void initialize();
    };
}
