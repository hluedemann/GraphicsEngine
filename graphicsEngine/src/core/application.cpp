#include "application.h"


#include <iostream>

namespace engine {


Application* Application::instance_ = nullptr;

Application::Application()
{
    instance_ = this;

    window_.reset(new Window({"Test Window", 1280, 720}));

    window_->setEventCallbackFunc(std::bind(&Application::onEvent, this, std::placeholders::_1));
}

void Application::run()
{
    float lastFrameTime = 0.0f;

    while (running_)
    {
        float time = static_cast<float>(glfwGetTime());

        TimeStep dt = time - lastFrameTime;
        lastFrameTime = time;

        for (auto layer : layerStack_)
            layer->onUpdate(dt);

        window_->update();
    }
}

void Application::pushLayer(Layer *_layer)
{
    layerStack_.pushLayer(_layer);
}

void Application::onWindowClose(WindowCloseEvent &_event)
{
    running_ = false;
}

void Application::onEvent(Event &_event)
{
    EventDispatcher eventDispatcher{_event};

    eventDispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));

    for (auto it = layerStack_.end(); it != layerStack_.begin();)
    {
        (*--it)->onEvent(_event);
    }
}

}
