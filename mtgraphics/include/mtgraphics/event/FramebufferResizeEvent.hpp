#pragma once

namespace mtgraphics
{
    struct FramebufferResizeEvent
    {
        const GLuint windowId;
        const GLint width;
        const GLint height;

        FramebufferResizeEvent(GLuint windowId, GLint width, GLint height) :
            windowId(windowId),
            width(width),
            height(height)
        {}
    };
}