#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include <glm/glm.hpp>


namespace engine {


class OrthographicCamera
{
public:
    OrthographicCamera(float _left, float _right, float _bottom, float _top);

    void setPosition(glm::vec3 const& _position);
    void setZoom(float _zoom);
    void setRotation(float _rotation);

    void moveByOffset(glm::vec3 const& _offset);

    glm::vec3 getPosition() const { return position_; }
    float getZoom() const { return zoom_; }
    float getRotation() const { return rotation_; }


    glm::mat4 const& getViewMatrix() const { return viewMatrix_; }
    glm::mat4 const& getProjectionMatrix() const { return projectionMatrix_; }
    glm::mat4 const& getViewProjectionMatrix() const { return viewProjectionMatrix_; }

private:

    void recalculateViewMatrix();
    void recalculateProjectionMatrix();

    float left_;
    float right_;
    float bottom_;
    float top_;

    glm::mat4 projectionMatrix_;
    glm::mat4 viewMatrix_;
    glm::mat4 viewProjectionMatrix_;

    glm::vec3 position_;
    float zoom_;
    float rotation_;

};

}


#endif // ORTHOGRAPHICCAMERA_H
