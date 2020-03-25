#ifndef APPLICATION_H
#define APPLICATION_H


#include "layer.h"
#include "layerstack.h"

namespace engine {

class Application
{
public:
    Application();
    virtual ~Application() = default;

    void run();

    void pushLayer(Layer *_layer);

    inline static Application& getApplication() { return *instance_; }

private:

    bool running_;
    static Application *instance_;

    LayerStack layerStack_;

};

Application* createApplication();

}

#endif // APPLICATION_H
