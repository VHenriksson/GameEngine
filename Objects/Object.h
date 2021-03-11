//
// Created by viktor on 2021-02-17.
//

#ifndef GAMEENGINE_OBJECT_H
#define GAMEENGINE_OBJECT_H


#include <vector>
#include <memory>
#include "GLMesh/GLMeshBase.h"
#include "Importer.h"
#include "Geometry.h"

class Object{
protected:
    std::shared_ptr<Geometry> geometry;
public:
    std::unordered_map<size_t, materialSource> getMaterials();
    virtual void setShader(std::shared_ptr<ShaderProgramBase> shader) = 0;
    void draw();
    virtual void setupDraw() = 0;
    virtual void setupForMesh(std::shared_ptr<GLMeshBase> mesh) = 0;
};


#endif //GAMEENGINE_OBJECT_H
