#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <array>
#include <memory>

#include "vertexbuffer.h"
#include "vertexarray.h"
#include "indexbuffer.h"
#include "shader.h"

namespace engine {


class Renderer
{
public:
    Renderer();

    static void submit(std::shared_ptr<Shader> const& _shader, std::shared_ptr<VertexArray> const& _vertexArray);
};

}

#endif // RENDERER_H
