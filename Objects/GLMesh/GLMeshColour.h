//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_GLMESHCOLOUR_H
#define GAMEENGINE_GLMESHCOLOUR_H


#include <assimp/mesh.h>
#include "GLMeshBase.h"
#include "ImportedMesh.h"

class GLMeshColour : public ImportedMesh {

    void setSpecifics() override;

    int extrasSize() override;
    void setExtras(unsigned int i) override;

public:
    explicit GLMeshColour(aiMesh* mesh);
    void drawSetup() override;
};


#endif //GAMEENGINE_GLMESHCOLOUR_H
