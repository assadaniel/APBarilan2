//
// Created by User on 05/08/2022.
//

#ifndef APBARILAN2_SOCKETFILESERVER_H
#define APBARILAN2_SOCKETFILESERVER_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "SocketFile.h"


class SocketFileServer : public SocketFile {
private:
    const int port_no;
public:
    SocketFileServer(const int port_no);
};


#endif //APBARILAN2_SOCKETFILESERVER_H
