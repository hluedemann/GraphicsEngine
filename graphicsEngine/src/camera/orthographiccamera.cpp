#include "orthographiccamera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace engine {

OrthographicCamera::OrthographicCamera(float _left, float _right, float _bottom, float _top)
    : left_(_left),
      right_(_right),
      bottom_(_bottom),
      top_(_top),
      projectionMatrix_{glm::ortho(_left, _right, _bottom, _top)},
      viewMatrix_{1.0f},
      position_{glm::vec3(0.0f, 0.0f, 0.0f)},
      zoom_{1.0f},
      rotation_{0.0f}
{
    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_;
}

void OrthographicCamera::setPosition(glm::vec3 const& _position)
{
    position_ = _position;
    recalculateViewMatrix();
}

void OrthographicCamera::setZoom(float _zoom)
{
    zoom_ = _zoom;
    recalculateProjectionMatrix();
}

void OrthographicCamera::setRotation(float _rotation)
{
    rotation_ = _rotation;
    recalculateViewMatrix();
}

void OrthographicCamera::recalculateViewMatrix()
{
    viewMatrix_ = glm::rotate(glm::mat4(1.0f), glm::radians(-rotation_), glm::vec3(0.0f, 0.0f, 1.0f)) *
                  glm::translate(glm::mat4(1.0f), -position_);

    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_;
}

void OrthographicCamera::recalculateProjectionMatrix()
{
    projectionMatrix_ = glm::ortho(zoom_ * left_,
                                   zoom_ * right_,
                                   zoom_ * bottom_,
                                   zoom_ * top_);

    viewProjectionMatrix_ = projectionMatrix_ * viewMatrix_;
}

}
