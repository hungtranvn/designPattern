#include "adapter.h"
#include <iostream>

// client code
void doSomething(Rectangle* r) {
  int w = r->width();
  int h = r->height();

  std::cout << "width: " << w << "\nheight: " << h << std::endl;
}

int main() {
  Square s(2);
  Rectangle* r = new Rectangle(2,3);
  doSomething(r);
  //doSomething(s);
  Rectangle* a = new Adapter(s);
  doSomething(a);
  return 0;
}
