/*
 * AcceptorThreadHandlerFactory.h
 *
 *  Created on: 2020. 8. 3.
 *      Author: tys
 */

#ifndef OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTORTHREADHANDLERFACTORY_H_
#define OPEN_REACTOR_TCP_ACCEPTOR_ACCEPTORTHREADHANDLERFACTORY_H_

#include <acceptor/AcceptorThreadHandler.h>

namespace reactor
{

class AcceptorThreadHandlerFactory
{
public:
  virtual ~AcceptorThreadHandlerFactory() {}
  virtual AcceptorThreadHandler *create() = 0;
};

template<typename ACCEPTOR_THREAD_HANDLER_T = AcceptorThreadHandler>
class AcceptorThreadHandlerFactoryTemplate : public AcceptorThreadHandlerFactory
{
public:
  virtual ~AcceptorThreadHandlerFactoryTemplate() {}
  AcceptorThreadHandler *create() override
  {
    return dynamic_cast<ACCEPTOR_THREAD_HANDLER_T *>(new ACCEPTOR_THREAD_HANDLER_T);
  }
};

}

#endif /* OPEN_REACTOR_ACCEPTORTHREADHANDLERFACTORY_H_ */
