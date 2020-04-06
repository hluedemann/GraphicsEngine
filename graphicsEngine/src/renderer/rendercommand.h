#ifndef RENDERCOMMAND_H
#define RENDERCOMMAND_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "vertexarray.h"

namespace engine {


class RenderCommand
{
public:
    static void setClearColor(glm::vec4 const& _color);
    static void clear();
    static void drawIndexed(std::shared_ptr<VertexArray> const& _vertexArray);

private:
    static RenderCommand *renderCommand_;
};

}

#endif // RENDERCOMMAND_H
