//
// Created by viktor on 2021-02-01.
//

#ifndef GAMEENGINE_SHADERPROGRAMBASE_H
#define GAMEENGINE_SHADERPROGRAMBASE_H


#include <string>
#include "ShaderVariableList.h"
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

class ShaderProgramBase {
    std::string source;
    int vertexShader;
    int fragmentShader;
    void testProgramLinked();
protected:
    unsigned int shaderID = glCreateProgram();
    virtual unsigned int getUniform(const char* name);
    ShaderVariableList var;
public:
    explicit ShaderProgramBase(std::string shaderSource);
    void use();
    void createVertexShader();
    void testShaderCompilation(unsigned int shader);
    void createFragmentShader();
};


#endif //GAMEENGINE_SHADERPROGRAMBASE_H
