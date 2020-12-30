#include "Transform.h"

Transform::Transform(float x, float y) :
  x(x), y(y) {}

void Transform::translateX(float &x) {
  this->x += x;
}
    
void Transform::translateY(float &y) {
  this->y += y;
}

void Transform::translate(Vector& v) {
  x += v.getX();
  y += v.getY();
}

float Transform::getX() {
  return x;
}

float Transform::getY() {
  return y;
}
