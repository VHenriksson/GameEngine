//
// Created by viktor on 2021-03-12.
//

#ifndef GAMEENGINE_GAMEPART_H
#define GAMEENGINE_GAMEPART_H
#include "Scenes/Scene.h"
#include "InputManager/InputManagerBase.h"
#include "GamePartBase.h"

template <class SceneType,class InputManagerType>

class GamePart : public GamePartBase {
public:
    GamePart(){
        scene = std::make_shared<SceneType>(SceneType());
        inputManager = std::make_shared<InputManagerType>(InputManagerType(std::dynamic_pointer_cast<SceneType>(scene)));
    };
};


#endif //GAMEENGINE_GAMEPART_H
