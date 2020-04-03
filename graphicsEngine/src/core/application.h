#ifndef APPLICATION_H
#define APPLICATION_H


#include "layer.h"
#include "layerstack.h"
#include "window.h"
#include "../events/event.h"
#include "../events/applicationEvent.h"


#include <memory>

namespace engine {

class Application
{
public:
    Application();
    virtual ~Application() = default;

    void run();

    void pushLayer(Layer *_layer);

    inline static Application& getApplication() { return *instance_; }

    inline Window& getWindow() { return *window_; }

private:

    void onWindowClose(WindowCloseEvent &_event);

    void onEvent(Event &_event);

    std::unique_ptr<Window> window_;

    bool running_ = true;
    static Application *instance_;

    LayerStack layerStack_;

};

Application* createApplication();

}

#endif // APPLICATION_H
