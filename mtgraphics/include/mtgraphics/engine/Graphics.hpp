#pragma once

#include "mtgraphics/graphic/Window.hpp"
#include "mtgraphics/graphic/IRenderer.hpp"
#include "mtgraphics/input/Input.hpp"
#include "mtgraphics/graphic/Camera.hpp"

#include <utilities/property/StructureProperty.hpp>

#include <glm/glm.hpp>

#include <vector>

namespace mtgraphics
{
    class Graphics
    {
    private:
	std::vector<Window*> windows;
	std::vector<IRenderer*> renderers;
	glm::vec4 clearColor;
	Camera* camera;

	GLuint bufferMask;

    public:
	utility::StructureProperty<std::vector<Window*>> Windows;
	
	Graphics();

	void render();

	void addRenderer(IRenderer* renderer);
	void addWindow(Window* window);

	GLuint getBufferMask();
	Window* getWindow(GLuint index);
	Camera* getCamera();

	void setBufferMask(GLuint bufferMask);
	void setClearColor(const glm::vec4& color);
	void setCamera(Camera* camera);
            
    };
}
