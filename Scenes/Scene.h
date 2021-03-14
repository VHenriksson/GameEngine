//
// Created by viktor on 2021-02-17.
//

#ifndef GAMEENGINE_SCENE_H
#define GAMEENGINE_SCENE_H


#include "GeometryList.h"
#include "RenderingList.h"

class Scene {
private:
    void loadTextures();
protected:
    RenderingList renderList;
    MaterialList materials;
    GeometryList geometries;
    glm::vec4 backgroundColour;
    virtual void tickScene() = 0;
    virtual void setScene() = 0;
    void setShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader);
    void removeFromShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader);
public:
    void draw();
    void load();
};


#endif //GAMEENGINE_SCENE_H
