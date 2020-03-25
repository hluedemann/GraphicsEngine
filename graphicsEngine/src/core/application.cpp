#include "application.h"


namespace engine {


Application* Application::instance_ = nullptr;

Application::Application()
{
    instance_ = this;
}

void Application::run()
{
    running_ = true;
    while (running_)
    {
        for (auto layer : layerStack_)
            layer->onEvent();
        for (auto layer : layerStack_)
            layer->onUpdate();

    }
}

void Application::pushLayer(Layer *_layer)
{
    layerStack_.pushLayer(_layer);
}

}
