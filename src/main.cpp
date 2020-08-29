#include "Game.h"
#include "SocketClient.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

int main( int argc, char* args[] )
{
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;


    SocketClient client = SocketClient();
    if (! client.connect("127.0.0.1", 8888))
    {
        return 0;
    }

    Game* game = new Game(&client);
    game->init("Surwild", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 960, false);

    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}
