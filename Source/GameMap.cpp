#include "GameMap.h"

void GameMap::update() {
  for (auto& it : mapLayers) {
    it->update();
  }
}

void GameMap::draw() {
  for (auto& it : mapLayers) {
    it->draw();
  }
}

std::vector<Layer*> GameMap::getMapLayers() {
  return mapLayers;
}

void GameMap::loadMapLayers(Layer* tileLayer) {
  mapLayers.push_back(tileLayer);
}
