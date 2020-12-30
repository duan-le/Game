#include "GameObject.h"

GameObject::GameObject(std::string textureID, int x, int y, int w, int h, SDL_RendererFlip flip) :
  textureID(textureID), w(w), h(h), flip(flip) {
    t = new Transform(x, y);
}

GameObject::~GameObject() {
  delete t;
}
