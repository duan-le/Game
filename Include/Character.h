#pragma once

#include "SDL2/SDL.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <string>

class Character : public GameObject {
  public:
    Character(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual void update();
    virtual void draw();
    virtual void clean();
  
  private:
    std::string name;
    int row, frame, frameCount, animationSpeed;
};
