#ifndef GAME_H
#define GAME_H

#include <iostream>

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include <SDL2/SDL_image.h>

class Camera;
class Map;
class Player;

extern const Uint8* keys;

class Game
{
    public:
        Game();
        virtual ~Game();

        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();

        bool running() { return isRunning; }

        static SDL_Renderer *renderer;

        static Camera* camera;
        static Map* map;
        static Player* player;

    protected:

    private:
        bool isRunning;
        SDL_Window *window;
};


#endif // GAME_H
