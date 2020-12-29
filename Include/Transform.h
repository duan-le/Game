#pragma once

#include "Vector.h"

class Transform {
  public:
    Transform(float x = 0, float y = 0) : x(x), y(y) {}
    void translateX(float &x) {this->x += x;}
    void translateY(float &y) {this->y += y;}
    void translate(Vector& v) {
      x + v.getX();
      y + v.getY();
    }
    float getX() {return x;}
    float getY() {return y;}

  private:
    float x, y;
};
