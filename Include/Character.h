#pragma once

#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Animation.h"
#include <string>

class Character : public GameObject {
  public:
    Character(std::string textureID, int x, int y, int w, int h, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
    ~Character();
    virtual void update();
    virtual void draw();
    virtual void clean();
  
  private:
    std::string name;
    Animation* animation;
};
