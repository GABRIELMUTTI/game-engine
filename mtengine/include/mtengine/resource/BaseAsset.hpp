#pragma once

#include <string>

namespace mtengine
{
    class BaseAsset
    {
        private:
            std::string filepath;

        public:
            BaseAsset(const std::string& filepath) :
                filepath(filepath)
            {}

            const std::string& getFilepath()
            {
                return filepath;
            }
    };
}
