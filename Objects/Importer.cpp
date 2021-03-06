//
// Created by viktor on 2021-01-24.
//

#include <stdexcept>
#include <iostream>
#include "Importer.h"


Importer::Importer(std::string source) {
    std::string fullsource = "Models/" + source;
    Assimp::Importer importer;

    scene = importer.ReadFile(fullsource,aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::runtime_error("Could not load model\nAssimp error: " + std::string(importer.GetErrorString()) + "\n");
    }
    processNode(scene->mRootNode);
}

void Importer::processNode(aiNode *node)
{
    processMeshes(node);
    for(unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i]);
    }
}

void Importer::processMeshes(const aiNode *node) {
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        if (mesh->mTextureCoords[0]) {
            addTextureMesh(mesh);
        } else {
            meshes.push_back(std::make_shared<GLMeshColour>(mesh)); //TODO Implement
        }
    }
}

void Importer::addTextureMesh(aiMesh *mesh) {
    GLMeshTexture textureMesh = GLMeshTexture(mesh);
    aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
    std::shared_ptr<Material> pointerToMaterial = std::make_shared<Material>(Material(material));
    textureMesh.setMaterial(pointerToMaterial);
    meshes.push_back(std::make_shared<GLMeshTexture>(textureMesh));
}

std::vector<std::shared_ptr<GLMeshBase>> Importer::getMeshes() {
    return meshes;
}


