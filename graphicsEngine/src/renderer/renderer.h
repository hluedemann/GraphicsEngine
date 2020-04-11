#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <array>
#include <memory>

#include "vertexbuffer.h"
#include "vertexarray.h"
#include "indexbuffer.h"
#include "shader.h"
#include "../camera/orthographiccamera.h"

namespace engine {


class Renderer
{
public:
    Renderer();

    static void beginScene(OrthographicCamera const& _camera);
    static void endScene();
    static void submit(std::shared_ptr<Shader> const& _shader,
                       std::shared_ptr<VertexArray> const& _vertexArray,
                       glm::mat4 const& _transformation = glm::mat4(1.0f));

private:
    struct SceneData
    {
        glm::mat4 viewProjectionMatrix;
    };

    static SceneData* sceneData_;
};

}

#endif // RENDERER_H
