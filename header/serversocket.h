#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#include "../header/parsecommand.h"

class ServerSocket
{
public:
public:
    ServerSocket(int port, int connections);
    int initSocket();
    void sendData();
    void receiveData();
    void listenSocket();
    int acceptConnection();
    void connectionManager();

private:
    int server;
    int port;
    int connection_numbers;
    int my_socket;
    int clientCount;
    struct sockaddr_in server_address;
    socklen_t size;

    char buffer[256];
    int con_status;
    char bb;

    ParseCommand p_cmd;
};

#endif // SERVERSOCKET_H
