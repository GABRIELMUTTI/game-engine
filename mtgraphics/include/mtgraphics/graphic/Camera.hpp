#pragma once

#include "mtgraphics/engine/GLInclude.hpp"
#include "mtgraphics/graphic/Transform.hpp"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace mtgraphics
{
    class Camera
    {
    private:
	glm::mat4 viewMatrix;
	glm::mat4 projection;
	GLuint fov;
	GLuint screenWidth;
	GLuint screenHeight;
            
	glm::vec3 up;
	glm::vec3 view;
	
    public:
	Transform transform;
	
	Camera(GLuint screenWidth, GLuint screenHeight, GLuint fov);

	void updateViewMatrix();
	
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();    

	Transform getTransform();
	glm::vec3 getView();
	glm::vec3 getUpVector();

	void setView(const glm::vec3& view);  
    };
}
