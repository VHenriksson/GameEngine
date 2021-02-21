//
// Created by viktor on 2021-02-19.
//

#ifndef GAMEENGINE_SHADERPROGRAMLIST_H
#define GAMEENGINE_SHADERPROGRAMLIST_H


#include <unordered_map>
#include <memory>
#include "../Shading/ShaderProgramBase.h"
#include "../Shading/TexturePhongShader.h"

class ShaderProgramList : public std::unordered_map<size_t, std::unique_ptr<ShaderProgramBase>> {
public:
    void set(std::string shaderName, TexturePhongShader shaderProgram);
    void use(std::string shaderName);
};


#endif //GAMEENGINE_SHADERPROGRAMLIST_H
