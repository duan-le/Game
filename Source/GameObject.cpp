#include "GameObject.h"

GameObject::GameObject(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  textureID(textureID), w(w), h(h), scale(scale), flip(flip) {
    transform = new Transform(x, y);
}

GameObject::~GameObject() {
  delete transform;
}
