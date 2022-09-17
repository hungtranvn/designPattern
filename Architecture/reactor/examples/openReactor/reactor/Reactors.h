/*
 * Reactors.h
 *
 *  Created on: 2020. 2. 12.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_REACTORS_H_
#define OPEN_REACTOR_REACTOR_REACTORS_H_

#include <reactor/ReactorHandlerFactory.h>
#include <reactor/ReactorThread.h>

#include <mutex>
#include <condition_variable>
#include <vector>

namespace reactor
{

class Reactors
{
public:
  bool    init  (const size_t           &thread_num,
                 const size_t           &max_clients_per_reactor = 1000,
                 const size_t           &max_events_per_reactor  = 500,
                 ReactorHandlerFactory  *factory = nullptr);

  bool    init  (const size_t           &thread_num,
                 ReactorHandlerFactory  *factory,
                 const size_t           &max_clients_per_reactor = 1000,
                 const size_t           &max_events_per_reactor  = 500);

  bool    start ();
  void    stop  ();
  size_t  handler_count() const;

  const std::vector<Reactor *> &
          get_reactos() { return reactors_; }

private:
  std::vector<ReactorThread *> reactor_threads_;
  std::vector<Reactor *>       reactors_;

private:
  std::condition_variable condition_;
  std::mutex condition_lock_;
  bool is_run_ = false;
};

}

#endif /* OPEN_REACTOR_REACTOR_REACTORS_H_ */




