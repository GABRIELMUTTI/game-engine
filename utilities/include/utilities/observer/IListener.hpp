#pragma once

namespace utility
{
    template<class T>
    class IListener
    {
        public:
            virtual void receive(T* message) = 0;
    };
}
