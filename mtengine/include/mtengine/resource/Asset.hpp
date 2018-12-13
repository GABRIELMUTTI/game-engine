#pragma once

#include "mtengine/resource/BaseAsset.hpp"

namespace mtengine
{
    template<class T>
    class Asset : public BaseAsset
    {
        private:
            T* resource;

        public:
            Asset(const std::string& filepath, T* resource) :
                BaseAsset(filepath),
                resource(resource)
            {}

            T* getResource()
            {
                return resource;
            }
    };
}
