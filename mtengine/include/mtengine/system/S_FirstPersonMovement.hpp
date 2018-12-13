#pragma once

#include "mtengine/system/System.hpp"
#include "mtengine/component/C_FirstPersonMovement.hpp"
#include "mtengine/component/C_Transform.hpp"
#include "mtengine/component/C_Camera.hpp"

namespace mtengine
{
    class S_FirstPersonMovement : public System
    {
        private:
            mtgraphics::Camera* camera;

            void onCCameraAdded(Message message);
            void onForwardCommand(Message message);
            void onBackwardCommand(Message message);
            void onRightwardCommand(Message message);
            void onLeftwardCommand(Message message);

        public:
            S_FirstPersonMovement(unsigned int id);

            void initialize();
            void update(float deltaTime);
    };
}
