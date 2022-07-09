#include "Entity.h"

#include <sstream>
#include <string>

#include "TextureManager.h"
#include "Game.h"
#include "Camera.h"
#include "Map.h"
#include "SocketClient.h"
#include "PacketManager.h"

Entity::Entity() {
    src.x = src.y = 0;
    src.w = src.h = 32;

    dest.x = dest.y = 0;
    dest.w = dest.h = 64;

    isMoving = false;
    movementDirection = Direction::DOWN;
    tilePosition = new SDL_Point();

    atFrame = 0;
    frameOrder = nullptr;
    animationTime = 0;

    setTilePosition(0, 0);
}

Entity::~Entity() {
    delete[] frameOrder;
}

void Entity::update() {
    if (isMoving) {
        updateMovement();

        animationTime++;
        while (animationTime >= animationDuration) {
            animationTime -= animationDuration;

            atFrame++;
            if (atFrame >= maxFrames)
                atFrame = 0;
            src.y = frameOrder[atFrame] * src.h;
        }
    } else {
        src.y = 0;
    }
}

void Entity::render() {
    SDL_Rect render_dest;
    render_dest.x = dest.x - Game::camera->getX();
    render_dest.y = dest.y - Game::camera->getY() - 2; // Every entity should be rendered to pixels up
    render_dest.w = dest.w;
    render_dest.h = dest.h;

    TextureManager::render(texture, src, render_dest);
}

void Entity::setTilePosition(uint16_t x, uint16_t y) {
    tilePosition->x = x;
    tilePosition->y = y;
    dest.x = x * 64;
    dest.y = y * 64;
}

bool Entity::canMove(Direction direction) {
    switch (direction) {
        case Direction::UP:
            return Game::map->canTravel(tilePosition->x, tilePosition->y - 1);
        case Direction::DOWN:
            return Game::map->canTravel(tilePosition->x, tilePosition->y + 1);
        case Direction::LEFT:
            return Game::map->canTravel(tilePosition->x - 1, tilePosition->y);
        case Direction::RIGHT:
            return Game::map->canTravel(tilePosition->x + 1, tilePosition->y);
        default:
            break;
    }
    return false;
}

void Entity::look(Direction direction) {
    src.x = direction * 32;
}

void Entity::move(Direction direction) {
    if (!isMoving) {
        // turn even if you can't move
        look(direction);

        if (canMove(direction)) {
            switch (direction) {
                case Direction::UP:
                    tilePosition->y -= 1;
                    break;
                case Direction::DOWN:
                    tilePosition->y += 1;
                    break;
                case Direction::LEFT:
                    tilePosition->x -= 1;
                    break;
                case Direction::RIGHT:
                    tilePosition->x += 1;
                    break;
                default:
                    break;
            }

            isMoving = true;
            movementDirection = direction;
            distanceLeft = 64;
        }
    }
}

void Entity::updateMovement() {
    // move player
    switch (movementDirection) {
        case Direction::UP:
            dest.y -= movementSpeed;
            distanceLeft -= movementSpeed;
            break;
        case Direction::DOWN:
            dest.y += movementSpeed;
            distanceLeft -= movementSpeed;
            break;
        case Direction::LEFT:
            dest.x -= movementSpeed;
            distanceLeft -= movementSpeed;
            break;
        case Direction::RIGHT:
            dest.x += movementSpeed;
            distanceLeft -= movementSpeed;
            break;
        default:
            break;
    }

    // check if finished walking
    if (distanceLeft <= 0) {
        isMoving = false;
        setTilePosition(tilePosition->x, tilePosition->y);


        std::stringstream sstream;
        sstream << "0\037[X: " << tilePosition->x << ", Y: " << tilePosition->y << "]";

        Game::client->send(sstream.str().c_str());

        //Game::client->send("Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet. Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore magna aliquyam erat, sed diam voluptua. At vero eos et accusam et justo duo dolores et ea rebum. Stet clita kasd gubergren, no sea takimata sanctus est Lorem ipsum dolor sit amet.");
    }
}
