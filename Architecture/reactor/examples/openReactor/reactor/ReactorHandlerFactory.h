/*
 * ReactorHandlerFactory.h
 *
 *  Created on: 2020. 6. 26.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_REACTOR_REACTORHANDLERFACTORY_H_
#define OPEN_REACTOR_REACTOR_REACTORHANDLERFACTORY_H_

#include <reactor/ReactorHandler.h>

namespace reactor
{

class ReactorHandlerFactory
{
public:
  virtual ~ReactorHandlerFactory() {}
  virtual ReactorHandler *create (Reactor        *reactor) = 0;
  virtual void            destroy(Reactor        *reactor,
                                  ReactorHandler *handler) = 0;
};

}

#endif /* reactor_ReactorHandlerFactory_h */


