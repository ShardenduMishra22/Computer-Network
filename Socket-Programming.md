Conversation opened. 1 read message.

Skip to content
Using Indian Institute of Information Technology Dharwad Mail with screen readers

1 of 5,124
(no subject)
External
Inbox

Anas
3:02 AM (1 minute ago)
to me

TCP SERVER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, newsock;
    char buffer[1024];
    struct sockaddr_in server, client;
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));
    listen(sockfd, 5);

    addr_size = sizeof(client);
    newsock = accept(sockfd, (struct sockaddr*)&client, &addr_size);

    recv(newsock, buffer, sizeof(buffer), 0);
    printf("Client: %s\n", buffer);

    strcpy(buffer, "Hello from TCP Server!");
    send(newsock, buffer, strlen(buffer), 0);

    close(newsock);
    close(sockfd);
    return 0;
}
TCP CLIENT
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
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr*)&server, sizeof(server));

    strcpy(buffer, "Hello TCP Server!");
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Server: %s\n", buffer);

    close(sockfd);
    return 0;
}
UDP SERVER
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
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    addr_size = sizeof(client);
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&client, &addr_size);
    printf("Client: %s\n", buffer);

    strcpy(buffer, "Hello from UDP Server!");
    sendto(sockfd, buffer, strlen(buffer), 0,
           (struct sockaddr*)&client, addr_size);

    close(sockfd);
    return 0;
}
UDP CLIENT
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
    struct sockaddr_in server;
    socklen_t addr_size;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer, "Hello UDP Server!");
    sendto(sockfd, buffer, strlen(buffer), 0,
           (struct sockaddr*)&server, sizeof(server));

    addr_size = sizeof(server);
    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&server, &addr_size);
    printf("Server: %s\n", buffer);

    close(sockfd);
    return 0;
}
