#include <engine/engine.h>

class Sandbox : public engine::Application
{
public:
    Sandbox() { }
    ~Sandbox() = default;
};

engine::Application* engine::createApplication()
{
    return new Sandbox();
}

