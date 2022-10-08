#include <iostream>
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

int main() 
{
  ConcreteComponent component{};
  ConcreteDecoratorA decoratorA(&component);
  decoratorA.Operation();

  return 0;
}
