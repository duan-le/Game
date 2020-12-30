#include "Vector.h"

Vector::Vector(float x, float y) :
  x(x), y(y) {}

Vector Vector::operator+(const Vector& rhs) {
  return Vector(x + rhs.x, y + rhs.y);
}

Vector Vector::operator-(const Vector& rhs) {
  return Vector(x - rhs.x, y - rhs.y);
}

Vector Vector::operator*(const float& rhs) {
  return Vector(x * rhs, y * rhs);
}

float Vector::getX() {
  return x;
}

float Vector::getY() {
  return y;
}
