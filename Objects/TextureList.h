//
// Created by viktor on 2021-02-06.
//

#ifndef GAMEENGINE_TEXTURELIST_H
#define GAMEENGINE_TEXTURELIST_H

#include <functional>
#include <unordered_map>
#include "Materials/Material.h"
#include "GLMesh/hashFunction.h"


class TextureList : std::unordered_map<size_t,Material>{
public:
    Material get(std::size_t hashValue) {return this->at(hashValue);}
    Material get(std::string textureName) {return this->at(getHash(textureName));}
    void set(std::size_t hashValue,Material material) {
        this->insert(std::pair<size_t,Material>(std::make_pair(hashValue,material)));
    }
    void set(std::string textureName,Material material) {
        this->insert(std::pair<size_t,Material>(std::make_pair(getHash(textureName),material)));
    }
    bool notSet(std::string textureName){
        return (this->find(getHash(textureName)) == this->end());
    }
};


#endif //GAMEENGINE_TEXTURELIST_H
