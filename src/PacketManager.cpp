#include "PacketManager.h"

#include "Player.h"


//// packet
PACKET::PACKET() : packetId(0) {};
PACKET::PACKET(int id) : packetId(id) {};

std::string PACKET::PACKET::pack() {
    std::stringstream packet("");
    packet << htons(packetId);
    return packet.str();
};

PACKET_DISCONNECT::PACKET_DISCONNECT() : PACKET(1) {};


//// login
PACKET_LOGIN::PACKET_LOGIN(std::string packet) : PACKET() {
    std::stringstream p_stream(packet);
    std::string line;

    // packetId will -always- be 2
    std::getline(p_stream, line, '\037');
    packetId = ntohs((uint16_t) std::stoul(line));

    std::getline(p_stream, username, '\037');
    std::getline(p_stream, password, '\037');
};
PACKET_LOGIN::PACKET_LOGIN(std::string username_, std::string password_) : PACKET(2) {
    username = username_;
    password = password_;
};

std::string PACKET_LOGIN::PACKET_LOGIN::pack(){
    std::stringstream packet("");
    packet    << htons(packetId)
    << '\037' << username
    << '\037' << password
    ;
    return packet.str();
};


//// unregister_player
PACKET_UNREGISTER_PLAYER::PACKET_UNREGISTER_PLAYER(std::string packet) : PACKET() {
    std::stringstream p_stream(packet);
    std::string line;

    // packetId will -always- be 3
    std::getline(p_stream, line, '\037');
    packetId = ntohs((uint16_t) std::stoul(line));

    std::getline(p_stream, line, '\037');
    playerId = ntohs((unsigned int) std::stoul(line));
};
PACKET_UNREGISTER_PLAYER::PACKET_UNREGISTER_PLAYER(Player* player) : PACKET(3) {
    playerId = player->playerId;
};

std::string PACKET_UNREGISTER_PLAYER::PACKET_UNREGISTER_PLAYER::pack(){
    std::stringstream packet("");
    packet    << htons(packetId)
    << '\037' << htons(playerId);
    ;
    return packet.str();
};


//// player_data
PACKET_PLAYER_DATA::PACKET_PLAYER_DATA(std::string packet) : PACKET() {
    std::stringstream p_stream(packet);
    std::string line;

    // packetId will -always- be 4
    std::getline(p_stream, line, '\037');
    packetId = ntohs((uint16_t) std::stoul(line));

    std::getline(p_stream, line, '\037');
    playerId = ntohs((unsigned int) std::stoul(line));

    std::getline(p_stream, line, '\037');
    entityId = ntohs((unsigned int) std::stoul(line));

    std::getline(p_stream, textureString, '\037');

    std::getline(p_stream, line, '\037');
    movementDirection = Direction(ntohs((unsigned short) std::stoul(line)));

    std::getline(p_stream, line, '\037');
    tilePositionX = ntohs((unsigned short) std::stoul(line));

    std::getline(p_stream, line, '\037');
    tilePositionY = ntohs((unsigned short) std::stoul(line));

    std::getline(p_stream, line, '\037');
    x = ntohs((unsigned short) std::stoul(line));

    std::getline(p_stream, line, '\037');
    y = ntohs((unsigned short) std::stoul(line));


    // debug
    std::cout << "\\\\ ID: " << packetId << std::endl;
    std::cout << "\\ playerId: " << playerId << std::endl;
    std::cout << "\\ entityId: " << entityId << std::endl;
    std::cout << "\\ textureString: " << textureString << std::endl;
    std::cout << "\\ movementDirection: " << movementDirection << std::endl;
    std::cout << "\\ tilePositionX: " << tilePositionX << std::endl;
    std::cout << "\\ tilePositionY: " << tilePositionY << std::endl;
    std::cout << "\\ x: " << x << std::endl;
    std::cout << "\\ y: " << y << std::endl;

};
PACKET_PLAYER_DATA::PACKET_PLAYER_DATA(Player* player) : PACKET(4) {
    playerId = player->playerId;
    entityId = player->entityId;
    textureString = player->textureString;
    movementDirection = player->movementDirection;
    tilePositionX = player->tilePosition->x;
    tilePositionY = player->tilePosition->y;
    x = player->src.x;
    y = player->src.y;
};

std::string PACKET_PLAYER_DATA::PACKET_PLAYER_DATA::pack(){
    std::stringstream packet("");
    packet    << htons(packetId)
    << '\037' << htons(playerId)
    << '\037' << htons(entityId)
    << '\037' << textureString
    << '\037' << htons(movementDirection)
    << '\037' << htons(tilePositionX)
    << '\037' << htons(tilePositionY)
    << '\037' << htons(x)
    << '\037' << htons(y)
    ;
    return packet.str();
};
