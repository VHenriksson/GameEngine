//
// Created by viktor on 2021-02-01.
//

#include <GL/glew.h>
#include <stdexcept>
#include "ShaderProgram.h"
#include "ShaderLoader.h"

ShaderProgram::ShaderProgram(std::string shaderSource) {
    source = shaderSource;
    createVertexShader();
    createFragmentShader();

    glLinkProgram(shaderID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ShaderProgram::createVertexShader() {
    std::string vSource = ShaderLoader::load(source + ".vert");
    const char* vertexSource = vSource.c_str();
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    testShaderCompilation(vertexShader);
    glAttachShader(shaderID, vertexShader);
}

void ShaderProgram::createFragmentShader() {
    std::string fSource = ShaderLoader::load(source + ".frag");
    const char* fragmentSource = fSource.c_str();
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    testShaderCompilation(fragmentShader);
    glAttachShader(shaderID, fragmentShader);
}

void ShaderProgram::draw() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderID);
    glBindVertexArray(1);
//    glBindTexture(GL_TEXTURE_2D, textureId);
    glDrawElements(GL_TRIANGLES, 1000, GL_UNSIGNED_INT, 0);
}

static void ShaderProgram::testShaderCompilation(unsigned int shader) {
    GLint vShaderCompiled = GL_TRUE;
    char errorLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &vShaderCompiled );
    if( vShaderCompiled != GL_TRUE )
    {
        glGetShaderInfoLog(shader, 512, nullptr, &errorLog[0]);
        glDeleteShader(shader); // Don't leak the shader
        throw std::runtime_error( "Unable to compile shader! Shader ID: " + std::to_string(*shader) + ". Shaderlog:\n" + errorLog);
    }
}
