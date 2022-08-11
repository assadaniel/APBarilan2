client: ClientKNN.cpp SocketFileClient.cpp SocketFile.cpp
	g++ -std=c++11 ClientKNN.cpp SocketFileClient.cpp SocketFile.cpp -o client
server: Iris.cpp IrisReader.cpp IrisComp.cpp KSmallestElements.cpp KSmallestRun.cpp ServerKNN.cpp SocketFile.cpp SocketFileServer.cpp
	g++ -std=c++11 Iris.cpp IrisReader.cpp IrisComp.cpp KSmallestElements.cpp KSmallestRun.cpp ServerKNN.cpp SocketFile.cpp SocketFileServer.cpp -o server