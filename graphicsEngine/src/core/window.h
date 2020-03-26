#ifndef WINDOW_H
#define WINDOW_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <memory>

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
    Window(WindowProps _windowProps);
    ~Window();


    void update();

    int getWidth() { return windowData_.width; }
    int getHeight() { return windowData_.height; }
    std::string getTitle() { return windowData_.title; }

    bool isClosed() { return isClosed_; }

private:

    void init();
    void shutdown();

    bool isClosed_;

    GLFWwindow *window_;

    struct WindowData
    {
        std::string title;
        int width, height;
    };

    WindowData windowData_;
};

}

#endif // WINDOW_H
