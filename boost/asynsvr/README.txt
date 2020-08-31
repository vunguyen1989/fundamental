Document
https://stackoverflow.com/questions/29888435/boost-asio-and-array-of-sockets

Build
#for server
g++ -O2 {session,server,server_main}.cpp -o server -lboost_system -lboost_thread -lpthread

#for client
g++ -O2 cli.cpp -o cli -lboost_system -lboost_thread -lpthread