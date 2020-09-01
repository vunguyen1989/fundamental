Document
https://stackoverflow.com/questions/29888435/boost-asio-and-array-of-sockets

Build
#for server
g++ -O2 {checker,session,server,server_main}.cpp -o server -lboost_system -lboost_thread -lpthread -std=c++17

#for client
g++ -O2 cli.cpp -o cli -lboost_system -lboost_thread -lpthread -std=c++17

# Checking string format

# parse the string

#