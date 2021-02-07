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
    aiString diffuseMapLocation;
    material->GetTexture(aiTextureType_DIFFUSE,0,&diffuseMapLocation);
    int width;
    int height;
    int nrOfChannels;
    std::string fullPath = "/home/viktor/CLionProjects/GameEngine/" + aiStringToString(diffuseMapLocation) + ".jpg";
    unsigned char* data = stbi_load(&fullPath[0], &width, &height, &nrOfChannels, 0);
    /*
    for(int i = 0; i < width*height; i++){
        std::cout << data[i];
    }
     */
    glGenTextures(1, &colourTextureReference);
    glBindTexture(GL_TEXTURE_2D, colourTextureReference);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);
    std::cout << "Material created with id " << colourTextureReference << std::endl;
}

void Material::bind() {
    glBindTexture(GL_TEXTURE_2D, colourTextureReference);
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