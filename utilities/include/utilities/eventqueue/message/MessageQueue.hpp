#pragma once

#include "Message.hpp"
#include "../../delegate/Event.hpp"

#include <queue>
#include <string>

namespace utility
{
    class MessageQueue
    {
        private:
            std::queue<Message> queue;
            std::unordered_map<std::string, Event<Message>> delegates;

        public:
            MessageQueue()
            {
                
            }
            
            void flush()
            {
                while (!queue.empty())
                {
                    Message message = queue.front();
                    auto it = delegates.find(message.getType());
                    if (it != delegates.end())
                    {
                        it->second.invoke(message);
                    }

                    queue.pop();
                }
            }

            void send(const Message& message)
            {
                queue.push(message);
            }

            void subscribe(const char* eventType, Delegate<Message> delegate)
            {
                auto it = delegates.find(eventType);
                if (it != delegates.end())
                {
                    it->second.add(delegate);
                }
                else
                {
                    Event<Message> event;
                    event.add(delegate);
                    delegates[eventType] = event;
                }
            }

            template<class Class, void(Class::*Function)(Message)>
            void subscribe(Class* instance, const char* eventType)
            {
                auto it = delegates.find(eventType);
                if (it != delegates.end())
                {
                    it->second.template add<Class, Function>(instance);
                }
                else
                {
                    Event<Message> event;
                    event.template add<Class, Function>(instance);
                    delegates[eventType] = event;
                }
            }

    };
}
