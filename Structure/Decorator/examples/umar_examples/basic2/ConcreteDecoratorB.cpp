#include "ConcreteDecoratorB.h"
#include <iostream>
void ConcreteDecoratorB::Operation() {
  std::cout << "ConcreteDecoratorB: Operation()\n";
  Decorator::Operation();
}
