#include "input.h"
#include "application.h"

namespace engine {

bool isKeyPressed(int _key)
{
    GLFWwindow* window = Application::getApplication().getWindow().getNativeWindow();

    auto state = glfwGetKey(window, _key);

    return state == GLFW_PRESS;
}

bool isMouseButtonPressed(int _button)
{
    GLFWwindow* window = Application::getApplication().getWindow().getNativeWindow();

    auto state = glfwGetMouseButton(window, _button);

    return state == GLFW_PRESS;
}

std::pair<double, double> getMousePosition()
{
    GLFWwindow* window = Application::getApplication().getWindow().getNativeWindow();

    double xpos, ypos;

    glfwGetCursorPos(window, &xpos, &ypos);

    return { xpos, ypos };
}

}
