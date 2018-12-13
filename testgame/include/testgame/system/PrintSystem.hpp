#pragma once

#include <mtengine/system/System.hpp>
#include <mtengine/component/C_Input.hpp>

namespace testgame
{
    class PrintSystem : public mtengine::System
    {
        private:
            mtecs::Group* group;

        public:
	    PrintSystem(unsigned int id) : System(id)
            {

            }

            void initialize()
            {
                events->subscribe<PrintSystem, &PrintSystem::onPrintCommand>(this, "empty_command");
                group = groups->getGroup<mtengine::C_Input>();
            }

            void update(float deltaTime)
            {
                mtecs::ComponentHandle<mtengine::C_Input> cInput;
              
                for (mtecs::Entity* entity : group->getEntities<mtengine::C_Input>(cInput))
                {
                    //std::cout << cInput->context << std::endl;
                }
            }

            void onPrintCommand(utility::Message message)
            {
                std::cout << "received empty command with intensity of " << message.getInt("intensity") << "." << std::endl;
                graphics->getWindow(0)->setWindowShouldClose(true);
            }
    };
}
