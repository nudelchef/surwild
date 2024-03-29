#include "Player.h"

#include "Camera.h"
#include "TextureManager.h"

Player::Player() {
    setTexture(TextureManager::LoadTexture("assets/naey_spritesheet.png"));

    uint8_t frameOrder_[4] = {0, 2, 0, 3};

    setFrameOrder(frameOrder_, sizeof(frameOrder_) / sizeof(frameOrder_[0]));
}

Player::~Player() = default;

void Player::setData(const PACKET::REGISTER_PLAYER &data) {
    entityId = data.entityId;
    playerId = data.playerId;

    textureString = data.textureString;
    look(data.movementDirection);
    setTilePosition(data.tilePositionX, data.tilePositionY);
}

void Player::update() {
    if (keys[SDL_SCANCODE_UP]) {
        move(Direction::UP);
    } else if (keys[SDL_SCANCODE_DOWN]) {
        move(Direction::DOWN);
    } else if (keys[SDL_SCANCODE_LEFT]) {
        move(Direction::LEFT);
    } else if (keys[SDL_SCANCODE_RIGHT]) {
        move(Direction::RIGHT);
    }

    Game::camera->set(getCenterX(), getCenterY());

    Entity::update();
}
