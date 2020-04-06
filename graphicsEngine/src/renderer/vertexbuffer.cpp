#include "vertexbuffer.h"
#include "../core/log.h"

#include <glad/glad.h>
#include <array>

namespace engine {

VertexBuffer::VertexBuffer(float *_vertices, unsigned int _size)
{
    glGenBuffers(1, &id_);
    glBindBuffer(GL_ARRAY_BUFFER, id_);
    glBufferData(GL_ARRAY_BUFFER, _size, _vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    E_CORE_INFO("Deleted Buffer");
    glDeleteBuffers(1, &id_);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

}
