//
// Created by User on 05/08/2022.
//
#define CHUNK_SIZE 512

#include <fstream>
#include "SocketFileServer.h"


SocketFileServer::SocketFileServer( const int port_no) : port_no(port_no) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(port_no);
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int cs = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
    setClientSock(cs);

    if (cs < 0) {
        perror("error accepting client");
    }

}







