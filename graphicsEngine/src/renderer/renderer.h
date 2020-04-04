#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <array>

namespace engine {


class Renderer
{
public:
    Renderer();

    void init();

    void draw();

private:
    std::array<float, 9> vertices = { -0.5f, -0.5f, 0.0f,
                                       0.5f, -0.5f, 0.0f,
                                       0.0f,  0.5f, 0.0f };
};

}

#endif // RENDERER_H
