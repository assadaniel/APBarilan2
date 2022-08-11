//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512

#include <sys/stat.h>
#include "SocketFile.h"

void SocketFile::receiveFile(std::fstream &file_s) {
    char buffer[CHUNK_SIZE];
    size_t data;
    data = recv(client_sock, buffer, CHUNK_SIZE, 0);
    file_s.write(buffer, data);
    if (data < 0) {
        std::cout << "Server : Error receiving file." << std::endl;
    } else {
        std :: cout << "Received " << data << " bytes." << std::endl;
    }

}

void SocketFile::sendFile(std::fstream &file_s, long file_size) {
    size_t sent = 0;
    std::string line;
    char buffer[CHUNK_SIZE];
    file_s.read(buffer, file_size);
    sent = send(client_sock, buffer, file_size, 0);
    if (sent < 0) {
        std::cout << "Server : Error sending file." << std::endl;
    } else {
        std :: cout << "Sent " << sent << " bytes." << std::endl;
    }
}

void SocketFile::setClientSock(int clientSock) {
    client_sock = clientSock;
}

SocketFile::~SocketFile() = default;

int SocketFile::getClientSock() const {
    return client_sock;
}

//FROM STACK OVERFLOW: https://stackoverflow.com/questions/5840148/how-can-i-get-a-files-size-in-c?noredirect=1&lq=1
long SocketFile::getFileSize(const std::string &filename) {
    struct stat stat_buf{};
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}
