#include "CollisionManager.h"
#include "Engine.h"

CollisionManager* CollisionManager::instance = nullptr;

CollisionManager::CollisionManager() {
  collisionLayer = (TileLayer*)Engine::getInstance()->getMap()->getMapLayers().front();
  collisionTileMap = collisionLayer->getTileMap();
}

CollisionManager* CollisionManager::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new CollisionManager();
  }
}

bool CollisionManager::isCollision(SDL_Rect rectA, SDL_Rect rectB) {
  bool xOverlap = (rectA.x < rectB.x + rectB.w) && (rectA.x + rectA.w > rectB.x);
  bool yOverlap = (rectA.y < rectB.y + rectB.h) && (rectA.y + rectA.h > rectB.y);
  return (xOverlap && yOverlap);
}


bool CollisionManager::isMapCollision(SDL_Rect rect) {
  int tileSize = 32;
  int rowCount = 20;
  int colCount = 60;
  int leftTile = rect.x / tileSize;
  int rightTile = (rect.x + rect.w) / tileSize;
  int topTile = rect.y / tileSize;
  int bottomTile = (rect.y + rect.h) / tileSize;

  if (leftTile < 0) leftTile = 0;
  if (rightTile > colCount) rightTile = colCount;
  if (topTile < 0) topTile = 0;
  if (bottomTile > rowCount) bottomTile = rowCount;

  for (int i = leftTile; i <= rightTile; i++) {
    for (int j = topTile; j <= bottomTile; j++) {
      if (collisionTileMap[j][i] > 0)
        return true;
    }
  }

  return false;
}

