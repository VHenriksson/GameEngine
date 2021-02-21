//
// Created by viktor on 2021-02-17.
//

#include <set>
#include "Scene.h"
#include "../Objects/TexturedGeometry.h"

void Scene::loadTextures() {
    for (std::pair<unsigned long, std::shared_ptr<Geometry>> objectPair : geometries) {
        std::shared_ptr<TexturedGeometry> texGeometry = dynamic_pointer_cast<TexturedGeometry>(objectPair.second);
        if (texGeometry){
            for(std::shared_ptr<GLMeshBase> mesh : *texGeometry){
                std::shared_ptr<GLMeshTexture> texMesh = dynamic_pointer_cast<GLMeshTexture>(objectPair.second);
                if (texMesh){
                    if (materials.notSet(texMesh->getMaterialID())){
                        texMesh->getMaterial()->load();
                        materials.set(texMesh->getMaterialID(), texMesh->getMaterial());
                    } else {
                        texMesh->setMaterial(materials.get(texMesh->getMaterialID()));
                    }
                }
            }
        }
    }
}

void Scene::load() {
    loadTextures();
}

void Scene::draw() {
    glClearColor(backgroundColour[0],backgroundColour[1],backgroundColour[2],backgroundColour[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(std::pair<std::shared_ptr<ShaderProgramBase>,std::pair<std::shared_ptr<ShaderProgramBase>,std::set<std::shared_ptr<Object>>>> pair : renderList){
        std::shared_ptr<ShaderProgramBase> shader = pair.second.first;
        shader->use();
        shaderSettings(shader);
        for(std::shared_ptr<Object> object : pair.second.second){
            object->draw();
        }
    }
}

void Scene::setShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader) {
    renderList.renderUsing(object,shader);
}


