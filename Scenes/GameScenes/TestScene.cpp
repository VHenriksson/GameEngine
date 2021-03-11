//
// Created by viktor on 2021-02-17.
//

#include "TestScene.h"
#include "GameObjects/Planet.h"
#include "GameObjects/Food.h"


const int RESET_TIME = 80;

void TestScene::setObjects() {
    backgroundColour = glm::vec4(0,0.1,0.2,1);
    geometries.setTextured("planet","../planet.obj");
    geometries.setTextured("plupp","../plupp.obj");
    geometries.setTextured("food","../food.obj");
    planet = std::make_shared<Planet>(geometries["planet"]);
    food = std::make_shared<Food>(geometries["food"]);
    sunPosition = glm::vec3(1,1,0);
    mainShader = std::make_shared<TexturePhongShader>(TexturePhongShader());
    setShader(planet,mainShader);
    setShader(food,mainShader);
    mainShader->setWorldPosition(glm::mat4(1.0f));
    mainShader->setSunPosition(sunPosition);
    food->appear();
    caterpillar.setGeometry(geometries["plupp"], geometries["plupp"]);
    setShader(caterpillar.getHead(),mainShader);

}

void TestScene::updateSceneGlobals() {
    if(gameIsLostCounter){
        tickTimeout();
    } else {
        tickGame();
    }
}

void TestScene::tickGame() {
    moveWorld();
    moveCaterpillar();
    testCollisions();
}

void TestScene::moveCaterpillar() {
//    headPosition = glm::rotate(headPosition, 0.015f, rotationVector);
    caterpillar.move(rotationVector);
}

void TestScene::moveWorld() {
    worldPosition = glm::rotate(worldPosition, -0.015f, rotationVector);
    mainShader->setWorldPosition(worldPosition);
}

void TestScene::testCollisions() {
    if(testFoodCollision()){
        food->appear();
        addTail();
    }
    if(caterpillar.testCollisson()){
        gameIsLostCounter = 1;
    }
}

void TestScene::tickTimeout() {
    gameIsLostCounter++;
    if(gameIsLostCounter == RESET_TIME){
        reset();
    }
}

void TestScene::reset() {
    gameIsLostCounter = 0;
    for(std::shared_ptr<Plupp> tailPlupp : caterpillar){
        removeFromShader(tailPlupp, mainShader);
    }
    caterpillar.reset();
}

void TestScene::rotateLeft() {
    if(!gameIsLostCounter){
        worldPosition = glm::rotate(worldPosition,-0.1f,caterpillar.getHeadPosition());
        rotationVector = glm::rotate(rotationVector,0.1f,caterpillar.getHeadPosition());
        caterpillar.rotate(0.1f);
    }
}

void TestScene::rotateRight() {
    if(!gameIsLostCounter){
        worldPosition = glm::rotate(worldPosition,0.1f,caterpillar.getHeadPosition());
        rotationVector = glm::rotate(rotationVector,-0.1f,caterpillar.getHeadPosition());
        caterpillar.rotate(0.1f);
    }
}

void TestScene::rotateUp() {
//    pos = glm::rotate(pos,0.1f,glm::vec3(1.0f,0,0));
}

void TestScene::rotateDown() {
//    pos = glm::rotate(pos,-0.1f,glm::vec3(1.0f,0,0));
}

bool TestScene::testFoodCollision() {
    double closeness = glm::dot(caterpillar.getHeadPosition(),-glm::normalize(food->getPosition()));
    return closeness > 0.988;
}

void TestScene::addTail() {
    caterpillar.extend();
    setShader(caterpillar.getEnd(), mainShader);
}




