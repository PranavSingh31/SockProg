#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(){
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char buffer[80];
    
    bzero(&servaddr, sizeof(servaddr));
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
    serv_addr.sin_port=htons(SERV_TCP_PORT);
       
    printf("\nReady for sending...");
    connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("\nEnter the message to send\n");
    printf("\nClient: ");
    
	fgets(buffer,80,stdin);
    write(sockfd,buffer,4096);
    printf("Serverecho:%s",buffer);
    printf("\n");
    
    close(sockfd);
    return 0;
}
