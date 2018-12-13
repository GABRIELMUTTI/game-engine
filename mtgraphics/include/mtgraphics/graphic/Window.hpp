#pragma once

#include "mtgraphics/engine/GLInclude.hpp"
#include "mtgraphics/event/FramebufferResizeEvent.hpp"
#include "mtgraphics/input/Input.hpp"
#include "mtgraphics/graphic/WindowUserPointer.hpp"

#include <utilities/delegate/Event.hpp>
#include <utilities/property/EventProperty.hpp>

#include <iostream>

namespace mtgraphics
{
    class Window
    {
    private:
	GLuint width;
	GLuint height;
	const GLchar* title;
	GLuint id;

	GLFWwindow* windowHandle;
	Input* input;

	utility::Event<FramebufferResizeEvent> framebufferResizeEvent;

	static void framebufferResizeCallback(GLFWwindow* windowHandle, int width, int height);

    public:
	utility::EventProperty<FramebufferResizeEvent> OnFramebufferResize;
	
	Window(GLuint id, GLuint width, GLuint height, const GLchar* title);

	void makeWindowContextCurrent();
	void swapBuffers();
	bool shouldClose();

	GLuint getId();
	Input* getInput();
	GLuint getWidth();
	GLuint getHeight();

	void setInput(Input* input);
	void setWidth(GLuint width);
	void setHeight(GLuint height);
	void setTitle(GLchar* title);

	void setWindowShouldClose(bool value);            
    };
}
