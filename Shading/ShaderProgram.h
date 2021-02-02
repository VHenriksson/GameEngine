//
// Created by viktor on 2021-02-01.
//

#ifndef GAMEENGINE_SHADERPROGRAM_H
#define GAMEENGINE_SHADERPROGRAM_H


#include <string>

class ShaderProgram {
    unsigned int shaderID = glCreateProgram();
    std::string source;
    int vertexShader;
    int fragmentShader;
public:
    explicit ShaderProgram(std::string shaderSource);
    void draw();

    void createShader(std::string shaderSource, unsigned int shaderType);

    void createVertexShader();

    void testShaderCompilation(unsigned int shader);

    void createFragmentShader();
};


#endif //GAMEENGINE_SHADERPROGRAM_H
