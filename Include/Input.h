#pragma once

#include "SDL2/SDL.h"

class Input {
  public:
    static Input* getInstance();
    void listen();
    bool getKeyDown(SDL_Scancode key);

  private:
    Input();
    void keyUp();
    void keyDown();
    const Uint8* keyStates;
    static Input* instance;
};
