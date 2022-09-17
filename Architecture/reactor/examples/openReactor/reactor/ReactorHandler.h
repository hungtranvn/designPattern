/*
 * ReactorHandler.h
 *
 *  Created on: 2020. 6. 26.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_REACTORHANDLER_H_
#define OPEN_REACTOR_REACTOR_REACTORHANDLER_H_

#include <reactor/EventHandler.h>

#include <string>
#include <sys/socket.h>
#include <unistd.h>

namespace reactor
{

class Reactors;
class Reactor;

class ReactorHandler : public EventHandler
{
public:
  ReactorHandler() {}

protected:
  virtual void reactor_handle_registered(Reactor *reactor) = 0;
  virtual void reactor_handle_timeout   (Reactor *reactor) = 0;
  virtual void reactor_handle_shutdown  (Reactor *reactor) { (void)reactor; }
  virtual void reactor_handle_error     (Reactor *reactor,
                                         const int         &error_no,
                                         const std::string &error_str)
  { (void)reactor, (void)error_no, (void)error_str; }

  virtual void reactor_handle_registered_handler(Reactor *reactor, EventHandler *handler)
  { (void)reactor, (void)handler; }

  virtual void reactor_handle_removed_handler   (Reactor *reactor, EventHandler *handler)
  { (void)reactor, (void)handler; }

protected:
  bool set_timeout  (const uint32_t &msec);
  void unset_timeout();

private:
  bool init();
  void handle_registered(Reactor *reactor, const io_handle_t &io_handle) override;
  void handle_removed   (Reactor *reactor) override;
  void handle_timeout   (Reactor *reactor) override;
  void handle_shutdown  (Reactor *reactor) override;
  void handle_input     (Reactor *reactor) override;
  void handle_output    (Reactor *reactor) override;
  void handle_error     (Reactor *reactor, const int &error_no, const std::string &error_str) override;
  void handle_close     (Reactor *reactor) override;

private:
  uint8_t buffer_[100];
  int     pipe_send_= INVALID_IO_HANDLE;
  Reactor *reactor_ = nullptr;

  friend class Reactors;
  friend class Reactor;
};

inline bool
ReactorHandler::init()
{
  int pipe_fd[2];
  if (pipe(pipe_fd) < 0)
    return false;

  io_handle_  = pipe_fd[0];
  pipe_send_  = pipe_fd[1];

  return true;
}

inline void
ReactorHandler::handle_registered(Reactor *reactor, const io_handle_t &io_handle)
{
  (void)io_handle;
  reactor_ = reactor;
  this->reactor_handle_registered(reactor);
}

inline void
ReactorHandler::handle_removed(Reactor *reactor)
{
  (void)reactor;
}

inline void
ReactorHandler::handle_timeout(Reactor *reactor)
{
  this->reactor_handle_timeout(reactor);
}

inline void
ReactorHandler::handle_input(Reactor *reactor)
{
  (void)reactor;
  auto ignore_result = [&](const size_t &)->void {};
  ignore_result(::read(io_handle_, buffer_, sizeof(buffer_)));
}

inline void
ReactorHandler::handle_shutdown(Reactor *reactor)
{
  ::close(io_handle_);
  ::close(pipe_send_);
  this->reactor_handle_shutdown(reactor);
}

inline void
ReactorHandler::handle_output(Reactor *reactor)
{
  (void)reactor;
}

inline void
ReactorHandler::handle_close(Reactor *reactor)
{
  (void)reactor;
  ::close(io_handle_);
  ::close(pipe_send_);
}

inline void
ReactorHandler::handle_error(Reactor *reactor, const int &error_no, const std::string &error_str)
{
  (void)reactor;
  this->reactor_handle_error(reactor_, error_no, error_str);
}

}

#endif /* SRC_HTTP_REACTOR_REACTOR_REACTORHANDLER_H_ */




