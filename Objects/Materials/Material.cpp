//
// Created by viktor on 2021-01-28.
//

#include <iostream>
#include <GL/glew.h>
#include "Material.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "../../Textures/stb_image.h"
#endif



Material::Material(aiMaterial* material) {
    source = materialSource(material);
}

void Material::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, colourTextureReference);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, normalTextureReference);
}

Material::Material(materialSource material) {
    source = material;
}

void Material::load() {
    generateTexture(&colourTextureReference, source.diffuseTexture);
    generateTexture(&normalTextureReference, source.normalTexture);
}

void Material::generateTexture(unsigned int *reference, std::string source) {
    int width;
    int height;
    int nrOfChannels;
    unsigned char *data;
    std::string fullPath= "/home/viktor/CLionProjects/GameEngine/" + source + ".jpg";
    data= stbi_load(&fullPath[0], &width, &height, &nrOfChannels, 0);
    glGenTextures(1, reference);
    glBindTexture(GL_TEXTURE_2D, *reference);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);
}

size_t Material::getID() {
    return source.id;
}

glm::vec3 Material::getPhongVector() {
    return phongVector;
}

int Material::getShininess() {
    return shininess;
}

Material::~Material() {
    glDeleteTextures(1,&colourTextureReference);
    glDeleteTextures(1,&normalTextureReference);
}

std::string aiStringToString(aiString s){
    std::string returnString;
    for(int i = 0; i < s.length; i++){
        if(i >= 4){
            returnString += s.C_Str()[i];
        }
    }
    return returnString;
}