#pragma once

#include "SDL2/SDL.h"
#include <string>

class Animation {
  public:
    Animation(std::string textureID, int spriteRow, int frameCount, int animationSpeed, SDL_RendererFlip flip);
    void update();
    void draw(float x, float y, int w, int h);
  
  private:
    std::string textureID;
    int spriteRow, spriteFrame, frameCount, animationSpeed;
    SDL_RendererFlip flip;
};
