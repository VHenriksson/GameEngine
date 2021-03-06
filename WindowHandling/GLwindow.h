//
// Created by viktor on 2021-01-29.
//

#ifndef GAMEENGINE_GLWINDOW_H
#define GAMEENGINE_GLWINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include "GLContext.h"

class GLwindow {
private:
    int screenWidth = 1000;
    int screenHeight = 1000;
    std::shared_ptr<GLContext> context;
    void setup();
    void createSDLWindow();
    void createGLContext();
    SDL_Window * window = NULL;
public:
    GLwindow();
    GLwindow(int screenWidth, int screenHeight);
    ~GLwindow();
    void initializeSDLVideo();
    void updateWindow();
};


#endif //GAMEENGINE_GLWINDOW_H
