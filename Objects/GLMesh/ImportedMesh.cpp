//
// Created by viktor on 2021-01-25.
//

#include <glm/vec3.hpp>
#include <assimp/mesh.h>
#include <iostream>
#include "ImportedMesh.h"

void ImportedMesh::setNormal(unsigned int i) {
    vertices.push_back(mesh->mNormals[i].x);
    vertices.push_back(mesh->mNormals[i].y);
    vertices.push_back(mesh->mNormals[i].z);
}

void ImportedMesh::setPosition(unsigned int i) {
    vertices.push_back(mesh->mVertices[i].x);
    vertices.push_back(mesh->mVertices[i].y);
    vertices.push_back(mesh->mVertices[i].z);
}

void ImportedMesh::import(aiMesh* mesh) {
    this->mesh = mesh;
    std::vector<material> textures;

    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        setVertex(i);
    }
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        setFace(i);
    }
}

void ImportedMesh::setFace(unsigned int i) {
    aiFace face = mesh->mFaces[i];
    for(unsigned int j = 0; j < face.mNumIndices; j++){
        faceIndices.push_back(face.mIndices[j]);
    }
}

void ImportedMesh::setVertex(unsigned int i) {
    setPosition(i);
    setNormal(i);
    setExtras(i);
}

unsigned int ImportedMesh::vertexSize() {
    //Returns number of floats set by this class, i.e. 3 for vertex and 3 for normals, plus extras set by subclass
    return 6 + extrasSize();
}

unsigned int ImportedMesh::normalOffset() {
    //Returns number of floats before Normals
    return 3;
}





