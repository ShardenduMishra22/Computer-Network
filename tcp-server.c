// TCP SERVER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main() {
    char buffer[1024];
    struct sockaddr_in server, client;
    socklen_t addr_size;

    // 1. Create socket (IPv4, TCP, default protocol)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Set server address (family = IPv4, port = 8080, any interface)
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);       // host to network short
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // bind to all interfaces

    // 3. Bind socket to given IP and port
    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    // 4. Listen for incoming connections (max queue size = 5)
    listen(sockfd, 5);

    // 5. Accept a client connection
    int newsock = accept(sockfd, (struct sockaddr*)&client, sizeof(client));

    // 6. Receive data from client
    recv(newsock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    // 7. Send response back to client
    strcpy(buffer, "Hello from TCP Server!");
    send(newsock, buffer, strlen(buffer), 0);

    // 8. Close sockets
    close(newsock);
    close(sockfd);
    return 0;
}