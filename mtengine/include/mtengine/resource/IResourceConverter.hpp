#pragma once

namespace mtengine
{
    template<class TOriginal, class TConverted>
    class IResourceConverter
    {
        public:
            TConverted* convert(const TOriginal& original);
    };
}
