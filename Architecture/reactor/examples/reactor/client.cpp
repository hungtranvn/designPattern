#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <signal.h>
#include <arpa/inet.h>

#define PORT 9888 // the port client will be connecting to 

#define MAXDATASIZE 100 // max number of bytes we can get at once 

void sigchld_handler(int s){
    while(wait(NULL)>0);
    printf("client exit\n");
    exit(0);
}

int main(int argc, char *argv[]){

    int sockfd, numbytes;  
    char buf[MAXDATASIZE];
//    struct hostent *he;
    struct sockaddr_in their_addr; // connector's address information 
    struct sigaction sa;
    pid_t pid ;

    /*
    if (argc != 2) {
      fprintf(stderr,"usage: client hostname\n");
      exit(1);
    }*/

    /*
    if ((he=gethostbyname(argv[1])) == NULL) {  // get the host info 
        perror("gethostbyname");
       exit(1);
    }*/

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
         perror("socket");
         exit(1);
    }

    their_addr.sin_family = AF_INET;    // host byte order 
    their_addr.sin_port = htons(PORT);  // short, network byte order 
    //their_addr.sin_addr = *((struct in_addr *)he->h_addr);

    inet_pton(AF_INET, "127.0.0.1", &(their_addr.sin_addr));
    memset(&(their_addr.sin_zero), '\0', 8);  // zero the rest of the struct 

    sa.sa_handler = sigchld_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    
    if (sigaction(SIGCHLD, &sa, NULL) == -1){
        perror("sigaction");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    if ((pid = fork()) > 0){
        close(STDIN_FILENO);
        while(1){
            if ((numbytes=recv(sockfd, buf, MAXDATASIZE-1, 0)) == -1) {
                perror("recv");
                exit(1);
            }
            if (numbytes == 0)
            {
                printf("server crash\n");
                kill(pid, 9);
                exit(0);
            }
            buf[numbytes] = '\0';
            printf("Received: %s\n",buf);
            fflush(stdout);
        }
    } else if(pid == 0) {
        char sendBuf[100];
        while(1) {
            gets(sendBuf);
            int size = strlen(sendBuf);
            if (size == 0)
              continue;
            if (strcmp(sendBuf, "quit") == 0) 
                return 0;
            //int n = send(sockfd, sendBuf, strlen(sendBuf)+1, 0);
            int n = send(sockfd, sendBuf, size, 0);
            if (n == -1)
                perror("send");
        }
    } else 
        printf("fork error");
    close(sockfd);
    return 0;
} 