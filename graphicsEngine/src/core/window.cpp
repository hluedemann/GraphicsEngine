#include "window.h"


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
        std::cerr << "init glfw failed!" << std::endl;
        return;
    }

    window_ = glfwCreateWindow(windowData_.width, windowData_.height, windowData_.title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(window_);

    if (!window_)
    {
        std::cerr << "Failed to create window." << std::endl;
        glfwTerminate();
        return;
    }

    // Should be moved maybe?
    gladLoadGL();

    glClearColor(0.5f, 0.2f, 0.1f, 1.0f);

}

void Window::shutdown()
{
    glfwTerminate();
}

void Window::update()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window_);
    glfwPollEvents();
    isClosed_ = glfwWindowShouldClose(window_);
}

}
