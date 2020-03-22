#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#include "application.h"


extern engine::Application* engine::createApplication();

int main()
{
    auto app = engine::createApplication();
    app->run();

    delete app;
}


#endif // ENTRYPOINT_H
