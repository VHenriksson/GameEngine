//
// Created by viktor on 2021-02-02.
//

#include "TexturePhongShader.h"
#include "../Objects/GLMesh/GLMeshTexture.h"


void TexturePhongShader::setSpecifics() {
    glUniform1i(glGetUniformLocation(shaderID,"Texture"),0);
    glUniform1i(glGetUniformLocation(shaderID,"normalTexture"),1);
}

TexturePhongShader::TexturePhongShader(std::string name) : ShaderProgramBase(name) {
    MAIN_SHADER_SUN_POSITION = glGetUniformLocation(shaderID, "sunPos");
}

TexturePhongShader::TexturePhongShader() : ShaderProgramBase("/home/viktor/CLionProjects/GameEngine/Shading/Shaders/phongSunTexture") {
    MAIN_SHADER_SUN_POSITION = glGetUniformLocation(shaderID, "sunPos");
}
