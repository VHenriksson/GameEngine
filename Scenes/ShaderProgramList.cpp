//
// Created by viktor on 2021-02-19.
//

#include "ShaderProgramList.h"
#include "../Objects/GLMesh/hashFunction.h"


void ShaderProgramList::set(std::string name, TexturePhongShader shaderProgram) {
    this->insert(std::make_pair(getHash(name),std::make_unique<TexturePhongShader>(shaderProgram)));
}

void ShaderProgramList::use(std::string shaderName) {
    //(this->at(getHash(shaderName)))

}
