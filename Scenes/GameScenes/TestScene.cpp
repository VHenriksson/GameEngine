//
// Created by viktor on 2021-02-17.
//

#include "TestScene.h"


void TestScene::shaderSettings(std::shared_ptr<ShaderProgramBase> shader) {
    //TODO in general, test for shader
    glUniform3fv(MAIN_SHADER_SUN_POSITION, 1, glm::value_ptr(sunPosition));
}

void TestScene::setObjects() {
    geometries.set("balls","../spheres.obj");
    balls = std::make_shared<PhongShadedObject>(geometries["balls"]);
    mainShader = std::make_shared<TexturePhongShader>(TexturePhongShader());
    setShader(balls,mainShader);
}
