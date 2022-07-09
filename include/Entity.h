#ifndef ENTITY_H
#define ENTITY_H

#ifdef _WIN32
#include <SDL/SDL.h> /* Windows-specific SDL2 library */
#else

#include <SDL2/SDL.h> /* macOS- and GNU/Linux-specific */

#endif

#include <string>

#include "Direction.h"

class Entity {
public:
    Entity();

    virtual ~Entity();

    uint32_t entityId{};

    SDL_Rect src{};
    SDL_Rect dest{};
    SDL_Point *tilePosition;
    std::string textureString;
    Direction movementDirection;

    virtual void update();

    virtual void render();

    uint16_t getX() const {
        return dest.x;
    }

    uint16_t getY() const {
        return dest.y;
    }

    uint16_t getCenterX() const {
        return getX() + (dest.w >> 1);
    }

    uint16_t getCenterY() const {
        return getY() + (dest.h >> 1);
    }

    void setTexture(SDL_Texture *texture_) {
        texture = texture_;
    }

    void setFrameOrder(const uint8_t *frameOrder_, uint8_t size) {
        frameOrder = new uint8_t[size];
        for (int i = 0; i < size; i++) {
            frameOrder[i] = frameOrder_[i];
        }
        maxFrames = size;
    }

    void setTilePosition(uint16_t x, uint16_t y);

    void move(Direction direction);

    void look(Direction direction);

    bool canMove(Direction direction) const;

protected:

private:
    const int movementSpeed = 2;

    const int animationDuration = 8;
    uint8_t atFrame;
    uint8_t *frameOrder;
    uint8_t maxFrames{};
    uint8_t animationTime;

    bool isMoving;
    int distanceLeft{};
    SDL_Texture *texture{};

    void updateMovement();
};

#endif // ENTITY_H
