#include "Collider.h"

Collider::Collider(int x, int y, int w, int h) :
  hitbox({x, y, w, h}), buffer({0, 0, 0, 0}) {}

SDL_Rect Collider::getHitbox() {
  return hitbox;
}

void Collider::update(int x, int y, int w, int h) {
  hitbox.x = x + buffer.x;
  hitbox.y = y + buffer.y;
  hitbox.w = w + buffer.w;
  hitbox.h = h + buffer.h;
}

void Collider::setBuffer(int x, int y, int w, int h) {
  buffer.x = x;
  buffer.y = y;
  buffer.w = w;
  buffer.h = h;
}
