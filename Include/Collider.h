#pragma once

#include "SDL2/SDL.h"

class Collider {
  public:
    Collider(int x, int y, int w, int h);
    SDL_Rect getHitbox();
    void update(int x, int y, int w, int h);
    void setBuffer(int x, int y, int w, int h);

  private:
    SDL_Rect hitbox;
    SDL_Rect buffer;
};
