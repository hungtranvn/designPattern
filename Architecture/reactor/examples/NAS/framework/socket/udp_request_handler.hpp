#ifndef RD70_UDP_REQUEST_HANDLER
#define RD70_UDP_REQUEST_HANDLER

#include <iostream>
#include <netinet/in.h>
#include <memory>

#include "command.hpp"
#include "factory.hpp"

namespace ilrd
{

using sa_i = struct sockaddr_in;
using cmdFact_t = Factory<std::shared_ptr<Command>, char, void *>;

class UDPRequestHandler
{
public:
    explicit UDPRequestHandler(int sockfd_, char *buffer_, sa_i *clientAddr_, 
                                                            cmdFact_t &fact_);
    void HandleRequest();

private:
    int m_sockfd;
    char *m_buff;
    sa_i *m_clientAddr;
    cmdFact_t& m_fact;
};

} // namespace ilrd

#endif // RD70_UDP_REQUEST_HANDLER
