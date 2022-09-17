#ifndef _CONCRETE_HANDLER_1_H_
#define _CONCRETE_HANDLER_1_H_
#include "handler.h"
class ConcreteHandler1 : public Handler {
public:
  ~ConcreteHandler1() = default;
  bool canHandle();
  virtual void handlerRequest();
};
#endif // _CONCRETE_HANDLER_1_H_
