//
// Created by viktor on 2021-02-19.
//

#include "RenderingList.h"

void RenderingList::renderUsing(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader) {
    this->at(shader).second.insert(object);
}



void RenderingList::clearShader(std::shared_ptr<ShaderProgramBase> shader) {
    this->at(shader).second.clear();
}

bool RenderingList::shaderSet(std::shared_ptr<ShaderProgramBase> shader) {
    return !(this->find(shader) == this->end());
}

void RenderingList::setShader(std::shared_ptr<ShaderProgramBase> shader) {
    this->insert(std::make_pair(shader,std::make_pair(shader,std::set<std::shared_ptr<Object>>({}))));
}

void RenderingList::remove(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader) {
    this->at(shader).second.erase(object);
}
