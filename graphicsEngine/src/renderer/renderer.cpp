#include "renderer.h"
#include "../core/log.h"

#include "rendercommand.h"

namespace engine {

Renderer::SceneData* Renderer::sceneData_ = new Renderer::SceneData;


Renderer::Renderer()
{

}

void Renderer::beginScene(const OrthographicCamera &_camera)
{
    sceneData_->viewProjectionMatrix = _camera.getViewProjectionMatrix();
}

void Renderer::endScene()
{

}


void Renderer::submit(const std::shared_ptr<Shader> &_shader,
                      const std::shared_ptr<VertexArray> &_vertexArray,
                      glm::mat4 const& _transformation)
{
    _shader->bind();

    _shader->uploadUniformMat4("viewProjection", sceneData_->viewProjectionMatrix);
    _shader->uploadUniformMat4("transform", _transformation);

    _vertexArray->bind();
    RenderCommand::drawIndexed(_vertexArray);
}

}
