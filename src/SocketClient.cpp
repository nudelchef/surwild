#include "SocketClient.h"


#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h> // for close
#include <pthread.h>


#define COLOR_MAGENTA "\e[95m"
#define COLOR_CLEAR "\e[39m"

void *SocketClient::listen(void *arg) {
    auto *sock = (SocketClient *) arg;

    sock->listenerLock = PTHREAD_MUTEX_INITIALIZER;

    constexpr size_t CHUNK_LENGTH = 1024;
    char buffer[CHUNK_LENGTH];

    uint64_t bytesTotal;
    uint64_t bytesToRead;
    uint64_t bytesRead;
    uint64_t bytesRemaining;

    std::string message;

    while (true) {

        // READ MESSAGE LENGTH
        if (recv(sock->clientSocket, buffer, sizeof(uint64_t), 0) != sizeof(uint64_t)) {
            break;
        }
        memcpy(&bytesTotal, &buffer[0], sizeof(uint64_t));

        bytesTotal = ntohl((unsigned long) bytesTotal);
        bytesRemaining = bytesTotal;

        // READ MESSAGE
        message = "";
        do {
            bytesToRead = std::min(CHUNK_LENGTH, bytesRemaining);

            bytesRead = recv(sock->clientSocket, &buffer, bytesToRead, 0);

            if (bytesRead < 0) break;
            else bytesRemaining -= bytesRead;

            message.append(&buffer[0], bytesRead);

        } while (bytesRemaining > 0);

        int rc = pthread_mutex_lock(&sock->listenerLock);
        if (rc) {
            perror("pthread_mutex_lock");
            pthread_exit(nullptr);
        }
        // process whole message

        sock->messages_received.push_back(message);

        rc = pthread_mutex_unlock(&sock->listenerLock);
        if (rc) {
            perror("pthread_mutex_unlock");
            pthread_exit(nullptr);
        }
    }

    std::cout << ">>>Server Closed<<<" << std::endl;
    close(sock->clientSocket);

    pthread_exit(nullptr);
}

std::string SocketClient::pthread_pop() {
    std::string message;

    int rc = pthread_mutex_lock(&listenerLock);
    if (rc) { /* an error has occurred */
        perror("pthread_mutex_lock");
        pthread_exit(nullptr);
    }

    if (!messages_received.empty()) {
        message = messages_received.back();
        messages_received.pop_back();
    }

    rc = pthread_mutex_unlock(&listenerLock);
    if (rc) {
        perror("pthread_mutex_unlock");
        pthread_exit(nullptr);
    }

    return message;
}

void SocketClient::send(const std::string &message) const {
    constexpr size_t CHUNK_LENGTH = 1024;
    const size_t bytesTotal = message.length();
    size_t bytesRemaining = bytesTotal;
    size_t bytesSent;
    size_t bytesToSend;

    std::cout << "sending: [" << message << "] (" << bytesTotal << ") bytes." << std::endl;


    unsigned long lengthValue = htonl((unsigned long) bytesTotal);
    if (::send(clientSocket, (const char *) &lengthValue, sizeof(lengthValue), 0) < 0) {
        return;
    }

    do {
        bytesToSend = std::min(CHUNK_LENGTH, bytesRemaining);

        bytesSent = ::send(clientSocket, message.c_str() + (bytesTotal - bytesRemaining), bytesToSend, 0);

        if (bytesSent < 0) return;
        else bytesRemaining -= bytesSent;

    } while (bytesRemaining > 0);
}

bool SocketClient::connect(const char *ipAddr_, int port_) {
    ipAddr = ipAddr_;
    port = port_;
    std::cout << COLOR_MAGENTA << "Connecting to " << ipAddr << ", " << port << COLOR_CLEAR << std::endl;


    struct sockaddr_in serverAddr{};
    socklen_t addr_size;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;

    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(ipAddr);

    //Connect the socket to the server using the address
    addr_size = sizeof(serverAddr);
    if (::connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size) < 0) {
        std::cout << COLOR_MAGENTA << "Failed to connect: " << strerror(errno) << " (" << errno << ")" << COLOR_CLEAR
                  << std::endl;
        return false;
    }

    std::cout << COLOR_MAGENTA << "Connection established" << COLOR_CLEAR << std::endl;

    pthread_t thread;
    if (pthread_create(&thread, nullptr, SocketClient::listen, this))
        std::cout << "Failed to create thread" << std::endl;

    return true;
}

SocketClient::SocketClient() = default;

SocketClient::~SocketClient() = default;