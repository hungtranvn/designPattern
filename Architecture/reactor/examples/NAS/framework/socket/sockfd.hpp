#ifndef RD70_SOCKETFD
#define RD70_SOCKETFD

#include <sys/types.h> /* sendto */
#include <arpa/inet.h> /* htons */

namespace ilrd
{

class Sockfd
{
public:
    Sockfd();
    ~Sockfd();

    void SetSockfd(int sockfd_);
    int GetSockfd() const;

private:
    int m_sockfd;
};

} // namespace ilrd

#endif // RD70_SOCKETFD