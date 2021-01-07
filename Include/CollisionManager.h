#pragma once

#include "SDL2/SDL.h"
#include "TileLayer.h"
#include<vector>

class CollisionManager {
  public:
    static CollisionManager* getInstance();
    bool isCollision(SDL_Rect rectA, SDL_Rect rectB);
    bool isMapCollision(SDL_Rect rect);

  private:
    CollisionManager();
    static CollisionManager* instance;
    std::vector<std::vector<int>> collisionTileMap;
    TileLayer* collisionLayer;
};
