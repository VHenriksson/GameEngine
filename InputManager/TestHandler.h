//
// Created by viktor on 2021-02-24.
//

#ifndef GAMEENGINE_TESTHANDLER_H
#define GAMEENGINE_TESTHANDLER_H


#include "InputManagerBase.h"
#include "../Scenes/GameScenes/TestScene.h"
#include <memory>

class TestHandler : public InputManagerBase {
private:
    void handleRIGHT() override;
    void handleDOWN() override;
    void handleQUIT() override;
    void handleLEFT() override;
    void handleUP() override;
    void handleLEFT_ROTATE() override;
    void handleRIGHT_ROTATE() override;
    std::shared_ptr<TestScene> scene;
    bool *endScene;
public:
    TestHandler(std::shared_ptr<TestScene> scene, bool *endScene);
};





#endif //GAMEENGINE_TESTHANDLER_H
