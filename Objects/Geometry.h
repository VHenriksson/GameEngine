//
// Created by viktor on 2021-02-20.
//

#ifndef GAMEENGINE_GEOMETRY_H
#define GAMEENGINE_GEOMETRY_H


#include <unordered_map>
#include <memory>
#include "Materials/Material.h"
#include "GLMesh/GLMeshBase.h"

class Geometry  : public std::vector<std::shared_ptr<GLMeshBase>>{
    virtual void test();
public:
    void initialize();
};


#endif //GAMEENGINE_GEOMETRY_H
