#ifndef LAYER_H
#define LAYER_H


#include <string>

namespace engine {

class Layer
{
public:
    Layer(std::string const& _name = "Layer");
    virtual ~Layer();

    virtual void onAttach() { }
    virtual void onDetach() { }
    virtual void onUpdate() { }
    virtual void onEvent() { }

    inline const std::string getName() { return debugName_; }

private:
    std::string debugName_;
};

}

#endif // LAYER_H