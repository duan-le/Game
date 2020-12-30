#pragma once

#include "SDL2/SDL.h"
#include "Entity.h"
#include "Transform.h"
#include <string>

class GameObject : public Entity {
  public:
    GameObject(std::string textureID, int x, int y, int w, int h, int scale = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
    virtual ~GameObject();
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void clean() = 0;

  protected:
    std::string textureID;
    int w, h;
    int scale; // Scales the sprite to be displayed by renderer
    SDL_RendererFlip flip;
    Transform* transform;
};
