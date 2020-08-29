#include "SocketClient.h"

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <pthread.h>

#define COLOR_MAGENTA "\e[95m"
#define COLOR_CLEAR "\e[39m"

void* SocketClient::listen(void *arg)
{
    SocketClient *sock = (SocketClient *) arg;

    char buffer[1024 + 1];

    while(recv(sock->clientSocket, buffer, 1024 + 1, 0) > 0)
    {
        buffer[1024] = '\0';

        std::cout << "Received: [" << buffer << "]" << std::endl;
        memset(buffer, 0, sizeof(buffer));
    }
    //Print the received message
    std::cout << "Receive failed or closed" << std::endl;
    close(sock->clientSocket);

    return 0;
    //pthread_exit(NULL);
}

void SocketClient::send(const char* message)
{
    std::cout << "Sending: " << message << std::endl;

    unsigned long buffersize = 8;
    char buffer[buffersize + 1];
    buffer[buffersize + 1] = '\0';


    unsigned int chunks = strlen(message) / buffersize;
    unsigned long lastBit = strlen(message) % buffersize;

    unsigned long writeTil = buffersize;

    uint64_t message_length = strlen(message);
    memcpy(&buffer, &message_length, sizeof(uint64_t));
    if( ::send(clientSocket , buffer , sizeof(uint64_t) , 0) < 0)
    {
        std::cout << "Send failed" << std::endl;
    }

    for (unsigned int i = 0; i <= chunks; i++)
    {
        // copy message into buffer
        memcpy(&buffer[0], &message[0] + i * buffersize, buffersize);
        if (i == chunks) {
            if (lastBit < buffersize)
            {
                buffer[lastBit] = '\0';
                writeTil = lastBit + 1;
            }else{
                writeTil = buffersize + 1;
            }
        }

        std::cout << std::endl;
        if( ::send(clientSocket , buffer , writeTil , 0) < 0)
        {
            std::cout << "Send failed" << std::endl;
        }
    }
}

bool SocketClient::connect(const char *ipAddr_, long port_)
{
    ipAddr = ipAddr_;
    port = port_;
    std::cout << COLOR_MAGENTA << "Connecting to " << ipAddr << ", " << port << COLOR_CLEAR << std::endl;


    struct sockaddr_in serverAddr;
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr);

    //Connect the socket to the server using the address
    addr_size = sizeof( serverAddr );
    if ( ::connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size) < 0)
    {
        std::cout << COLOR_MAGENTA << "Failed to connect: " << strerror(errno) << " (" << errno << ")" << COLOR_CLEAR << std::endl;
        return false;
    }

    std::cout << COLOR_MAGENTA << "Connection established" << COLOR_CLEAR << std::endl;

    pthread_t thread;
    if( pthread_create(&thread, NULL, SocketClient::listen, this ) )
        std::cout << "Failed to create thread" << std::endl;

    return true;
}

SocketClient::SocketClient()
{

}

SocketClient::~SocketClient()
{
    //dtor
}
