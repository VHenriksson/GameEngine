//
// Created by viktor on 2021-02-25.
//

#ifndef GAMEENGINE_PLUPP_H
#define GAMEENGINE_PLUPP_H


#include <memory>
#include <list>
#include "../../../Objects/Geometry.h"
#include "PhongShadedObject.h"

class Plupp : public PhongShadedObject {
private:
    glm::mat4 position = glm::mat4(1.0f);
public:
    Plupp(std::shared_ptr<Geometry> geometry);
    Plupp(std::shared_ptr<Geometry> geometry,glm::mat4 position);
    glm::mat4 getPosition();
    void place(glm::mat4 position);
    void rotate(glm::vec3 rotationVector,float radians);

};


#endif //GAMEENGINE_PLUPP_H
