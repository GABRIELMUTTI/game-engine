#pragma once

#include "../delegate/Delegate.hpp"

#include <vector>
#include <algorithm>

namespace utility
{
    template<class T>
    class Event
    {
        typedef void(*FunctionPtr)(T);

        private:
            unsigned int numDelegates;
            std::vector<Delegate<T>> delegates;

        public:
            Event() :
                numDelegates(0)
            { 

            }

            void add(Delegate<T> delegate)
            {
                delegates.push_back(delegate);
                numDelegates++;
            }

            void remove(Delegate<T> delegate)
            {
                delegates.erase(std::remove(delegates.begin(), delegates.end(), delegate), delegates.end());
                numDelegates--;
            }
            
            void invoke(T arg)
            {
                for (uint i = 0; i < numDelegates; i++)
                {
                    delegates[i].invoke(arg);
                }
            }

            template<class Class, void(Class::*Function)(T)>
            void add(Class* instance)
            {
                Delegate<T> delegate;
                delegate.template bind<Class, Function>(instance);

                delegates.push_back(delegate);
                numDelegates++;
            }

            template<void(*Function)(T)>
            void add()
            {
                Delegate<T> delegate;
                delegate.template bind<Function>();

                delegates.push_back(delegate);
                numDelegates++;
            }
    };
}


/*


template<class T>
class Test
{

}

for (Component* component : components)
{
    
}

*/
