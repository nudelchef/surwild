#include "Game.h"

#include <iostream>
#include <sstream>
#include <arpa/inet.h> // htons ntohs

#include <SDL2/SDL_image.h>

#include "Camera.h"
#include "Map.h"
#include "Player.h"
#include "SocketClient.h"

SDL_Renderer* Game::renderer = nullptr;


Camera* Game::camera = nullptr;
Map* Game::map = nullptr;
Player* Game::player = nullptr;
SocketClient* Game::client = nullptr;



Game::Game(SocketClient *client_)
{
    Game::client = client_;
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

        /*<icon>*/
        // The icon is attached to the window pointer
        SDL_SetWindowIcon(window, IMG_Load("assets/logo.png"));
        /*</icon>*/

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "SDL Renderer created." << std::endl;
        }

        isRunning = true;
    }
    else
    {
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

void Game::handleNetcode(const std::string& message)
{
    std::stringstream m_stream(message);
    std::string line;
    std::getline(m_stream, line, '\037');

    uint16_t packetId = ntohs((uint16_t) std::stoul(line));

    switch(packetId) {
        case 0: // PACKET
            break;
        case 1: // DISCONNECT
            //client->disconnect();
            break;
        case 2: // LOGIN -- server can't login lmao
            break;
        case 3: // UNREGISTER PLAYER

            break;
        case 4: // PLAYERDATA
            player->setData(PACKET::REGISTER_PLAYER(message));
            break;
        default:
            std::cout << "unknown packet (" << packetId << ") received?" << std::endl;
            break;
    }
}

void Game::update()
{
    // receive network messages
    std::string message = client->pthread_pop();
    while(!message.empty())
    {
        handleNetcode(message);

        message = client->pthread_pop();
    }

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

