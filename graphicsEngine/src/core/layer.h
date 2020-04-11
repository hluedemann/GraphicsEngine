#ifndef LAYER_H
#define LAYER_H


#include <string>

#include "../events/event.h"
#include "timestep.h"

namespace engine {

class Layer
{
public:
    Layer(std::string const& _name = "Layer");
    virtual ~Layer();

    virtual void onAttach() { }
    virtual void onDetach() { }
    virtual void onUpdate(TimeStep _dt) { }
    virtual void onEvent(Event &_event) { }

    inline const std::string getName() { return debugName_; }

private:
    std::string debugName_;
};

}

#endif // LAYER_H
