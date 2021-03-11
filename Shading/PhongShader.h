//
// Created by viktor on 2021-02-24.
//

#ifndef GAMEENGINE_PHONGSHADER_H
#define GAMEENGINE_PHONGSHADER_H


#include "ShaderProgramBase.h"

class PhongShader : public ShaderProgramBase {
private:
    unsigned int phongVector;
    unsigned int shininess;
public:
    void setPhongDetails(glm::vec3 phongVector, int shininess);
    explicit PhongShader(std::string source);
};


#endif //GAMEENGINE_PHONGSHADER_H
