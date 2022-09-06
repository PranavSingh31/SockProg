#icnlude<stdio.h>
#include<netdb.h>
#include<string.h>
#include<sts/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#define MAX 80
#define PORT 8000
#define SA struct sockaddr

void func(int connfd){
	char buff[MAX];
	int n;
	
	for(;;){
		bzero(buff,MAX);
		
		//---------------------------------------------------------
		read(connfd,buff,sizeof(buff));
		printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n=0;
        
        //copying message in buffer
        while((buff[n++])=getchar()) !='\n');
        
        write(connfd, buff, sizeof(buff));
        
        if(strcmp("exit",buff,4)==0){
        	print("Server Exit....\n");
        	break;
		}
	}
}

int main(){
	int sockfd , connfd , len;
	struct sockaddr_in servaddr, cli;
	
	//-------------------------------------------------------------
	sockfd = socket (AF_INET,SOCK_STREAM,0);
	if(sockfd==-1){
		printf("socket creating failed...\n");
		exit(0);
	}
	else{
		printf("socket successfully created... \n");
	}
	//-------------------------------------------------------------
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
	servaddr.sin_port(PORT);
	//-------------------------------------------------------------
	if((bind(sockfd,(SA*)&servaddr, sizeof(servaddr))) != 0){
		printf("socket bind failed..\n");
		exit(0);
	}
	else printf("socket successfully binded..\n")
	//-------------------------------------------------------------
	if((listen(sockfd,5))!=0){
		printf("Listen failed...\n");
		exit(0);
	}
	else printf("Server listening..\n");
	//-------------------------------------------------------------
	connfd = accept(sockfd,(SA*)&cli,&len);
	if(connfd<0){
		printf("Server accept failed...\n");
		exit(0);
	}
	else print("Server accept the client....\n");
	//-------------------------------------------------------------
	func(connfd);
	//-------------------------------------------------------------
	close(sockfd);
}
