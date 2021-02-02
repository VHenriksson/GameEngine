//
// Created by viktor on 2021-01-24.
//

#ifndef GAMEENGINE_IMPORTER_H
#define GAMEENGINE_IMPORTER_H


#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <unordered_map>
#include "GLMesh/GLMeshBase.h"
#include "GLMesh/GLMeshTexture.h"
#include "GLMesh/GLMeshColour.h"
#include "Materials/Material.h"

class Importer {
    const aiScene *scene;
    std::unordered_map<unsigned int,Material> materials;
    std::vector<GLMeshTexture> textureMeshes;
    std::vector<GLMeshColour> colourMeshes;

    void processNode(aiNode *node);

    void processMeshes(const aiNode *node);

public:
    Importer(std::string source);
    std::vector<float> getMesh();

    std::vector<unsigned int> getFaces();
};


#endif //GAMEENGINE_IMPORTER_H
