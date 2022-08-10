#include "Server.h"
#include "SocketFileServer.h"
#include "SocketFile.h"
void KNN(){
    // Create socket 
    int port_no = 3;
    SocketFileServer SFS(port_no);

    //Create classified Iris vector
    std::fstream classified("classified.csv");

    //TODO: replace k
    int k = 9;
    //Create Unclassified Iris vector
    KSmallestRun::runKSmallest(k,classified,"Unclassified.csv");
    SFS.sendFile(classified);

}