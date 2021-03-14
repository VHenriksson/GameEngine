//
// Created by viktor on 2021-03-12.
//

#ifndef GAMEENGINE_GAMEPARTBASE_H
#define GAMEENGINE_GAMEPARTBASE_H


#include <memory>
#include "Scenes/Scene.h"
#include "InputManager/InputManagerBase.h"

class GamePartBase {
protected:
    bool endScene = false;
    std::shared_ptr<Scene> scene;
    std::shared_ptr<InputManagerBase> inputManager;
public:
    virtual void setup();
    virtual void run();
    virtual bool endPart();
};


#endif //GAMEENGINE_GAMEPARTBASE_H
