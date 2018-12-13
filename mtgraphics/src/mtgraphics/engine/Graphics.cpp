#include "mtgraphics/engine/Graphics.hpp"

namespace mtgraphics
{
    Graphics::Graphics() :
        clearColor(glm::vec4(0.0f, 0.0f, 0.0f, 0.0f)),
	bufferMask(0),
        Windows(windows)
    {
        int status = glfwInit();
        if (!status)
        {
            fprintf(stderr, "ERROR: glfwInit() failed.\n");
            std::exit(EXIT_FAILURE);
        }
	
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void Graphics::render()
    {
        glClear(bufferMask);

        for (IRenderer* renderer : renderers)
        {
            renderer->render();
        }

        for (Window* window : windows)
        {
            window->swapBuffers();
        }

        glfwPollEvents();
    }

    void Graphics::addWindow(Window* window)
    {
        windows.push_back(window);
        gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

        glEnable(GL_DEPTH);
        setClearColor(clearColor);
    }

    void Graphics::addRenderer(IRenderer* renderer)
    {
        renderers.push_back(renderer);
    }

    void Graphics::setCamera(Camera* camera)
    {
        this->camera = camera;

        for (IRenderer* renderer : renderers)
        {
            renderer->setCamera(camera);
        }
    }

    void Graphics::setBufferMask(GLuint bufferMask)
    {
        this->bufferMask = bufferMask;
    }

    GLuint Graphics::getBufferMask()
    {
        return bufferMask;
    }

    Camera* Graphics::getCamera()
    {
        return camera;
    }

    Window* Graphics::getWindow(GLuint id)
    {
        if (id >= 0 && id < windows.size())
        {
            return windows[id];
        }

        return nullptr;
    }

    void Graphics::setClearColor(const glm::vec4& color)
    {
        clearColor = color;
        glClearColor(clearColor.x, clearColor.y, clearColor.z, clearColor.a);
    }
}
