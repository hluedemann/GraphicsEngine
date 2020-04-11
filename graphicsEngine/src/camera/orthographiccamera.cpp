#include "orthographiccamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace engine {

OrthographicCamera::OrthographicCamera(float _left, float _right, float _bottom, float _top)
    : projectionMatrix_{glm::ortho(_left, _right, _bottom, _top)}, viewMatrix_{1.0f}
{
    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_;
}

void OrthographicCamera::setPosition(const glm::vec3 &_position)
{
    position_ = _position;
    recalculateViewMatrix();
}

void OrthographicCamera::setRotation(float rotation)
{
    rotation_ = rotation;
    recalculateViewMatrix();
}

void OrthographicCamera::recalculateViewMatrix()
{
    viewMatrix_ = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation_), glm::vec3(0.0f, 0.0f, 1.0f)) *
                  glm::translate(glm::mat4(1.0f), -position_);

    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_;
}

}
