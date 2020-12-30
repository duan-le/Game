#pragma once

class Vector {
  public:
    Vector(float x = 0, float y = 0);
    Vector operator+(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    Vector operator*(const float& rhs);
    float getX();
    float getY();

  private:
    float x, y;
};
