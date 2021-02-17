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
    setTangents();
}

GLMeshTexture::GLMeshTexture(aiMesh *mesh) {
    std::cout << "Mesh created from AI-mesh " << mesh << std::endl;
    import(mesh);
}





void GLMeshTexture::setExtras(unsigned int i) {
    vertices.push_back(mesh->mTextureCoords[0][i].x);
    vertices.push_back(mesh->mTextureCoords[0][i].y);
    vertices.push_back(mesh->mTangents[i][0]);
    vertices.push_back(mesh->mTangents[i][1]);
    vertices.push_back(mesh->mTangents[i][2]);
    vertices.push_back(mesh->mBitangents[i][0]);
    vertices.push_back(mesh->mBitangents[i][1]);
    vertices.push_back(mesh->mBitangents[i][2]);
}

int GLMeshTexture::extrasSize() {
    return 8;
}

std::vector<float> GLMeshTexture::getData() {
    return vertices;
}

std::vector<unsigned int> GLMeshTexture::getFaces() {
    return faceIndices;
}

void GLMeshTexture::setPointerToMaterial(std::size_t pointer) {
    pointerToMaterial = pointer;
}

std::size_t GLMeshTexture::getMaterial() {
    return pointerToMaterial;
}

void GLMeshTexture::setTangents() {
    glEnableVertexAttribArray(3);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, this->vertexSize()*sizeof(float), (void*)(8*sizeof(float)));
    glEnableVertexAttribArray(4);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, this->vertexSize()*sizeof(float), (void*)(11*sizeof(float)));
}
