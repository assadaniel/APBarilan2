//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512
#include "SocketFile.h"
void SocketFile ::receiveFile(std::fstream file_s) {
    char buffer[CHUNK_SIZE];
    size_t data;
    while ((data = recv(client_sock, buffer, CHUNK_SIZE, 0)) > 0) {
        file_s << buffer << std::endl;
    }
    if (data == -1) {
        std::cout << "Server : Error receiving file." << std::endl;
    }
}

void SocketFile::sendFile(std::fstream file_s) {
    int sent = 0;
    std::string line;
    while(getline(file_s,line)) {
        sent = send(client_sock, line.c_str(),line.length(),0);
        if(sent < 0) {
            std::cout << "Server: Error sending file." << std::endl;
        }
    }
}

void SocketFile::setClientSock(int clientSock) {
    client_sock = clientSock;
}
