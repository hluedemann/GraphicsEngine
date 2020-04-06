#include "indexbuffer.h"

#include <glad/glad.h>

namespace engine {


IndexBuffer::IndexBuffer(unsigned int *_indices, int _count)
    : count_(_count)
{
    glCreateBuffers(1, &id_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * sizeof (unsigned int), _indices, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &id_);
}

void IndexBuffer::bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
}

void IndexBuffer::unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int IndexBuffer::getCount() const
{
    return count_;
}

}
