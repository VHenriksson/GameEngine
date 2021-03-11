//
// Created by viktor on 2021-02-28.
//

#ifndef GAMEENGINE_CATERPILLAR_H
#define GAMEENGINE_CATERPILLAR_H


#include <vector>
#include <list>
#include "Plupp.h"

class Caterpillar : public std::vector<std::shared_ptr<Plupp>> {
    std::shared_ptr<Geometry> geometry;
    std::shared_ptr<Plupp> head;
    std::vector<std::list<glm::mat4>> positionChain;
public:
    void extend();
    std::shared_ptr<Object> getEnd();
    bool testCollisson();
    void rotate(float radians);
    void reset();
    void move(glm::vec3 rotationsVector);
    void setGeometry(std::shared_ptr<Geometry> bodyGeometry, std::shared_ptr<Geometry> headGeometry);
    glm::vec3 getHeadPosition();

    std::shared_ptr<Plupp> getHead();
};


#endif //GAMEENGINE_CATERPILLAR_H
