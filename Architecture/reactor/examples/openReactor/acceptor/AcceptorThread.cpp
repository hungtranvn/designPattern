/*
 * AcceptorThread.cpp
 *
 *  Created on: 2020. 2. 11.
 *      Author: tys
 */

#include "AcceptorThread.h"
#include <reactor/trace.h>

// tcp nodelay
#include <linux/socket.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/socket.h>

namespace reactor
{

size_t AcceptorThread::reactor_selector_ = 0;

void
AcceptorThread::run()
{
  io_handle_t               client_io_handle  = INVALID_IO_HANDLE;
  struct ::sockaddr_storage client_addr;

  Reactor       *reactor       = nullptr;
  EventHandler  *event_handler = nullptr;

  if (acceptor_thread_handler_factory_ != nullptr)
  {
    acceptor_thread_handler_ = acceptor_thread_handler_factory_->create();
    if (acceptor_thread_handler_ != nullptr)
      acceptor_thread_handler_->handle_registered();
  }

  {
    std::unique_lock<std::mutex> lock(condition_lock_);
    is_run_ = true;
    condition_.notify_all();
  }

  while (true)
  {
    int32_t min_timeout = -1;
    if (acceptor_thread_handler_ != nullptr)
    {
      while ((min_timeout = acceptor_thread_handler_->get_min_timeout()) == 0)
        acceptor_thread_handler_->handle_timeout();
    }

    client_io_handle = acceptor_.accept(client_addr, min_timeout);

    // timeout
    if (client_io_handle == 0)
      continue;

    if (client_io_handle < 0)
      break;

    static int enable = 1;
    setsockopt(client_io_handle, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));
    setsockopt(client_io_handle, IPPROTO_TCP, TCP_NODELAY, &enable, sizeof(int));

    event_handler = handler_factory_.create(reactor);
    if (event_handler == nullptr)
    {
      ::close(client_io_handle);
      return;
    }

    reactor = select_reactor(reactors_.get_reactos());
    reactor->register_event_handler(event_handler, client_io_handle);
  }

  if (acceptor_thread_handler_ != nullptr)
    acceptor_thread_handler_->handle_shutdown();
}

}
