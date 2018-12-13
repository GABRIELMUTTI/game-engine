#pragma once

#include <string>

namespace mtengine
{
    class IStateSaver
    {
        public:
            virtual void save(const std::string& filepath);
    };
}