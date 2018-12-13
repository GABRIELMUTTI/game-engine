#pragma once

namespace utility
{
    template<class Derived, typename Type>
    class Iterator
    {
        public:
            bool operator != (const Derived& other)
            {
                return *static_cast<Derived*>(this) != other;
            }

            Type operator * ()
            {
                return *static_cast<Derived*>(this);
            }

            void operator ++ ()
            {
                return static_cast<Derived*>(this)++; 
            }
    };
}
