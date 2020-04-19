#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include <fstream>
#include <iostream>
#include <map>
#include <string>

class Map;

#include "StringUtils.h"

#include "Game.h"
#include "TextureManager.h"

class Map
{
public:
    Map();
    ~Map();

    void LoadMap(const char *filename);
    void renderMap();

    int getTotalMapWidth() { return mapWidth * dest.w; }
    int getTotalMapHeight() { return mapHeight * dest.h; }

    bool canTravel(int tileX, int tileY);

protected:

private:
    SDL_Rect src, dest;

    int* map;

    std::map<int, SDL_Texture*> map_atlas;

    std::string mapName;
    int mapWidth;
    int mapHeight;

    void setMapProperty(std::string object_name, std::string object_data);

    void setPropertyMapName(std::string object_data);
    void setPropertyMapDimension(std::string object_data);
    void setPropertyMapAtlas(std::string object_data);
    void setPropertyMapData(std::string object_data);

};

#endif // MAP_H_INCLUDED
