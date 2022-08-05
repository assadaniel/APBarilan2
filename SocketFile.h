//
// Created by User on 05/08/2022.
//

#ifndef APBARILAN2_SOCKETFILE_H
#define APBARILAN2_SOCKETFILE_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>

class SocketFile {
private:
    int client_sock;
public:
    virtual void receiveFile(std::fstream file_s) = 0;

    virtual void sendFile(std::fstream file_s) = 0;

    void setClientSock(int clientSock);
};


#endif //APBARILAN2_SOCKETFILE_H
