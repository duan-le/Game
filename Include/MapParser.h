#pragma once

#include "TileLayer.h"
#include "GameMap.h"
#include "tinyxml.h"
#include <map>
#include <string>

class MapParser {
  public:
    static MapParser* getInstance();
    void load();
    void clean();
    GameMap* getMaps();

  private:
    MapParser();
    void parse(std::string id, std::string filepath);
    TileSet parseTileSet(TiXmlElement* xmlTileSet);
    TileLayer* parseTileLayer(TiXmlElement* xmlLayer, std::vector<TileSet> tileSetList, int tileSize, int rowCount, int colCount);
    static MapParser* instance;
    std::map<std::string, GameMap*> maps;
};
