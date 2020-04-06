#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H

namespace engine {


class IndexBuffer
{
public:
    IndexBuffer(unsigned int* _indices, int _count);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    int getCount() const;

private:
    unsigned int id_;
    int count_;
};


}

#endif // INDEXBUFFER_H
