#include <iostream>
#include <stdio.h>
#include "server.hpp"
using namespace std;

int main(int argc, char *argv[]){
	Server *servidor;
	if(argc <2){
		std::cout<<"Passar Argumento por Parametro "<<std::endl;
		exit(1);
	}
	servidor = new Server(atoi( argv[1]));
	servidor->acceptConnection();//BlockCall
	std::string str = servidor->readString(true);
	int num = servidor->readLongInt(true);
	std::cout<<num<<" "<<std::endl;

	servidor->closeServer();
	return 0 ;
}