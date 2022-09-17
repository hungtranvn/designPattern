#include "concreteHandler2.h"
#include <iostream>

bool ConcreteHandler2::canHandle() {
  return false;
}

void ConcreteHandler2::handlerRequest() {
  if (canHandle()) {
    std::cout << "Handled by concrete handler 2" << std::endl;
  }
  else {
    std::cout << "Can not handled by handler 2" << std::endl;
    Handler::handlerRequest();
  }
}
