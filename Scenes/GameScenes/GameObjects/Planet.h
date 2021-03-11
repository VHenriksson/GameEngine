//
// Created by viktor on 2021-02-25.
//

#ifndef GAMEENGINE_PLANET_H
#define GAMEENGINE_PLANET_H


#include <memory>
#include "../../../Objects/Geometry.h"
#include "PhongShadedObject.h"

class Planet : public PhongShadedObject {
    glm::mat4 position = glm::mat4(1.0f);
    glm::vec3 rotationVector = glm::vec3(1.0f,0,0);
    glm::vec3 headPosition = glm::vec3(0,-1.0f,1.0f);
public:
    Planet(std::shared_ptr<Geometry> geometry);
    void rotate();
    void turnRight();
    void turnLeft();
};


#endif //GAMEENGINE_PLANET_H
