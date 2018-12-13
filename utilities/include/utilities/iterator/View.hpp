#pragma once

namespace utility
{
    template<class Collection, class Iterator>
    class View
    {
        public:
            Iterator begin()
            {
                return static_cast<Derived*>(this)->begin();
            }

            Iterator end()
            {
                return static_cast<Derived*>(this)->end();
            }
    };
}
