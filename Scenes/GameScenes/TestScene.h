//
// Created by viktor on 2021-02-17.
//

#ifndef GAMEENGINE_TESTSCENE_H
#define GAMEENGINE_TESTSCENE_H


#include <unordered_map>
#include "../Scene.h"
#include "../../Shading/TexturePhongShader.h"
#include "../../Objects/TextureList.h"
#include "GameObjects/PhongShadedObject.h"

class TestScene : public Scene {
private:
    glm::vec3 sunPosition;
    std::shared_ptr<PhongShadedObject> balls;
    std::shared_ptr<TexturePhongShader> mainShader;
protected:
    void shaderSettings(std::shared_ptr<ShaderProgramBase> shader) override;
    void setObjects() override;
public:
    TestScene();

};


#endif //GAMEENGINE_TESTSCENE_H
