//
// Created by viktor on 2021-02-02.
//

#ifndef GAMEENGINE_TEXTUREPHONGSHADER_H
#define GAMEENGINE_TEXTUREPHONGSHADER_H


#include <memory>
#include "ShaderProgramBase.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

class TexturePhongShader : public ShaderProgramBase {
    void setSpecifics() override;
    unsigned int sunPosUniform;
    glm::vec3 sunPos = glm::vec3(3,3,-100);
    float t = 0;
public:
    explicit TexturePhongShader(std::string name);
};


#endif //GAMEENGINE_TEXTUREPHONGSHADER_H
