//
// Created by viktor on 2021-01-17.
//

#ifndef GAMEENGINE_GAMEENGINE_H
#define GAMEENGINE_GAMEENGINE_H

#include <memory>
#include <unordered_map>
#include "Scenes/Scene.h"
#include "WindowHandling/GLwindow.h"
#include "InputManager/InputManagerBase.h"
#include "GamePart.h"

class GameEngine {
private:
    GLwindow window = GLwindow(1000,1000);
    void run(GamePartBase part);
public:
    GameEngine();

    void runLoop(GamePartBase part);
};


#endif //GAMEENGINE_GAMEENGINE_H
