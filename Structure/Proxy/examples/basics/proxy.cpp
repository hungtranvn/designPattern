#include "proxy.h"

Proxy::Proxy(void) {
  pSubject = new RealSubject();
}

Proxy::~Proxy(void) {
  delete pSubject;
}

void Proxy::request(void) {
  pSubject->request();
}
