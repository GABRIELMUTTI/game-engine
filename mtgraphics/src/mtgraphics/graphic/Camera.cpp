#include "mtgraphics/graphic/Camera.hpp"

namespace mtgraphics
{
    Camera::Camera(GLuint screenWidth, GLuint screenHeight, GLuint fov) :
        screenWidth(screenWidth),
        screenHeight(screenHeight),
        fov(fov),
        up(glm::vec3(0.0f, 1.0f, 0.0f)),
        view(glm::vec3(0.0f, 0.0f, 1.0f))
    {
        updateViewMatrix();
        projection = glm::perspective(glm::radians((GLfloat)fov), (GLfloat)screenWidth / (GLfloat)screenHeight, 0.1f, 100.0f);
    }

    glm::mat4 Camera::getViewMatrix()
    {
        updateViewMatrix();
        return viewMatrix;
    }

    glm::mat4 Camera::getProjectionMatrix()
    {
        return projection;
    }

    glm::vec3 Camera::getView()
    {
        return view;
    }

    glm::vec3 Camera::getUpVector()
    {
        return up;
    }

    void Camera::setView(const glm::vec3& view)
    {
        this->view = view;
    }

    void Camera::updateViewMatrix()
    {
        viewMatrix = glm::lookAt(transform.translation, transform.translation + view, glm::vec3(0.0f, 1.0f, 0.0f));
    }

    Transform Camera::getTransform()
    {
        return transform;
    }
}