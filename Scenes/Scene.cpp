//
// Created by viktor on 2021-02-17.
//

#include <set>
#include <memory>
#include "Scene.h"
#include "../Objects/TexturedGeometry.h"

void Scene::loadTextures() {
    for (std::pair<unsigned long, std::shared_ptr<Geometry>> objectPair : geometries) {
        for(std::shared_ptr<GLMeshBase> mesh : *objectPair.second){
            std::shared_ptr<GLMeshTexture> texMesh = std::dynamic_pointer_cast<GLMeshTexture>(mesh);
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

void Scene::load() {
    setScene();
    loadTextures();
    for(std::pair<size_t, std::shared_ptr<Geometry>> pair : geometries){
        std::shared_ptr<Geometry> geometry = pair.second;
        geometry->initialize();
    }
}

void Scene::draw() {
    glClearColor(backgroundColour[0],backgroundColour[1],backgroundColour[2],backgroundColour[3]);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    tickScene();
    for(std::pair<std::shared_ptr<ShaderProgramBase>,std::pair<std::shared_ptr<ShaderProgramBase>,std::set<std::shared_ptr<Object>>>> pair : renderList){
        std::shared_ptr<ShaderProgramBase> shader = pair.second.first;
        shader->use();
        for(std::shared_ptr<Object> object : pair.second.second){
            object->draw();
        }
    }
}

void Scene::setShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader) {
    if(!renderList.shaderSet(shader)){
        renderList.setShader(shader);
    }
    renderList.renderUsing(object,shader);
    object->setShader(shader);
}

void Scene::removeFromShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader) {
    if(!renderList.shaderSet(shader)){
        throw std::runtime_error("Trying to remove object from shader which has not been set.");
    }
    renderList.remove(object,shader);
}



