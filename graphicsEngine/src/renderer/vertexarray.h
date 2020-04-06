#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include "vertexbuffer.h"
#include "indexbuffer.h"

#include <vector>
#include <memory>

namespace engine {

class VertexArray
{
public:
    using VertexBufferPtrs = std::vector<std::shared_ptr<VertexBuffer>>;
    using IndexBufferPtr = std::shared_ptr<IndexBuffer>;

    VertexArray();
    ~VertexArray();

    void bind() const;
    void unbind() const;

    void addVertexBuffer(std::shared_ptr<VertexBuffer> const& _vertexBuffer);
    void addIndexBuffer(IndexBufferPtr const& _indexBuffer);

    VertexBufferPtrs const& getVertexBuffers() const;
    IndexBufferPtr const& getindexBuffer() const;


private:
    unsigned int id_;

    VertexBufferPtrs vertexBuffers_;
    IndexBufferPtr indexBuffer_;

};

}


#endif // VERTEXARRAY_H
