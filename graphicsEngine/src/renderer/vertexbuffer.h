#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <vector>
#include <string>

namespace engine {


enum class ShaderDataType
{
    None, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

static unsigned int shaderDataTypeSize(ShaderDataType type)
{
    switch (type)
    {
    case ShaderDataType::Float:
        return 4;
    case ShaderDataType::Float2:
        return 4 * 2;
    case ShaderDataType::Float3:
        return 4 * 3;
    case ShaderDataType::Float4:
        return 4 * 4;
    case ShaderDataType::Mat3:
        return 3 * 3;
    case ShaderDataType::Mat4:
        return 4 * 4;
    case ShaderDataType::Int:
        return 4;
    case ShaderDataType::Int2:
        return 4 * 2;
    case ShaderDataType::Int3:
        return 4 * 3;
    case ShaderDataType::Int4:
        return 4 * 4;
    case ShaderDataType::Bool:
        return 1;
    case ShaderDataType::None:
        return 0;
    }
    return 0;
}

struct BufferElement
{
    ShaderDataType type;
    std::string name;
    unsigned int offset;
    unsigned int size;
    bool normalized;

    BufferElement() = default;

    BufferElement(ShaderDataType _type, std::string const& _name, bool _normalized = false)
        : type(_type), name(_name), offset(0), size(shaderDataTypeSize(_type)), normalized(_normalized)
    { }

    int getComponentCount() const
    {
        switch (type)
        {
        case ShaderDataType::Float:
            return 1;
        case ShaderDataType::Float2:
            return 2;
        case ShaderDataType::Float3:
            return 3;
        case ShaderDataType::Float4:
            return 4;
        case ShaderDataType::Mat3:
            return 3 * 3;
        case ShaderDataType::Mat4:
            return 4 * 4;
        case ShaderDataType::Int:
            return 1;
        case ShaderDataType::Int2:
            return 2;
        case ShaderDataType::Int3:
            return 3;
        case ShaderDataType::Int4:
            return 4;
        case ShaderDataType::Bool:
            return 1;
        case ShaderDataType::None:
            return 0;
        }
    }
};


class BufferLayout
{
public:
    BufferLayout() = default;

    BufferLayout(std::initializer_list<BufferElement> const& _bufferElements)
        : bufferElements_(_bufferElements)
    {
        calculateOffsetsAndStrides();
    }

    const std::vector<BufferElement> getElements() const { return bufferElements_; }
    int getStride() const { return stride_; }

    auto begin() { return bufferElements_.begin(); }
    auto end() { return bufferElements_.end(); }
    auto begin() const { return bufferElements_.begin(); }
    auto end() const { return bufferElements_.end(); }

private:

    void calculateOffsetsAndStrides()
    {
        unsigned int offset = 0;
        stride_ = 0;

        for (auto &element : bufferElements_)
        {
            element.offset = offset;
            offset += element.size;
            stride_ += element.size;
        }
    }

    std::vector<BufferElement> bufferElements_;
    int stride_ = 0;

};

class VertexBuffer
{
public:
    VertexBuffer(float *_vertices, unsigned int _size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;

    void setLayout(BufferLayout &_layout) {bufferLayout_ = _layout; }
    BufferLayout const& getLayout() const { return bufferLayout_; }

private:
    unsigned int id_;
    BufferLayout bufferLayout_;
};


}

#endif // VERTEXBUFFER_H
