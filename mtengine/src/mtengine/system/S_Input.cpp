#include "mtengine/system/S_Input.hpp"

namespace mtengine
{
    S_Input::S_Input(unsigned int id) :
        System(id)
    {        
	
    }
    

    void S_Input::initialize()
    {
        for (mtgraphics::Window* window : graphics->Windows)
	{
	    mtgraphics::Input* input = window->getInput();
	    input->OnKeyEvent.add<S_Input, &S_Input::onKeyEvent>(this);
	    input->OnPointerEvent.add<S_Input, &S_Input::onPointerInput>(this);
        }
        
        events->subscribe<S_Input, &S_Input::onInputMappingModified>(this, "input_mapping_modified");
        events->subscribe<S_Input, &S_Input::onCInputAdded>(this, "component_added");
    }

    void S_Input::update(float deltaTime)
    {

    }

    void S_Input::onKeyEvent(const mtgraphics::KeyInput input)
    {
	KeyInput keyInput = KeyInput(input.key, input.key, input.scancode, input.action, input.mods);
	
        for (uint i = 0; i < contexts.size(); i++)
        {
	    contexts[i]->handleInput(keyInput);
        }
    }

    void S_Input::onPointerInput(const mtgraphics::PointerInput input)
    {
	PointerInput pointerInput = PointerInput(input.windowId, input.xPos, input.yPos);
	
        for (InputContext* context : contexts)
        {
            context->handleInput(pointerInput);
        }

        Message message = Message("on_pointer_moved");
        events->send(message);
    }

    void S_Input::addContext(InputContext* context)
    {
        contexts.push_back(context);
    }

    void S_Input::removeContext(InputContext* context)
    {
        contexts.erase(std::remove(contexts.begin(), contexts.end(), context), contexts.end());
    }

    void S_Input::onCInputAdded(Message message)
    {
        unsigned int entityId = message.getUnsignedInt("entity_id");
        mtecs::Mask mask = mtecs::Mask(message.getInt("component_mask"));

        if (registry->getMask<C_Input>() == mask)
        {
            auto cInput = components->getComponent<C_Input>(entityId, mask);
            std::string name = cInput->context;

            bool doesContextExists = false;
            for (InputContext* context : contexts)
            {
                if (context->getName() == name)
                {
                    doesContextExists = true;
                }
            }

            if (!doesContextExists)
            {
                InputContext* newContext = new InputContext(name, entityId, cInput->keyInputMapping, cInput->pointerMapping, events);
                addContext(newContext);
            }
        }
    }

    void S_Input::onInputMappingModified(Message message)
    {
        std::string contextName = message.getString("context_name");
        std::string inputType = message.getString("input_type");
        std::string event = message.getString("new_event");
        
        if (inputType == "key_mapping")
        {
            KeyInput newKeySetting = KeyInput(message.getString("new_mapping"));
            
            for (InputContext* context : contexts)
            {
                if (context->getName() == contextName)
                {
                    context->addKeySetting(newKeySetting, event);

                    if (message.hasArgument("old_mapping"))
                    {
                        context->removeKeySetting(KeyInput(message.getString("old_mapping")), message.getString("old_event"));
                    }
                }
            }
        }
        else if (inputType == "pointer_mapping")
        {
            for (InputContext* context : contexts)
            {
                if (context->getName() == contextName)
                {
                    context->addPointerSetting(event);

                    if (message.hasArgument("old_mapping"))
                    {
                        context->removePointerSetting(message.getString("old_mapping"));
                    }
                }
            }
        }
    }
}
