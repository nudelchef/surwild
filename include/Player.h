#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player: public Entity
{
    public:
        Player();
        virtual ~Player();

        void update();

    protected:

    private:
};

#endif // PLAYER_H