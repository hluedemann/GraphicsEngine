#include "graphicscontext.h"

#include "../src/core/log.h"


namespace engine {


GraphicsContext::GraphicsContext(GLFWwindow *_windowHandle)
    : windowHandle_(_windowHandle)
{
}

void GraphicsContext::init()
{
    glfwMakeContextCurrent(windowHandle_);

    if (!gladLoadGL())
    {
        E_CORE_ERROR("Failed to initialiez glad!");
    }

    E_CORE_INFO("OpenGL Renderer:");
    E_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
    E_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
    E_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));
}

void GraphicsContext::swpaBuffers()
{
    glfwSwapBuffers(windowHandle_);
}

}
