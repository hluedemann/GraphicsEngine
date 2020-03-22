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
        continue;
    }
}

}
