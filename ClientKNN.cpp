//
// Created by User on 09/08/2022.


#include <fstream>
#include <SocketFileClient.h>

int main(int argc, char **argv) {
    if(argc < 2) {
        std::cout << "Must provide paths for unclassified file and classified file." << std::endl;
    }
    std::fstream unclassified_file(argv[1], std::fstream::in);
    std::fstream classified_file(argv[2], std::fstream::out);
    SocketFileClient sfc("127.0.0.1", 5555);
    sfc.sendFile(unclassified_file);
    sfc.receiveFile(classified_file);

}
