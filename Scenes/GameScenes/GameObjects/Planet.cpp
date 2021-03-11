//
// Created by viktor on 2021-02-25.
//

#include "Planet.h"

Planet::Planet(std::shared_ptr <Geometry> geometry) : PhongShadedObject(geometry) {
    setPosition(position);
}

void Planet::rotate() {
    position = glm::rotate(position,-0.01f,rotationVector);
    headPosition = glm::rotate(headPosition,0.01f,rotationVector);
}

void Planet::turnRight() {
    headPosition = glm::rotate(headPosition,0.05f,headPosition);
    position = glm::rotate(position,0.05f,headPosition);
    rotationVector = glm::rotate(rotationVector,-0.05f,headPosition);
}

void Planet::turnLeft() {
    headPosition = glm::rotate(headPosition,-0.05f, headPosition);
    position = glm::rotate(position,-0.05f,headPosition);
    rotationVector = glm::rotate(rotationVector,0.05f,headPosition);
}

