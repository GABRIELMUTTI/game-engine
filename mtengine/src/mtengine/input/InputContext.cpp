#include "mtengine/input/InputContext.hpp"

namespace mtengine
{
    InputContext::InputContext(const std::string& name, unsigned int entityId, MessageQueue* messageQueue) :
        name(name),
        messageQueue(messageQueue),
	entityId(entityId)
    {

    }

    InputContext::InputContext(const std::string& name, unsigned int entityId, const KeyInputMap& inputMap, const PointerInputMap& pointerInputMap, MessageQueue* messageQueue) :

        name(name),
        keyInputMapping(inputMap),
        pointerInputMapping(pointerInputMap),
        messageQueue(messageQueue),
	entityId(entityId)
    {

    }

    void InputContext::handleInput(const KeyInput input)
    {
        auto it = keyInputMapping.find(input);
        if (it != keyInputMapping.end())
        {
            for (std::string mappedEvent : it->second)
            {
		//std::cout << "entiyt id: " << entityId << std::endl;
		Message message = Message(mappedEvent);
                message.addArgument("intensity", 1);
		message.addArgument("entity_id", entityId);
		messageQueue->send(message);
            }
        }
    }

    void InputContext::handleInput(const PointerInput input)
    {
        for (std::string mappedEvent : pointerInputMapping)
        {
            Message message = Message(mappedEvent);
            message.addArgument("intensity", 1);
            messageQueue->send(message);
        }
    }

    void InputContext::addKeySetting(const KeyInput keyInput, const std::string& event)
    {
        auto it = keyInputMapping.find(keyInput);
        if (it != keyInputMapping.end())
        {
            it->second.push_back(event);
        }
        else
        {
            std::vector<std::string> events;
            events.push_back(event);
            keyInputMapping[keyInput] = events;
        }
    }

    void InputContext::removeKeySetting(const KeyInput keyInput, const std::string& event)
    {
        auto it = keyInputMapping.find(keyInput);
        if (it != keyInputMapping.end())
        {
            it->second.erase(std::remove(it->second.begin(), it->second.end(), event), it->second.end());
        }
    }

    bool InputContext::hasKeySetting(const KeyInput keyInput, const std::string& event) const
    {
        auto it = keyInputMapping.find(keyInput);
        if (it != keyInputMapping.end())
        {
            return true;
        }

        return false;
    }


    void InputContext::addPointerSetting(const std::string& event)
    {
        for (std::string mappedEvent : pointerInputMapping)
        {
            if (mappedEvent == event)
            {
                return;
            }
        }

        pointerInputMapping.push_back(event);
    }
    
    void InputContext::removePointerSetting(const std::string& event)
    {
        pointerInputMapping.erase(std::remove(pointerInputMapping.begin(), pointerInputMapping.end(), event), pointerInputMapping.end());
    }

    std::string InputContext::getName() const
    {
        return name;
    }
}
