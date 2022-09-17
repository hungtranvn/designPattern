#ifndef RD70_READER
#define RD70_READER

#include <iostream>     // std
#include <memory>       // shared_ptr

#include "rw_cmd.hpp"
#include "send_data.hpp"
#include "logger.hpp"

namespace ilrd
{

using sa_i = struct sockaddr_in;

class Reader: public RWCmd
{
public:
    explicit Reader(int sockfd_, char *buff_, sa_i *cliAddr_);
    
    // Generated Dtor
    // Generated CCtor - SHOULD BLOCK?
    // Generated assignment operator - SHOULD BLOCK?

    virtual bool operator()();

private:
    void ReadFromFile();
    void Send();
    
    sa_i *m_cliAddr;
    Logger *m_logger;
};

extern "C"
{
    std::shared_ptr<Command> CreateCmd(void *sendData);
    char GetKey(); 
}

} // namespace ilrd

#endif // RD70_READER