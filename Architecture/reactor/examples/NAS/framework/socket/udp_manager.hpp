#ifndef RD70_UDP_MANAGER
#define RD70_UDP_MANAGER

#include <netinet/in.h>
#include <cstddef>

#include "command.hpp"
#include "factory.hpp"

namespace ilrd
{

using FD = int;
using sa_i  = struct sockaddr_in;
using cmdFact_t  = Factory<std::shared_ptr<Command>, char, void *>;

class UDPManager
{
public:
    explicit UDPManager(int port_, cmdFact_t &fact_);
    //~UDPManager() = default;

    FD CreateSocketAndBind();
    void ReceiveAndHandleRequest();

    static const size_t PACK_LEN = 4120;
    
private:
    void CheckRet(int ret_, std::string msg_);

    int m_port;
    int m_sockfd;
    cmdFact_t& m_fact;
};

} // namespace ilrd

#endif // RD70_UDP_MANAGER
