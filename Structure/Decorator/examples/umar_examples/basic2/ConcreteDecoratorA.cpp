#include "ConcreteDecoratorA.h"
#include <iostream>
void ConcreteDecoratorA::Operation() {
  std::cout << "ConcreteDecoratorA: Operation()\n";
  Decorator::Operation();
}
