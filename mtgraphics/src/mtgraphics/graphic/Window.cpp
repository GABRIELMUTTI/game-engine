#include "mtgraphics/graphic/Window.hpp"

namespace mtgraphics
{
    Window::Window(GLuint id, GLuint width, GLuint height, const GLchar* title) :
        id(id),
        width(width),
        height(height),
        title(title),
        OnFramebufferResize(framebufferResizeEvent)
    {
        windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);

        if (windowHandle == nullptr)
        {
            glfwTerminate();
            std::cout << "Fatal error: Failed to create GLFWwindow." << std::endl;
        }

        input = new Input(windowHandle);
    }

    void Window::makeWindowContextCurrent()
    {
        glfwMakeContextCurrent(windowHandle);
        glfwSetWindowUserPointer(windowHandle, this);
        glfwSetFramebufferSizeCallback(windowHandle, framebufferResizeCallback);

        glfwSetWindowUserPointer(windowHandle, new WindowUserPointer(this, input, id));
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(windowHandle);
    }

    bool Window::shouldClose()
    {
        return glfwWindowShouldClose(windowHandle);
    }

    GLuint Window::getId()
    {
        return id;
    }

    Input* Window::getInput()
    {
        return input;
    }

    GLuint Window::getWidth()
    {
        return width;
    }

    GLuint Window::getHeight()
    {
        return height;
    }

    void Window::setWindowShouldClose(bool value)
    {
        glfwSetWindowShouldClose(windowHandle, value);
    }

    void Window::setWidth(GLuint width)
    {
        glfwSetWindowSize(windowHandle, width, height);
        this->width = width;
    }

    void Window::setHeight(GLuint height)
    {
        glfwSetWindowSize(windowHandle, width, height);
        this->height = height;
    }

    void Window::setTitle(GLchar* title)
    {
        glfwSetWindowTitle(windowHandle, title);
        this->title = title;
    }


    void Window::framebufferResizeCallback(GLFWwindow* windowHandle, int width, int height)
    {
        WindowUserPointer* windowUserPointer = static_cast<WindowUserPointer*>(glfwGetWindowUserPointer(windowHandle));
        Window* window = static_cast<Window*>(windowUserPointer->windowPtr);

        window->width = width;
        window->height = height;
        glViewport(0, 0, width, height);

        window->framebufferResizeEvent.invoke(FramebufferResizeEvent(window->getId(), width, height));
    }
}