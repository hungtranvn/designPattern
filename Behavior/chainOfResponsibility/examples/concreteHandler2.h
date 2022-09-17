#ifndef _CONCRETE_HANDLER_2_H_
#define _CONCRETE_HANDLER_2_H_
#include "handler.h"
class ConcreteHandler2 : public Handler {
public:
  ~ConcreteHandler2() = default;
  bool canHandle();
  virtual void handlerRequest();
};
#endif // _CONCRETE_HANDLER_2_H_
