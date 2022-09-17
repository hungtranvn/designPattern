#include <sys/socket.h>
#include <cstring>
#include <dlfcn.h>
#include <fstream>
#include <functional>
#include <errno.h>

#include "logger.hpp"
#include "udp_manager.hpp"
#include "udp_request_handler.hpp"

namespace ilrd
{

using namespace std;

UDPManager::UDPManager(int port, cmdFact_t &fact)
    : m_port(port), m_sockfd(-1), m_fact(fact)
{
}

FD UDPManager::CreateSocketAndBind()
{
    sa_i serverAddr;

    m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    CheckRet(m_sockfd, "socket() failed");

    cout << "UDP Socket successfully created!" << endl;

    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = m_port;
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int status = bind(m_sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
    CheckRet(status, "bind() failed");

    cout << "UDP Socket successfully binded!" << endl;

    return m_sockfd;
}

void UDPManager::ReceiveAndHandleRequest()
{   
    sa_i cliAddr;
    char buffer[PACK_LEN] = {0};

    socklen_t length = sizeof(sa_i);
    memset(&cliAddr, 0, length);

    int rcvdByts = recvfrom(m_sockfd, buffer, PACK_LEN, 0,
                                    (struct sockaddr *)&cliAddr, &length);
    CheckRet(rcvdByts, "recvfrom() failed");

    UDPRequestHandler udpRequestHandler(m_sockfd, buffer, &cliAddr, m_fact);
    udpRequestHandler.HandleRequest();
}

void UDPManager::CheckRet(int ret, string msg)
{
    if (-1 == ret)
    {
        cerr << "\nUDPManager: " << strerror(errno) << endl;
        GetLoggerSingleton()->Log(Logger::ERROR, msg);
    }
}


} // namespace ilrd