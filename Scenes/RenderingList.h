//
// Created by viktor on 2021-02-19.
//

#ifndef GAMEENGINE_RENDERINGLIST_H
#define GAMEENGINE_RENDERINGLIST_H


#include <unordered_map>
#include <set>
#include "../Objects/Object.h"
#include "../Shading/ShaderProgramBase.h"

class RenderingList : public std::unordered_map<std::shared_ptr<ShaderProgramBase>,std::pair<std::shared_ptr<ShaderProgramBase>, std::set<std::shared_ptr<Object>>>>{
public:
    void renderUsing(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader);
    void clearShader(std::shared_ptr<ShaderProgramBase> shader);
    bool shaderSet(std::shared_ptr<ShaderProgramBase> shader);
    void setShader(std::shared_ptr<ShaderProgramBase> shader);

    void remove(std::shared_ptr<Object> sharedPtr, std::shared_ptr<ShaderProgramBase> sharedPtr1);
};


#endif //GAMEENGINE_RENDERINGLIST_H
