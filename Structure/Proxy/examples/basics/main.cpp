#include "proxy.h"

int main() {
  Proxy *proxy = new Proxy();
  proxy->request();

  delete proxy;
  return 0;
}
