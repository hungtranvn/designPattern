#ifndef RD70_SEND_DATA
#define RD70_SEND_DATA

namespace ilrd
{

using sa_i = struct sockaddr_in;

class SendData
{
public:
    explicit SendData(int sockfd_, char *buff_, sa_i *cliAddr_)
        : m_sockfd(sockfd_), m_buff(buff_), m_cliAddr(cliAddr_)
    {}

    // Generated Dtor
    // Generated CCtor
    // Generated assignment operator

    int GetSockfd()
    {
        return m_sockfd;
    }

    char *GetBuffer()
    {
        return m_buff;
    }

    sa_i *GetClientAddr()
    {
        return m_cliAddr;
    }

private:
    int m_sockfd;
    char *m_buff;
    sa_i *m_cliAddr;
};


} // namespace ilrd

#endif // RD70_SEND_DATA