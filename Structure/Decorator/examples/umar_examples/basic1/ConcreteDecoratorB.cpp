#include "ConcreteDecoratorB.h"
#include <iostream>
void ConcreteDecoratorB::Operation() {
  std::cout << "ConcreteDecoratorB: Operation()\n";
  m_ptr->Operation();
}
