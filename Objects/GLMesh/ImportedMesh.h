//
// Created by viktor on 2021-01-25.
//

#ifndef GAMEENGINE_IMPORTEDMESH_H
#define GAMEENGINE_IMPORTEDMESH_H


#include "GLMeshBase.h"


class ImportedMesh : public GLMeshBase {
protected:
    aiMesh* mesh;
    void setPosition(unsigned int i);
    void setNormal(unsigned int i);
    virtual void setExtras(unsigned int i) = 0;
    void setVertex(unsigned int i);
    unsigned int vertexSize() final;
    virtual int extrasSize() = 0;
    unsigned int normalOffset() override;
    void import (aiMesh* mesh);

    void setFace(unsigned int i);

};


#endif //GAMEENGINE_IMPORTEDMESH_H
