#include <engine/engine.h>


#include <memory>
#include <iostream>


class ExampleLayer : public engine::Layer
{
public:
    ExampleLayer()
        : renderer{ engine::Renderer()} {};

    virtual void onAttach() override
    {
        E_INFO("Attached layer!");

        renderer.init();
    }
    virtual void onDetach() override
    {
        E_INFO("Detached layer!");
    }
    virtual void onUpdate() override
    {
        auto [x, y] = engine::getMousePosition();
        E_INFO("Mouse position: ({0}, {1})", x, y);

        renderer.draw();

    }
    virtual void onEvent(engine::Event &_event) override
    {
        auto name = _event.getName();
    }


    engine::Renderer renderer;


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

