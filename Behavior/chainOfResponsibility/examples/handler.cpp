#include "handler.h"

void Handler::setNextHandler(Handler* s) {
  successor = s;
}

void Handler::handlerRequest() {
  if (successor != 0) {
    successor->handlerRequest();
  }
}
