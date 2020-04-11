#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <string>

namespace engine {

class Shader {
public:
    Shader(std::string const& vertexSource, std::string const& fragmentSource);
    ~Shader();

    void bind() const;
    void unbind() const;

    void uploadUniformMat4(std::string const& _name, glm::mat4 const& _matrix);

private:
    unsigned int programmID_;
};

}

#endif // SHADER_H
