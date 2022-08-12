#include <sys/select.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include <algorithm>

#include "fdlistener.hpp"

using namespace ilrd;
using namespace std;

#define MAX(x, y) (x > y ? x : y)
#define MAX_CLIENTS (30)
#define BUFF_LEN (20)
#define MAX_CONN (3)

//___________________________ Multiserver Functions ____________________________

void UDPCheckReturnedVal(int ret, const char *msg);
int UDPCreateSocketAndBind(struct sockaddr_in *sa_p, int domain, int type, 
                                    int protocol, int family, int port, int addr);
void UDPRecvAndSend(int sockfd, char *buffer, size_t len, int rcv_flag, 
                                    int snd_flag, struct sockaddr_in *client_addr);
void TCPCheckReturnedVal(int ret, const char *msg);
int TCPCreateSocketAndBind(struct sockaddr_in *sa_p, int domain, int type, 
                                    int protocol, int family, int port, int addr);
void TCPListen(int master_socket, int conn_n);
void TCPAccept(int master_socket, struct sockaddr_in *client, 
                                                            int *new_socket_out);
void PingStdin(char *input);

static void AddFDsPairs(vector<pair<FD, FDListener::FDType>>& fdVec, 
                                                FD stdinFd, FD udpFd, FD tcpFd);

//______________________________________________________________________________

int main(int argc, char *argv[])
{
    FD stdinFd = 0;
    FD tcpSockFd = -1;
    FD udpSockfd = -1;
    FD newSocket = 0;
    int port = 0;
    char buffer[BUFF_LEN];
    char input[BUFF_LEN] = {0};

    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;

    port = htons(atoi(argv[argc - 1]));

    udpSockfd = UDPCreateSocketAndBind(&serverAddr, AF_INET, SOCK_DGRAM, 0,
                                        AF_INET, port, INADDR_ANY);

    tcpSockFd = TCPCreateSocketAndBind(&serverAddr, AF_INET, SOCK_STREAM, 0,
                                           AF_INET, port, INADDR_ANY);
    TCPListen(tcpSockFd, MAX_CONN);

    vector<pair<FD, FDListener::FDType>> fdVec;

    AddFDsPairs(fdVec, stdinFd, udpSockfd, tcpSockFd);

    FDListener fdListener;

    while (1)
    {
        vector<pair<FD, FDListener::FDType>> clientFDVec(fdListener.Wait(fdVec));
        
        for_each(clientFDVec.begin(), clientFDVec.end(), 
                                        [&](pair<FD, FDListener::FDType> pair)
        {
            if (pair.first == tcpSockFd)
            {
                char po[] = "pong!";

                TCPAccept(tcpSockFd, &clientAddr, &newSocket);

                if (send(newSocket, po, strlen(po), 0) < 0)
                {
                    perror("send() failed.");
                }
            }
            if (pair.first == udpSockfd)
            {
                UDPRecvAndSend(udpSockfd, buffer, sizeof(buffer), MSG_WAITALL,
                           MSG_CONFIRM, &clientAddr);
            }
            if (pair.first == stdinFd)
            {
                int ret = 0;

                memset(input, 0, BUFF_LEN);
                ret = read(stdinFd, input, 10);

                if ((-1 != ret) && (strcmp(input, "exit\n")))
                {
                    PingStdin(input);
                }
            }
        });
    }

    close(udpSockfd);

    return 0;
}

/*___________________________________ UDP ____________________________________*/

void  UDPCheckReturnedVal(int ret, const char *msg)
{
    if (-1 == ret)
    {
        perror(msg);
        exit(1);
    }
}

int UDPCreateSocketAndBind(struct sockaddr_in *sa_p, int domain, int type, 
                                    int protocol, int family, int port, int addr)
{
    int udpfd = 0;
    int status = 0;

    udpfd = socket(domain, type, protocol);
    UDPCheckReturnedVal(udpfd, "socket() failed");

    printf("UDP Socket successfully created!\n");

    memset(sa_p, 0, sizeof(struct sockaddr_in));
    sa_p->sin_family = family;
    sa_p->sin_addr.s_addr = htonl(addr);
    sa_p->sin_port = port;

    status = bind(udpfd, (struct sockaddr *)sa_p, sizeof(*sa_p));
    UDPCheckReturnedVal(status, "bind() failed");

    printf("UDP Socket successfully binded!\n\n");

    return udpfd;
}

void UDPRecvAndSend(int sockfd, char *buffer, size_t len, int rcv_flag, 
                                    int snd_flag, struct sockaddr_in *client_addr)
{
    socklen_t length = 0;
    int status = 0;
    int rcvd_byts = 0;
    char po[] = "pong!";

    length = sizeof(struct sockaddr_in);
    memset(client_addr, 0, sizeof(struct sockaddr_in));

   
    rcvd_byts = recvfrom(sockfd, (char *)buffer, len, rcv_flag, 
                                    (struct sockaddr *)client_addr, &length);
    UDPCheckReturnedVal(rcvd_byts, "recvfrom() failed");

    printf("UDP Client: %s\n", buffer);

    status = sendto(sockfd, po, sizeof(po), snd_flag, 
                            (const struct sockaddr *)client_addr, length);
    UDPCheckReturnedVal(status, "send() failed");
    
}


/*___________________________________ TCP ____________________________________*/

void TCPCheckReturnedVal(int ret, const char *msg)
{
    if (-1 == ret)
    {
        perror(msg);
        exit(1);
    }
}

int TCPCreateSocketAndBind(struct sockaddr_in *sa_p, int domain, int type, 
                                    int protocol, int family, int port, int addr)
{
    int master_socket = 0;
    int status = 0;

    master_socket = socket(domain, type, protocol);
    TCPCheckReturnedVal(master_socket, "TCP socket() failed");

    printf("TCP Socket successfully created!\n");

    memset(sa_p, 0, sizeof(*sa_p));
    sa_p->sin_family = family;
    sa_p->sin_addr.s_addr = addr;
    sa_p->sin_port = port;

    status = bind(master_socket, (struct sockaddr *)sa_p, sizeof(struct sockaddr_in));
    TCPCheckReturnedVal(status, "bind() failed");

    printf("TCP Socket successfully binded!\n\n");

    return master_socket;
}

void TCPListen(int master_socket, int conn_n)
{
    int status = 0;

    status = listen(master_socket, conn_n);
    TCPCheckReturnedVal(status, "listen() failed.\n");

    printf("TCP Server is listening.\n\n");
}

void TCPAccept(int master_socket, struct sockaddr_in *client, 
                                                            int *new_socket_out)
{
    unsigned int length = 0;
    char buff[BUFF_LEN];

    bzero(buff, BUFF_LEN);
    length = sizeof(struct sockaddr_in);

    *new_socket_out = accept(master_socket, (struct sockaddr *)client, &length);
    TCPCheckReturnedVal(*new_socket_out, "accept() failed.\n");

    printf("New connection, socket fd is: %d, ip is: %s, port: %d\n\n",
           *new_socket_out,
           inet_ntoa(client->sin_addr),
           ntohs(client->sin_port));

    read(*new_socket_out, buff, sizeof(buff));
    printf("TCP Client: %s\n", buff);
}

void PingStdin(char *input)
{
    if (! strcmp(input, "ping\n"))
    {
        printf("pong\n");
    }
}


/*____________________________Static Functions________________________________*/


static void AddFDsPairs(vector<pair<FD, FDListener::FDType>>& fdVec, FD stdinFd, 
                        FD udpFd, FD tcpFd)
{    
    pair<FD, FDListener::FDType> stdinPair = make_pair(stdinFd, FDListener::READ);
    pair<FD, FDListener::FDType> udpPair = make_pair(udpFd, FDListener::READ);
    pair<FD, FDListener::FDType> tcpPair = make_pair(tcpFd, FDListener::READ);

    fdVec.push_back(stdinPair);
    fdVec.push_back(udpPair);
    fdVec.push_back(tcpPair);
}

