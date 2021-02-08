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
    std::cout << "Material loaded with " << aiStringToString(diffuseMapLocation) << std::endl;
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


    aiString normalMapLocation;
    material->GetTexture(aiTextureType_HEIGHT,0,&normalMapLocation); //TODO Assimp loads normal maps as height maps for .obj files. Should generalize to check the file type.
    std::cout << "Material loaded with " << aiStringToString(normalMapLocation) << std::endl;
    fullPath = "/home/viktor/CLionProjects/GameEngine/" + aiStringToString(normalMapLocation) + ".jpg";
    data = stbi_load(&fullPath[0], &width, &height, &nrOfChannels, 0);
    glGenTextures(1, &normalTextureReference);
    glBindTexture(GL_TEXTURE_2D, normalTextureReference);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free((void *) data);
    std::cout << "Normals created with id " << normalTextureReference << std::endl;
}

void Material::bind() {
    /*
    std::cout << "New mesh " << std::endl;
    glActiveTexture(GL_TEXTURE0);
    std::cout << "Binding Texture " << colourTextureReference << std::endl;
    glBindTexture(GL_TEXTURE_2D, colourTextureReference);
    glActiveTexture(GL_TEXTURE1);
    std::cout << "Binding Texture " << normalTextureReference << std::endl;
    glBindTexture(GL_TEXTURE_2D, normalTextureReference);
    */
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