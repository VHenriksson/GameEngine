//
// Created by viktor on 2021-01-24.
//

#include "GLMeshColour.h"

void GLMeshColour::setMaterial() {
    //TODO
}

int GLMeshColour::extrasSize() {
    return 0;
}

void GLMeshColour::setExtras(unsigned int i) {
}

GLMeshColour::GLMeshColour(aiMesh *mesh) {
    import(mesh);
}

void GLMeshColour::drawSetup() {

}

