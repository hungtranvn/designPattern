#include <iostream>
#include <functional>
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
#include "reactor.hpp"
#include "rw_cmd.hpp"
#include "writer.hpp"
#include "reader.hpp"
// #include "udp_server.hpp" - DELETED
#include "factory.hpp"
#include "sever_increase.hpp"
#include "logger.hpp"

using namespace ilrd;
using namespace std;

#define MAX(x, y) (x > y ? x : y)
#define MAX_CLIENTS (30)
#define BUFF_LEN (20)
#define MAX_CONN (3)

void TCPCheckReturnedVal(int ret, const char *msg);
int TCPCreateSocketAndBind(struct sockaddr_in *sa_p, int domain, int type, 
                                    int protocol, int family, int port, int addr);
void TCPListen(int masterSocket, int conn_n);
void TCPAcceptAndSend(int masterSocket);
void TCPPlay(int clientSocket);
void PingStdin(char *input);

Reactor reactor;

// int main(int argc, char *argv[])
int main()
{
    // FD tcpSockFd = -1;
    // struct sockaddr_in serverAddr;
    // int port = 0;

    // port = htons(atoi(argv[argc - 1]));
    // cout << "listening on port: " << port << endl;

    // tcpSockFd = TCPCreateSocketAndBind(&serverAddr, AF_INET, SOCK_STREAM, 0,
    //                                                 AF_INET, port, INADDR_ANY);
    // FDPair tcpPair = make_pair(tcpSockFd, FDListener::READ);

    // TCPListen(tcpSockFd, MAX_CONN);

    // reactor.AddFD(tcpPair, TCPAcceptAndSend);

    // reactor.Start();

    return 0;
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
    int masterSocket = 0;
    int status = 0;

    masterSocket = socket(domain, type, protocol);
    TCPCheckReturnedVal(masterSocket, "TCP socket() failed");

    printf("TCP Socket successfully created!\n");

    memset(sa_p, 0, sizeof(*sa_p));
    sa_p->sin_family = family;
    sa_p->sin_addr.s_addr = addr;
    sa_p->sin_port = port;

    status = bind(masterSocket, (struct sockaddr *)sa_p, sizeof(struct sockaddr_in));
    TCPCheckReturnedVal(status, "bind() failed");

    printf("TCP Socket successfully binded!\n\n");

    return masterSocket;
}

void TCPListen(int masterSocket, int conn_n)
{
    int status = 0;

    status = listen(masterSocket, conn_n);
    TCPCheckReturnedVal(status, "listen() failed.\n");

    printf("TCP Server is listening.\n\n");
}

void TCPAcceptAndSend(int masterSocket)
{
    unsigned int length = 0;
    int newSocket = -1;
    char buff[BUFF_LEN];
    struct sockaddr_in clientAddr;

    bzero(buff, BUFF_LEN);
    length = sizeof(struct sockaddr_in);

    newSocket = accept(masterSocket, (struct sockaddr *)&clientAddr, &length);
    TCPCheckReturnedVal(newSocket, "accept() failed.\n");

    FDPair newPair = make_pair(newSocket, FDListener::READ);
    reactor.AddFD(newPair, TCPPlay);

    printf("New connection, socket fd is: %d, ip is: %s, port: %d\n\n",
           newSocket,
           inet_ntoa(clientAddr.sin_addr),
           ntohs(clientAddr.sin_port));
}

void TCPPlay(int clientSocket)
{
    char buff[BUFF_LEN];
    char po[] = "pong!";

    if (0 == read(clientSocket, buff, sizeof(buff)))
    {
        FDPair clientPair = make_pair(clientSocket, FDListener::READ);
        reactor.RemoveFD(clientPair);
    }
    else
    {
        printf("TCP Client: %s\n", buff);

        sleep(1);

        if (send(clientSocket, po, strlen(po), 0) < 0)
        {
            perror("send() failed.");
        }
    }
}

void PingStdin(char *input)
{
    if (! strcmp(input, "ping\n"))
    {
        printf("pong\n");
    }
}