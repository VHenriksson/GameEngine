//
// Created by viktor on 2021-01-28.
//

#ifndef GAMEENGINE_MATERIAL_H
#define GAMEENGINE_MATERIAL_H


#include <string>
#include <glm/vec3.hpp>

class Material {
    std::string id;
    glm::vec3 ambientColour;
    glm::vec3 diffuseColour;
    glm::vec3 specularColour;
    glm::vec3 specularConstant;
    unsigned int colourTextureReference;
    unsigned int bumpMapReference;
    Material();
};


#endif //GAMEENGINE_MATERIAL_H
