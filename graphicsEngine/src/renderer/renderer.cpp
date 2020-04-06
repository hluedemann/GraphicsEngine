#include "renderer.h"
#include "../core/log.h"

#include "rendercommand.h"

namespace engine {


Renderer::Renderer()
{

}


void Renderer::submit(const std::shared_ptr<Shader> &_shader, const std::shared_ptr<VertexArray> &_vertexArray)
{
    _shader->bind();

    _vertexArray->bind();

    RenderCommand::drawIndexed(_vertexArray);
}

}
