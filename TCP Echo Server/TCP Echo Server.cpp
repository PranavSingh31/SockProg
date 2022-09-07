#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#define PORT 5035

int main(){
    int sockfd,echofd,len;
    struct sockaddr_in servaddr,cliaddr;
    char buffer[80];
       
    sockfd=socket(AF_INET,SOCK_STREAM,0);
       
    bzero(&servaddr, sizeof(servaddr));

    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    serv_addr.sin_port=htons(PORT);
       
    printf("\nStart");
       
    bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    printf("\nListening...\n");
       
    listen(sockfd,5);

    len=sizeof(cliaddr);
    
    newsockfd=accept(sockfd,(struct sockaddr*)&cliaddr,&len);
    printf("\nAccepted\n");

    read(newsockfd,buffer,80);
    printf("\nClient message:%s",buffer);
       
    write(newsockfd,buffer,80);
    printf("\n");
       
    close(sockfd);
       
    return 0;
}
