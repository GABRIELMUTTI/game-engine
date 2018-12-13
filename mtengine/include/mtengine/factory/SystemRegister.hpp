#include "mtengine/factory/IRegister.hpp"
#include "mtengine/system/S_FirstPersonCamera.hpp"
#include "mtengine/system/S_FirstPersonMovement.hpp"
#include "mtengine/system/S_Input.hpp"
#include "mtengine/system/S_ModelRenderer.hpp"
        namespace mtengine
        {
            class SystemRegister : public IRegister<System, int>
            {
                public:
                    SystemRegister()
                    {

                    }

                    void registerTypes(Factory<System, int>* factory)
                    {
factory->registerType<S_FirstPersonCamera>("S_FirstPersonCamera");
factory->registerType<S_FirstPersonMovement>("S_FirstPersonMovement");
factory->registerType<S_Input>("S_Input");
factory->registerType<S_ModelRenderer>("S_ModelRenderer");
}};}