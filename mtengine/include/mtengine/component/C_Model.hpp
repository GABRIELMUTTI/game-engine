#pragma once

#include <mtecs/component/Component.hpp>

#include <string>

namespace mtengine
{
    class C_Model : public mtecs::Component
    {
        public:
            std::string name;

            C_Model() :
                name("")
            {}

            C_Model(const std::string& name) :
                name(name)
            {}
    };
}