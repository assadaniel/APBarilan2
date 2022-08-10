#ifndef APBARILAN2_SERVER_H
#define APBARILAN2_SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <fstream>
#include "KSmallestElements.hpp"
#include "Iris.hpp"
#include "IrisReader.hpp"
#include "IrisComp.hpp"
#include "KSmallestElements.hpp"
#include "KSmallestRun.h"


class Server {
    public:
        void KNN();
};
#endif //APBARILAN2_SERVER_H
