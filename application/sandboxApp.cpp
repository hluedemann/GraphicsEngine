#include <engine/engine.h>


#include <memory>
#include <iostream>


class ExampleLayer : public engine::Layer
{
public:
    ExampleLayer() = default;

    virtual void onAttach() override
    {
        std::cout << "Attached" << std::endl;
    }
    virtual void onDetach() override
    {
        std::cout << "Detached" << std::endl;
    }
    virtual void onUpdate() override
    {
        auto [x, y] = engine::getMousePosition();
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
    virtual void onEvent(engine::Event &_event) override
    {
        auto name = _event.getName();
    }
};


class Sandbox : public engine::Application
{
public:
    Sandbox() { }
    ~Sandbox() = default;
};

engine::Application* engine::createApplication()
{

    auto app = new Sandbox();

    app->pushLayer(new ExampleLayer());

    return app;
}

