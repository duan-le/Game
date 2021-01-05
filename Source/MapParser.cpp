#include "MapParser.h"

MapParser* MapParser::instance = nullptr;

MapParser::MapParser() {}

MapParser* MapParser::getInstance() {
  if (instance != nullptr) {
    return instance;
  } else {
    return instance = new MapParser();
  }
}

void MapParser::load() {
  parse("test_level", "assets/map.tmx");
}

void MapParser::clean() {
  
}

GameMap* MapParser::getMaps() {
  
}

void MapParser::parse(std::string id, std::string filepath) {

}

TileSet MapParser::parseTileSet(TiXmlElement* xmlTileSet) {
  TileSet tileSet;
  tileSet.name = xmlTileSet->Attribute("name");
  xmlTileSet->Attribute("tilecount", &tileSet.tileCount);
  xmlTileSet->Attribute("firstgid", &tileSet.firstID);
  tileSet.lastID = tileSet.firstID + tileSet.tileCount - 1;
  xmlTileSet->Attribute("columns", &tileSet.colCount);
  tileSet.rowCount = tileSet.tileCount / tileSet.colCount;
  xmlTileSet->Attribute("tilewidth", &tileSet.tileSize);
  tileSet.source = xmlTileSet->FirstChildElement()->Attribute("source");
  return tileSet;
}

TileLayer* MapParser::parseTileLayer(TiXmlElement* xmlLayer, std::vector<TileSet> tileSetList, int tileSize, int rowCount, int colCount) {
  TiXmlElement* data;
  for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
    if (e->Value() == std::string("data")) {
      data = e;
      break;
    }
  }

  std::string matrix(data->GetText());
  std::istringstream iss(matrix);
  std::string id;
  std::vector<std::vector<int>> tileMap(rowCount, std::vector<int>(colCount, 0));

  for (int row = 0; row = rowCount; row++) {
    for (int col = 0; col = colCount; col++) {
      std::getline(iss, id, ',');
      std::stringstream converter(id);
      converter >> tileMap[row][col];
      if (!iss.good()) {
        break;
      } 
    }
  }

  return (new Tile)
}
