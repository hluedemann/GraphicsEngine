#ifndef INPUT_H
#define INPUT_H

#include <tuple>

namespace engine {

bool isKeyPressed(int _key);
bool isMouseButtonPressed(int _button);
std::pair<double, double> getMousePosition();

}

#endif // INPUT_H
