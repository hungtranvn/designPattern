#ifndef NET_HPP_
#define NET_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream> 
#include <strings.h>
#include <unistd.h>

#include "net.hpp" 

namespace net {

    #define BUF_SIZE  8096
    class SockAcceptor;
    class SockStream {
        friend class SockAcceptor;
        public:
            SockStream();
            inline int get_handle(void) const { return handle_;}
            int recv_stream();
            void close_stream();
        private:
            char buf_[BUF_SIZE];
            int handle_;
            sockaddr_in remote_address_;
    };

    class SockAcceptor {
        public:
            SockAcceptor(int _port); 
            inline int get_handle(void) const {return handle_;}
            int init(void);
            int accept_sock(SockStream&);
        private:
            int handle_;
            int port_;
    };

    class InetAddr {
        public:
            InetAddr(int _port);
    };
}   
#endif