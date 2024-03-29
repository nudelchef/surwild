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

extern const Uint8 *keys;

class Game {
public:
    explicit Game(SocketClient *client_);

    virtual ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();

    static void update();

    static void render();

    void clean();

    bool running() const {
        return isRunning;
    }

    static SDL_Renderer *renderer;

    static Camera *camera;
    static Map *map;
    static Player *player;
    static SocketClient *client;

protected:

private:
    bool isRunning{};
    SDL_Window *window{};

    static void handleNetcode(const std::string &message);
};


#endif // GAME_H
