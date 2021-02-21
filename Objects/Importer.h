//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_IMPORTER_H
#define GAMEENGINE_IMPORTER_H


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <unordered_map>
#include <memory>
#include "GLMesh/GLMeshBase.h"
#include "GLMesh/GLMeshTexture.h"
#include "GLMesh/GLMeshColour.h"
#include "TextureList.h"


class Importer {
    const aiScene *scene;
    std::vector<std::shared_ptr<GLMeshBase>> meshes;
    std::vector<GLMeshTexture> textureMeshes;
    std::vector<GLMeshColour> colourMeshes;

    void processNode(aiNode *node);

    void processMeshes(const aiNode *node);

public:
    Importer(std::string source);
    GLMeshTexture getMesh();
    std::vector<std::shared_ptr<GLMeshBase>> getMeshes();
    std::vector<unsigned int> getFaces();
};


#endif //GAMEENGINE_IMPORTER_H
