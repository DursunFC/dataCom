#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include<winsock3.h>
#include<winsock2.h>
#include<netinet/socklen.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    char *response = "Hello there";

    // Soket oluþturma
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Socket baðlantý
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Baðlantý
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    printf("Server is listening on port %d...\n", PORT);

    // Onay
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *),&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Okuma
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Client: %s\n", buffer);

    // Mesaj 
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client.\n");

    // Disconnect
    close(new_socket);
    close(server_fd);
    return 0;
}

