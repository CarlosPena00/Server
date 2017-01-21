#ifndef MYSERVER_H
#define MYSERVER_H

#include <iostream>
#include <cstdlib>
#include <unistd.h> //Unix

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <stdio.h>
#include <string>
#include <cstring>

#define LISTENNO 5

using namespace std;
class Server
{
public:
    Server(int portNod);
    //Constructor includes Socket, bind
    void error(const char*);
    void acceptConnection(); //!Blocking Call
    void write(string srt);
    void writeString(string str);
    void writeInt(int n);
    void closeServer();
    string readString(bool debug = false);
    long int readLongInt(bool debug = false);

    
private:
     int sockFD, newSockFD, portNo;
     socklen_t cliLen;
     char buffer[256];
     struct sockaddr_in servAddr, cliAddr;
     int n;
};

#endif // MYSERVER_H