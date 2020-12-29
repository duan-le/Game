#pragma once

class Vector {
  public:
    Vector(float x = 0, float y = 0) : x(x), y(y) {}
    Vector operator+(const Vector& rhs) {
      return Vector(x + rhs.x, y + rhs.y);
    }
    Vector operator-(const Vector& rhs) {
      return Vector(x - rhs.x, y - rhs.y);
    }
    Vector operator*(const float& rhs) {
      return Vector(x * rhs, y * rhs);
    }
    float getX() {return x;}
    float getY() {return y;}

  private:
    float x, y;
};
