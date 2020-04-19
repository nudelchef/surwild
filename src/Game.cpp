#include "Game.h"
#include "Map.h"
#include "Player.h"

SDL_Renderer* Game::renderer = nullptr;


Camera* camera = nullptr;
Map* map = nullptr;
Player* player = nullptr;



Game::Game()
{
}

Game::~Game()
{
}


const Uint8* keys = SDL_GetKeyboardState(NULL);



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL initialised." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window)
        {
            std::cout << "SDL Window created." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "SDL Renderer created." << std::endl;
        }

        isRunning = true;
    } else {
        isRunning = false;
    }

    camera = new Camera(width, height);

    map = new Map();
    player = new Player();
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:

        break;
    case SDL_KEYUP:

        break;
    default:
        break;
    }
}

void Game::update()
{
    camera->update();
    player->update();

    camera->forceBorder(0, 0, map->getTotalMapWidth(), map->getTotalMapHeight());
}

void Game::render()
{
    SDL_RenderClear(renderer);

    map->renderMap();
    player->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    delete map;

    std::cout << "Game cleaned." << std::endl;
}

