#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <pthread.h>
#include <string>
#include <vector>

void* run(void*);

class SocketClient
{
    public:
        SocketClient();
        virtual ~SocketClient();

        bool connect(const char *ipAddr, long port);
        void send(const std::string& message);

        pthread_mutex_t listenerLock;

        std::string pthread_pop();

    protected:

    private:
        const char* ipAddr;
        long port;
        int clientSocket;

        std::vector<std::string> messages_received;

        static void* listen(void *arg);
};

#endif // SOCKETCLIENT_H
