#ifndef GAME_H
#define GAME_H

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include <string>

class Camera;
class Map;
class Player;
class SocketClient;

extern const Uint8* keys;

class Game
{
public:
    Game(SocketClient* client_);
    virtual ~Game();

    void init(const char* title, uint32_t xpos, uint32_t ypos, uint32_t width, uint32_t height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running()
    {
        return isRunning;
    }

    static SDL_Renderer *renderer;

    static Camera* camera;
    static Map* map;
    static Player* player;
    static SocketClient* client;

protected:

private:
    bool isRunning;
    SDL_Window *window;

    void handleNetcode(const std::string& message);
};


#endif // GAME_H
