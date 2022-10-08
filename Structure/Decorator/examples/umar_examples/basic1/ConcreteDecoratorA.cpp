#include "ConcreteDecoratorA.h"
#include <iostream>
void ConcreteDecoratorA::Operation() {
  std::cout << "ConcreteDecoratorA: Operation()\n";
  m_ptr->Operation();
}
