#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "PacketManager.h"

class Player: public Entity
{
public:
    Player();
    virtual ~Player();

    unsigned int playerId;

    void setData(PACKET::REGISTER_PLAYER data);
    void update();

protected:

private:
};

#endif // PLAYER_H
