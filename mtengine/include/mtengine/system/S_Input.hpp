#pragma once

#include "mtengine/system/System.hpp"
#include "mtengine/input/InputContext.hpp"
#include "mtengine/component/C_Input.hpp"
#include "mtengine/factory/Factory.hpp"
#include "mtengine/input/KeyInput.hpp"
#include "mtengine/input/PointerInput.hpp"

#include <mtgraphics/input/Input.hpp>

#include <utility/eventqueue/message/MessageQueue.hpp>

#include <vector>
#include <algorithm>

namespace mtengine
{
    class S_Input : public System
    {
        private:
            std::vector<InputContext*> contexts;

	    void onKeyEvent(const mtgraphics::KeyInput keyInput);
            void onPointerInput(const mtgraphics::PointerInput pointerInput);

            void onCInputAdded(Message message);
            void onInputMappingModified(Message message);

        public:
            S_Input(unsigned int id);

            void initialize();
            void update(float deltaTime);

            void addContext(InputContext* context);
            void removeContext(InputContext* context);
    };
}
