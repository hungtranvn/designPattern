/*
 * Reactors.cpp
 *
 *  Created on: 2020. 2. 12.
 *      Author: tys
 */
#include "Reactors.h"

using namespace reactor;

bool
Reactors::init(const size_t           &thread_num,
               const size_t           &max_clients_per_reactor,
               const size_t           &max_events_per_reactor,
               ReactorHandlerFactory  *factory)
{
  for (size_t index = 0; index < thread_num; ++index)
  {
    ReactorThread  *reactor_thread  = new ReactorThread;
    reactor_thread->reactor.init(max_clients_per_reactor,
                                 max_events_per_reactor,
                                 factory);

    reactor_threads_.push_back(reactor_thread);
    reactors_       .push_back(&reactor_thread->reactor);
  }

  return true;
}

bool
Reactors::init(const size_t           &thread_num,
               ReactorHandlerFactory  *factory,
               const size_t           &max_clients_per_reactor,
               const size_t           &max_events_per_reactor)
{
  return this->init(thread_num, max_clients_per_reactor, max_events_per_reactor, factory);
}

bool
Reactors::start()
{
  for (ReactorThread *reactor_thread : reactor_threads_)
    reactor_thread->start();

  return true;
}

void
Reactors::stop()
{
  for (ReactorThread *reactor_thread : reactor_threads_)
    reactor_thread->stop();
}

size_t
Reactors::handler_count() const
{
  size_t count = 0;

  for (Reactor *reactor : reactors_)
    count += reactor->handler_count();

  return count;
}

