#include "TileLayer.h"
#include "TextureManager.h"
#include <iostream>

TileLayer::TileLayer(int tileSize, int rowCount, int colCount, std::vector<TileSet> tileSetList, std::vector<std::vector<int>> tileMap) :
  tileSize(tileSize), rowCount(rowCount), colCount(colCount), tileSetList(tileSetList), tileMap(tileMap) {
    for (unsigned long i = 0; i < tileSetList.size(); i++) {
      TextureManager::getInstance()->load(tileSetList[i].name, "Assets/" + tileSetList[i].source);
    }
}

void TileLayer::update() {
  
}

void TileLayer::draw() {
  for (int i = 0; i < rowCount; i++) {
    for (int j = 0; j < colCount; j++)
    {
      int tileID = tileMap[i][j];
      if (tileID == 0) {
        continue;
      } else {
        int tileSetIndex = 0;
        if (tileSetList.size() > 1) {
          std::cout << "Went in here" << std::endl;
          for (unsigned long k = 1; k < tileSetList.size(); k++) {
            if (tileID > tileSetList[k].firstID && tileID < tileSetList[k].lastID) {
              tileID = tileID + tileSetList[k].tileCount - tileSetList[k].lastID;
              tileSetIndex = k;
              break;
            }
          }
        }

        // std::cout << "TileSetList Size: " << tileSetList.size() << std::endl;
        // std::cout << "TileSetIndex: " << tileSetIndex << std::endl;
      
        TileSet tileSet = tileSetList[tileSetIndex]; // This is causing segmentation fault
        int tileRow = tileID / tileSet.colCount;
        int tileCol = tileID - tileRow * tileSet.colCount - 1;

        if (tileID % tileSet.rowCount == 0) {
          tileRow--;
          tileCol = tileSet.colCount - 1;
        }

        TextureManager::getInstance()->drawTile(tileSet.name, tileSet.tileSize, j * tileSet.tileSize, i * tileSet.tileSize, tileRow, tileCol);
      }
    }
  }
}

std::vector<std::vector<int>> TileLayer::getTileMap() {
  return tileMap;
}
