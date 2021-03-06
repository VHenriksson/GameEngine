//
// Created by viktor on 2021-02-21.
//

#include "PhongShadedObject.h"
#include "../../../Objects/PhongShadedGeometry.h"
#include "../../../Shading/TexturePhongShader.h"

PhongShadedObject::PhongShadedObject(std::shared_ptr<Geometry> geometry) {
    this->geometry  = geometry;
}

void PhongShadedObject::setupDraw() {
    shader->setObjectPosition(position);
}



void PhongShadedObject::setShader(std::shared_ptr<ShaderProgramBase> shader) {
    this->shader = std::dynamic_pointer_cast<TexturePhongShader>(shader);
    if(!this->shader){
        throw std::runtime_error("Trying to set non-textured shader to textured object");
    }
}

void PhongShadedObject::setPosition(glm::mat4 position) {
    this->position = position;
}

void PhongShadedObject::setupForMesh(std::shared_ptr<GLMeshBase> mesh) {
    std::shared_ptr<GLMeshTexture> texMesh =  std::dynamic_pointer_cast<GLMeshTexture>(mesh);
    if(!this->shader){
        throw std::runtime_error("Trying to shade a non-textured mesh with a texture shader");
    }
    std::shared_ptr<Material> material = texMesh->getMaterial();
    shader->setPhongDetails(material->getPhongVector(),material->getShininess());
}
