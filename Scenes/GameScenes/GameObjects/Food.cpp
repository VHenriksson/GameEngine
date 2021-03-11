//
// Created by viktor on 2021-02-26.
//

#include "Food.h"

Food::Food(std::shared_ptr <Geometry> geometry) : PhongShadedObject(geometry) {
}

void Food::rotate() {
    position = glm::rotate(position,-0.01f,rotationVector);
    rotation = glm::rotate(rotation,-0.01f,rotationVector);
    headPosition = glm::rotate(headPosition,0.01f,rotationVector);
}


void Food::turnLeft() {
    headPosition = glm::rotate(headPosition,-0.05f, headPosition);
    position = glm::rotate(position,-0.05f,headPosition);
    rotationVector = glm::rotate(rotationVector,0.05f,headPosition);
}

glm::vec3 Food::getPosition() {
    return glm::mat3(rotation) * testPosition;
}

void Food::appear() {
    glm::vec3 rotationVector = glm::normalize(glm::vec3(rand(),rand(),rand()));
    rotation = glm::rotate(glm::mat4(1.0f),3.0f,rotationVector);
    glm::mat4 positioner = glm::scale(glm::translate(rotation,position),scale);
    setPosition(positioner);
}

