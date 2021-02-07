//
// Created by viktor on 2021-02-02.
//

#include "TexturePhongShader.h"
#include "../Objects/GLMesh/GLMeshTexture.h"


void TexturePhongShader::setSpecifics() {
    glUniform3fv(sunPosUniform, 1, glm::value_ptr(sunPos));
    sunPos = glm::vec3(sin(t),1,cos(t));
    t += 0.01;
    /*
    std::shared_ptr<GLMeshTexture> texObject = dynamic_cast<GLMeshBase>(object);
    if (std::MeshTexture* c = dynamic_cast<GLMeshTexture>(object.get()))
    {
        // do Child specific stuff
    }
    glBindTexture(GL_TEXTURE_2D, textureId);
     */
}

TexturePhongShader::TexturePhongShader(std::string name) : ShaderProgramBase(name) {
    sunPosUniform = glGetUniformLocation(shaderID, "sunPos");
    std::cout << "creating " << sunPosUniform << std::endl;
}
