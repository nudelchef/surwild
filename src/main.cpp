#include "Game.h"
#include "SocketClient.h"

#include <vector>
#include <algorithm>

int main(int argc, char *args[]) {
    const uint16_t FPS = 60;
    const uint16_t frameDelay = 1000 / FPS;

    uint32_t frameStart;
    uint32_t frameTime;


    auto *client = new SocketClient();
    if (!client->connect("127.0.0.1", 8888)) {
        return 0;
    }

    Game *game = new Game(client);
    game->init("Surwild", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 960, false);

    while (game->running()) {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        Game::update();
        Game::render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}
