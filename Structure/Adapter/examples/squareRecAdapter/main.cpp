#include "adapter.h"
#include <iostream>

// client code
void doSomething(Rectangle& r) {
  int w = r.width();
  int h = r.height();

  std::cout << "width: " << w << "\nheight: " << h << std::endl;
}

int main() {
  Square s(2);
  Rectangle r(2,3);
  doSomething(r);
  //doSomething(s);
  Adapter a(s);
  doSomething(a);
  return 0;
}
