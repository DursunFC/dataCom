#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define	PORT 8080

void main(){
	int clientSocket;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	clientSocket=socket(PF_INET, SOCK_STREAM, 0);
	memset(&serverAddr,'\0',sizeof(serverAddr));
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(PORT);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	
	recv(clientSocket, buffer, 1024, 0);
	printf("Data Received: %s",buffer);
}
