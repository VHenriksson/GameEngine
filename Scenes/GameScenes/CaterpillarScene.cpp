//
// Created by viktor on 2021-02-17.
//

#include "CaterpillarScene.h"
#include "GameObjects/Planet.h"
#include "GameObjects/Food.h"


const int RESET_TIME = 80;

void CaterpillarScene::setScene() {
    mainShader = std::make_shared<TexturePhongShader>(TexturePhongShader());
    setupWorld();
    setupPlanet();
    setupFood();
    setupCaterpillar();
}

void CaterpillarScene::setupWorld() {
    backgroundColour = glm::vec4(0, 0.1, 0.2, 1);
    mainShader->setWorldPosition(glm::mat4(1.0f));
    sunPosition = glm::vec3(1, 1, 0);
    mainShader->setSunPosition(sunPosition);
}

void CaterpillarScene::setupPlanet() {
    geometries.setTextured("planet", "planet.obj");
    planet = std::make_shared<Planet>(geometries["planet"]);
    setShader(planet, mainShader);
}

void CaterpillarScene::setupFood() {
    geometries.setTextured("food", "food.obj");
    food = std::make_shared<Food>(geometries["food"]);
    setShader(food, mainShader);
    food->appear();
}

void CaterpillarScene::setupCaterpillar() {
    geometries.setTextured("plupp", "plupp.obj");
    caterpillar.setGeometry(geometries["plupp"], geometries["plupp"]);
    setShader(caterpillar.getHead(), mainShader);
}

void CaterpillarScene::tickScene() {
    if(gameIsLostCounter){
        tickTimeout();
    } else {
        tickGame();
    }
}

void CaterpillarScene::tickGame() {
    moveWorld();
    moveCaterpillar();
    testCollisions();
}

void CaterpillarScene::moveCaterpillar() {
    caterpillar.move(rotationVector);
}

void CaterpillarScene::moveWorld() {
    worldPosition = glm::rotate(worldPosition, -0.015f, rotationVector);
    mainShader->setWorldPosition(worldPosition);
}

void CaterpillarScene::testCollisions() {
    if(testFoodCollision()){
        food->appear();
        addTail();
    }
    if(caterpillar.testCollisson()){
        gameIsLostCounter = 1;
    }
}

void CaterpillarScene::tickTimeout() {
    gameIsLostCounter++;
    if(gameIsLostCounter == RESET_TIME){
        reset();
    }
}

void CaterpillarScene::reset() {
    gameIsLostCounter = 0;
    for(std::shared_ptr<Plupp> tailPlupp : caterpillar){
        removeFromShader(tailPlupp, mainShader);
    }
    caterpillar.reset();
}

void CaterpillarScene::rotateLeft() {
    if(!gameIsLostCounter){
        worldPosition = glm::rotate(worldPosition,0.1f,caterpillar.getHeadPosition());
        rotationVector = glm::rotate(rotationVector,-0.1f,caterpillar.getHeadPosition());
        caterpillar.rotate(-0.1f);
    }
}

void CaterpillarScene::rotateRight() {
    if(!gameIsLostCounter){
        worldPosition = glm::rotate(worldPosition,-0.1f,caterpillar.getHeadPosition());
        rotationVector = glm::rotate(rotationVector,0.1f,caterpillar.getHeadPosition());
        caterpillar.rotate(0.1f);
    }
}

void CaterpillarScene::rotateUp() {
//    pos = glm::rotate(pos,0.1f,glm::vec3(1.0f,0,0));
}

void CaterpillarScene::rotateDown() {
//    pos = glm::rotate(pos,-0.1f,glm::vec3(1.0f,0,0));
}

bool CaterpillarScene::testFoodCollision() {
    double closeness = glm::dot(caterpillar.getHeadPosition(),glm::normalize(food->getPosition()));
    return closeness > 0.988;
}

void CaterpillarScene::addTail() {
    caterpillar.extend();
    setShader(caterpillar.getEnd(), mainShader);
}

void CaterpillarScene::hidePlanet() {
    if (planetVisible){
        removeFromShader(planet,mainShader);
        planetVisible = false;
    } else {
        setShader(planet,mainShader);
        planetVisible = true;
    }
}




