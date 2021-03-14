//
// Created by viktor on 2021-02-06.
//

#ifndef GAMEENGINE_MATERIALLIST_H
#define GAMEENGINE_MATERIALLIST_H

#include <functional>
#include <unordered_map>
#include "Materials/Material.h"
#include "GLMesh/hashFunction.h"


class MaterialList : std::unordered_map<size_t,std::shared_ptr<Material>>{
public:
    std::shared_ptr<Material> get(std::size_t hashValue) {return this->at(hashValue);}
    std::shared_ptr<Material> get(std::string textureName) {return this->at(getHash(textureName));}
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


#endif //GAMEENGINE_MATERIALLIST_H
