#include "Map.h"

Map::Map()
{
    char const *mapName = "maps/plainfield";
    LoadMap(mapName);

    src.x = src.y = 0;
    src.w = src.h = 32;

    dest.x = dest.y = 0;
    dest.w = dest.h = 64;
}

Map::~Map()
{
    delete[] map;
}

void Map::setMapProperty(std::string object_name, std::string object_data)
{

    if (object_name == "map_name")
    {
        mapName=object_data;

        std::cout << "MAP " << mapName << std::endl << std::endl;

    } else if (object_name == "map_dimension")
    {
        int splitterIndex = object_data.find(",");

        mapWidth = std::stoi(object_data.substr(0, splitterIndex));
        mapHeight = std::stoi(object_data.substr(splitterIndex+1));

    } else if (object_name == "map_atlas")
    {
        std::string delimiter = ",";

        size_t pos = 0;
        std::string token;
        int splitterIndex;

        std::string filename;
        while ((pos = object_data.find(delimiter)) != std::string::npos) {
            token = object_data.substr(0, pos);

            splitterIndex = token.find(":");
            filename = "assets/";
            filename += token.substr(splitterIndex + 1);
            filename += ".png";

            map_atlas[std::stoi(token.substr(0, splitterIndex))] = TextureManager::LoadTexture(filename.c_str());

            object_data.erase(0, pos + delimiter.length());
        }
        // repeat for last element
        token = object_data;

        splitterIndex = token.find(":");
        filename = "assets/";
        filename += token.substr(splitterIndex + 1);
        filename += ".png";

        map_atlas[std::stoi(token.substr(0, splitterIndex))] = TextureManager::LoadTexture(filename.c_str());

    } else if (object_name == "map_data")
    {
        map = new int[mapWidth * mapHeight];

        std::cout << "<info> [Map] size " << mapWidth << ", " << mapHeight << std::endl;

        int ind = 0;


        std::string delimiter = ",";
        size_t pos = 0;
        std::string token;
        while ((pos = object_data.find(delimiter)) != std::string::npos) {

            token = object_data.substr(0, pos);
            map[ind++] = std::stoi(token);

            object_data.erase(0, pos + delimiter.length());
        }
        // repeat for last element
        token = object_data;
        map[ind] = std::stoi(token);

        std::cout << "<info> [Map] index " << (ind) << " tile " << token << std::endl;

    } else {
        std::cout << "<warn> [Map] Loading Map - Unknown map Option: " << object_name << std::endl;
    }
}

void Map::LoadMap(const char *filename)
{
    std::string line;
    std::ifstream mapFile(filename);


    std::string object_name;
    std::string object_data;

    if (mapFile.is_open())
    {
        while( std::getline(mapFile, line) )
        {
            if (line.rfind(" ", 0))
            {

                if (object_name != "")
                    setMapProperty(object_name, object_data);

                // new option
                object_name = StringUtils::removeSpaces(line);

                if (object_name.find(":") != std::string::npos) {

                    // object data is inside name // split

                    int splitterIndex = object_name.find(":");

                    object_data = object_name.substr(splitterIndex+1);
                    object_name = object_name.substr(0, splitterIndex);

                    std::cout << "<info> [Map][Object] " << object_name << std::endl;
                    std::cout << "<info> [Map][Object-Data] " << object_data << std::endl;
                } else
                {
                    // reset object data
                    std::cout << "<info> [Map][Object] " << object_name << std::endl;
                    object_data = "";
                }


            } else {
                // append
                if (object_data != "")
                {
                    object_data.append(",");
                }
                object_data.append(StringUtils::removeSpaces(line));

                std::cout << "<info> [Map][Object-Data] " << object_data << std::endl;
            }


            //std::cout << line << std::endl;
        }

        // repeat for last element
        if (object_name != "")
            setMapProperty(object_name, object_data);

        mapFile.close();
    } else {
        std::cout << "<erro> [Map] Couldn't read map file" << std::endl;
    }
}

bool Map::canTravel(int tileX, int tileY)
{
    if (tileX < 0 || tileY < 0 || tileX >= mapWidth || tileY >= mapHeight)
        return false;

    return true;
}

void Map::renderMap()
{
    int type = 0;

    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            type = map[y * mapWidth + x];

            dest.x = x * dest.w - camera->getX();
            dest.y = y * dest.h - camera->getY();

            TextureManager::render(map_atlas[type], src, dest);
        }
    }
}
