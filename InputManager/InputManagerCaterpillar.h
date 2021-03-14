//
// Created by viktor on 2021-02-24.
//

#ifndef GAMEENGINE_INPUTMANAGERCATERPILLAR_H
#define GAMEENGINE_INPUTMANAGERCATERPILLAR_H


#include "InputManagerBase.h"
#include "../Scenes/GameScenes/CaterpillarScene.h"
#include <memory>

class InputManagerCaterpillar : public InputManagerBase {
private:
    void handleRIGHT() override;
    void handleDOWN() override;
    void handleQUIT() override;
    void handleLEFT() override;
    void handleUP() override;
    void handleSPACE() override;
    std::shared_ptr<CaterpillarScene> scene;
public:
    InputManagerCaterpillar(std::shared_ptr<CaterpillarScene> scene);
};





#endif //GAMEENGINE_INPUTMANAGERCATERPILLAR_H
