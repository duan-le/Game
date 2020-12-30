#pragma once

#include "Vector.h"

class RigidBody {
  public:
    RigidBody(float mass = 1.0, float gravity = 9.8);
    void update(float dt);
    void setMass(float mass);
    void setGravity(float gravity);
    void setForce(Vector force);
    void setForceX(float forceX);
    void setForceY(float forceY);
    void setFriction(Vector friction);
    float getMass();
    float getGravity();
    Vector getForce();
    Vector getFriction();
    Vector getPosition();
    Vector getVelocity();
    Vector getAcceleration();

  private:
    float mass;
    float gravity;
    Vector force;
    Vector friction;
    Vector postion;
    Vector velocity;
    Vector acceleration;
};
