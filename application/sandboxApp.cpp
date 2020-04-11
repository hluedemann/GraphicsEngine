#include <engine/engine.h>


#include <memory>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>


class ExampleLayer : public engine::Layer
{
public:
    ExampleLayer() : camera_{-1.6f, 1.6f, -0.9f, 0.9f}
    {

    }

    virtual void onAttach() override
    {
        E_INFO("Attached layer!");

        vertexArray_.reset(new engine::VertexArray());

        // only reset works
        vertexBuffer_.reset(new engine::VertexBuffer(vertices.data(), sizeof(vertices)));

        engine::BufferLayout layout
        {
            {engine::ShaderDataType::Float3, "aPos"}
        };
        vertexBuffer_->setLayout(layout);

        vertexArray_->addVertexBuffer(vertexBuffer_);

        indexBuffer_.reset(new engine::IndexBuffer(indices.data(), static_cast<int>(indices.size())));

        vertexArray_->addIndexBuffer(indexBuffer_);

        std::string vertexShaderSource = "#version 430 core\n"
                                         "layout (location = 0) in vec3 aPos;\n"
                                         "uniform mat4 viewProjection;"
                                         "uniform mat4 transform;"
                                         "void main()\n"
                                         "{\n"
                                         "  gl_Position = viewProjection * transform * vec4(aPos, 1.0);\n"
                                         "}\0";

        std::string fragmentShaderSource = "#version 430 core\n"
                                           "out vec4 FragColor;\n"
                                           "void main()\n"
                                           "{"
                                           "    FragColor = vec4(1.0f, 0.5f, 0.2f, 0.5f);"
                                           "}\0";

        shader_.reset(new engine::Shader(vertexShaderSource, fragmentShaderSource));

        camera_.setPosition({0.5f, 0.0f, 0.0f});
        camera_.setRotation(45.0f);
    }


    virtual void onDetach() override
    {
        E_INFO("Detached layer!");
    }


    virtual void onUpdate(engine::TimeStep _dt) override
    {
        engine::RenderCommand::setClearColor({0.5f, 0.4f, 0.2f, 1.0f});
        engine::RenderCommand::clear();

        engine::Renderer::beginScene(camera_);
        engine::Renderer::submit(shader_, vertexArray_, glm::translate(glm::mat4(1.0f),{0.0f, 0.0f, 0.0f}));
        engine::Renderer::endScene();

        E_INFO(_dt.getSeconds());
    }


    virtual void onEvent(engine::Event &_event) override
    {
        auto name = _event.getName();
    }

private:

    std::shared_ptr<engine::VertexArray> vertexArray_;
    std::shared_ptr<engine::VertexBuffer> vertexBuffer_;
    std::shared_ptr<engine::IndexBuffer> indexBuffer_;
    std::shared_ptr<engine::Shader> shader_;

    engine::OrthographicCamera camera_;

    std::array<float, 9> vertices = { -0.5f, -0.5f, 0.0f,
                                       0.5f, -0.5f, 0.0f,
                                       0.0f,  0.5f, 0.0f };

    std::array<unsigned int, 3> indices = {0, 1, 2};


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

