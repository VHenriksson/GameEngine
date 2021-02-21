//
// Created by viktor on 2021-01-24.
//

#include <stdexcept>
#include <iostream>
#include "Importer.h"


Importer::Importer(std::string source) {
    Assimp::Importer importer;

    scene = importer.ReadFile(source,aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::runtime_error("Could not load model\nAssimp error: " + std::string(importer.GetErrorString()) + "\n");
    }
    processNode(scene->mRootNode);
    std::cout << "Texture Meshes:" << std::endl;
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
    std::cout << "Material indices: " << std::endl;
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
        if (mesh->mTextureCoords[0]) {
            GLMeshTexture textureMesh = GLMeshTexture(mesh);
            aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
            std::shared_ptr<Material> pointerToMaterial = std::make_shared<Material>(Material(material));
            textureMesh.setMaterial(pointerToMaterial);
            meshes.push_back(std::make_shared<GLMeshTexture>(textureMesh));
        } else {
            meshes.push_back(std::make_shared<GLMeshColour>(mesh));
            //colourMeshes.push_back(GLMeshColour(mesh));
        }
    }
}

GLMeshTexture Importer::getMesh() {
    return textureMeshes[0];
//    return t.getData();
}

std::vector<unsigned int> Importer::getFaces() {
    GLMeshTexture t = textureMeshes[0];
    return t.getFaces();
}

std::vector<std::shared_ptr<GLMeshBase>> Importer::getMeshes() {
    return meshes;
}


