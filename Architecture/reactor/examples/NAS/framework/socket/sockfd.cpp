#include <unistd.h>

#include "sockfd.hpp"

namespace ilrd
{

Sockfd::Sockfd()
{}

Sockfd::~Sockfd()
{
    close(m_sockfd);
}

void Sockfd::SetSockfd(int sockfd_)
{
    m_sockfd = sockfd_;
}

int Sockfd::GetSockfd() const
{
    return m_sockfd;
}

} // namespace ilrd