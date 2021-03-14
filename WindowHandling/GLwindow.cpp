//
// Created by viktor on 2021-01-29.
//

#include <iostream>
#include "GLwindow.h"
GLwindow::GLwindow() {
    setup();
}

void GLwindow::setup() {
    try {
        initializeSDLVideo();
        createSDLWindow();
        createGLContext();
    } catch (std::exception& e) {
        throw std::runtime_error("Failed to start SDL-Runner!\n" + std::string(e.what()));
    }
}


void GLwindow::initializeSDLVideo() {
    if(SDL_Init(SDL_INIT_VIDEO ) < 0 )
    {
        throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
    }
}

void GLwindow::updateWindow() {
    SDL_GL_SwapWindow(window);
}

GLwindow::GLwindow(int screenWidth, int screenHeight) {
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    setup();
}


void GLwindow::createSDLWindow() {
    window = SDL_CreateWindow("TITLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenHeight, screenWidth, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        throw std::runtime_error("GLwindow could not be created! SDL_Error: " + std::string(SDL_GetError()));
    }
}

GLwindow::~GLwindow() {
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void GLwindow::createGLContext() {
    context = std::make_shared<GLContext>(window);
}




