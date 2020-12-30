#pragma once

#include "SDL2/SDL.h"
#include <string>

class Animation {
  public:
    Animation(std::string textureID, int spriteRow, int frameCount, int animationSpeed);
    void update();
    void draw(float x, float y, int w, int h, int scale, SDL_RendererFlip flip);
  
  private:
    std::string textureID;
    int spriteRow, spriteFrame, frameCount, animationSpeed;
};
