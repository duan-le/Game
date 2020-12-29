#pragma once

#include "SDL2/SDL.h"
#include "Entity.h"
#include "Transform.h"
#include <string>

class GameObject : public Entity {
  public:
    GameObject(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip = SDL_FLIP_NONE) :
      textureID(textureID), w(w), h(h), flip(flip) {
        t = new Transform(x, y);
    }
    virtual ~GameObject() {delete t;}
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void clean() = 0;

  protected:
    std::string textureID;
    int w, h;
    SDL_RendererFlip flip;
    Transform* t;
};
