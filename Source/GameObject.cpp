#include "GameObject.h"

GameObject::GameObject(std::string textureID, int x, int y, int w, int h, int scale, SDL_RendererFlip flip) :
  textureID(textureID), w(w), h(h), scale(scale), flip(flip) {
    transform = new Transform(x, y);
    origin = new Vector(x + w / 2, y + h / 2);
}

GameObject::~GameObject() {
  delete transform;
  delete origin;
}

Vector* GameObject::getOrigin() {
  return origin;
}
