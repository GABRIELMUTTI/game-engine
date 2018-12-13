#include "mtengine/factory/IRegister.hpp"
#include "mtengine/component/C_Transform.hpp"
#include "mtengine/component/C_Input.hpp"
#include "mtengine/component/C_FirstPersonMovement.hpp"
#include "mtengine/component/C_Camera.hpp"
        namespace mtengine
        {
            class ComponentRegister : public IRegister<Component>
            {
                public:
                    ComponentRegister()
                    {

                    }

                    void registerTypes(Factory<Component>* factory)
                    {
factory->registerType<C_Transform>("C_Transform");
factory->registerType<C_Input>("C_Input");
factory->registerType<C_FirstPersonMovement>("C_FirstPersonMovement");
factory->registerType<C_Camera>("C_Camera");
}};}