//
// Created by viktor on 2021-02-26.
//

#ifndef GAMEENGINE_FOOD_H
#define GAMEENGINE_FOOD_H


#include "PhongShadedObject.h"

class Food : public PhongShadedObject {
    glm::vec3 position = glm::vec3(0,0.89f,0);
    glm::vec3 testPosition = glm::vec3(0,1.0f,0);
    glm::mat4 rotation = glm::mat4(1.0f);
    glm::vec3 scale = glm::vec3 (0.1f);
    glm::vec3 rotationVector = glm::vec3(1.0f,0,0);
    glm::vec3 headPosition = glm::vec3(0,-1.0f,1.0f);
public:
    Food(std::shared_ptr<Geometry> geometry);
    void rotate();
    glm::vec3 getPosition();
    void appear();
    void turnLeft();
};


#endif //GAMEENGINE_FOOD_H
