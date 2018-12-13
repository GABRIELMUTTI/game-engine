#pragma once

#include "../../eventqueue/event/IEventQueue.hpp"
#include "../../eventqueue/event/EventArgs.hpp"
#include "../../delegate/Event.hpp"

#include <vector>

namespace utility
{
    template<class EventType>
    class EventQueue : public IEventQueue
    {
        private:
            Event<EventType> event;
            std::vector<EventType*> eventsQueued;

        public:
            void flush()
            {
                for (int i = 0; i < eventsQueued.size(); i++)
                {
                    event.invoke(*eventsQueued[i]);
                }
                
                eventsQueued.clear();
            }
            
            void send(EventArgs* event)
            {
                eventsQueued.push_back(static_cast<EventType*>(event));
            }

            void subscribe(Delegate<EventType> delegate)
            {
                event.add(delegate);
            }

            void unsubscribe(Delegate<EventType> delegate)
            {
                event.remove(delegate);
            }
    };
}
