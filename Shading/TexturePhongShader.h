//
// Created by viktor on 2021-02-02.
//

#ifndef GAMEENGINE_TEXTUREPHONGSHADER_H
#define GAMEENGINE_TEXTUREPHONGSHADER_H


#include <memory>
#include "ShaderProgramBase.h"
#include "glm/glm.hpp"
#include <glm/gtc/type_ptr.hpp>

//unsigned int MAIN_SHADER_SUN_POSITION;
//unsigned int MAIN_SHADER_OBJECT_POSITION;

class TexturePhongShader : public ShaderProgramBase {
    glm::vec3 sunPos = glm::vec3(3,3,-100);
    float t = 0;
    unsigned int sunPosition;
    unsigned int objectPosition;
public:
    void setSunPosition(glm::vec3 position);
    void setObjectPosition(glm::mat4 positioner);
    TexturePhongShader();
    explicit TexturePhongShader(std::string name);
};


#endif //GAMEENGINE_TEXTUREPHONGSHADER_H
