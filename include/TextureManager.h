#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Game.h"

namespace TextureManager
{
SDL_Texture* LoadTexture(const char* filename);

void render(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
}

#endif // GAME_H
