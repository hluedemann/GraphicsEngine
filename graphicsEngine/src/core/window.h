#ifndef WINDOW_H
#define WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>
#include <functional>

#include "../events/event.h"
#include "../renderer/graphicscontext.h"

namespace engine {


struct WindowProps
{
    std::string title;
    int width;
    int height;

    WindowProps(std::string _title = "Window", int _width = 1280, int _height = 720)
        : title(_title), width(_width), height(_height)
    {

    }
};


class Window
{
public:

    using EventCallbackFunc = std::function<void(Event&)>;

    Window(WindowProps _windowProps);
    ~Window();


    void update();

    int getWidth() { return windowData_.width; }
    int getHeight() { return windowData_.height; }
    std::string getTitle() { return windowData_.title; }

    GLFWwindow* getNativeWindow() { return window_; }

    void setEventCallbackFunc(EventCallbackFunc _eventCallbackFunc)
    {
        windowData_.eventCallback = _eventCallbackFunc;
    }

private:

    void init();
    void shutdown();

    GLFWwindow *window_;

    struct WindowData
    {
        std::string title;
        int width, height;

        EventCallbackFunc eventCallback;
    };

    WindowData windowData_;
    std::shared_ptr<GraphicsContext> graphicsContext_;

};

}

#endif // WINDOW_H
