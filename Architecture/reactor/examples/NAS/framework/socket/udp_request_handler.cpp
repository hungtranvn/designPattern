#include <dlfcn.h>

#include "udp_request_handler.hpp"
#include "send_data.hpp"
#include "logger.hpp"

namespace ilrd
{

using namespace std;

UDPRequestHandler::UDPRequestHandler(int sockfd, char *buffer, sa_i *clientAddr, 
                                                                cmdFact_t &fact)
    : m_sockfd(sockfd), m_buff(buffer), m_clientAddr(clientAddr), m_fact(fact)
{
}

void UDPRequestHandler::HandleRequest()
{      
    char type = *(char *)m_buff;

    SendData sendData(m_sockfd, m_buff, m_clientAddr);

    if (! m_fact.IsKeyExist(type))
    {
        cout << "Plugin doesn't exist!" << endl;
    }
    else
    {
        shared_ptr<Command> cmd = m_fact.Create(type, &sendData);
        GetLoggerSingleton()->Log(Logger::INFO, "Create function of Plugin\
                             (key = " + to_string((int)type) + ") was created");
        (*cmd)();
    }
}

} // namespace ilrd