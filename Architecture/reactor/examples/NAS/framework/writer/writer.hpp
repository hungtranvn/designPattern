#ifndef RD70_WRITER
#define RD70_WRITER

#include <iostream>     // std
#include <memory>       // shared_ptr

#include "rw_cmd.hpp"
#include "send_data.hpp"
#include "logger.hpp"

namespace ilrd
{

using sa_i = struct sockaddr_in;

class Writer: public RWCmd
{
public:
    explicit Writer(int sockfd_, char *buff_, sa_i *cliAddr_);

    // Generated Dtor
    // Generated CCtor - SHOLD BLOCK?
    // Generated assignment operator - SHOULD BLOCK?

    virtual bool operator()();

private:
    void WriteToFile();
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

#endif // RD70_WRITER