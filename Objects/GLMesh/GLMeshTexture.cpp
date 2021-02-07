//
// Created by viktor on 2021-01-24.
//

#include <GL/glew.h>
#include <iostream>
#include "GLMeshTexture.h"

void GLMeshTexture::setTextureCoordinates() {
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, this->vertexSize()*sizeof(float), (void*)(6*sizeof(float)));
}

void GLMeshTexture::setMaterial() {
    setTextureCoordinates();
}

GLMeshTexture::GLMeshTexture(aiMesh *mesh) {
    import(mesh);
}





void GLMeshTexture::setExtras(unsigned int i) {
    vertices.push_back(mesh->mTextureCoords[0][i].x);
    vertices.push_back(mesh->mTextureCoords[0][i].y);
}

int GLMeshTexture::extrasSize() {
    return 2;
}

std::vector<float> GLMeshTexture::getData() {
    return vertices;
}

std::vector<unsigned int> GLMeshTexture::getFaces() {
    return faceIndices;
}

void GLMeshTexture::prepareForDraw() {
    glBindTexture(GL_TEXTURE_2D, 2);
}

void GLMeshTexture::setPointerToMaterial(std::size_t pointer) {
    pointerToMaterial = pointer;
}
