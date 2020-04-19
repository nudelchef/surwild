#include "Player.h"

#include "Camera.h"
#include "TextureManager.h"

Player::Player()
{
    setTexture(TextureManager::LoadTexture("assets/naey_spritesheet.png"));

    int frameOrder_[4] = {0, 2, 0, 3};

    setFrameOrder(frameOrder_, sizeof(frameOrder_) / sizeof(frameOrder_[0]));
}

Player::~Player()
{

}

void Player::update()
{
    if (keys[SDL_SCANCODE_UP])
    {
        move(Direction::UP);
    } else if (keys[SDL_SCANCODE_DOWN])
    {
        move(Direction::DOWN);
    } else if (keys[SDL_SCANCODE_LEFT])
    {
        move(Direction::LEFT);
    } else if (keys[SDL_SCANCODE_RIGHT])
    {
        move(Direction::RIGHT);
    }

    Game::camera->set(getCenterX(), getCenterY());

    Entity::update();
}
