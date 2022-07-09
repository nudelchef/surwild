#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "PacketManager.h"

class Player : public Entity {
public:
    Player();

    ~Player() override;

    uint32_t playerId{};

    void setData(const PACKET::REGISTER_PLAYER &data);

    void update() override;

protected:

private:
};

#endif // PLAYER_H
