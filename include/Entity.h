#ifndef ENTITY_H
#define ENTITY_H

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else
#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */
#endif

#include <string>

#include "Direction.h"

class Entity
{
public:
    Entity();
    virtual ~Entity();

    unsigned int entityId;

    SDL_Rect src;
    SDL_Rect dest;
    SDL_Point* tilePosition;
    std::string textureString;
    Direction movementDirection;

    virtual void update();
    virtual void render();

    int getX()
    {
        return dest.x;
    }

    int getY()
    {
        return dest.y;
    }

    int getCenterX()
    {
        return dest.x + (dest.w >> 1);
    }

    int getCenterY()
    {
        return dest.y + (dest.h >> 1);
    }

    void setTexture(SDL_Texture *texture_)
    {
        texture = texture_;
    }

    void setFrameOrder(int *frameOrder_, int size)
    {
        for (int i = 0 ; i < size ; i++)
        {
            frameOrder[i] = frameOrder_[i];
        }
        maxFrames = size;
    }

    void setTilePosition(int x, int y);

    void move(Direction direction);

    void look(Direction direction);

    bool canMove(Direction direction);

protected:

private:
    const int movementSpeed = 2;

    const int animationDuration = 8;
    int atFrame;
    int* frameOrder;
    int maxFrames;
    int animationTime;

    bool isMoving;
    int distanceLeft;
    SDL_Texture* texture;

    void updateMovement();
};

#endif // ENTITY_H
