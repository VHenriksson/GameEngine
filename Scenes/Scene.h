//
// Created by viktor on 2021-02-17.
//

#ifndef GAMEENGINE_SCENE_H
#define GAMEENGINE_SCENE_H


#include "SceneGeometries.h"
#include "ShaderProgramList.h"
#include "RenderingList.h"

class Scene {
private:
    void loadTextures();
protected:
    RenderingList renderList;
    TextureList materials;
    SceneGeometries geometries;
    glm::vec4 backgroundColour;
    virtual void updateSceneGlobals() = 0;
    virtual void setObjects() = 0;
    void setShader(std::shared_ptr<Object> object, std::shared_ptr<ShaderProgramBase> shader);
public:
    void draw();
    void load();

};


#endif //GAMEENGINE_SCENE_H
