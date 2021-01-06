#pragma once

#include "Layer.h"
#include <vector>

class GameMap {
  public:
    void update();
    void draw();
    std::vector<Layer*> getMapLayers();
    void loadMapLayers(Layer* tileLayer);

  private:
    std::vector<Layer*> mapLayers;
};
