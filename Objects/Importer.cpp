//
// Created by viktor on 2021-01-24.
//

#include <stdexcept>
#include <iostream>
#include "Importer.h"


Importer::Importer(std::string source) {
    Assimp::Importer importer;

    scene = importer.ReadFile(source,aiProcess_Triangulate | aiProcess_FlipUVs);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        throw std::runtime_error("Could not load model\nAssimp error: " + std::string(importer.GetErrorString()) + "\n");
    }
    processNode(scene->mRootNode);
    std::cout << "Texture Meshes:" << std::endl;
    for(GLMeshTexture t : textureMeshes){
        t.setupMesh();
        t.print();
    }
    std::cout << "Colour Meshes:" << std::endl;
    for(GLMeshColour t : colourMeshes){
        t.print();
    }

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
            textureMeshes.push_back(GLMeshTexture(mesh));
            /*
            if(!materials[mesh->mMaterialIndex]){

            }
            aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
            std::cout << material->GetName() << std::endl;
            std::cout << mesh->mMaterialIndex << std::endl;
            aiString str;
            material->GetTexture(aiTextureType_DIFFUSE, 0, &str);
            material->GetTexture(aiTextureType_NONE, 0, &str);
            std::cout << material << std::endl;
            std::cout << str.C_Str() << std::endl;
            std::cout << "Hello" << std::endl;
             */
        } else {
            colourMeshes.push_back(GLMeshColour(mesh));
        }
    }
}

std::vector<float> Importer::getMesh() {
    GLMeshTexture t = textureMeshes[0];
    return t.getData();
}

std::vector<unsigned int> Importer::getFaces() {
    GLMeshTexture t = textureMeshes[0];
    return t.getFaces();
}
