#include "application.h"


namespace engine {


Application* Application::instance_ = nullptr;

Application::Application()
{
    instance_ = this;

    window_.reset(new Window({"Test Window", 1280, 720}));
}

void Application::run()
{
    running_ = true;
    while (!window_->isClosed())
    {
        for (auto layer : layerStack_)
            layer->onEvent();
        for (auto layer : layerStack_)
            layer->onUpdate();

        window_->update();
    }
}

void Application::pushLayer(Layer *_layer)
{
    layerStack_.pushLayer(_layer);
}

}
