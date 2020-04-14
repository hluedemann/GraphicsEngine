#include "cameracontroller.h"
#include "../core/input.h"
#include "../core/log.h"

#include <functional>

namespace engine {


CameraController::CameraController(std::shared_ptr<OrthographicCamera> _camera, float _speedX, float _speedY, float _speedZoom)
    : camera_{_camera},
      speedX_{_speedX},
      speedY_{_speedY},
      speedZoom_{_speedZoom}
{
}

void CameraController::bindControlKeys(KeyCode _left, KeyCode _right, KeyCode _bottom, KeyCode _top)
{
    controlKeys_.left = _left;
    controlKeys_.right = _right;
    controlKeys_.bottom = _bottom;
    controlKeys_.top = _top;
}

void CameraController::onEvent(Event &_event)
{
    EventDispatcher eventDispatcher{_event};
    E_CORE_INFO(_event.getName());

    eventDispatcher.dispatch<MouseScrollEvent>(std::bind(&CameraController::updateZoom, this, std::placeholders::_1));
}

void CameraController::update(TimeStep _dt)
{
    updatePosition(_dt);
}

void CameraController::updateZoom(MouseScrollEvent &_e)
{
    camera_->setZoom(camera_->getZoom() + speedZoom_ * static_cast<float>(_e.getYOffset()));
}

void CameraController::updatePosition(TimeStep _dt)
{
    if (isKeyPressed(controlKeys_.left))
        camera_->moveByOffset({-_dt.getSeconds() * speedX_, 0.0f, 0.0f});

    if (isKeyPressed(controlKeys_.right))
        camera_->moveByOffset({_dt.getSeconds() * speedX_, 0.0f, 0.0f});

    if (isKeyPressed(controlKeys_.bottom))
        camera_->moveByOffset({0.0f, -_dt.getSeconds() *speedY_, 0.0f});

    if (isKeyPressed(controlKeys_.top))
        camera_->moveByOffset({0.0f, _dt.getSeconds() * speedY_, 0.0f});
}

}
