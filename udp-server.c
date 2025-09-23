// // UDP CLIENT

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <arpa/inet.h>

// int main() {
//     int sockfd;  
//     char buffer[1024];  
//     struct sockaddr_in server;  
//     socklen_t addr_size;  

//     sockfd = socket(AF_INET, SOCK_DGRAM, 0);  

//     server.sin_family = AF_INET;            // 2 (AF_INET)
//     server.sin_port = htons(8080);          // 0x1F90 = 8080
//     server.sin_addr.s_addr = inet_addr("127.0.0.1");  

//     strcpy(buffer, "Hello UDP Server!");
//     sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&server, sizeof(server));

//     addr_size = sizeof(server);
//     recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&server, &addr_size);  
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

int main(){
    int sockfd;
    char buffer[1024];

    struct sockaddr_in server;
    socklen_t addr_size;

    sockfd = socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    strcpy(buffer,"Hi");
    sendto(sockfd,buffer,strlen(buffer),0,(struct sockaddr*)&server,sizeof(server));

    addr_size = sizeof(server);
    recvfrom(sockfd,buffer,sizeof(buffer),0,(struct sockaddr*)&server,&addr_size);

    close(sockfd);
    return 0;
}