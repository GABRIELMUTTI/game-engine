#pragma once

namespace mtgraphics
{
    struct WindowUserPointer
    {
        void* windowPtr;
        void* inputPtr;
        GLuint windowId;
    
        WindowUserPointer(void* windowPtr, void* inputPtr, GLuint windowId) :
            windowPtr(windowPtr),
            inputPtr(inputPtr),
            windowId(windowId)
        {}
    };
}