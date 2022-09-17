#include "Acceptor.h"
#include <reactor/trace.h>

#include <chrono>
#include <cstring>

#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/poll.h>

namespace reactor
{

bool
Acceptor::listen_ipv4(const uint16_t     &port,
                      const std::string  &address,
                      const int          &backlog)
{
  if (listen_ != INVALID_IO_HANDLE)
    ::close(listen_);

  listen_ = socket(AF_INET, SOCK_STREAM, 0); /* do some error checking! */

  int enable = 1;
  if (setsockopt(listen_, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

  struct sockaddr_in  addr4_;

  addr4_.sin_family  = AF_INET;      /* host byte order */
  addr4_.sin_port    = htons(port);  /* short, network byte order */
  inet_pton(AF_INET, address.c_str(), &(addr4_.sin_addr));
  memset(&(addr4_.sin_zero), 0x00, sizeof(addr4_.sin_zero)); /* zero the rest of the struct */

  /* don't forget your error checking for these calls: */
  if (::bind(listen_, (struct sockaddr *)&addr4_, sizeof(struct sockaddr)) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

  set_listen_port(port, address);

  if (::listen(listen_, backlog) < 0)
    return false;

  int io_flag = fcntl(listen_, F_GETFL, 0);
  fcntl(listen_, F_SETFL, io_flag | O_NONBLOCK);

  ipv4_ = true;
  ipv6_ = false;
  return true;
}
bool
Acceptor::listen_ipv6(const uint16_t     &port,
                      const std::string  &address,
                      const int          &backlog)
{
  if (listen_ != INVALID_IO_HANDLE)
    ::close(listen_);

  listen_ = socket(AF_INET6, SOCK_STREAM, 0); /* do some error checking! */

  int enable = 1;
  // ONLY IPV6
  if (setsockopt(listen_, IPPROTO_IPV6, IPV6_V6ONLY, (char *)&enable, sizeof(enable)) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

  if (setsockopt(listen_, SOL_SOCKET, SO_REUSEADDR, (char *)&enable, sizeof(enable)) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

//  struct sockaddr_in6 addr6_;
  addr6_.sin6_family = AF_INET6;      /* host byte order */
  addr6_.sin6_port   = htons(port);  /* short, network byte order */
  inet_pton(AF_INET6, address.c_str(), &(addr6_.sin6_addr));

  /* don't forget your error checking for these calls: */
  if (::bind(listen_, (struct sockaddr *)&addr6_, sizeof(addr6_)) < 0)
  {
    reactor_trace << strerror(errno) << std::endl;
    return false;
  }

  set_listen_port(port, address);

  if (::listen(listen_, backlog) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

  int io_flag = fcntl(listen_, F_GETFL, 0);
  fcntl(listen_, F_SETFL, io_flag | O_NONBLOCK);

  ipv4_ = false;
  ipv6_ = true;
  return true;
}

bool
Acceptor::listen_ipv46(const uint16_t     &port,
                       const std::string  &address,
                       const int          &backlog)
{
  if (listen_ != INVALID_IO_HANDLE)
    ::close(listen_);

  listen_ = socket(AF_INET6, SOCK_STREAM, 0); /* do some error checking! */

  int enable = 1;
  if (setsockopt(listen_, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

//  struct sockaddr_in6 addr6_;
  addr6_.sin6_family = AF_INET6;      /* host byte order */
  addr6_.sin6_port   = htons(port);  /* short, network byte order */
  inet_pton(AF_INET6, address.c_str(), &(addr6_.sin6_addr));

  /* don't forget your error checking for these calls: */
  if (::bind(listen_, (struct sockaddr *)&addr6_, sizeof(addr6_)) < 0)
  {
    reactor_trace << strerror(errno) << std::endl;
    return false;
  }

  set_listen_port(port, address);

  if (::listen(listen_, backlog) < 0)
  {
    reactor_trace << strerror(errno) << ":" << listen_ << std::endl;
    return false;
  }

  int io_flag = fcntl(listen_, F_GETFL, 0);
  fcntl(listen_, F_SETFL, io_flag | O_NONBLOCK);

  ipv4_ = true;
  ipv6_ = true;
  return true;
}

static thread_local struct pollfd fds[1];
static thread_local bool pollfd_init = false;

io_handle_t
Acceptor::accept(struct ::sockaddr_storage &client_addr, const int32_t &timeout_msec)
{
  if (pollfd_init == false)
  {
    fds[0].fd = listen_;
    fds[0].events = POLLIN | POLLPRI | POLLERR | POLLHUP;
    pollfd_init = true;
  }

  std::chrono::steady_clock::time_point timeout_point =
      std::chrono::steady_clock::now() + std::chrono::milliseconds(timeout_msec);

  int32_t remain_timeout_msec = timeout_msec;
  int32_t poll_result = 0;

  while (true)
  {
    poll_result = poll(fds, 1, remain_timeout_msec);

    if (poll_result <= 0)
      return poll_result;

    // when shutdown
    if (!(fds[0].revents & (POLLIN | POLLPRI)))
      break;

    static int sin_size = sizeof(client_addr);
    io_handle_t new_io_handle = ::accept(listen_, (sockaddr *)&client_addr, (socklen_t*)&sin_size);

    if (new_io_handle < 0 && errno != EWOULDBLOCK)
      return -1;

    if (new_io_handle < 0 && errno == EWOULDBLOCK)
    {
      if (timeout_msec >= 0)
      {
        remain_timeout_msec =
            std::chrono::duration_cast<std::chrono::milliseconds>
        (timeout_point - std::chrono::steady_clock::now()).count();

        if (remain_timeout_msec <= 0)
          return 0;
      }
      else
      {
        remain_timeout_msec = -1;
      }

      continue;
    }

    if (nonblock_client_ == true)
    {
      int io_flag = fcntl(new_io_handle, F_GETFL, 0);
      fcntl(new_io_handle, F_SETFL, io_flag | O_NONBLOCK);
    }

    return new_io_handle;
  }

  ::close(listen_);
  return -1;
}

void
Acceptor::close()
{
  ::shutdown(listen_, SHUT_RDWR);
}

}
