#include <iostream>
#include <string.h>
#include "../header/parsecommand.h"
#include "../header/serversocket.h"
#include <fstream>
#include <memory>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    ParseCommand p_cmd;
/*
    do{
        cout << "remote command: ";
        cin.getline(p_cmd.str_command,sizeof(p_cmd.str_command));
        p_cmd.executeCommand();
        cout << "read -> " << p_cmd.str_command << endl;
    }while(strcmp(p_cmd.str_command,"exit"));

*/
    try{
            std::unique_ptr<ServerSocket>server_socket(new ServerSocket(1500,1));
            server_socket->initSocket();
            server_socket->listenSocket();
            server_socket->connectionManager();

        }catch(string e){
            cout << "Error: " << e << endl;
        }

    return 0;
}
