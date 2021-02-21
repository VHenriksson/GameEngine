//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_GLMESHTEXTURE_H
#define GAMEENGINE_GLMESHTEXTURE_H


#include <assimp/mesh.h>
#include <memory>
#include "GLMeshBase.h"
#include "ImportedMesh.h"
#include "../Materials/Material.h"

class GLMeshTexture : public ImportedMesh {
    void setMaterial() override;
    void setTextureCoordinates();

    int extrasSize() override;
    void setExtras(unsigned int i) override;

    std::shared_ptr<Material> material;

public:
    explicit GLMeshTexture(aiMesh *mesh);
    void setPointerToMaterial(std::size_t pointer);

    std::vector<float> getData();
    void drawSetup() override;

    std::vector<unsigned int> getFaces();
    size_t getMaterialID();
    std::shared_ptr<Material> getMaterial();
    void setMaterial(std::shared_ptr<Material> material);

    void setTangents();
};


#endif //GAMEENGINE_GLMESHTEXTURE_H
