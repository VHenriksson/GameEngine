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

class GameEngine {
private:
    GLwindow window = GLwindow(1000,1000);
    void tryRun();
    bool endCurrentScene = false;
    std::shared_ptr<Scene> currentScene;
    std::shared_ptr<InputManagerBase> currentInputManager;
    void runScene();
public:
    GameEngine();
};


#endif //GAMEENGINE_GAMEENGINE_H
