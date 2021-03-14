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

    // vertex positions

    glBindVertexArray(0);
}

void GLMeshBase::makeFaces() {
    glData.bindEBO();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, faceIndices.size() * sizeof(unsigned int), &faceIndices[0], GL_STATIC_DRAW);
}

void GLMeshBase::makeVertices() {
    pushVertexData();
    setVertexPositions();
    setVertexNormals();
    setSpecifics();
}


void GLMeshBase::setVertexNormals(){
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertexSize()*sizeof(float), (void*)(normalOffset()*sizeof(float)));
    glEnableVertexAttribArray(1);
}

void GLMeshBase::setVertexPositions(){
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


void GLMeshBase::draw() {
    glData.bindVAO();
    drawSetup();
    glDrawElements(GL_TRIANGLES, faceIndices.size(), GL_UNSIGNED_INT, 0);
}

void GLMeshBase::setShader(std::shared_ptr<ShaderProgramBase> shader) {
    this->shader = shader;
}

GLMeshBase::~GLMeshBase() {
    glData.remove();
}



