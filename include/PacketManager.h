#ifndef PACKETMANAGER_H
#define PACKETMANAGER_H

#include <string>
#include <sstream>
#include <iostream>
#include <arpa/inet.h> // htons ntohs

#include "Direction.h"

class Player;

struct PACKET {
public:
    uint16_t packetId;

    PACKET();
    PACKET(int id);

    virtual std::string pack();
};

struct PACKET_DISCONNECT : PACKET {
public:
    PACKET_DISCONNECT();
};

struct PACKET_LOGIN : PACKET {
public:
    std::string username;
    std::string password;

    PACKET_LOGIN(std::string packet);
    PACKET_LOGIN(std::string username_, std::string password_);

    std::string pack();
};

struct PACKET_UNREGISTER_PLAYER : PACKET {
public:
    unsigned int playerId;

    PACKET_UNREGISTER_PLAYER(std::string packet);
    PACKET_UNREGISTER_PLAYER(Player* player);

    std::string pack();
};

struct PACKET_PLAYER_DATA : PACKET {
public:
    unsigned int playerId;
    unsigned int entityId;


    std::string textureString;

    Direction movementDirection;
    unsigned short tilePositionX;
    unsigned short tilePositionY;

    unsigned short x;
    unsigned short y;


    PACKET_PLAYER_DATA(std::string packet);
    PACKET_PLAYER_DATA(Player* player);

    std::string pack();
};


#endif // PACKETMANAGER_H
