// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <arpa/inet.h> 
// #include <sys/socket.h>
// #include <netinet/in.h>

// int main() {
//     int sockfd;
//     char buffer[1024];
//     struct sockaddr_in server;

//     sockfd = socket(AF_INET, SOCK_STREAM, 0);

//     server.sin_family = AF_INET;
//     server.sin_port = htons(8080);
//     server.sin_addr.s_addr = inet_addr("127.0.0.1");

//     connect(sockfd, (struct sockaddr*)&server, sizeof(server));

//     strcpy(buffer, "Hello TCP Server!");
//     send(sockfd, buffer, strlen(buffer), 0);

//     recv(sockfd, buffer, sizeof(buffer), 0);

//     close(sockfd);
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in server;

    sockfd = socket(AF_INET,SOCK_STREAM,0);


    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd,(struct sockaddr*)& server,sizeof(server));

    strcpy(buffer,"Hello TCP Server!");
    send(sockfd,buffer,strlen(buffer),0);
    recv(sockfd,buffer,sizeof(buffer),0);
    close(sockfd);
    return 0;
}