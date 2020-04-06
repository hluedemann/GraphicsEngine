#ifndef SHADER_H
#define SHADER_H

#include <string>

namespace engine {

class Shader
{
public:
    Shader(std::string const& vertexSource, std::string const& fragmentSource);
    ~Shader();

    void bind() const;
    void unbind() const;

private:
    unsigned int programmID_;


};

}


#endif // SHADER_H



