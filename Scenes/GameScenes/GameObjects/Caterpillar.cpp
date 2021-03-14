//
// Created by viktor on 2021-02-28.
//

#include "Caterpillar.h"
#include <memory>

void Caterpillar::setGeometry(std::shared_ptr<Geometry> bodyGeometry, std::shared_ptr<Geometry> headGeometry) {
    this->geometry = bodyGeometry;
    head = std::make_shared<Plupp>(headGeometry);
}

void Caterpillar::extend() {
    glm::mat4 position;
    if(this->empty()){
        position = head->getPosition();
    } else {
        position = this->at(this->size() - 1)->getPosition();
    }
    std::shared_ptr<Plupp> plupp = std::make_shared<Plupp>(geometry,position);
    this->push_back(plupp);
    std::list<glm::mat4> l;
    for(int i = 0; i < 10; i++){
        l.emplace_back(0);
    }
    positionChain.push_back(l);
}

void Caterpillar::move(glm::vec3 rotationVector) {
    head->rotate(rotationVector,0.015f);
    glm::mat4 position = head->getPosition();
    for(int i = 0; i < this->size(); i++){
        positionChain[i].push_front(position);
        position = positionChain[i].back();
        positionChain[i].pop_back();
        if (position != glm::mat4(0)){
            this->at(i)->place(position);
        }
    }
}

std::shared_ptr<Object> Caterpillar::getEnd() {
    return this->at(this->size()-1);
}

bool Caterpillar::testCollisson() {
    for(int i = 1; i < this->size(); i++){
        glm::vec3 pluppPosition = glm::mat3(this->at(i)->getPosition()) * glm::vec3(0,1,0);
        double closeness = glm::dot(getHeadPosition(),glm::normalize(pluppPosition));
        if ( closeness > 0.99 ){
            return true;
        }
    }
    return false;
}

void Caterpillar::reset() {
    this->clear();
    positionChain.clear();
}

void Caterpillar::rotate(float radians) {
    head->rotate(getHeadPosition(),radians);
}

std::shared_ptr<Plupp> Caterpillar::getHead() {
    return head;
}

glm::vec3 Caterpillar::getHeadPosition() {
    return glm::normalize(glm::vec3(head->getPosition() * glm::vec4(0,1,0,1)));
}

