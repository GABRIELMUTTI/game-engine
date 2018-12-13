#pragma once

#include "mtengine/input/KeyInput.hpp"

#include <mtecs/component/Component.hpp>

#include <unordered_map>
#include <vector>
#include <string>

namespace mtengine
{
    struct C_Input : public mtecs::Component
    {
        std::string context;
        std::unordered_map<KeyInput, std::vector<std::string>> keyInputMapping;
        std::vector<std::string> pointerMapping;

        C_Input()
        {

        }
    };
}
