#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace engine {

class GraphicsContext
{
public:
    GraphicsContext(GLFWwindow* _windowHandle);

    void init();
    void swpaBuffers();

private:
    GLFWwindow* windowHandle_;
};

}

#endif // GRAPHICSCONTEXT_H
