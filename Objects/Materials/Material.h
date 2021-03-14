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
    materialSource(){}
};

class Material {
    std::string id;
    glm::vec3 phongVector = glm::vec3(0.4,0.7,0.7);
    int shininess = 3;
    unsigned int colourTextureReference;
    unsigned int normalTextureReference;
    materialSource source;
    void generateTexture(unsigned int *reference, std::string source);
public:
    ~Material();
    Material(aiMaterial* material);
    Material(materialSource material);
    size_t getID();
    void load();
    void bind();
    glm::vec3 getPhongVector();
    int getShininess();
};


#endif //GAMEENGINE_MATERIAL_H
