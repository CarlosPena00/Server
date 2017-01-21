#include "server.hpp"


Server::Server(int portNo){
	this->sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if (sockFD < 0){
    	error("Error Opening Socket ");	
    	exit(1);
    } 
    bzero((char *) &servAddr, sizeof(servAddr));
    this->portNo = portNo;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = INADDR_ANY;
	servAddr.sin_port = htons(portNo);
	if (bind(sockFD, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0){
	 	error("Error on binding ");	
		exit(1);
	}
	listen(sockFD,LISTENNO);
}
void Server::acceptConnection(){
	this->cliLen = sizeof(cliAddr);
    newSockFD = accept(sockFD, (struct sockaddr *) &cliAddr, &cliLen);
     if (newSockFD < 0){
     	error("ERROR on accept ");
		exit(1);
	}
}

long int Server::readLongInt(bool debug){
	bzero(buffer,256);
    n = read(newSockFD,buffer,255);
    if (n < 0) error("Error reading from socket ");
    std::string::size_type sz;
    long int i_dec =  strtol (buffer,NULL,10);
    if(debug)std::cout<<"Server::ReadInt:: "<<i_dec<<std::endl;
    return i_dec;
}

string Server::readString(bool debug){
	bzero(buffer,256);
    n = read(newSockFD,buffer,255);
    if (n < 0) error("Error reading from socket ");
    string str(buffer);
    if(debug)std::cout<<"Server::readString:: "<<str<<std::endl;
    return str;
}

void Server::closeServer(){
	 close(newSockFD);
     close(sockFD);
}
void Server::error(const char* msg){
	perror(msg);
}

