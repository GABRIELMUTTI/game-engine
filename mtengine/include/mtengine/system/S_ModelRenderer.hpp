#pragma once

#include "mtengine/system/System.hpp"
#include "mtengine/component/C_Model.hpp"

#include <mtgraphics/graphic/Model.hpp>
#include <mtgraphics/graphic/ModelRenderer.hpp>

namespace mtengine
{
    class S_ModelRenderer : public System
    {
        private:
            mtgraphics::ModelRenderer* modelRenderer;

        private:
            void onCModelAdded(utility::Message message);
            void onCModelChanged(utility::Message message);

        public:
            S_ModelRenderer(unsigned int id);

            void initialize();
            void update(float deltaTime);

            void loadModel(mtecs::Entity* entity);
    };
}
