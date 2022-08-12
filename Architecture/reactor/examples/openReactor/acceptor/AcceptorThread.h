/*
 * AcceptorThread.h
 *
 *  Created on: 2020. 2. 11.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTTHREAD_H_
#define OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTTHREAD_H_

#include <acceptor/AcceptorThreadHandlerFactory.h>
#include <acceptor/Acceptor.h>
#include <acceptor/EventHandlerFactory.h>

#include <reactor/ReactorHandlerFactory.h>
#include <reactor/Reactors.h>
#include <reactor/ObjectsTimer.h>

#include <cstdio>
#include <thread>
#include <unordered_map>
#include <mutex>
#include <condition_variable>

namespace reactor
{

class AcceptorThread
{
public:
  AcceptorThread(Acceptor &acceptor,
                 Reactors &reactors,
                 EventHandlerFactory &event_handler_factory,
                 AcceptorThreadHandlerFactory *acceptor_thread_handler_factory = nullptr);

  ~AcceptorThread();

  void start();
  void stop ();

  const Acceptor &get_acceptor() const { return acceptor_; }

protected:
  void     run();
  Reactor *select_reactor(const std::vector<Reactor *> &reactors);
  static size_t reactor_selector_;

private:
  AcceptorThreadHandler        *acceptor_thread_handler_         = nullptr;
  AcceptorThreadHandlerFactory *acceptor_thread_handler_factory_ = nullptr;

private:
  Acceptor &acceptor_;
  Reactors &reactors_;
  EventHandlerFactory &handler_factory_;

private:
  std::thread *thread_  = nullptr;

private:
  std::condition_variable condition_;
  std::mutex condition_lock_;
  bool is_run_ = false;
};

inline
AcceptorThread::AcceptorThread(Acceptor &acceptor,
                               Reactors &reactors,
                               EventHandlerFactory &event_handler_factory,
                               AcceptorThreadHandlerFactory *acceptor_thread_handler_factory)
: acceptor_thread_handler_factory_(acceptor_thread_handler_factory),
  acceptor_       (acceptor),
  reactors_       (reactors),
  handler_factory_(event_handler_factory)
{
}

inline
AcceptorThread::~AcceptorThread()
{
  if (thread_ != nullptr)
    delete thread_;
}

inline void
AcceptorThread::start()
{
  if (thread_ != nullptr)
    delete thread_;

  thread_ = new std::thread{&AcceptorThread::run, this};

  std::unique_lock<std::mutex> lock(condition_lock_);
  if (is_run_ == true)
    return;

  condition_.wait(lock);
}

inline void
AcceptorThread::stop()
{
  acceptor_.close();
  thread_->join();
  delete thread_;
  thread_ = nullptr;
}

inline Reactor *
AcceptorThread::select_reactor(const std::vector<Reactor *> &reactors)
{
  return reactors[reactor_selector_++ % reactors.size()];
}

}

#endif /* OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTTHREAD_H_ */
