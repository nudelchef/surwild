#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include <map>
#include <string>

class Map
{
public:
    Map();
    ~Map();

    void LoadMap(const std::string& filename);
    void renderMap();

    int getTotalMapWidth() const {
        return mapWidth * dest.w;
    }

    int getTotalMapHeight() const {
        return mapHeight * dest.h;
    }

    bool canTravel(uint16_t tileX, uint16_t tileY) const;

protected:

private:
    SDL_Rect src{}, dest{};

    uint16_t *map{};

    std::map<uint16_t, SDL_Texture *> map_atlas;

    std::string mapName;
    uint16_t mapWidth{};
    uint16_t mapHeight{};

    void setMapProperty(std::string &object_name, std::string &object_data);

    void setPropertyMapName(std::string &object_data);

    void setPropertyMapDimension(std::string &object_data);

    void setPropertyMapAtlas(std::string &object_data);

    void setPropertyMapData(std::string &object_data);

};

#endif // MAP_H_INCLUDED
