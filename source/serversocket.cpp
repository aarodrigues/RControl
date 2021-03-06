#include "../header/serversocket.h"

ServerSocket::ServerSocket(int port, int connections)
{
    this->server = socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0){
        throw (server);
    }
    this->port = port;
    this->connection_numbers = connections;
}

int ServerSocket::initSocket() {

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htons(INADDR_ANY);
    server_address.sin_port = htons(port);

    int binded = bind(server, (struct sockaddr*) &server_address, sizeof(server_address));
    if(binded < 0){
        std::string err = "Error binding connection: " + std::to_string(binded);
        throw(err);
    }

    size = sizeof(server_address);
    return 0;
}

void ServerSocket::listenSocket() {
    listen(server,connection_numbers);
    std::cout << "Server started." <<std::endl;
}

int ServerSocket::acceptConnection() {
        std::cout << "Waiting for connections ..." << std::endl;
    my_socket = accept(server,(struct sockaddr *) &server_address, &size);

    if(my_socket < 0){
        std::string err = "Error on accepting: " + std::to_string(my_socket);
        throw(err);
    }

    strcpy(buffer, "=> Server connected...\n");
    send(my_socket, buffer, sizeof(buffer), MSG_NOSIGNAL);
    std::cout << "Client Connected." << std::endl;
    std::cout << "Waiting client request ..." << std::endl;

    return 0;
}

void ServerSocket::connectionManager(){
    acceptConnection();

    while(my_socket > 0){
        receiveData();
        sendData();
    }

    close(server);
}

void ServerSocket::sendData() {
    std::cout << "Server: ";
    /*
    std::cin >> buffer;
    std::cout << "String: " << s << std::endl;
    bb = *s.c_str();
    std::cout << "Char: " << s.c_str() <<std::endl;
    std::cout << bb <<std::endl;
    send(my_socket, s.c_str(), sizeof(buffer), MSG_NOSIGNAL);
    */

    send(my_socket, "executed", sizeof(buffer), MSG_NOSIGNAL);
    std::cout << "executed" << std::endl;
}

void ServerSocket::receiveData() {
    std::cout << "Client: ";
    con_status = recv(my_socket, buffer, sizeof(buffer), 0);
    if(con_status == 0){
        std::cout << "Connection lost!" << std::endl;
        acceptConnection();
    }
    //std::cout << "Nombre " << con_status <<std::endl;
    std::cout << buffer << std::endl;

    //strcpy(this->p_cmd.str_command, buffer);
    //this->p_cmd.executeCommand();
}
