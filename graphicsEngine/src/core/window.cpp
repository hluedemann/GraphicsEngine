
#include "window.h"
#include "../events/mouseEvent.h"
#include "../events/keyEvent.h"
#include "../events/applicationEvent.h"
#include "log.h"

#include <iostream>

namespace engine {


Window::Window(WindowProps _windowProps)
    : isClosed_(false)
{
    windowData_.title = _windowProps.title;
    windowData_.width = _windowProps.width;
    windowData_.height = _windowProps.height;

    init();
}

Window::~Window()
{
    shutdown();
}

void Window::init()
{
    if (!glfwInit())
    {
        E_CORE_ERROR("Failed to initialize glfw!");
        return;
    }

    window_ = glfwCreateWindow(windowData_.width, windowData_.height, windowData_.title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(window_);

    if (!window_)
    {
        E_CORE_ERROR("Failed to create glfw window!");
        glfwTerminate();
        return;
    }

    E_CORE_INFO("Crerated glfw window!");

    glfwSetWindowUserPointer(window_, &windowData_);

    // Should be moved maybe?
    gladLoadGL();

    glClearColor(0.5f, 0.2f, 0.1f, 1.0f);

    // Set up glfw call back functions


    glfwSetMouseButtonCallback(window_, [](GLFWwindow *_window, int _button, int _action, int _mds)
    {
        WindowData &windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(_window));

        switch (_action)
        {
        case GLFW_PRESS:
        {
            MouseButtonPressedEvent event(_button);
            windowData.eventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            MouseButtonReleasedEvent event(_button);
            windowData.eventCallback(event);
            break;
        }
        }

    });

    glfwSetScrollCallback(window_, [](GLFWwindow* _window, double _xoffset, double _yoffset){

        WindowData &windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(_window));

        MouseScrollEvent event(_xoffset, _yoffset);

        windowData.eventCallback(event);
    });


    glfwSetKeyCallback(window_, [](GLFWwindow* _window, int _key, int _scanCode, int _action, int _mds){

        WindowData &windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(_window));

        switch (_action)
        {
        case GLFW_PRESS:
        {
            KeyPressedEvent event(_key);
            windowData.eventCallback(event);
            break;
        }
        case GLFW_RELEASE:
        {
            KeyReleasedEvent event(_key);
            windowData.eventCallback(event);
            break;
        }
        case GLFW_REPEAT:
        {
            KeyPressedEvent event(_key);
            windowData.eventCallback(event);
            break;
        }

        }

    });


    glfwSetWindowCloseCallback(window_, [](GLFWwindow *_window){

        WindowData &windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(_window));

        WindowCloseEvent event;

        windowData.eventCallback(event);


    });

    glfwSetWindowSizeCallback(window_, [](GLFWwindow*_window, int _width, int _height){

        WindowData &windowData = *reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(_window));

        WindowResizeEvent event(_width, _height);

        windowData.eventCallback(event);

    });

}

void Window::shutdown()
{
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(window_);
    glfwPollEvents();
    isClosed_ = glfwWindowShouldClose(window_);
}

}
