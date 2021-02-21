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
    std::shared_ptr<Geometry> getGeometry();
    void draw();
    virtual void setupDraw() = 0;
};


#endif //GAMEENGINE_OBJECT_H
