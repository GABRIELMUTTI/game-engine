#pragma once

#include "mtengine/factory/Factory.hpp"
#include "mtengine/input/KeyInput.hpp"
#include "mtengine/input/PointerInput.hpp"

#include <mtgraphics/input/PointerInput.hpp>

#include <utilities/eventqueue/message/MessageQueue.hpp>

#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using utility::MessageQueue;
using utility::Message;

namespace mtengine
{
    class InputContext
    {
        typedef std::unordered_map<KeyInput, std::vector<std::string>> KeyInputMap;
        typedef std::vector<std::string> PointerInputMap;

    private:
	std::string name;
	KeyInputMap keyInputMapping;
	PointerInputMap pointerInputMapping;
	MessageQueue* messageQueue;
	unsigned int entityId;
	    
    public:
	InputContext(const std::string& name, unsigned int entityId, MessageQueue* messageQueue);
	InputContext(const std::string& name, unsigned int entityId, const KeyInputMap& keyInputMap, const PointerInputMap& pointerInputMap, MessageQueue* messageQueue);
	void handleInput(const KeyInput input);
	void handleInput(const PointerInput input);

	void addKeySetting(const KeyInput input, const std::string& event);
	void removeKeySetting(const KeyInput input, const std::string& event);
	bool hasKeySetting(const KeyInput input, const std::string& event) const;

	void addPointerSetting(const std::string& event);
	void removePointerSetting(const std::string& event);

	std::string getName() const;
    };
}
