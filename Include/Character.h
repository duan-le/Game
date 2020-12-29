#pragma once

#include "GameObject.h"
#include <string>

class Character : public GameObject {
  public:
    Character(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE) :
      GameObject(textureID, x, y, w, h, flip) {}
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void clean() = 0;
  
  protected:
    std::string name;
};
