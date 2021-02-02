//
// Created by viktor on 2021-01-20.
//

#include <iostream>
#include "GLMeshBase.h"

void GLMeshBase::setupMesh() {
    glData.setup();
    glData.bindVAO();

    makeVertices();
    makeFaces();
    std::cout << "Mesh set up with vao: " << glData.vao << std::endl;

    // vertex positions

    glBindVertexArray(0);
}

void GLMeshBase::makeFaces() {
    glData.bindEBO();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faceIndices.size() * sizeof(unsigned int),
                 &faceIndices[0], GL_STATIC_DRAW);
}

void GLMeshBase::makeVertices() {
    pushVertexData();
    setVertexPositions();
    setVertexNormals();
    setMaterial();
}


void GLMeshBase::setVertexNormals(){
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize()*sizeof(float), (void*)(normalOffset()*sizeof(float)));
    glEnableVertexAttribArray(1);
}

void GLMeshBase::setVertexPositions(){
    std::cout << "vertices set!" << std::endl;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertexSize()*sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

void GLMeshBase::pushVertexData() {
    glData.bindVBO();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
}

void GLMeshBase::initialize() {
    setupMesh();
}

void GLMeshBase::print() {
    int i = 0;
    for(float f : vertices){
        std::cout << f << " ";
        i++;
        if(i == vertexSize()){
            i = 0;
            std::cout << std::endl;
        }
    }
}


