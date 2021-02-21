//
// Created by viktor on 2021-02-21.
//

#ifndef GAMEENGINE_PHONGSHADEDOBJECT_H
#define GAMEENGINE_PHONGSHADEDOBJECT_H


#include "../../../Objects/Object.h"
#include "../../../Objects/PhongShadedGeometry.h"

class PhongShadedObject : public Object {
private:
    glm::mat4 position;
public:
    PhongShadedObject(std::shared_ptr<Geometry> geometry);
    void setupDraw() override;
};


#endif //GAMEENGINE_PHONGSHADEDOBJECT_H
