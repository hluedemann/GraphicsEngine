#ifndef INPUT_H
#define INPUT_H

#include <tuple>

#include "keycodes.h"
#include "mousecodes.h"

namespace engine {

bool isKeyPressed(KeyCode _key);
bool isMouseButtonPressed(MouseButton _button);
std::pair<double, double> getMousePosition();

}

#endif // INPUT_H
