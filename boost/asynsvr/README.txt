1) Document
https://stackoverflow.com/questions/29888435/boost-asio-and-array-of-sockets

2) Build
    #for server
        g++ {checker,processor,session,server,server_main}.cpp -o server -lboost_system -lboost_thread -lpthread -std=c++17
    #for client
        g++ cli.cpp -o cli -lboost_system -lboost_thread -lpthread -std=c++17
    #for unit test
        g++ {processor,unit_test}.cpp -o unit_test -lgtest -pthread -lboost_system

3) Run
    #for server
        ./server
    #for client        
        ./cli 
    #for client        
        ./unit_test 
    # Using telnet
        telnet 127.0.0.1 5001
4) Define test cases
    # Checking expresion format is valid or not
        - with/without new line character ‘\n’ at the end    
        - contain float number                               
        - the braces is invalid                              
        - strange character (not operator, not digit, not brace)  
    # ReqViaSocket  : via tcp client
    # Evaluating    : test the evaluating function

