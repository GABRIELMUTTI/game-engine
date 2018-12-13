#pragma once

#include "mtgraphics/engine/GLInclude.hpp"
#include "mtgraphics/input/KeyInput.hpp"
#include "mtgraphics/input/PointerInput.hpp"
#include "mtgraphics/graphic/WindowUserPointer.hpp"

#include <utilities/delegate/Event.hpp>
#include <utilities/property/EventProperty.hpp>

#include <glm/glm.hpp>

#include <vector>
#include <algorithm>
#include <iostream>

namespace mtgraphics
{
    class Input
    {
        typedef void(*KeyCallback)(int key, int scancode, int action, int mods);

    private:
	GLFWwindow* windowHandle;
	std::vector<KeyCallback> callbacks;

	utility::Event<KeyInput> keyEvent;
	utility::Event<PointerInput> pointerEvent;

	glm::vec2 lastCursorPosition;
	glm::vec2 currentCursorPosition;
	glm::vec2 deltaCursor;
	float cursorSensitivity;

	static void keyCallbackFunc(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseMoveCallback(GLFWwindow* window, double xPos, double yPos);

    public:
	utility::EventProperty<KeyInput> OnKeyEvent;
	utility::EventProperty<PointerInput> OnPointerEvent;
	
	Input(GLFWwindow* windowHandle);

	int getKey(int key);
	const char* getKeyName(int key, int scancode);

	glm::vec2 getLastCursorPosition();
	glm::vec2 getCurrentCursorPosition();
	glm::vec2 getDeltaCursor();
    };
}
