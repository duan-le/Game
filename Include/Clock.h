#pragma once

const int TARGET_FPS = 60;
const float TARGET_DELTATIME = 1.5;

class Clock {
  public:
    static Clock* getInstance();
    void tick();
    float getDeltaTime();
    
  private:
    Clock();
    static Clock* instance;
    float deltaTime;
    float lastTime;
};
