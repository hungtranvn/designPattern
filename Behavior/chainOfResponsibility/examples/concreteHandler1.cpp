#include "concreteHandler1.h"
#include <iostream>

bool ConcreteHandler1::canHandle() {
  return false;
}

void ConcreteHandler1::handlerRequest() {
  if (canHandle()) {
    std::cout << "Handled by concrete handler 1" << std::endl;
  }
  else {
    std::cout << "Can not handled by handler 1" << std::endl;
    Handler::handlerRequest();
  }
}
