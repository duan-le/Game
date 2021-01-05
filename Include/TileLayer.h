#pragma once

#include "Layer.h"
#include <vector>
#include <string>

struct TileSet {
  int firstID, lastID;
  int rowCount, colCount;
  int tileCount, tileSize;
  std::string name, filepath;
};

class TileLayer : public Layer {
  public:
    TileLayer(int tileSize, int rowCount, int colCount, std::vector<TileSet> tileSetList, std::vector<std::vector<int>> tileMap);
    virtual void update();
    virtual void draw();
    std::vector<std::vector<int>> getTileMap();

  private:
    int tileSize;
    int rowCount, colCount;
    std::vector<TileSet> tileSetList;
    std::vector<std::vector<int>> tileMap;
};
