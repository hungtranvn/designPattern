#ifndef RD70_RW_CMD
#define RD70_RW_CMD

#include <iostream>
#include <string>
#include <sstream> // ostringstream

#include "command.hpp"

namespace ilrd
{

class RWCmd : public Command
{
public:
    explicit RWCmd(int sockfd_, char *buff_) 
        : m_sockfd(sockfd_), m_buff(buff_), m_fullname("")
    {
        SetFile();
    }

    virtual ~RWCmd(){}

    // Generated CCtor
    // Generated assignment operator

    virtual bool operator()() = 0;

protected:
    int m_sockfd;
    char *m_buff;
    std::string m_fullname;
    static const size_t BUFF_LEN = 4096;

private:
    void SetFile()
    {
        unsigned long uid = 0;
        unsigned long blockIdx = 0;
        std::ostringstream fullname;

        uid = *(unsigned long *)(m_buff + 5);
        blockIdx = *(unsigned long *)(m_buff + 13);

        fullname << ntohl(uid) << ntohl(blockIdx) << ".txt";

        m_fullname = fullname.str();
    }
};

} // namespace ilrd

#endif // RD70_RW_CMD