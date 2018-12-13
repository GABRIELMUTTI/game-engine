#pragma once

#include "../observer/IListener.hpp"

#include <algorithm>

namespace utility
{
    template<class T>
    class Subject
    {
        private:
            std::vector<IListener<T>*> listeners;

        public:
            void fireEvent(T* message)
            {
                for (int i = 0; i < listeners.size(); i++)
                {
                    listeners[i]->receive(message);
                }
            }

            void observe(IListener<T>* listener)
            {
                listeners.push_back(listener);
            }

            
            void unobserve(IListener<T>* listener)
            {
                listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
            }
    };
}
