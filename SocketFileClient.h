//
// Created by User on 06/08/2022.
//

#ifndef APBARILAN2_SOCKETFILECLIENT_H
#define APBARILAN2_SOCKETFILECLIENT_H


#include "SocketFile.h"

class SocketFileClient : public SocketFile {
private:
    const char* ip_address;
    const int port_no;
    void close() override;
public:
    SocketFileClient(const char* ip_address, int port_no);

};


#endif //APBARILAN2_SOCKETFILECLIENT_H
