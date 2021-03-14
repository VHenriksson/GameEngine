//
// Created by viktor on 2021-02-01.
//

#include <GL/glew.h>
#include <stdexcept>
#include <vector>
#include "ShaderProgramBase.h"
#include "ShaderLoader.h"


ShaderProgramBase::ShaderProgramBase(std::string shaderSource) {
    source = shaderSource;
    createShader(vertexShader,GL_VERTEX_SHADER);
    createShader(fragmentShader,GL_FRAGMENT_SHADER);
    glLinkProgram(shaderID);
    testProgramLinked();
}


void ShaderProgramBase::testShaderCompilation(unsigned int shader) {
    GLint vShaderCompiled = GL_TRUE;
    char errorLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        handleCompilationError(shader, errorLog);
    }
}

void ShaderProgramBase::handleCompilationError(unsigned int shader, char *errorLog) const {
    glGetShaderInfoLog(shader, 512, nullptr, &errorLog[0]);
    glDeleteShader(shader);
    throw std::runtime_error( "Unable to compile shader! Shader ID: " + std::to_string(shader) + ". Shaderlog:\n" + errorLog);
}

void ShaderProgramBase::use() {
    glUseProgram(shaderID);
}

void ShaderProgramBase::testProgramLinked() {
    GLint isLinked = 0;
    glGetProgramiv(shaderID, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE)
    {
        handleLinkingError();
    }
}

void ShaderProgramBase::handleLinkingError() const {
    GLint maxLength = 0;
    glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
    std::vector<GLchar> infoLog(maxLength);
    glGetProgramInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);
    glDeleteProgram(shaderID);
}

unsigned int ShaderProgramBase::getUniform(const char* name) {
    unsigned int returnvalue = glGetUniformLocation(shaderID, name);
    if(returnvalue == -1){
        throw std::runtime_error("The variable " + std::string(name) + " does not occur in shader nr " + std::to_string(shaderID) + ". Maybe it has been optimized away?");
    }
}

void ShaderProgramBase::createShader(int &shaderReference, unsigned int type) {
    const char *sourceCode = getSourceCode(type);
    shaderReference = glCreateShader(type);
    glShaderSource(shaderReference, 1, &sourceCode, NULL);
    glCompileShader(shaderReference);
    testShaderCompilation(shaderReference);
    glAttachShader(shaderID, shaderReference);
    glDeleteShader(shaderReference);
}

const char *ShaderProgramBase::getSourceCode(unsigned int type) {
    std::string sourceCode;
    if (type == GL_VERTEX_SHADER){
        return ShaderLoader::load(source + ".vert");
    } else if (type == GL_FRAGMENT_SHADER) {
        return ShaderLoader::load(source + ".frag");
    }
}

ShaderProgramBase::~ShaderProgramBase() {
    glDeleteProgram(shaderID);
}
