//
// Created by viktor on 2021-02-25.
//

#include "Plupp.h"

Plupp::Plupp(std::shared_ptr<Geometry> geometry) : PhongShadedObject(geometry) {
    position = glm::rotate(position,glm::radians(-45.0f),glm::vec3(0.1f,0,0)); //TODO It seems to me like I am rotating in the wrong direction here??
    position = glm::translate(position,glm::vec3(0,0.89f,0));
    position = glm::scale(position,glm::vec3(0.1f));
    setPosition(position);
}

void Plupp::rotate(glm::vec3 rotationVector, float radians) {
    position = glm::rotate(glm::mat4(1.0f),radians,rotationVector) * position;
    setPosition(position);
}

Plupp::Plupp(std::shared_ptr<Geometry> geometry, glm::mat4 position) : PhongShadedObject(geometry) {
    this->position = position;
    setPosition(position);
}

glm::mat4 Plupp::getPosition() {
    return position;
}

void Plupp::place(glm::mat4 position) {
    this->position = position;
    setPosition(position);
}

