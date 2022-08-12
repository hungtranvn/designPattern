/*
 * IPV4AcceptThread.h
 *
 *  Created on: 2020. 2. 11.
 *      Author: tys
 */

#ifndef http_rserver_Acceptor_h
#define http_rserver_Acceptor_h

#include <reactor/DefinedType.h>

#include <string>
#include <netinet/in.h>

namespace reactor
{

class Acceptor
{
public:
  virtual ~Acceptor() {}
  Acceptor(const bool &nonblock_client = true) : nonblock_client_(nonblock_client) {}

  void nonblock_client_set()   { nonblock_client_ = true; }
  void nonblock_client_unset() { nonblock_client_ = false; }

  bool listen_ipv4 (const uint16_t     &port,
                    const std::string  &address = "0.0.0.0",
                    const int          &backlog = 100);

  bool listen_ipv46(const uint16_t     &port,
                    const std::string  &address = "::0",
                    const int          &backlog = 100);

  bool listen_ipv6 (const uint16_t     &port,
                    const std::string  &address = "::0",
                    const int          &backlog = 100);

  bool listen_ipv4 (const uint16_t     &port,
                    const int          &backlog,
                    const std::string  &address = "0.0.0.0");

  bool listen_ipv46(const uint16_t     &port,
                    const int          &backlog,
                    const std::string  &address = "::0");

  bool listen_ipv6 (const uint16_t     &port,
                    const int          &backlog,
                    const std::string  &address = "::0");

  virtual const uint16_t &
  listen_port() const { return port_; }

  virtual const std::string &
  listen_addr() const { return address_; }

  virtual std::string
  listen_addr_port() const { return address_ + ":" + std::to_string(port_); }

  virtual io_handle_t
  listen_socket () const { return listen_; }

  virtual io_handle_t
  accept(struct ::sockaddr_storage &client_addr, const int32_t &timeout_msec = -1);

  virtual bool
  is_ipv4 () const { return ipv4_; }

  virtual bool
  is_ipv6 () const { return ipv6_; }

  virtual void
  close();

protected:
  void set_listen_port(const uint16_t &port, const std::string &address)
  {
    port_     = port;
    address_  = address;
  }

protected:
  bool ipv4_ = false;
  bool ipv6_ = false;

private:
  io_handle_t listen_ = INVALID_IO_HANDLE;
  uint16_t    port_   = 0;
  std::string address_;
  bool        nonblock_client_;

private:
  struct sockaddr_in  addr4_;
  struct sockaddr_in6 addr6_;
};

inline bool
Acceptor::listen_ipv4 (const uint16_t     &port,
                       const int          &backlog,
                       const std::string  &address)
{ return listen_ipv4(port, address, backlog); }

inline bool
Acceptor::listen_ipv46(const uint16_t     &port,
                       const int          &backlog,
                       const std::string  &address)
{ return listen_ipv4(port, address, backlog); }

inline bool
Acceptor::listen_ipv6 (const uint16_t     &port,
                       const int          &backlog,
                       const std::string  &address)
{ return listen_ipv4(port, address, backlog); }


}

#endif /* OPEN_REACTOR_ACCCEPTOR_ACCEPTOR_H_ */
