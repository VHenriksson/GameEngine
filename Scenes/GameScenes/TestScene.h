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
#include "GameObjects/Planet.h"
#include "GameObjects/Plupp.h"
#include "GameObjects/Food.h"
#include "GameObjects/Caterpillar.h"

class TestScene : public Scene {
private:
    glm::vec3 sunPosition;
    glm::vec3 rotationVector = glm::vec3(1.0f,0,0);
//    glm::vec3 headPosition = glm::vec3(0,-1.0f,1.0f);
    std::shared_ptr<Planet> planet;
    Caterpillar caterpillar;
    std::shared_ptr<Food> food;
    std::shared_ptr<TexturePhongShader> mainShader;
    int gameIsLostCounter = 0;
    float t = 0;
    glm::mat4 worldPosition = glm::mat4(0.1f);
    bool testFoodCollision();
    void addTail();
protected:
    void updateSceneGlobals() override;
    void setObjects() override;
public:
    void rotateLeft();
    void rotateRight();
    void rotateUp();
    void rotateDown();

    void tickTimeout();

    void reset();

    void tickGame();

    void testCollisions();

    void moveWorld();

    void moveCaterpillar();
};


#endif //GAMEENGINE_TESTSCENE_H
