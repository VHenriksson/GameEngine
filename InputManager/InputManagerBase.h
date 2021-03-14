//
// Created by viktor on 2021-02-24.
//

#ifndef GAMEENGINE_INPUTMANAGERBASE_H
#define GAMEENGINE_INPUTMANAGERBASE_H


#include <SDL2/SDL_events.h>

class InputManagerBase {
protected:
    bool shouldQuit;
    SDL_Event event;
    unsigned int keyDown = 0;
    virtual void handleQUIT(){};
    virtual void handleUP(){};
    virtual void handleDOWN(){};
    virtual void handleRIGHT(){};
    virtual void handleLEFT(){};
    virtual void handleLEFT_ROTATE(){};
    virtual void handleRIGHT_ROTATE(){};
    virtual void handleSPACE(){};
public:
    void handleInputs();
    bool getQuitStatus();

    void checkKeyPressed();

    void doKeyMethod();
};



#endif //GAMEENGINE_INPUTMANAGERBASE_H
