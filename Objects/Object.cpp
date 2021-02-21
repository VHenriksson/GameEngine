//
// Created by viktor on 2021-02-17.
//

#include "Object.h"



std::shared_ptr<Geometry> Object::getGeometry() {
    return geometry;
}

void Object::draw() {
    setupDraw();
    for(std::shared_ptr<GLMeshBase> mesh : *geometry){
        mesh->setMaterial();
        mesh->draw();
    }
}
