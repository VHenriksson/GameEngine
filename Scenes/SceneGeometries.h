//
// Created by viktor on 2021-02-18.
//

#ifndef GAMEENGINE_SCENEGEOMETRIES_H
#define GAMEENGINE_SCENEGEOMETRIES_H


#include <unordered_map>
#include "../Objects/Object.h"

class SceneGeometries : public std::unordered_map<size_t,std::shared_ptr<Geometry>> {
public:
    std::shared_ptr<Geometry> operator[] (std::string name);
    void set(std::string name,Geometry geometry);
    void set(std::string name,std::string source);

    void setTextured(std::string name, std::string source);
};


#endif //GAMEENGINE_SCENEGEOMETRIES_H
