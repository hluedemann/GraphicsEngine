#include "input.h"
#include "application.h"

namespace engine {

bool isKeyPressed(KeyCode _key)
{
    GLFWwindow* window = Application::getApplication().getWindow().getNativeWindow();

    auto state = glfwGetKey(window, static_cast<int>(_key));

    return state == GLFW_PRESS;
}

bool isMouseButtonPressed(MouseButton _button)
{
    GLFWwindow* window = Application::getApplication().getWindow().getNativeWindow();

    auto state = glfwGetMouseButton(window, static_cast<int>(_button));

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
