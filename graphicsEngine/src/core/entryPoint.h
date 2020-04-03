#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "application.h"
#include "log.h"

extern engine::Application* engine::createApplication();

int main()
{
    engine::Log::init();

    E_CORE_INFO("Initialize Core Logger!");
    E_INFO("Initialize Client Logger!");

    auto app = engine::createApplication();
    app->run();

    delete app;
}


#endif // ENTRYPOINT_H
