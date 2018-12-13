#pragma once

#include "../delegate/Event.hpp"

namespace utility
{
    template<class EventType>
    class EventProperty
    {
        private:
            Event<EventType>& myEvent;
        
        public:
            
            EventProperty(Event<EventType>& event) : 
                myEvent(event) 
            {

            }

            void add(Delegate<EventType> delegate)
            {
                myEvent.add(delegate);
            }

            template<class Class, void(Class::*Function)(EventType)>
            void add(Class* instance)
            {
                Delegate<EventType> delegate;
                delegate.template bind<Class, Function>(instance);
                myEvent.add(delegate);
            }

            template<void(*Function)(EventType)>
            void add()
            {
                myEvent.template add<Function>();
            }

            void remove(Delegate<EventType> delegate)
            {
                myEvent.remove(delegate);
            }

            template<class Class, void(Class::*Function)(EventType)>
            void remove(Class* instance)
            {
                Delegate<EventType> delegate;
                delegate.template bind<Class, Function>(instance);
                myEvent.template remove(delegate);
            }

            template<void(*Function)(EventType)>
            void remove()
            {
                myEvent.template remove<Function>();
            }
    };
}

