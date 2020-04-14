#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <memory>
#include <GLFW/glfw3.h>
#include <tuple>

#include "orthographiccamera.h"
#include "../core/timestep.h"
#include "../core/keycodes.h"
#include "../core/mousecodes.h"
#include "../events/mouseEvent.h"


namespace engine {

class CameraController
{
public:
    CameraController(std::shared_ptr<OrthographicCamera> _camera, float _speedX, float _speedY, float _speedZoom);

    void bindControlKeys(KeyCode _left, KeyCode _right, KeyCode _bottom, KeyCode _top);

    void onEvent(Event &_event);
    void update(TimeStep _dt);

    void updateZoom(MouseScrollEvent &_e);
    void updatePosition(TimeStep _dt);

    void setSpeedX(float _speedX) { speedX_ = _speedX; }
    void setSpeedY(float _speedY) { speedY_ = _speedY; }
    void setSpeed(float _speedX, float _speedY) { speedX_ = _speedX; speedY_ = _speedY; }
    void setZoomSpeed(float _zoomSpeed) { speedZoom_ = _zoomSpeed; }

    std::pair<float, float> getSpeed() const { return { speedX_, speedY_ }; }
    float getZoomSpeed() const { return speedZoom_; }

private:

    struct ControlKeys
    {
        ControlKeys(KeyCode _left = KeyCode::KEY_A,
                    KeyCode _right = KeyCode::KEY_D,
                    KeyCode _bottom = KeyCode::KEY_S,
                    KeyCode _top = KeyCode::KEY_W)
            : left{_left}, right{_right}, bottom{_bottom}, top{_top}
        {}

        KeyCode left, right, bottom, top;
    };

    std::shared_ptr<OrthographicCamera> camera_;

    float speedX_;
    float speedY_;
    float speedZoom_;

    ControlKeys controlKeys_;
};

}


#endif // CAMERACONTROLLER_H
