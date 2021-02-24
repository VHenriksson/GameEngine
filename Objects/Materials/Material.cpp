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
    int width;
    int height;
    int nrOfChannels;
    std::string fullPath = "/home/viktor/CLionProjects/GameEngine/" + source.diffuseTexture + ".jpg";
    unsigned char* data = stbi_load(&fullPath[0], &width, &height, &nrOfChannels, 0);
    glGenTextures(1, &colourTextureReference);
    glBindTexture(GL_TEXTURE_2D, colourTextureReference);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);
    std::cout << "Material created with id " << colourTextureReference << std::endl;
    std::cout << "Material loaded with " << source.diffuseTexture << std::endl;

    fullPath = "/home/viktor/CLionProjects/GameEngine/" + source.normalTexture + ".jpg";
    unsigned char* normalData = stbi_load(&fullPath[0], &width, &height, &nrOfChannels, 0);
    glGenTextures(1, &normalTextureReference);
    glBindTexture(GL_TEXTURE_2D, normalTextureReference);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, normalData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);
    std::cout << "Normals created with id " << normalTextureReference << std::endl;
    std::cout << "Material loaded with " << source.normalTexture << std::endl;
}

size_t Material::getID() {
    return source.id;
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