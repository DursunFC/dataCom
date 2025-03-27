#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<winsock2.h>

#define PORT 8080
#define	BUFFER_SIZE 1024

void main(){
	int server_fd, new_socket;
	struct sockaddr_in address;
	int opt=1;
	int addrlen= sizeof(address);
	char buffer[BUFFER_SIZE]={0};

	if((server_fd=socket(AF_INET, SOCK_STREAM, 0))==0){
		printf("Socket failed");
		exit(EXIT_FAILURE);
	}
}
