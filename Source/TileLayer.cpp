#include "TileLayer.h"

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, std::vector<TileSet> tileSetList, std::vector<std::vector<int>> tileMap) :
  tileSize(tileSize), rowCount(rowCount), colCount(colCount), tileSetList(tileSetList), tileMap(tileMap) {}

void TileLayer::update() {

}

void TileLayer::draw() {

}

std::vector<std::vector<int>> TileLayer::getTileMap() {
  return tileMap;
}
