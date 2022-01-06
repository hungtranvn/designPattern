#include "adapter.h"
#include <iostream>

// client code
void doSomething(Rectangle& r) {
  int w = r.width();
  int h = r.height();

  std::cout << "width: " << w << "\nheight: " << h << std::endl;
}

int main() {
  Rectangle r(2,3);
  doSomething(r);
  
  Square s(2);
  // ?doSomething(s);
  
  Adapter a(s); 
  doSomething(a);
  return 0;
}
