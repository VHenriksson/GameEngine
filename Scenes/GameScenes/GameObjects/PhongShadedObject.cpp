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
    glUniform3fv(MAIN_SHADER_OBJECT_POSITION, 1, glm::value_ptr(position));
}
