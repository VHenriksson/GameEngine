//
// Created by viktor on 2021-02-06.
//

#ifndef GAMEENGINE_TEXTURELIST_H
#define GAMEENGINE_TEXTURELIST_H

#include <functional>
#include <unordered_map>
#include "Materials/Material.h"
#include "GLMesh/hashFunction.h"


class TextureList : std::unordered_map<size_t,std::shared_ptr<Material>>{
public:
    std::shared_ptr<Material> get(std::size_t hashValue) {return this->at(hashValue);}
    std::shared_ptr<Material> get(std::string textureName) {return this->at(getHash(textureName));}
    /*
    void set(std::size_t hashValue,Material material) {
        this->insert(std::pair<size_t,Material>(std::make_pair(hashValue,stdmaterial)));
    }
    void set(std::string textureName,Material material) {
        this->insert(std::pair<size_t,Material>(std::make_pair(getHash(textureName),material)));
    }*/
    void set(size_t textureID,std::shared_ptr<Material> material) {
        this->insert(std::make_pair(textureID,material));
    }
    bool notSet(std::string textureName){
        return (this->find(getHash(textureName)) == this->end());
    }
    bool notSet(std::size_t textureReference){
        return (this->find(textureReference) == this->end());
    }
};


#endif //GAMEENGINE_TEXTURELIST_H
