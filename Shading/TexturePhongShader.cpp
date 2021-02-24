//
// Created by viktor on 2021-02-02.
//

#include "TexturePhongShader.h"
#include "../Objects/GLMesh/GLMeshTexture.h"



TexturePhongShader::TexturePhongShader(std::string name) : ShaderProgramBase(name) {
    glUniform1i(glGetUniformLocation(shaderID,"Texture"),0);
    glUniform1i(glGetUniformLocation(shaderID,"normalTexture"),1);
    sunPosition = glGetUniformLocation(shaderID, "sunPos");
    objectPosition = glGetUniformLocation(shaderID, "position");
}

TexturePhongShader::TexturePhongShader() : ShaderProgramBase("/home/viktor/CLionProjects/GameEngine/Shading/Shaders/phongSunTexture") {
    use();
    glUniform1i(glGetUniformLocation(shaderID,"Texture"),0);
    glUniform1i(glGetUniformLocation(shaderID,"normalTexture"),1);
    sunPosition = getUniform("sunPos");
    objectPosition = getUniform("transform");
}

void TexturePhongShader::setObjectPosition(glm::mat4 positioner) {
    glUniformMatrix4fv(objectPosition, 1, GL_FALSE, glm::value_ptr(positioner));
}

void TexturePhongShader::setSunPosition(glm::vec3 position) {
    glUniform3fv(sunPosition, 1, glm::value_ptr(position));
}
