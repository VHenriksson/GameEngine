//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_GLMESHTEXTURE_H
#define GAMEENGINE_GLMESHTEXTURE_H


#include <assimp/mesh.h>
#include "GLMeshBase.h"
#include "ImportedMesh.h"

class GLMeshTexture : public ImportedMesh {
    void setMaterial() override;
    void setTextureCoordinates();

    int extrasSize() override;
    void setExtras(unsigned int i) override;

public:
    explicit GLMeshTexture(aiMesh *mesh);

    std::vector<float> getData();

    std::vector<unsigned int> getFaces();
};


#endif //GAMEENGINE_GLMESHTEXTURE_H
