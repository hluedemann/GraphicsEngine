#include "rendercommand.h"

namespace engine {

RenderCommand* RenderCommand::renderCommand_ = new RenderCommand;


void RenderCommand::setClearColor(glm::vec4 const& _color)
{
    glClearColor(_color.r, _color.b, _color.g, _color.a);
}

void RenderCommand::clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderCommand::drawIndexed(const std::shared_ptr<VertexArray> &_vertexArray)
{
    glDrawElements(GL_TRIANGLES,
                   _vertexArray->getindexBuffer()->getCount(),
                   GL_UNSIGNED_INT,
                   nullptr);
}


}
