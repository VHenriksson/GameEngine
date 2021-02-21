//
// Created by viktor on 2021-02-01.
//

#include <GL/glew.h>
#include <stdexcept>
#include <memory>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
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
    unsigned int transformLoc = glGetUniformLocation(shaderID, "transform");
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
