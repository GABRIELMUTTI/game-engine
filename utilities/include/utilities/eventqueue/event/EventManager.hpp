#pragma once

#include "../../eventqueue/event/IEventQueue.hpp"
#include "../../eventqueue/event/EventQueue.hpp"

#include <unordered_map>
#include <vector>
#include <typeindex>

namespace utility
{
    class EventManager
    {
        private:
            std::unordered_map<std::type_index, IEventQueue*> eventQueues;

            template<class EventType>
            EventQueue<EventType>* createEventQueue()
            {
                EventQueue<EventType>* eventQueue = new EventQueue<EventType>();
                eventQueues[typeid(EventType)] = eventQueue;

                return eventQueue;
            }

        public:
            EventManager() {}

            void flush()
            {
                auto begin = eventQueues.begin();
                auto end = eventQueues.end();
                for (auto it = begin; it != end; it++)
                {
                    it->second->flush();
                }
            }

            template<class EventType, class Class, void(Class::*Function)(EventType)>
            void subscribe(Class* instance)
            {
                Delegate<EventType> delegate;
                delegate.template bind<Class, Function>(instance);
                
                auto it = eventQueues.find(typeid(EventType));
                if (it != eventQueues.end())
                {
                    static_cast<EventQueue<EventType>*>(it->second)->subscribe(delegate);
                }
                else
                {
                    createEventQueue<EventType>()->subscribe(delegate);
                }
            }

            void send(EventArgs* event)
            {
                auto it = eventQueues.find(typeid(*event));
                if (it != eventQueues.end())
                {
                    it->second->send(event);
                }
            }
    };
}
