//
// Created by viktor on 2021-01-28.
//

#ifndef GAMEENGINE_MATERIAL_H
#define GAMEENGINE_MATERIAL_H


#include <string>
#include <glm/vec3.hpp>
#include <assimp/material.h>
#include <functional>
#include <assimp/scene.h>
#include "../GLMesh/hashFunction.h"

std::string aiStringToString(aiString s);
struct materialSource{
    std::string diffuseTexture;
    std::string normalTexture;
    size_t id;
    materialSource(const aiScene *scene,aiMesh *mesh){
        aiMaterial *material = scene->mMaterials[mesh->mMaterialIndex];
        aiString str;
        material->GetTexture(aiTextureType_DIFFUSE,0,&str);
        diffuseTexture = aiStringToString(str);
        material->GetTexture(aiTextureType_HEIGHT,0,&str); //TODO Weird for .obj files
        normalTexture = aiStringToString(str);
        size_t id = getHash(diffuseTexture + normalTexture);
    }
    materialSource(aiMaterial *material){
        aiString str;
        material->GetTexture(aiTextureType_DIFFUSE,0,&str);
        diffuseTexture = aiStringToString(str);
        material->GetTexture(aiTextureType_HEIGHT,0,&str); //TODO Weird for .obj files
        normalTexture = aiStringToString(str);
        size_t id = getHash(diffuseTexture + normalTexture);
    }
};

class Material {
    std::string id;
    glm::vec3 ambientColour;
    glm::vec3 diffuseColour;
    glm::vec3 specularColour;
    glm::vec3 specularConstant;
    unsigned int colourTextureReference;
    unsigned int normalTextureReference;
    unsigned int bumpMapReference;
    materialSource source;
public:
    Material(aiMaterial* material);
    Material(materialSource material);
    size_t getID();
    void load();
    void bind();

};


#endif //GAMEENGINE_MATERIAL_H
