//
// Created by viktor on 2021-02-17.
//

#include "Object.h"



void Object::draw() {
    setupDraw();
    for(std::shared_ptr<GLMeshBase> mesh : *geometry){
        setupForMesh(mesh);
        mesh->draw();
    }
}
