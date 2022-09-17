/*
 * EventHandlerFactory.h
 *
 *  Created on: 2021. 7. 25.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_ACCEPTOR_EVENTHANDLERFACTORY_H_
#define OPEN_REACTOR_ACCEPTOR_EVENTHANDLERFACTORY_H_

#include <reactor/EventHandler.h>

namespace reactor
{

class EventHandlerFactory
{
public:
  virtual ~EventHandlerFactory() {}
  virtual EventHandler *create (Reactor *reactor) = 0;
};

}


#endif /* OPEN_REACTOR_EVENTHANDLERFACTORY_H_ */
