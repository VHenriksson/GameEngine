//
// Created by viktor on 2021-02-17.
//

#include "TestScene.h"



void TestScene::setObjects() {
    backgroundColour = glm::vec4(0,0.1,0.2,1);
    geometries.setTextured("balls","../spheres.obj");
    balls = std::make_shared<PhongShadedObject>(geometries["balls"]);
    sunPosition = glm::vec3(1,1,0);
    mainShader = std::make_shared<TexturePhongShader>(TexturePhongShader());
    setShader(balls,mainShader);
}

void TestScene::updateSceneGlobals() {
    t+=0.02;
    mainShader->setSunPosition(sunPosition);
    glm::mat4 pos = glm::mat4(cos(t),0, sin(t),0,0,1,0,0,-sin(t),0,cos(t),0,0,0,0,1);
    balls->setPosition(pos);
}
