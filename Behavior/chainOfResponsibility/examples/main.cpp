#include "concreteHandler1.h"
#include "concreteHandler2.h"

int main() {
  ConcreteHandler1 handler1;
  ConcreteHandler2 handler2;

  handler1.setNextHandler(&handler2);
  handler1.handlerRequest();

  return 0;
}
