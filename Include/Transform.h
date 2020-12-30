#pragma once

#include "Vector.h"

class Transform {
  public:
    Transform(float x = 0, float y = 0);
    void translateX(float &x);
    void translateY(float &y);
    void translate(Vector& v);
    float getX();
    float getY();

  private:
    float x, y;
};
