#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include <vector>

#include "layer.h"

namespace engine {

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void pushLayer(Layer* _layer);

    auto begin() { return layerStack_.begin(); }
    auto end() { return layerStack_.end(); }

private:

    std::vector<Layer*> layerStack_;

};

}

#endif // LAYERSTACK_H
