#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define Port 8080

void print(int sockfd){
	printf("Server entered this function\n");
	char buff[256];
	int n;
	struct sockaddr_in newaddr;
	int len = sizeof(newaddr);

	for (;;){
		bzero(buff, sizeof(buff));

		recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&newaddr, &len);
		printf("Message from client : %s\n", buff);

		bzero(buff, sizeof(buff));
		n = 0;
		printf("Message to client : ");
		while ((buff[n++] = getchar()) != '\n');
		sendto(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&newaddr, len);

		if (strncmp(buff, "exit", 4) == 0){
			printf("Server exit...\n");
			break;
		}
	}
}

int main(){
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd == -1){
		printf("Socket creation failed...\n");
		return 0;
	}
	else{
		printf("Socket creation successfull...\n");
	}

	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(Port);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0){
		printf("socket bind failed...\n");
		return 0;
	}
	else{
		printf("socket bind successfully...\n");
	}

	print(sockfd);

	close(sockfd);
}
