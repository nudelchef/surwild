#include "TextureManager.h"

#include <iostream>

#include <SDL2/SDL_image.h>

namespace TextureManager
{
    SDL_Texture* LoadTexture(const char* filename)
    {
        std::cout << "<info> [TextureManager] Loading file: " << filename << std::endl;

        SDL_Surface* tempSurface = IMG_Load(filename);
        SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
        SDL_FreeSurface(tempSurface);

        return tex;
    }

    void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
    {
        SDL_RenderCopy(Game::renderer, tex, &src, &dest);
    }
}


