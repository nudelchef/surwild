#include "Entity.h"

Entity::Entity()
{
    src.x = src.y = 0;
    src.w = src.h = 32;

    dest.x = dest.y = 0;
    dest.w = dest.h = 64;

    isMoving = false;
    movementDirection = Direction::DOWN;
    tilePosition = new SDL_Point();

    atFrame = 0;
    frameOrder = new int[1];
    animationTime = 0;

    setTilePosition(0, 0);
}

Entity::~Entity()
{
    delete[] frameOrder;
}

void Entity::setTilePosition(int x, int y)
{
    tilePosition->x = x;
    tilePosition->y = y;
    dest.x = x * 64;
    dest.y = y * 64;
}

bool Entity::canMove(Direction direction)
{
    switch (direction)
    {
    case Direction::UP:
        return map->canTravel(tilePosition->x, tilePosition->y - 1);
    case Direction::DOWN:
        return map->canTravel(tilePosition->x, tilePosition->y + 1);
    case Direction::LEFT:
        return map->canTravel(tilePosition->x - 1, tilePosition->y);
    case Direction::RIGHT:
        return map->canTravel(tilePosition->x + 1, tilePosition->y);
    default:
        break;
    }
    return false;
}

void Entity::look(Direction direction)
{
    switch(direction)
    {
    case Direction::UP:
        src.x = 64;
        break;
    case Direction::DOWN:
        src.x = 0;
        break;
    case Direction::LEFT:
        src.x = 32;
        break;
    case Direction::RIGHT:
        src.x = 96;
        break;
    default:
        break;
    }
}

void Entity::move(Direction direction)
{
    if (!isMoving)
    {
        // turn even if you can't move
        look(direction);

        if (canMove(direction))
        {
            switch(direction)
            {
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

void Entity::updateMovement()
{
    // move player
    switch (movementDirection)
    {
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
    if (distanceLeft <= 0)
    {
        isMoving = false;
        setTilePosition(tilePosition->x, tilePosition->y);
    }
}
