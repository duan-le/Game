#pragma once

#include "SDL2/SDL.h"
#include "GameObject.h"
#include "Animation.h"
#include <string>

class Character : public GameObject {
  public:
    Character(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE);
    ~Character();
    virtual void update();
    virtual void draw();
    virtual void clean();
  
  private:
    std::string name;
    Animation* a;
};
