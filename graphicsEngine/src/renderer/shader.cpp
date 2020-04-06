#include "shader.h"
#include "../core/log.h"


#include <glad/glad.h>

namespace engine {

Shader::Shader(const std::string &vertexSource, const std::string &fragmentSource)
{
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    auto source = reinterpret_cast<GLchar const*>(vertexSource.c_str());

    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);

    // Compilation error
    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE)
    {
            GLint maxLength = 0;
            glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(static_cast<std::size_t>(maxLength));
            glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(vertexShader);

            E_CORE_ERROR("Vertex shader compilation error!");
            E_CORE_ERROR(" {0}", infoLog.data());

            return;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    source = reinterpret_cast<GLchar const*>(fragmentSource.c_str());

    glShaderSource(fragmentShader, 1, &source, nullptr);
    glCompileShader(fragmentShader);

    // Compilation error
    isCompiled = 0;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);

    if (isCompiled == GL_FALSE)
    {
            GLint maxLength = 0;
            glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(static_cast<std::size_t>(maxLength));
            glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

            // We don't need the shader anymore.
            glDeleteShader(fragmentShader);

            E_CORE_ERROR("Fragment shader compilation error!");
            E_CORE_ERROR(" {0}", infoLog.data());

            return;
    }

    programmID_ = glCreateProgram();

    glAttachShader(programmID_, vertexShader);
    glAttachShader(programmID_, fragmentShader);

    glLinkProgram(programmID_);

    GLint isLinked = 0;
    glGetProgramiv(programmID_, GL_LINK_STATUS, reinterpret_cast<int*>(&isLinked));
    if (isLinked == GL_FALSE)
    {
            GLint maxLength = 0;
            glGetProgramiv(programmID_, GL_INFO_LOG_LENGTH, &maxLength);

            // The maxLength includes the NULL character
            std::vector<GLchar> infoLog(static_cast<std::size_t>(maxLength));
            glGetProgramInfoLog(programmID_, maxLength, &maxLength, &infoLog[0]);

            // We don't need the program anymore.
            glDeleteProgram(programmID_);
            // Don't leak shaders either.
            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);

            E_CORE_ERROR("Shader programm linking error!");
            E_CORE_ERROR("  {0}", infoLog.data());

            return;
    }

    glDetachShader(programmID_, vertexShader);
    glDetachShader(programmID_, fragmentShader);

}

Shader::~Shader()
{
    glDeleteProgram(programmID_);
}

void Shader::bind() const
{
    glUseProgram(programmID_);
}

void Shader::unbind() const
{
    glUseProgram(0);
}


}


