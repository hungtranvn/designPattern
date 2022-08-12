#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include <iostream>

#include "initiation_Dispatcher.hpp"
#include "net.hpp"
#include "event_Handler.hpp"
#include "logging_Acceptor.hpp"
#include "log.hpp"

using namespace std;

#define PORT 9888

int main(){

  reactor::event_Handler *acceptor_Handler = new reactor::logging_Acceptor(PORT);
  
  for (;;) {
    reactor::initiation_Dispatcher::instance()->handle_Events(0);
    LOG("handle events restart");
  }
  
  
  /*
  net::SockStream sock;
  net::SockAcceptor acceptor(PORT);
  if (acceptor.init() == -1)
  {
    LOG("acceptor init fail");
    perror("acceptor init");
  }
  
  if (acceptor.accept_sock(sock) == -1) 
  {
    LOG("accept fail");
    perror("accept");
  }
  sock.recv_stream();
  */

  return 0;
}