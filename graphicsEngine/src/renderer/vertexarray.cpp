#include "vertexarray.h"

#include <glad/glad.h>
#include <gsl/gsl-lite.hpp>

namespace engine {


namespace detail {

static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
{
    switch (type)
    {
    case ShaderDataType::Float:
        return GL_FLOAT;
    case ShaderDataType::Float2:
        return GL_FLOAT;
    case ShaderDataType::Float3:
        return GL_FLOAT;
    case ShaderDataType::Float4:
        return GL_FLOAT;
    case ShaderDataType::Mat3:
        return GL_FLOAT;
    case ShaderDataType::Mat4:
        return GL_FLOAT;
    case ShaderDataType::Int:
        return GL_INT;
    case ShaderDataType::Int2:
        return GL_INT;
    case ShaderDataType::Int3:
        return GL_INT;
    case ShaderDataType::Int4:
        return GL_INT;
    case ShaderDataType::Bool:
        return GL_BOOL;
    case ShaderDataType::None:
        return GL_NONE;  // ??
    }
}

} // end namespace detail






VertexArray::VertexArray()
{
    glGenVertexArrays(1, &id_);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &id_);
}

void VertexArray::bind() const
{
    glBindVertexArray(id_);
}

void VertexArray::unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer> &_vertexBuffer)
{
    Expects(_vertexBuffer->getLayout().getElements().size() > 0);

    bind();

    _vertexBuffer->bind();

    auto const& layout = _vertexBuffer->getLayout();

    unsigned int index = 0;

    for (auto const& element : layout.getElements())
    {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index,
                              element.getComponentCount(),
                              detail::ShaderDataTypeToOpenGLBaseType(element.type),
                              element.normalized ? GL_TRUE : GL_FALSE,
                              layout.getStride(),
                              reinterpret_cast<const void*>(element.offset));
        index ++;
    }
    vertexBuffers_.push_back(_vertexBuffer);
}

void VertexArray::addIndexBuffer(const VertexArray::IndexBufferPtr &_indexBuffer)
{
    glBindVertexArray(id_);
    _indexBuffer->bind();

    indexBuffer_ = _indexBuffer;
}

const VertexArray::VertexBufferPtrs &VertexArray::getVertexBuffers() const
{
    return vertexBuffers_;
}

const VertexArray::IndexBufferPtr &VertexArray::getindexBuffer() const
{
    return indexBuffer_;
}

}
