//
// Created by viktor on 2021-02-21.
//

#ifndef GAMEENGINE_PHONGSHADEDOBJECT_H
#define GAMEENGINE_PHONGSHADEDOBJECT_H


#include "../../../Objects/Object.h"
#include "../../../Objects/PhongShadedGeometry.h"
#include "../../../Shading/TexturePhongShader.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>

class PhongShadedObject : public Object {
private:
    glm::mat4 position;
    std::shared_ptr<TexturePhongShader> shader;
public:
    PhongShadedObject(std::shared_ptr<Geometry> geometry);
    void setupDraw() override;
    void setupForMesh(std::shared_ptr<GLMeshBase> mesh) override;
    void setPosition(glm::mat4 position);
    void setShader(std::shared_ptr<ShaderProgramBase> shader) override;
};


#endif //GAMEENGINE_PHONGSHADEDOBJECT_H
