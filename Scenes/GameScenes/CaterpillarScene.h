//
// Created by viktor on 2021-02-17.
//

#ifndef GAMEENGINE_CATERPILLARSCENE_H
#define GAMEENGINE_CATERPILLARSCENE_H


#include <unordered_map>
#include "../Scene.h"
#include "../../Shading/TexturePhongShader.h"
#include "../../Objects/MaterialList.h"
#include "GameObjects/PhongShadedObject.h"
#include "GameObjects/Planet.h"
#include "GameObjects/Plupp.h"
#include "GameObjects/Food.h"
#include "GameObjects/Caterpillar.h"

class CaterpillarScene : public Scene {
private:
    bool planetVisible = true;
    glm::vec3 sunPosition;
    glm::vec3 rotationVector = glm::vec3(1.0f,0,0);
    std::shared_ptr<Planet> planet;
    Caterpillar caterpillar;
    std::shared_ptr<Food> food;
    std::shared_ptr<TexturePhongShader> mainShader;
    int gameIsLostCounter = 0;
    float t = 0;
    glm::mat4 worldPosition = glm::mat4(0.1f);
    bool testFoodCollision();
    void addTail();
    void tickTimeout();
    void reset();
    void tickGame();
    void testCollisions();
    void moveWorld();
    void moveCaterpillar();
    void setupCaterpillar();
    void setupFood();
    void setupPlanet();
    void setupWorld();
protected:
    void tickScene() override;
    void setScene() override;
public:
    void rotateLeft();
    void rotateRight();
    void rotateUp();
    void rotateDown();
    void hidePlanet();
};


#endif //GAMEENGINE_CATERPILLARSCENE_H
