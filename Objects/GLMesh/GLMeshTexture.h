//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_GLMESHTEXTURE_H
#define GAMEENGINE_GLMESHTEXTURE_H


#include <assimp/mesh.h>
#include "GLMeshBase.h"
#include "ImportedMesh.h"
#include "../Materials/Material.h"

class GLMeshTexture : public ImportedMesh {
    void setMaterial() override;
    void setTextureCoordinates();

    int extrasSize() override;
    void setExtras(unsigned int i) override;
    void prepareForDraw() override;

    size_t pointerToMaterial;

public:
    explicit GLMeshTexture(aiMesh *mesh);
    void setPointerToMaterial(std::size_t pointer);

    std::vector<float> getData();

    std::vector<unsigned int> getFaces();

    size_t getMaterial();
};


#endif //GAMEENGINE_GLMESHTEXTURE_H
