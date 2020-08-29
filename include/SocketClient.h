#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H


void* run(void*);

class SocketClient
{
    public:
        SocketClient();
        virtual ~SocketClient();

        bool connect(const char *ipAddr, long port);
        void send(const char* message);

    protected:

    private:
        const char* ipAddr;
        long port;
        int clientSocket;

        static void* listen(void *arg);
};

#endif // SOCKETCLIENT_H
