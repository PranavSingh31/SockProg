#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>

#define Port 8080

int main(){
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1){
        printf("Socket not created...\n");
        return 0;
    }
    else printf("Socket Created Successfully...\n");
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(Port);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int len = sizeof(servaddr);

    char buff[256];
    int n = 0;
    for (;;){
        bzero(buff, sizeof(buff));

        n = 0;
        printf("Message to server : ");
        while ((buff[n++] = getchar()) != '\n');

        sendto(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, len);

        bzero(buff, sizeof(buff));

        recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&servaddr, &len);
        printf("\nMessage from the server : %s\n", buff);

        if (strncmp(buff, "exit", 4) == 0)
        {
            printf("Client exit...\n");
            break;
        }
    }

    close(sockfd);
}
