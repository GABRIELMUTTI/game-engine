#include "mtgraphics/input/Input.hpp"

namespace mtgraphics
{
    Input::Input(GLFWwindow* windowHandle) :
        windowHandle(windowHandle),
        OnKeyEvent(keyEvent), 
        OnPointerEvent(pointerEvent),
        cursorSensitivity(0.05f)
    {
        glfwSetKeyCallback(windowHandle, &keyCallbackFunc);
        glfwSetCursorPosCallback(windowHandle, &mouseMoveCallback);
    }

    int Input::getKey(int key)
    {
        return glfwGetKey(windowHandle, key);
    }

    const char* Input::getKeyName(int key, int scancode)
    {
        return glfwGetKeyName(key, scancode);
    }

    void Input::keyCallbackFunc(GLFWwindow* windowHandle, int key, int scancode, int action, int mods)
    {
        WindowUserPointer* windowUserPointer = static_cast<WindowUserPointer*>(glfwGetWindowUserPointer(windowHandle));
        Input* input = static_cast<Input*>(windowUserPointer->inputPtr);

        input->keyEvent.invoke(KeyInput(windowUserPointer->windowId, key, scancode, action, mods));
    }

    void Input::mouseMoveCallback(GLFWwindow* windowHandle, double xPos, double yPos)
    {
        WindowUserPointer* windowUserPointer = static_cast<WindowUserPointer*>(glfwGetWindowUserPointer(windowHandle));
        Input* input = static_cast<Input*>(windowUserPointer->inputPtr);

        input->lastCursorPosition.x = input->currentCursorPosition.x;
        input->lastCursorPosition.y = input->currentCursorPosition.y;

        input->currentCursorPosition.x = xPos;
        input->currentCursorPosition.y = yPos;

        input->deltaCursor.x = input->currentCursorPosition.x - input->lastCursorPosition.x; 
        input->deltaCursor.y = input->lastCursorPosition.y - input->currentCursorPosition.y; 
        

        input->pointerEvent.invoke(PointerInput(windowUserPointer->windowId, xPos, yPos));
    }

    glm::vec2 Input::getLastCursorPosition()
    {
        return lastCursorPosition;
    }

    glm::vec2 Input::getCurrentCursorPosition()
    {
        return currentCursorPosition;
    }

    glm::vec2 Input::getDeltaCursor()
    {
        return deltaCursor;
    }
}

