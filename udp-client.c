#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server, client;
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    addr_size = sizeof(client);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &addr_size);

    strcpy(buffer, "Hello from UDP Server!");
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&client, addr_size);

    close(sockfd);
    return 0;
}