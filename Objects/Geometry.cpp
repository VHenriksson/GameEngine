//
// Created by viktor on 2021-02-20.
//

#include "Geometry.h"
#include "Importer.h"

void Geometry::test() {
}

void Geometry::initialize() {
    for(std::shared_ptr<GLMeshBase> mesh : *this){
        mesh->initialize();
    }
}
