#include "renderer.h"

namespace engine {


Renderer::Renderer()
{

}

void Renderer::init()
{
    // Generate vertex array
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate vertex buffer
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof (vertices), vertices.data(), GL_STATIC_DRAW);


    // Vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), nullptr);
    glEnableVertexAttribArray(0);

    const char* vertexShaderSource = "#version 430 core\n"
                                     "layout (location=0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    const char* fragmentShaderSource = "#version 430 core\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{"
                                       "    FragColor = vec4(1.0f, 0.5f, 0.2f, 0.5f);"
                                       "}\0";

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);


    // Shader program
    unsigned int shaderProgramm;
    shaderProgramm = glCreateProgram();
    glAttachShader(shaderProgramm, vertexShader);
    glAttachShader(shaderProgramm, fragmentShader);
    glLinkProgram(shaderProgramm);
    glUseProgram(shaderProgramm);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


}

void Renderer::draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

}

}
