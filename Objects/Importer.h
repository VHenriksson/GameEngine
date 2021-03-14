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
#include "MaterialList.h"


class Importer {
    const aiScene *scene;
    std::vector<std::shared_ptr<GLMeshBase>> meshes;
    std::vector<GLMeshTexture> textureMeshes;
    void processNode(aiNode *node);
    void processMeshes(const aiNode *node);
    void addTextureMesh(aiMesh *mesh);
public:
    Importer(std::string source);
    std::vector<std::shared_ptr<GLMeshBase>> getMeshes();
};


#endif //GAMEENGINE_IMPORTER_H
