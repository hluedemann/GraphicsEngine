#include "layerstack.h"

namespace engine {

LayerStack::LayerStack()
{

}

LayerStack::~LayerStack()
{
    for(auto layer : layerStack_)
    {
        layer->onDetach();
        delete layer;
    }
}

void LayerStack::pushLayer(Layer *_layer)
{
    _layer->onAttach();
    layerStack_.push_back(_layer);
}

}
