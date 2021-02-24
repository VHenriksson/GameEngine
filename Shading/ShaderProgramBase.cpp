//
// Created by viktor on 2021-02-01.
//

#include <GL/glew.h>
#include <stdexcept>
#include <memory>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include "ShaderProgramBase.h"
#include "ShaderLoader.h"
#include "../Objects/Materials/Material.h"

ShaderProgramBase::ShaderProgramBase(std::string shaderSource) {
    source = shaderSource;
    createVertexShader();
    createFragmentShader();

    glLinkProgram(shaderID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    testProgramLinked();
}

void ShaderProgramBase::createVertexShader() {
    std::string vSource = ShaderLoader::load(source + ".vert");
    const char* vertexSource = vSource.c_str();
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    testShaderCompilation(vertexShader);
    glAttachShader(shaderID, vertexShader);
}

void ShaderProgramBase::createFragmentShader() {
    std::string fSource = ShaderLoader::load(source + ".frag");
    const char* fragmentSource = fSource.c_str();
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    testShaderCompilation(fragmentShader);
    glAttachShader(shaderID, fragmentShader);
}


void ShaderProgramBase::testShaderCompilation(unsigned int shader) {
    GLint vShaderCompiled = GL_TRUE;
    char errorLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        glGetShaderInfoLog(shader, 512, nullptr, &errorLog[0]);
        glDeleteShader(shader); // Don't leak the shader
        throw std::runtime_error( "Unable to compile shader! Shader ID: " + std::to_string(shader) + ". Shaderlog:\n" + errorLog);
    }
}

void ShaderProgramBase::use() {
    glUseProgram(shaderID);
}

void ShaderProgramBase::testProgramLinked() {
    GLint isLinked = 0;
    glGetProgramiv(shaderID, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);
        glDeleteProgram(shaderID);
        return;
    }
}

unsigned int ShaderProgramBase::getUniform(const char* name) {
    unsigned int returnvalue = glGetUniformLocation(shaderID, name);
    if(returnvalue == -1){
        throw std::runtime_error("The variable " + std::string(name) + " does not occure in shader nr " + std::to_string(shaderID) + ". Maybe it has been optimized away?");
    }
}
